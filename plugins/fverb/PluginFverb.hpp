/*
 * Fverb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2020 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#pragma once
#include "DistrhoPlugin.hpp"
#include "WDLex/resampleMOD.h"
#include <vector>
#include <array>
#include <memory>

class Fverb;

// -----------------------------------------------------------------------

class PluginFverb : public Plugin {
public:
    PluginFverb();

    ~PluginFverb();

protected:
    // -------------------------------------------------------------------
    // Information

    const char *getLabel() const noexcept override
    {
        return "fverb";
    }

    const char *getDescription() const override
    {
        return "Fverb";
    }

    const char *getMaker() const noexcept override
    {
        return "Jean Pierre Cimalando";
    }

    const char *getHomePage() const override
    {
        return "http://jpcima.sdf1.org/lv2/fverb";
    }

    const char *getLicense() const noexcept override
    {
        return "http://spdx.org/licenses/BSD-2-Clause";
    }

    uint32_t getVersion() const noexcept override
    {
        return d_version(0, 1, 0);
    }

    // Go to:
    //
    // http://service.steinberg.de/databases/plugin.nsf/plugIn
    //
    // Get a proper plugin UID and fill it in here!
    int64_t getUniqueId() const noexcept override
    {
        return d_cconst('a', 'b', 'c', 'd');
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter &parameter) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;

    // -------------------------------------------------------------------
    // Optional

    // Optional callback to inform the plugin about a sample rate change.
    void sampleRateChanged(double newSampleRate) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;

    void run(const float **, float **outputs, uint32_t frames) override;

    void clear();

    // -------------------------------------------------------------------
private:
    void runAtNormalRate(const float **inputs, float **outputs, uint32_t frames);
    void runDownsampled(const float **inputs, float **outputs, uint32_t frames);
    void runDownsampled_(const float **inputs, float **outputs, uint32_t frames);

    // -------------------------------------------------------------------

private:
    enum {
        kNumChannels = DISTRHO_PLUGIN_NUM_OUTPUTS,
    };

private:
    std::unique_ptr<Fverb> fDsp;

    float fBypass = 0;
    bool fWasBypass = false;

    bool fVintage = false;
    bool fWasVintage = false;

    WDL_Resampler fDownsampler;
    WDL_Resampler fUpsampler;

    std::array<float, kNumChannels> fLastDspOutputs{};

    std::vector<float> fDownsamplerOut;
    std::vector<float> fUpsamplerOut;
    std::vector<float> fDspIn[kNumChannels];
    std::vector<float> fDspOut[kNumChannels];

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginFverb)
};

// -----------------------------------------------------------------------
