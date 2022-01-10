/*
 * Fverb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2020 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#include "PluginFverb.hpp"
#include "dsp/Fverb.hpp"
#include "blink/DenormalDisabler.h"
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cassert>

enum {
    pIdBypass,
    pIdDspFirst,
    pIdDspLast = pIdDspFirst + Fverb::NumActives - 1,
    pIdDry,
    pIdWet,
    pIdVintage,
    kNumParameters,
};

static constexpr float kVintageSampleRate = 29761;

static constexpr uint32_t kMaxResampledBlock = 256;

// -----------------------------------------------------------------------

PluginFverb::PluginFverb()
    : Plugin(kNumParameters, 0, 0),
      fDsp(new Fverb)
{
    for (unsigned p = 0; p < kNumParameters; ++p) {
        Parameter param;
        initParameter(p, param);
        setParameterValue(p, param.ranges.def);
    }

    float tau = 5e-3;
    fDry.setTimeConstant(tau);
    fWet.setTimeConstant(tau);

    sampleRateChanged(getSampleRate());
}

PluginFverb::~PluginFverb()
{
}

// -----------------------------------------------------------------------
// Init

void PluginFverb::initParameter(uint32_t index, Parameter &parameter)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, );

    switch (index) {
    case pIdBypass:
        parameter.initDesignation(kParameterDesignationBypass);
        return;
    case pIdDry:
        parameter.hints = kParameterIsAutomatable;
        parameter.name = "Dry";
        parameter.symbol = "dry";
        parameter.ranges.def = 0;
        parameter.ranges.min = 0;
        parameter.ranges.max = 100;
        parameter.unit = "%";
        return;
    case pIdWet:
        parameter.hints = kParameterIsAutomatable;
        parameter.name = "Wet";
        parameter.symbol = "wet";
        parameter.ranges.def = 0;
        parameter.ranges.min = 0;
        parameter.ranges.max = 100;
        parameter.unit = "%";
        return;
    case pIdVintage:
        parameter.hints = kParameterIsAutomatable;
        parameter.name = "Vintage";
        parameter.symbol = "vintage";
        parameter.hints |= kParameterIsBoolean|kParameterIsInteger;
        parameter.ranges.def = 0;
        parameter.ranges.min = 0;
        parameter.ranges.max = 1;
        return;
    }

    DISTRHO_SAFE_ASSERT_RETURN(index >= pIdDspFirst && index <= pIdDspLast, );
    index -= pIdDspFirst;

    parameter.hints = kParameterIsAutomatable;

    parameter.name = Fverb::parameter_label(index);
    parameter.shortName = Fverb::parameter_short_label(index);
    parameter.symbol = Fverb::parameter_symbol(index);
    parameter.unit = Fverb::parameter_unit(index);

    const Fverb::ParameterRange &range = *Fverb::parameter_range(index);
    parameter.ranges.def = range.init;
    parameter.ranges.min = range.min;
    parameter.ranges.max = range.max;

    if (Fverb::parameter_is_trigger(index))
        parameter.hints |= kParameterIsTrigger;
    if (Fverb::parameter_is_boolean(index))
        parameter.hints |= kParameterIsBoolean|kParameterIsInteger;
    if (Fverb::parameter_is_integer(index))
        parameter.hints |= kParameterIsInteger;
    if (Fverb::parameter_is_logarithmic(index))
        parameter.hints |= kParameterIsLogarithmic;
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PluginFverb::sampleRateChanged(double newSampleRate)
{
    fDsp->init(fVintage ? kVintageSampleRate : newSampleRate);

    fDry.setSampleRate(newSampleRate);
    fWet.setSampleRate(newSampleRate);

    for (uint32_t ch = 0; ch < kNumChannels; ++ch)
        fInputKeep[ch].resize(kMaxResampledBlock);

    fDownsampler.SetRates((int)newSampleRate, kVintageSampleRate);
    fUpsampler.SetRates(kVintageSampleRate, (int)newSampleRate);

    fDownsamplerOut.resize(kNumChannels * (4 + kMaxResampledBlock * (kVintageSampleRate / newSampleRate)));
    fUpsamplerOut.resize(kNumChannels * (4 + kMaxResampledBlock * (newSampleRate / kVintageSampleRate)));

    for (uint32_t ch = 0; ch < kNumChannels; ++ch) {
        fDspIn[ch].resize((4 + kMaxResampledBlock * (kVintageSampleRate / newSampleRate)));
        fDspOut[ch].resize((4 + kMaxResampledBlock * (kVintageSampleRate / newSampleRate)));
    }

    clear();
}

/**
  Get the current value of a parameter.
*/
float PluginFverb::getParameterValue(uint32_t index) const
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, 0);

    switch (index) {
    case pIdBypass:
        return fBypass;
    case pIdDry:
        return fDry.getTarget() * 100;
    case pIdWet:
        return fWet.getTarget() * 100;
    case pIdVintage:
        return fVintage;
    }

    DISTRHO_SAFE_ASSERT_RETURN(index >= pIdDspFirst && index <= pIdDspLast, 0);
    index -= pIdDspFirst;

    return fDsp->get_parameter(index);
}

