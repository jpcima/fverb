/*
 * Fshim audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2020 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#include "PluginFshim.hpp"
#include "dsp/Fshim.hpp"
#include "blink/DenormalDisabler.h"
#include <cstring>

enum {
    pIdBypass,
    pIdDspFirst,
    pIdDspLast = pIdDspFirst + Fshim::NumActives - 1,
    kNumParameters,
};

// -----------------------------------------------------------------------

PluginFshim::PluginFshim()
    : Plugin(kNumParameters, 0, 0),
      fDsp(new Fshim)
{
    for (unsigned p = 0; p < kNumParameters; ++p) {
        Parameter param;
        initParameter(p, param);
        setParameterValue(p, param.ranges.def);
    }

    sampleRateChanged(getSampleRate());
}

PluginFshim::~PluginFshim()
{
}

// -----------------------------------------------------------------------
// Init

void PluginFshim::initParameter(uint32_t index, Parameter &parameter)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, );

    if (index < pIdDspFirst) {
        switch (index) {
        case pIdBypass:
            parameter.initDesignation(kParameterDesignationBypass);
            break;
        }
        return;
    }
    index -= pIdDspFirst;

    parameter.hints = kParameterIsAutomable;

    parameter.name = Fshim::parameter_label(index);
    parameter.shortName = Fshim::parameter_short_label(index);
    parameter.symbol = Fshim::parameter_symbol(index);
    parameter.unit = Fshim::parameter_unit(index);

    const Fshim::ParameterRange &range = *Fshim::parameter_range(index);
    parameter.ranges.def = range.init;
    parameter.ranges.min = range.min;
    parameter.ranges.max = range.max;

    if (Fshim::parameter_is_trigger(index))
        parameter.hints |= kParameterIsTrigger;
    if (Fshim::parameter_is_boolean(index))
        parameter.hints |= kParameterIsBoolean|kParameterIsInteger;
    if (Fshim::parameter_is_integer(index))
        parameter.hints |= kParameterIsInteger;
    if (Fshim::parameter_is_logarithmic(index))
        parameter.hints |= kParameterIsLogarithmic;
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PluginFshim::sampleRateChanged(double newSampleRate)
{
    fDsp->init(newSampleRate);
}

/**
  Get the current value of a parameter.
*/
float PluginFshim::getParameterValue(uint32_t index) const
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, 0);

    if (index < pIdDspFirst) {
        switch (index) {
        case pIdBypass:
            return fBypass;
        }
        return 0;
    }
    index -= pIdDspFirst;

    return fDsp->get_parameter(index);
}

/**
  Change a parameter value.
*/
void PluginFshim::setParameterValue(uint32_t index, float value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < kNumParameters, );

    if (index < pIdDspFirst) {
        switch (index) {
        case pIdBypass:
            fBypass = value;
            break;
        }
        return;
    }
    index -= pIdDspFirst;

    fDsp->set_parameter(index, value);
}

// -----------------------------------------------------------------------
// Process

void PluginFshim::activate()
{
    fDsp->clear();
    fWasBypass = false;
}


void PluginFshim::run(const float **inputs, float **outputs, uint32_t frames)
{
    WebCore::DenormalDisabler dd;

    if (fBypass < 0.5f) {
        // TODO make it smooth
        if (fWasBypass) {
            fDsp->clear();
            fWasBypass = false;
        }
        fDsp->process(inputs[0], inputs[1], outputs[0], outputs[1], frames);
    }
    else {
        if (inputs[0] != outputs[0])
            std::memcpy(outputs[0], inputs[0], frames * sizeof(float));
        if (inputs[1] != outputs[1])
            std::memcpy(outputs[1], inputs[1], frames * sizeof(float));
        fWasBypass = true;
    }
}

// -----------------------------------------------------------------------

Plugin *DISTRHO::createPlugin()
{
    return new PluginFshim;
}

// -----------------------------------------------------------------------
