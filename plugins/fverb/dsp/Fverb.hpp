
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: fverb.dsp
// Name: fverb
// Author: Jean Pierre Cimalando
// Copyright:
// License: BSD-2-Clause
// Version: 0.5
//------------------------------------------------------------------------------


#pragma once
#ifndef Fverb_Faust_pp_Gen_HPP_
#define Fverb_Faust_pp_Gen_HPP_

#include <memory>

class Fverb {
public:
    Fverb();
    ~Fverb();

    void init(float sample_rate);
    void clear() noexcept;

    void process(const float *in0, const float *in1, float *out0, float *out1,
                 unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 13 };
    enum { NumPassives = 0 };
    enum { NumParameters = 13 };

    enum Parameter {
        p_predelay,
        p_input,
        p_input_lowpass,
        p_input_highpass,
        p_input_diffusion_1,
        p_input_diffusion_2,
        p_tail_density,
        p_decay,
        p_damping,
        p_mod_frequency,
        p_mod_depth,
        p_dry,
        p_wet,

    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;


    float get_predelay() const noexcept;

    float get_input() const noexcept;

    float get_input_lowpass() const noexcept;

    float get_input_highpass() const noexcept;

    float get_input_diffusion_1() const noexcept;

    float get_input_diffusion_2() const noexcept;

    float get_tail_density() const noexcept;

    float get_decay() const noexcept;

    float get_damping() const noexcept;

    float get_mod_frequency() const noexcept;

    float get_mod_depth() const noexcept;

    float get_dry() const noexcept;

    float get_wet() const noexcept;


    void set_predelay(float value) noexcept;

    void set_input(float value) noexcept;

    void set_input_lowpass(float value) noexcept;

    void set_input_highpass(float value) noexcept;

    void set_input_diffusion_1(float value) noexcept;

    void set_input_diffusion_2(float value) noexcept;

    void set_tail_density(float value) noexcept;

    void set_decay(float value) noexcept;

    void set_damping(float value) noexcept;

    void set_mod_frequency(float value) noexcept;

    void set_mod_depth(float value) noexcept;

    void set_dry(float value) noexcept;

    void set_wet(float value) noexcept;


public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;
};


#endif  // Fverb_Faust_pp_Gen_HPP_