/**
  Change a parameter value.
*/
void PluginFverb::setParameterValue(uint32_t index, float value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, );

    switch (index) {
    case pIdBypass:
        fBypass = value;
        return;
    case pIdDry:
        fDry.setTarget(value / 100);
        return;
    case pIdWet:
        fWet.setTarget(value / 100);
        return;
    case pIdVintage:
        fVintage = value >= 0.5f;
        return;
    }

    DISTRHO_SAFE_ASSERT_RETURN(index >= pIdDspFirst && index <= pIdDspLast, );
    index -= pIdDspFirst;

    fDsp->set_parameter(index, value);
}

// -----------------------------------------------------------------------
// Process

void PluginFverb::activate()
{
    fDsp->clear();
    fWasBypass = false;
}

///
static inline void interleave(const float *const *inputs, float *const outputs, uint32_t nch, uint32_t nframes)
{
    for (uint32_t ch = 0; ch < nch; ++ch) {
        const float *src = inputs[ch];
        float *dst = outputs + ch;
        for (uint32_t i = 0; i < nframes; ++i)
            dst[i * nch] = src[i];
    }
}

static inline void deinterleave(const float *const inputs, float *const *outputs, uint32_t nch, uint32_t nframes)
{
    for (uint32_t ch = 0; ch < nch; ++ch) {
        const float *src = inputs + ch;
        float *dst = outputs[ch];
        for (uint32_t i = 0; i < nframes; ++i)
            dst[i] = src[i * nch];
    }
}

///
void PluginFverb::run(const float **inputs, float **outputs, uint32_t frames)
{
    if (frames < 1)
        return;

    WebCore::DenormalDisabler dd;

    if (fBypass < 0.5f) {
        // TODO make it smooth
        if (fWasBypass) {
            clear();
            fWasBypass = false;
        }
        if (fVintage != fWasVintage) {
            fDsp->init(fVintage ? kVintageSampleRate : getSampleRate());
            clear();
            fWasVintage = fVintage;
        }
        runSegmented(inputs, outputs, frames);
    }
    else {
        for (uint32_t ch = 0; ch < kNumChannels; ++ch) {
            if (inputs[ch] != outputs[ch])
                std::copy_n(inputs[ch], frames, outputs[ch]);
        }
        fWasBypass = true;
    }
}

void PluginFverb::clear()
{
    fDsp->clear();

    fDry.clearToTarget();
    fWet.clearToTarget();

    fDownsampler.Reset();
    fUpsampler.Reset();

    for (uint32_t ch = 0; ch < kNumChannels; ++ch)
        fLastDspOutputs[ch] = 0;
}

void PluginFverb::runSegmented(const float **inputs, float **outputs, uint32_t frames)
{
    float *inputKeep[kNumChannels];
    for (uint32_t ch = 0; ch < kNumChannels; ++ch) {
        inputKeep[ch] = fInputKeep[ch].data();
        std::copy_n(inputs[ch], frames, inputKeep[ch]);
    }

    uint32_t index = 0;
    while (index < frames) {
        uint32_t bs = frames - index;
        if (bs > kMaxResampledBlock)
            bs = kMaxResampledBlock;

        const float *offsetInputs[kNumChannels];
        float *offsetOutputs[kNumChannels];
        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            offsetInputs[ch] = inputs[ch] + index;
        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            offsetOutputs[ch] = outputs[ch] + index;

        if (!fVintage)
            runAtNormalRate(offsetInputs, offsetOutputs, bs);
        else
            runDownsampled(offsetInputs, offsetOutputs, bs);

        index += bs;
    }

    ///
    if (fWet.getCurrentValue() == fWet.getTarget()) {
        float wet = fWet.getCurrentValue();
        for (uint32_t i = 0; i < frames; ++i) {
            for (uint32_t ch = 0; ch < kNumChannels; ++ch)
                outputs[ch][i] *= wet;
        }
    }
    else {
        for (uint32_t i = 0; i < frames; ++i) {
            float wet = fWet.next();
            for (uint32_t ch = 0; ch < kNumChannels; ++ch)
                outputs[ch][i] *= wet;
        }
    }

    ///
    if (fDry.getCurrentValue() == fDry.getTarget()) {
        float dry = fDry.getCurrentValue();
        for (uint32_t i = 0; i < frames; ++i) {
            for (uint32_t ch = 0; ch < kNumChannels; ++ch)
                outputs[ch][i] += dry * inputKeep[ch][i];
        }
    }
    else {
        for (uint32_t i = 0; i < frames; ++i) {
            float dry = fDry.next();
            for (uint32_t ch = 0; ch < kNumChannels; ++ch)
                outputs[ch][i] += dry * inputKeep[ch][i];
        }
    }
}

void PluginFverb::runAtNormalRate(const float **inputs, float **outputs, uint32_t frames)
{
    fDsp->process(inputs[0], inputs[1], outputs[0], outputs[1], frames);

    for (uint32_t ch = 0; ch < kNumChannels; ++ch)
        fLastDspOutputs[ch] = outputs[ch][frames - 1];
}

void PluginFverb::runDownsampled(const float **inputs, float **outputs, uint32_t frames)
{
    uint32_t dspCount;
    float *dspIn[kNumChannels];
    float *dspOut[kNumChannels];

    for (uint32_t ch = 0; ch < kNumChannels; ++ch)
        dspIn[ch] = fDspIn[ch].data();
    for (uint32_t ch = 0; ch < kNumChannels; ++ch)
        dspOut[ch] = fDspOut[ch].data();

    // downsample
    {
        WDL_ResampleSample *dsIn;
        fDownsampler.SetFeedMode(true);
        int ret = fDownsampler.ResamplePrepare((int)frames, kNumChannels, &dsIn);
        assert(ret == frames);
        interleave(inputs, dsIn, kNumChannels, frames);

        float *dsOut = fDownsamplerOut.data();
        uint32_t dsOutCap = fDownsamplerOut.size();
        dspCount = fDownsampler.ResampleOut(dsOut, frames, dsOutCap, kNumChannels);

        deinterleave(dsOut, dspIn, kNumChannels, dspCount);
    }

    // DSP
    if (dspCount > 0) {
        fDsp->process(dspIn[0], dspIn[1], dspOut[0], dspOut[1], dspCount);

        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            fLastDspOutputs[ch] = outputs[ch][dspCount - 1];
    }

    // upsample
    if (dspCount > 0) {
        WDL_ResampleSample *usIn;
        fUpsampler.SetFeedMode(true);
        int ret = fUpsampler.ResamplePrepare(dspCount, kNumChannels, &usIn);
        assert(ret == dspCount);

        interleave(dspOut, usIn, kNumChannels, dspCount);

        float *usOut = fUpsamplerOut.data();
        uint32_t usOutCap = fUpsamplerOut.size();

        uint32_t finalCount = fUpsampler.ResampleOut(usOut, dspCount, frames, kNumChannels);

        uint32_t pad = frames - finalCount;
        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            std::fill_n(outputs[ch], pad, fLastDspOutputs[ch]);

        float *outputsWithPad[kNumChannels];
        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            outputsWithPad[ch] = outputs[ch] + pad;

        deinterleave(usOut, outputsWithPad, kNumChannels, finalCount);
    }
    else {
        for (uint32_t ch = 0; ch < kNumChannels; ++ch)
            std::fill_n(outputs[ch], frames, fLastDspOutputs[ch]);
    }
}

// -----------------------------------------------------------------------

Plugin *DISTRHO::createPlugin()
{
    return new PluginFverb;
}

// -----------------------------------------------------------------------
