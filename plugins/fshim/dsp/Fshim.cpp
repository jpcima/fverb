
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: fshim.dsp
// Name: fshim
// Author: Jean Pierre Cimalando
// Copyright:
// License: BSD-2-Clause
// Version: 0.5
//------------------------------------------------------------------------------


#include "Fshim.hpp"


#include <utility>
#include <cmath>

class Fshim::BasicDsp {
public:
    virtual ~BasicDsp()
    {
    }
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b)
{
    return (a < b) ? a : b;
}
template <class T> inline T max(T a, T b)
{
    return (a > b) ? a : b;
}

class Meta {
public:
    // dummy
    void declare(...)
    {
    }
};

class UI {
public:
    // dummy
    void openHorizontalBox(...)
    {
    }
    void openVerticalBox(...)
    {
    }
    void closeBox(...)
    {
    }
    void declare(...)
    {
    }
    void addButton(...)
    {
    }
    void addCheckButton(...)
    {
    }
    void addVerticalSlider(...)
    {
    }
    void addHorizontalSlider(...)
    {
    }
    void addVerticalBargraph(...)
    {
    }
    void addHorizontalBargraph(...)
    {
    }
};

typedef Fshim::BasicDsp dsp;

}  // namespace

#define FAUSTPP_VIRTUAL  // do not declare any methods virtual
#define FAUSTPP_PRIVATE public  // do not hide any members
#define FAUSTPP_PROTECTED public  // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

class mydspSIG0 {

    FAUSTPP_PRIVATE :

        int iRec20[2];

public:
    int getNumInputsmydspSIG0()
    {
        return 0;
    }
    int getNumOutputsmydspSIG0()
    {
        return 1;
    }
    int getInputRatemydspSIG0(int channel)
    {
        int rate;
        switch ((channel)) {
        default: {
            rate = -1;
            break;
        }
        }
        return rate;
    }
    int getOutputRatemydspSIG0(int channel)
    {
        int rate;
        switch ((channel)) {
        case 0: {
            rate = 0;
            break;
        }
        default: {
            rate = -1;
            break;
        }
        }
        return rate;
    }

    void instanceInitmydspSIG0(int sample_rate)
    {
        for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
            iRec20[l3] = 0;
        }
    }

    void fillmydspSIG0(int count, float *table)
    {
        for (int i = 0; (i < count); i = (i + 1)) {
            iRec20[0] = (iRec20[1] + 1);
            table[i] = std::sin((9.58738019e-05f * float((iRec20[0] + -1))));
            iRec20[1] = iRec20[0];
        }
    }
};

static mydspSIG0 *newmydspSIG0()
{
    return (mydspSIG0 *)new mydspSIG0();
}
static void deletemydspSIG0(mydspSIG0 *dsp)
{
    delete dsp;
}

static float ftbl0mydspSIG0[65536];

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {

    FAUSTPP_PRIVATE :

        FAUSTFLOAT fHslider0;
    float fRec2[2];
    FAUSTFLOAT fHslider1;
    float fRec11[2];
    int fSampleRate;
    float fConst0;
    FAUSTFLOAT fHslider2;
    float fRec19[2];
    float fConst1;
    FAUSTFLOAT fHslider3;
    float fRec22[2];
    float fRec21[2];
    float fConst2;
    float fConst3;
    float fRec15[2];
    float fRec16[2];
    int iRec17[2];
    int iRec18[2];
    FAUSTFLOAT fHslider4;
    float fRec33[2];
    float fRec34[2];
    int IOTA;
    float fVec0[131072];
    FAUSTFLOAT fHslider5;
    float fRec35[2];
    FAUSTFLOAT fHslider6;
    float fRec36[2];
    float fRec32[2];
    FAUSTFLOAT fHslider7;
    float fRec37[2];
    float fRec31[2];
    FAUSTFLOAT fHslider8;
    float fRec38[2];
    float fVec1[1024];
    int iConst4;
    float fRec29[2];
    float fVec2[1024];
    int iConst5;
    float fRec27[2];
    FAUSTFLOAT fHslider9;
    float fRec39[2];
    float fVec3[4096];
    int iConst6;
    float fRec25[2];
    float fVec4[2048];
    int iConst7;
    float fRec23[2];
    int iConst8;
    FAUSTFLOAT fHslider10;
    float fRec40[2];
    float fVec5[131072];
    float fRec13[2];
    float fVec6[32768];
    int iConst9;
    FAUSTFLOAT fHslider11;
    float fRec41[2];
    float fRec12[2];
    float fVec7[32768];
    int iConst10;
    float fRec9[2];
    float fRec3[32768];
    float fRec4[16384];
    float fRec5[32768];
    float fRec47[2];
    float fRec48[2];
    int iRec49[2];
    int iRec50[2];
    float fVec8[131072];
    float fRec60[2];
    float fRec59[2];
    float fVec9[1024];
    int iConst11;
    float fRec57[2];
    float fVec10[1024];
    int iConst12;
    float fRec55[2];
    float fVec11[4096];
    int iConst13;
    float fRec53[2];
    float fVec12[2048];
    int iConst14;
    float fRec51[2];
    int iConst15;
    float fVec13[131072];
    float fRec45[2];
    float fVec14[32768];
    int iConst16;
    float fRec44[2];
    float fVec15[16384];
    int iConst17;
    float fRec42[2];
    float fRec6[32768];
    float fRec7[8192];
    float fRec8[32768];
    int iConst18;
    int iConst19;
    int iConst20;
    int iConst21;
    int iConst22;
    int iConst23;
    int iConst24;
    float fRec0[131072];
    int iConst25;
    int iConst26;
    int iConst27;
    int iConst28;
    int iConst29;
    int iConst30;
    int iConst31;
    float fRec1[131072];
    FAUSTFLOAT fHslider12;
    float fRec61[2];

public:
    void metadata(Meta *m)
    {
        m->declare("author", "Jean Pierre Cimalando");
        m->declare("basics.lib/name", "Faust Basic Element Library");
        m->declare("basics.lib/version", "0.1");
        m->declare("delays.lib/name", "Faust Delay Library");
        m->declare("delays.lib/version", "0.1");
        m->declare("filename", "fshim.dsp");
        m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
        m->declare("filters.lib/allpass_comb:copyright",
                   "Copyright (C) 2003-2019 by Julius O. Smith III "
                   "<jos@ccrma.stanford.edu>");
        m->declare("filters.lib/allpass_comb:license",
                   "MIT-style STK-4.3 license");
        m->declare("filters.lib/fir:author", "Julius O. Smith III");
        m->declare("filters.lib/fir:copyright",
                   "Copyright (C) 2003-2019 by Julius O. Smith III "
                   "<jos@ccrma.stanford.edu>");
        m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
        m->declare("filters.lib/iir:author", "Julius O. Smith III");
        m->declare("filters.lib/iir:copyright",
                   "Copyright (C) 2003-2019 by Julius O. Smith III "
                   "<jos@ccrma.stanford.edu>");
        m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
        m->declare("filters.lib/lowpass0_highpass1",
                   "Copyright (C) 2003-2019 by Julius O. Smith III "
                   "<jos@ccrma.stanford.edu>");
        m->declare("filters.lib/name", "Faust Filters Library");
        m->declare("fverb.dsp/author", "Jean Pierre Cimalando");
        m->declare("fverb.dsp/license", "BSD-2-Clause");
        m->declare("fverb.dsp/name", "fverb");
        m->declare("fverb.dsp/version", "0.5");
        m->declare("license", "BSD-2-Clause");
        m->declare("maths.lib/author", "GRAME");
        m->declare("maths.lib/copyright", "GRAME");
        m->declare("maths.lib/license", "LGPL with exception");
        m->declare("maths.lib/name", "Faust Math Library");
        m->declare("maths.lib/version", "2.1");
        m->declare("misceffects.lib/name", "Faust Math Library");
        m->declare("misceffects.lib/version", "2.0");
        m->declare("name", "fshim");
        m->declare("oscillators.lib/name", "Faust Oscillator Library");
        m->declare("oscillators.lib/version", "0.0");
        m->declare("signals.lib/name", "Faust Signal Routing Library");
        m->declare("signals.lib/version", "0.0");
        m->declare("version", "0.5");
    }

    FAUSTPP_VIRTUAL int getNumInputs()
    {
        return 2;
    }
    FAUSTPP_VIRTUAL int getNumOutputs()
    {
        return 2;
    }
    FAUSTPP_VIRTUAL int getInputRate(int channel)
    {
        int rate;
        switch ((channel)) {
        case 0: {
            rate = 1;
            break;
        }
        case 1: {
            rate = 1;
            break;
        }
        default: {
            rate = -1;
            break;
        }
        }
        return rate;
    }
    FAUSTPP_VIRTUAL int getOutputRate(int channel)
    {
        int rate;
        switch ((channel)) {
        case 0: {
            rate = 1;
            break;
        }
        case 1: {
            rate = 1;
            break;
        }
        default: {
            rate = -1;
            break;
        }
        }
        return rate;
    }

    static void classInit(int sample_rate)
    {
        mydspSIG0 *sig0 = newmydspSIG0();
        sig0->instanceInitmydspSIG0(sample_rate);
        sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
        deletemydspSIG0(sig0);
    }

    FAUSTPP_VIRTUAL void instanceConstants(int sample_rate)
    {
        fSampleRate = sample_rate;
        fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
        fConst1 = (1.0f / fConst0);
        fConst2 = (1.0f / float(int((0.00999999978f * fConst0))));
        fConst3 = (0.0f - fConst2);
        iConst4 =
            std::min<int>(65536, std::max<int>(0, (int((0.00462820474f * fConst0)) + -1)));
        iConst5 =
            std::min<int>(65536, std::max<int>(0, (int((0.00370316859f * fConst0)) + -1)));
        iConst6 =
            std::min<int>(65536, std::max<int>(0, (int((0.013116831f * fConst0)) + -1)));
        iConst7 =
            std::min<int>(65536, std::max<int>(0, (int((0.00902825873f * fConst0)) + -1)));
        iConst8 =
            (std::min<int>(65536, std::max<int>(0, int((0.106280029f * fConst0)))) + 1);
        iConst9 = std::min<int>(65536, std::max<int>(0, int((0.141695514f * fConst0))));
        iConst10 =
            std::min<int>(65536, std::max<int>(0, (int((0.0892443135f * fConst0)) + -1)));
        iConst11 =
            std::min<int>(65536, std::max<int>(0, (int((0.00491448538f * fConst0)) + -1)));
        iConst12 =
            std::min<int>(65536, std::max<int>(0, (int((0.00348745007f * fConst0)) + -1)));
        iConst13 =
            std::min<int>(65536, std::max<int>(0, (int((0.0123527432f * fConst0)) + -1)));
        iConst14 =
            std::min<int>(65536, std::max<int>(0, (int((0.00958670769f * fConst0)) + -1)));
        iConst15 =
            (std::min<int>(65536, std::max<int>(0, int((0.124995798f * fConst0)))) + 1);
        iConst16 = std::min<int>(65536, std::max<int>(0, int((0.149625346f * fConst0))));
        iConst17 =
            std::min<int>(65536, std::max<int>(0, (int((0.0604818389f * fConst0)) + -1)));
        iConst18 =
            std::min<int>(65536, std::max<int>(0, int((0.00893787201f * fConst0))));
        iConst19 = std::min<int>(65536, std::max<int>(0, int((0.099929437f * fConst0))));
        iConst20 = std::min<int>(65536, std::max<int>(0, int((0.067067638f * fConst0))));
        iConst21 =
            std::min<int>(65536, std::max<int>(0, int((0.0642787516f * fConst0))));
        iConst22 =
            std::min<int>(65536, std::max<int>(0, int((0.0668660328f * fConst0))));
        iConst23 =
            std::min<int>(65536, std::max<int>(0, int((0.0062833908f * fConst0))));
        iConst24 =
            std::min<int>(65536, std::max<int>(0, int((0.0358186886f * fConst0))));
        iConst25 =
            std::min<int>(65536, std::max<int>(0, int((0.0118611604f * fConst0))));
        iConst26 = std::min<int>(65536, std::max<int>(0, int((0.121870905f * fConst0))));
        iConst27 =
            std::min<int>(65536, std::max<int>(0, int((0.0898155272f * fConst0))));
        iConst28 = std::min<int>(65536, std::max<int>(0, int((0.041262053f * fConst0))));
        iConst29 = std::min<int>(65536, std::max<int>(0, int((0.070931755f * fConst0))));
        iConst30 =
            std::min<int>(65536, std::max<int>(0, int((0.0112563418f * fConst0))));
        iConst31 =
            std::min<int>(65536, std::max<int>(0, int((0.00406572362f * fConst0))));
    }

    FAUSTPP_VIRTUAL void instanceResetUserInterface()
    {
        fHslider0 = FAUSTFLOAT(50.0f);
        fHslider1 = FAUSTFLOAT(50.0f);
        fHslider2 = FAUSTFLOAT(0.5f);
        fHslider3 = FAUSTFLOAT(1.0f);
        fHslider4 = FAUSTFLOAT(100.0f);
        fHslider5 = FAUSTFLOAT(0.0f);
        fHslider6 = FAUSTFLOAT(10000.0f);
        fHslider7 = FAUSTFLOAT(100.0f);
        fHslider8 = FAUSTFLOAT(75.0f);
        fHslider9 = FAUSTFLOAT(62.5f);
        fHslider10 = FAUSTFLOAT(70.0f);
        fHslider11 = FAUSTFLOAT(5500.0f);
        fHslider12 = FAUSTFLOAT(100.0f);
    }

    FAUSTPP_VIRTUAL void instanceClear()
    {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fRec2[l0] = 0.0f;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec11[l1] = 0.0f;
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec19[l2] = 0.0f;
        }
        for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
            fRec22[l4] = 0.0f;
        }
        for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
            fRec21[l5] = 0.0f;
        }
        for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
            fRec15[l6] = 0.0f;
        }
        for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
            fRec16[l7] = 0.0f;
        }
        for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
            iRec17[l8] = 0;
        }
        for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
            iRec18[l9] = 0;
        }
        for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
            fRec33[l10] = 0.0f;
        }
        for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
            fRec34[l11] = 0.0f;
        }
        IOTA = 0;
        for (int l12 = 0; (l12 < 131072); l12 = (l12 + 1)) {
            fVec0[l12] = 0.0f;
        }
        for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
            fRec35[l13] = 0.0f;
        }
        for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
            fRec36[l14] = 0.0f;
        }
        for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
            fRec32[l15] = 0.0f;
        }
        for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
            fRec37[l16] = 0.0f;
        }
        for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
            fRec31[l17] = 0.0f;
        }
        for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
            fRec38[l18] = 0.0f;
        }
        for (int l19 = 0; (l19 < 1024); l19 = (l19 + 1)) {
            fVec1[l19] = 0.0f;
        }
        for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
            fRec29[l20] = 0.0f;
        }
        for (int l21 = 0; (l21 < 1024); l21 = (l21 + 1)) {
            fVec2[l21] = 0.0f;
        }
        for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
            fRec27[l22] = 0.0f;
        }
        for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
            fRec39[l23] = 0.0f;
        }
        for (int l24 = 0; (l24 < 4096); l24 = (l24 + 1)) {
            fVec3[l24] = 0.0f;
        }
        for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
            fRec25[l25] = 0.0f;
        }
        for (int l26 = 0; (l26 < 2048); l26 = (l26 + 1)) {
            fVec4[l26] = 0.0f;
        }
        for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
            fRec23[l27] = 0.0f;
        }
        for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
            fRec40[l28] = 0.0f;
        }
        for (int l29 = 0; (l29 < 131072); l29 = (l29 + 1)) {
            fVec5[l29] = 0.0f;
        }
        for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
            fRec13[l30] = 0.0f;
        }
        for (int l31 = 0; (l31 < 32768); l31 = (l31 + 1)) {
            fVec6[l31] = 0.0f;
        }
        for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
            fRec41[l32] = 0.0f;
        }
        for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
            fRec12[l33] = 0.0f;
        }
        for (int l34 = 0; (l34 < 32768); l34 = (l34 + 1)) {
            fVec7[l34] = 0.0f;
        }
        for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
            fRec9[l35] = 0.0f;
        }
        for (int l36 = 0; (l36 < 32768); l36 = (l36 + 1)) {
            fRec3[l36] = 0.0f;
        }
        for (int l37 = 0; (l37 < 16384); l37 = (l37 + 1)) {
            fRec4[l37] = 0.0f;
        }
        for (int l38 = 0; (l38 < 32768); l38 = (l38 + 1)) {
            fRec5[l38] = 0.0f;
        }
        for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
            fRec47[l39] = 0.0f;
        }
        for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
            fRec48[l40] = 0.0f;
        }
        for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
            iRec49[l41] = 0;
        }
        for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
            iRec50[l42] = 0;
        }
        for (int l43 = 0; (l43 < 131072); l43 = (l43 + 1)) {
            fVec8[l43] = 0.0f;
        }
        for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
            fRec60[l44] = 0.0f;
        }
        for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
            fRec59[l45] = 0.0f;
        }
        for (int l46 = 0; (l46 < 1024); l46 = (l46 + 1)) {
            fVec9[l46] = 0.0f;
        }
        for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
            fRec57[l47] = 0.0f;
        }
        for (int l48 = 0; (l48 < 1024); l48 = (l48 + 1)) {
            fVec10[l48] = 0.0f;
        }
        for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
            fRec55[l49] = 0.0f;
        }
        for (int l50 = 0; (l50 < 4096); l50 = (l50 + 1)) {
            fVec11[l50] = 0.0f;
        }
        for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
            fRec53[l51] = 0.0f;
        }
        for (int l52 = 0; (l52 < 2048); l52 = (l52 + 1)) {
            fVec12[l52] = 0.0f;
        }
        for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
            fRec51[l53] = 0.0f;
        }
        for (int l54 = 0; (l54 < 131072); l54 = (l54 + 1)) {
            fVec13[l54] = 0.0f;
        }
        for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
            fRec45[l55] = 0.0f;
        }
        for (int l56 = 0; (l56 < 32768); l56 = (l56 + 1)) {
            fVec14[l56] = 0.0f;
        }
        for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
            fRec44[l57] = 0.0f;
        }
        for (int l58 = 0; (l58 < 16384); l58 = (l58 + 1)) {
            fVec15[l58] = 0.0f;
        }
        for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
            fRec42[l59] = 0.0f;
        }
        for (int l60 = 0; (l60 < 32768); l60 = (l60 + 1)) {
            fRec6[l60] = 0.0f;
        }
        for (int l61 = 0; (l61 < 8192); l61 = (l61 + 1)) {
            fRec7[l61] = 0.0f;
        }
        for (int l62 = 0; (l62 < 32768); l62 = (l62 + 1)) {
            fRec8[l62] = 0.0f;
        }
        for (int l63 = 0; (l63 < 131072); l63 = (l63 + 1)) {
            fRec0[l63] = 0.0f;
        }
        for (int l64 = 0; (l64 < 131072); l64 = (l64 + 1)) {
            fRec1[l64] = 0.0f;
        }
        for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
            fRec61[l65] = 0.0f;
        }
    }

    FAUSTPP_VIRTUAL void init(int sample_rate)
    {
        classInit(sample_rate);
        instanceInit(sample_rate);
    }
    FAUSTPP_VIRTUAL void instanceInit(int sample_rate)
    {
        instanceConstants(sample_rate);
        instanceResetUserInterface();
        instanceClear();
    }

    FAUSTPP_VIRTUAL mydsp *clone()
    {
        return new mydsp();
    }

    FAUSTPP_VIRTUAL int getSampleRate()
    {
        return fSampleRate;
    }

    FAUSTPP_VIRTUAL void buildUserInterface(UI *ui_interface)
    {
        ui_interface->openVerticalBox("fshim");
        ui_interface->declare(&fHslider5, "01", "");
        ui_interface->declare(&fHslider5, "symbol", "predelay");
        ui_interface->declare(&fHslider5, "unit", "ms");
        ui_interface->addHorizontalSlider("Predelay", &fHslider5, 0.0f, 0.0f, 300.0f, 1.0f);
        ui_interface->declare(&fHslider4, "02", "");
        ui_interface->declare(&fHslider4, "symbol", "input");
        ui_interface->declare(&fHslider4, "unit", "%");
        ui_interface->addHorizontalSlider("Input amount", &fHslider4, 100.0f,
                                          0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider6, "03", "");
        ui_interface->declare(&fHslider6, "scale", "log");
        ui_interface->declare(&fHslider6, "symbol", "input_lowpass");
        ui_interface->declare(&fHslider6, "unit", "Hz");
        ui_interface->addHorizontalSlider("Input low-pass cutoff", &fHslider6,
                                          10000.0f, 1.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fHslider7, "04", "");
        ui_interface->declare(&fHslider7, "scale", "log");
        ui_interface->declare(&fHslider7, "symbol", "input_highpass");
        ui_interface->declare(&fHslider7, "unit", "Hz");
        ui_interface->addHorizontalSlider("Input high-pass cutoff", &fHslider7,
                                          100.0f, 1.0f, 1000.0f, 1.0f);
        ui_interface->declare(&fHslider8, "05", "");
        ui_interface->declare(&fHslider8, "symbol", "input_diffusion_1");
        ui_interface->declare(&fHslider8, "unit", "%");
        ui_interface->addHorizontalSlider("Input diffusion 1", &fHslider8,
                                          75.0f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider9, "06", "");
        ui_interface->declare(&fHslider9, "symbol", "input_diffusion_2");
        ui_interface->declare(&fHslider9, "unit", "%");
        ui_interface->addHorizontalSlider("Input diffusion 2", &fHslider9,
                                          62.5f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider10, "07", "");
        ui_interface->declare(&fHslider10, "symbol", "tail_density");
        ui_interface->declare(&fHslider10, "unit", "%");
        ui_interface->addHorizontalSlider("Tail density", &fHslider10, 70.0f,
                                          0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider1, "08", "");
        ui_interface->declare(&fHslider1, "symbol", "decay");
        ui_interface->declare(&fHslider1, "unit", "%");
        ui_interface->addHorizontalSlider("Decay", &fHslider1, 50.0f, 0.0f,
                                          100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider11, "09", "");
        ui_interface->declare(&fHslider11, "scale", "log");
        ui_interface->declare(&fHslider11, "symbol", "damping");
        ui_interface->declare(&fHslider11, "unit", "Hz");
        ui_interface->addHorizontalSlider("Damping", &fHslider11, 5500.0f,
                                          10.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fHslider3, "10", "");
        ui_interface->declare(&fHslider3, "symbol", "mod_frequency");
        ui_interface->declare(&fHslider3, "unit", "Hz");
        ui_interface->addHorizontalSlider("Modulator frequency", &fHslider3, 1.0f,
                                          0.00999999978f, 4.0f, 0.00999999978f);
        ui_interface->declare(&fHslider2, "11", "");
        ui_interface->declare(&fHslider2, "symbol", "mod_depth");
        ui_interface->declare(&fHslider2, "unit", "ms");
        ui_interface->addHorizontalSlider("Modulator depth", &fHslider2, 0.5f,
                                          0.0f, 10.0f, 0.100000001f);
        ui_interface->declare(&fHslider12, "12", "");
        ui_interface->declare(&fHslider12, "symbol", "dry");
        ui_interface->declare(&fHslider12, "unit", "%");
        ui_interface->addHorizontalSlider("Dry", &fHslider12, 100.0f, 0.0f,
                                          100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider0, "13", "");
        ui_interface->declare(&fHslider0, "symbol", "wet");
        ui_interface->declare(&fHslider0, "unit", "%");
        ui_interface->addHorizontalSlider("Wet", &fHslider0, 50.0f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->closeBox();
    }

    FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT **inputs, FAUSTFLOAT **outputs)
    {
        FAUSTFLOAT *input0 = inputs[0];
        FAUSTFLOAT *input1 = inputs[1];
        FAUSTFLOAT *output0 = outputs[0];
        FAUSTFLOAT *output1 = outputs[1];
        float fSlow0 = (9.99999975e-06f * float(fHslider0));
        float fSlow1 = (9.99999975e-06f * float(fHslider1));
        float fSlow2 = (9.99999997e-07f * float(fHslider2));
        float fSlow3 = (0.00100000005f * float(fHslider3));
        float fSlow4 = (9.99999975e-06f * float(fHslider4));
        float fSlow5 = (9.99999997e-07f * float(fHslider5));
        float fSlow6 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider6))))));
        float fSlow7 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider7))))));
        float fSlow8 = (9.99999975e-06f * float(fHslider8));
        float fSlow9 = (9.99999975e-06f * float(fHslider9));
        float fSlow10 = (9.99999975e-06f * float(fHslider10));
        float fSlow11 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider11))))));
        float fSlow12 = (9.99999975e-06f * float(fHslider12));
        for (int i = 0; (i < count); i = (i + 1)) {
            float fTemp0 = float(input0[i]);
            fRec2[0] = (fSlow0 + (0.999000013f * fRec2[1]));
            fRec11[0] = (fSlow1 + (0.999000013f * fRec11[1]));
            float fTemp1 =
                std::min<float>(0.5f, std::max<float>(0.25f, (fRec11[0] + 0.150000006f)));
            fRec19[0] = (fSlow2 + (0.999000013f * fRec19[1]));
            fRec22[0] = (fSlow3 + (0.999000013f * fRec22[1]));
            float fTemp2 = (fRec21[1] + (fConst1 * fRec22[0]));
            fRec21[0] = (fTemp2 - float(int(fTemp2)));
            int iTemp3 =
                (int((fConst0 *
                      ((fRec19[0] *
                        ftbl0mydspSIG0[int((65536.0f * (fRec21[0] + (0.25f - float(int((fRec21[0] + 0.25f)))))))]) +
                       0.0305097271f))) +
                 -1);
            float fTemp4 =
                ((fRec15[1] != 0.0f) ?
                     (((fRec16[1] > 0.0f) & (fRec16[1] < 1.0f)) ? fRec15[1] : 0.0f) :
                     (((fRec16[1] == 0.0f) & (iTemp3 != iRec17[1])) ?
                          fConst2 :
                          (((fRec16[1] == 1.0f) & (iTemp3 != iRec18[1])) ? fConst3 : 0.0f)));
            fRec15[0] = fTemp4;
            fRec16[0] =
                std::max<float>(0.0f, std::min<float>(1.0f, (fRec16[1] + fTemp4)));
            iRec17[0] =
                (((fRec16[1] >= 1.0f) & (iRec18[1] != iTemp3)) ? iTemp3 : iRec17[1]);
            iRec18[0] =
                (((fRec16[1] <= 0.0f) & (iRec17[1] != iTemp3)) ? iTemp3 : iRec18[1]);
            fRec33[0] = (fSlow4 + (0.999000013f * fRec33[1]));
            fRec34[0] = std::fmod((fRec34[1] + 2047.0f), 2048.0f);
            int iTemp5 = int(fRec34[0]);
            int iTemp6 = (std::min<int>(65537, std::max<int>(0, iTemp5)) + 1);
            float fTemp7 = std::floor(fRec34[0]);
            float fTemp8 = (fTemp7 + (1.0f - fRec34[0]));
            float fTemp9 = (fRec34[0] - fTemp7);
            int iTemp10 = (std::min<int>(65537, std::max<int>(0, (iTemp5 + 1))) + 1);
            float fTemp11 = std::min<float>((0.0009765625f * fRec34[0]), 1.0f);
            float fTemp12 = (fRec34[0] + 2048.0f);
            int iTemp13 = int(fTemp12);
            int iTemp14 = (std::min<int>(65537, std::max<int>(0, iTemp13)) + 1);
            float fTemp15 = std::floor(fTemp12);
            float fTemp16 = (fTemp15 + (-2047.0f - fRec34[0]));
            float fTemp17 = (fRec34[0] + (2048.0f - fTemp15));
            int iTemp18 = (std::min<int>(65537, std::max<int>(0, (iTemp13 + 1))) + 1);
            float fTemp19 = (1.0f - fTemp11);
            fVec0[(IOTA & 131071)] =
                (fRec33[0] * ((((fRec1[((IOTA - iTemp6) & 131071)] * fTemp8) +
                                (fTemp9 * fRec1[((IOTA - iTemp10) & 131071)])) *
                               fTemp11) +
                              (((fRec1[((IOTA - iTemp14) & 131071)] * fTemp16) +
                                (fTemp17 * fRec1[((IOTA - iTemp18) & 131071)])) *
                               fTemp19)));
            fRec35[0] = (fSlow5 + (0.999000013f * fRec35[1]));
            int iTemp20 =
                std::min<int>(65536, std::max<int>(0, int((fConst0 * fRec35[0]))));
            fRec36[0] = (fSlow6 + (0.999000013f * fRec36[1]));
            fRec32[0] = (fVec0[((IOTA - iTemp20) & 131071)] + (fRec36[0] * fRec32[1]));
            float fTemp21 = (1.0f - fRec36[0]);
            fRec37[0] = (fSlow7 + (0.999000013f * fRec37[1]));
            fRec31[0] = ((fRec32[0] * fTemp21) + (fRec37[0] * fRec31[1]));
            float fTemp22 = (fRec37[0] + 1.0f);
            float fTemp23 = (0.0f - (0.5f * fTemp22));
            fRec38[0] = (fSlow8 + (0.999000013f * fRec38[1]));
            float fTemp24 = (((0.5f * (fRec31[0] * fTemp22)) + (fRec31[1] * fTemp23)) -
                             (fRec38[0] * fRec29[1]));
            fVec1[(IOTA & 1023)] = fTemp24;
            fRec29[0] = fVec1[((IOTA - iConst4) & 1023)];
            float fRec30 = (fRec38[0] * fTemp24);
            float fTemp25 = ((fRec30 + fRec29[1]) - (fRec38[0] * fRec27[1]));
            fVec2[(IOTA & 1023)] = fTemp25;
            fRec27[0] = fVec2[((IOTA - iConst5) & 1023)];
            float fRec28 = (fRec38[0] * fTemp25);
            fRec39[0] = (fSlow9 + (0.999000013f * fRec39[1]));
            float fTemp26 = ((fRec28 + fRec27[1]) - (fRec39[0] * fRec25[1]));
            fVec3[(IOTA & 4095)] = fTemp26;
            fRec25[0] = fVec3[((IOTA - iConst6) & 4095)];
            float fRec26 = (fRec39[0] * fTemp26);
            float fTemp27 = ((fRec26 + fRec25[1]) - (fRec39[0] * fRec23[1]));
            fVec4[(IOTA & 2047)] = fTemp27;
            fRec23[0] = fVec4[((IOTA - iConst7) & 2047)];
            float fRec24 = (fRec39[0] * fTemp27);
            fRec40[0] = (fSlow10 + (0.999000013f * fRec40[1]));
            float fTemp28 =
                (fRec23[1] + ((fRec11[0] * fRec6[((IOTA - iConst8) & 32767)]) +
                              (fRec24 + (fRec40[0] * fRec13[1]))));
            fVec5[(IOTA & 131071)] = fTemp28;
            fRec13[0] =
                (((1.0f - fRec16[0]) *
                  fVec5[((IOTA - std::min<int>(65536, std::max<int>(0, iRec17[0]))) & 131071)]) +
                 (fRec16[0] *
                  fVec5[((IOTA - std::min<int>(65536, std::max<int>(0, iRec18[0]))) & 131071)]));
            float fRec14 = (0.0f - (fRec40[0] * fTemp28));
            float fTemp29 = (fRec14 + fRec13[1]);
            fVec6[(IOTA & 32767)] = fTemp29;
            fRec41[0] = (fSlow11 + (0.999000013f * fRec41[1]));
            fRec12[0] = (fVec6[((IOTA - iConst9) & 32767)] + (fRec41[0] * fRec12[1]));
            float fTemp30 = (1.0f - fRec41[0]);
            float fTemp31 = ((fTemp1 * fRec9[1]) + ((fRec11[0] * fRec12[0]) * fTemp30));
            fVec7[(IOTA & 32767)] = fTemp31;
            fRec9[0] = fVec7[((IOTA - iConst10) & 32767)];
            float fRec10 = (0.0f - (fTemp1 * fTemp31));
            fRec3[(IOTA & 32767)] = (fRec10 + fRec9[1]);
            fRec4[(IOTA & 16383)] = (fRec12[0] * fTemp30);
            fRec5[(IOTA & 32767)] = fTemp29;
            int iTemp32 =
                (int((fConst0 * ((fRec19[0] * ftbl0mydspSIG0[int((65536.0f * fRec21[0]))]) +
                                 0.025603978f))) +
                 -1);
            float fTemp33 =
                ((fRec47[1] != 0.0f) ?
                     (((fRec48[1] > 0.0f) & (fRec48[1] < 1.0f)) ? fRec47[1] : 0.0f) :
                     (((fRec48[1] == 0.0f) & (iTemp32 != iRec49[1])) ?
                          fConst2 :
                          (((fRec48[1] == 1.0f) & (iTemp32 != iRec50[1])) ? fConst3 : 0.0f)));
            fRec47[0] = fTemp33;
            fRec48[0] =
                std::max<float>(0.0f, std::min<float>(1.0f, (fRec48[1] + fTemp33)));
            iRec49[0] =
                (((fRec48[1] >= 1.0f) & (iRec50[1] != iTemp32)) ? iTemp32 : iRec49[1]);
            iRec50[0] =
                (((fRec48[1] <= 0.0f) & (iRec49[1] != iTemp32)) ? iTemp32 : iRec50[1]);
            fVec8[(IOTA & 131071)] =
                (fRec33[0] *
                 ((fTemp11 * ((fTemp8 * fRec0[((IOTA - iTemp6) & 131071)]) +
                              (fTemp9 * fRec0[((IOTA - iTemp10) & 131071)]))) +
                  (fTemp19 * ((fTemp16 * fRec0[((IOTA - iTemp14) & 131071)]) +
                              (fTemp17 * fRec0[((IOTA - iTemp18) & 131071)])))));
            fRec60[0] = (fVec8[((IOTA - iTemp20) & 131071)] + (fRec36[0] * fRec60[1]));
            fRec59[0] = ((fTemp21 * fRec60[0]) + (fRec37[0] * fRec59[1]));
            float fTemp34 = (((0.5f * (fRec59[0] * fTemp22)) + (fTemp23 * fRec59[1])) -
                             (fRec38[0] * fRec57[1]));
            fVec9[(IOTA & 1023)] = fTemp34;
            fRec57[0] = fVec9[((IOTA - iConst11) & 1023)];
            float fRec58 = (fRec38[0] * fTemp34);
            float fTemp35 = ((fRec58 + fRec57[1]) - (fRec38[0] * fRec55[1]));
            fVec10[(IOTA & 1023)] = fTemp35;
            fRec55[0] = fVec10[((IOTA - iConst12) & 1023)];
            float fRec56 = (fRec38[0] * fTemp35);
            float fTemp36 = ((fRec56 + fRec55[1]) - (fRec39[0] * fRec53[1]));
            fVec11[(IOTA & 4095)] = fTemp36;
            fRec53[0] = fVec11[((IOTA - iConst13) & 4095)];
            float fRec54 = (fRec39[0] * fTemp36);
            float fTemp37 = ((fRec54 + fRec53[1]) - (fRec39[0] * fRec51[1]));
            fVec12[(IOTA & 2047)] = fTemp37;
            fRec51[0] = fVec12[((IOTA - iConst14) & 2047)];
            float fRec52 = (fRec39[0] * fTemp37);
            float fTemp38 =
                (fRec51[1] + ((fRec11[0] * fRec3[((IOTA - iConst15) & 32767)]) +
                              (fRec52 + (fRec40[0] * fRec45[1]))));
            fVec13[(IOTA & 131071)] = fTemp38;
            fRec45[0] =
                (((1.0f - fRec48[0]) *
                  fVec13[((IOTA - std::min<int>(65536, std::max<int>(0, iRec49[0]))) & 131071)]) +
                 (fRec48[0] *
                  fVec13[((IOTA - std::min<int>(65536, std::max<int>(0, iRec50[0]))) & 131071)]));
            float fRec46 = (0.0f - (fRec40[0] * fTemp38));
            float fTemp39 = (fRec46 + fRec45[1]);
            fVec14[(IOTA & 32767)] = fTemp39;
            fRec44[0] = (fVec14[((IOTA - iConst16) & 32767)] + (fRec41[0] * fRec44[1]));
            float fTemp40 =
                ((fTemp1 * fRec42[1]) + ((fRec11[0] * fTemp30) * fRec44[0]));
            fVec15[(IOTA & 16383)] = fTemp40;
            fRec42[0] = fVec15[((IOTA - iConst17) & 16383)];
            float fRec43 = (0.0f - (fTemp1 * fTemp40));
            fRec6[(IOTA & 32767)] = (fRec43 + fRec42[1]);
            fRec7[(IOTA & 8191)] = (fTemp30 * fRec44[0]);
            fRec8[(IOTA & 32767)] = fTemp39;
            fRec0[(IOTA & 131071)] =
                ((fTemp0 * fRec2[0]) +
                 (0.600000024f *
                  (((fRec5[((IOTA - iConst18) & 32767)] + fRec5[((IOTA - iConst19) & 32767)]) +
                    fRec3[((IOTA - iConst20) & 32767)]) -
                   (((fRec4[((IOTA - iConst21) & 16383)] + fRec8[((IOTA - iConst22) & 32767)]) +
                     fRec7[((IOTA - iConst23) & 8191)]) +
                    fRec6[((IOTA - iConst24) & 32767)]))));
            float fTemp41 = float(input1[i]);
            fRec1[(IOTA & 131071)] =
                ((fTemp41 * fRec2[0]) +
                 (0.600000024f *
                  (((fRec8[((IOTA - iConst25) & 32767)] + fRec8[((IOTA - iConst26) & 32767)]) +
                    fRec6[((IOTA - iConst27) & 32767)]) -
                   (((fRec7[((IOTA - iConst28) & 8191)] + fRec5[((IOTA - iConst29) & 32767)]) +
                     fRec4[((IOTA - iConst30) & 16383)]) +
                    fRec3[((IOTA - iConst31) & 32767)]))));
            fRec61[0] = (fSlow12 + (0.999000013f * fRec61[1]));
            output0[i] =
                FAUSTFLOAT((fRec0[((IOTA - 0) & 131071)] + (fTemp0 * fRec61[0])));
            output1[i] =
                FAUSTFLOAT((fRec1[((IOTA - 0) & 131071)] + (fTemp41 * fRec61[0])));
            fRec2[1] = fRec2[0];
            fRec11[1] = fRec11[0];
            fRec19[1] = fRec19[0];
            fRec22[1] = fRec22[0];
            fRec21[1] = fRec21[0];
            fRec15[1] = fRec15[0];
            fRec16[1] = fRec16[0];
            iRec17[1] = iRec17[0];
            iRec18[1] = iRec18[0];
            fRec33[1] = fRec33[0];
            fRec34[1] = fRec34[0];
            IOTA = (IOTA + 1);
            fRec35[1] = fRec35[0];
            fRec36[1] = fRec36[0];
            fRec32[1] = fRec32[0];
            fRec37[1] = fRec37[0];
            fRec31[1] = fRec31[0];
            fRec38[1] = fRec38[0];
            fRec29[1] = fRec29[0];
            fRec27[1] = fRec27[0];
            fRec39[1] = fRec39[0];
            fRec25[1] = fRec25[0];
            fRec23[1] = fRec23[0];
            fRec40[1] = fRec40[0];
            fRec13[1] = fRec13[0];
            fRec41[1] = fRec41[0];
            fRec12[1] = fRec12[0];
            fRec9[1] = fRec9[0];
            fRec47[1] = fRec47[0];
            fRec48[1] = fRec48[0];
            iRec49[1] = iRec49[0];
            iRec50[1] = iRec50[0];
            fRec60[1] = fRec60[0];
            fRec59[1] = fRec59[0];
            fRec57[1] = fRec57[0];
            fRec55[1] = fRec55[0];
            fRec53[1] = fRec53[0];
            fRec51[1] = fRec51[0];
            fRec45[1] = fRec45[0];
            fRec44[1] = fRec44[0];
            fRec42[1] = fRec42[0];
            fRec61[1] = fRec61[0];
        }
    }
};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


//------------------------------------------------------------------------------
// End the Faust code section


Fshim::Fshim()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();
}

Fshim::~Fshim()
{
}

void Fshim::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();
}

void Fshim::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();
}

void Fshim::process(const float *in0, const float *in1, float *out0,
                    float *out1, unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),
        const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,
        out1,
    };
    dsp.compute(count, inputs, outputs);
}

const char *Fshim::parameter_label(unsigned index) noexcept
{
    switch (index) {

    case 0:
        return "Predelay";

    case 1:
        return "Input amount";

    case 2:
        return "Input low-pass cutoff";

    case 3:
        return "Input high-pass cutoff";

    case 4:
        return "Input diffusion 1";

    case 5:
        return "Input diffusion 2";

    case 6:
        return "Tail density";

    case 7:
        return "Decay";

    case 8:
        return "Damping";

    case 9:
        return "Modulator frequency";

    case 10:
        return "Modulator depth";

    case 11:
        return "Dry";

    case 12:
        return "Wet";

    default:
        return 0;
    }
}

const char *Fshim::parameter_short_label(unsigned index) noexcept
{
    switch (index) {

    case 0:
        return "";

    case 1:
        return "";

    case 2:
        return "";

    case 3:
        return "";

    case 4:
        return "";

    case 5:
        return "";

    case 6:
        return "";

    case 7:
        return "";

    case 8:
        return "";

    case 9:
        return "";

    case 10:
        return "";

    case 11:
        return "";

    case 12:
        return "";

    default:
        return 0;
    }
}

const char *Fshim::parameter_symbol(unsigned index) noexcept
{
    switch (index) {

    case 0:
        return "predelay";

    case 1:
        return "input";

    case 2:
        return "input_lowpass";

    case 3:
        return "input_highpass";

    case 4:
        return "input_diffusion_1";

    case 5:
        return "input_diffusion_2";

    case 6:
        return "tail_density";

    case 7:
        return "decay";

    case 8:
        return "damping";

    case 9:
        return "mod_frequency";

    case 10:
        return "mod_depth";

    case 11:
        return "dry";

    case 12:
        return "wet";

    default:
        return 0;
    }
}

const char *Fshim::parameter_unit(unsigned index) noexcept
{
    switch (index) {

    case 0:
        return "ms";

    case 1:
        return "%";

    case 2:
        return "Hz";

    case 3:
        return "Hz";

    case 4:
        return "%";

    case 5:
        return "%";

    case 6:
        return "%";

    case 7:
        return "%";

    case 8:
        return "Hz";

    case 9:
        return "Hz";

    case 10:
        return "ms";

    case 11:
        return "%";

    case 12:
        return "%";

    default:
        return 0;
    }
}

const Fshim::ParameterRange *Fshim::parameter_range(unsigned index) noexcept
{
    switch (index) {

    case 0: {
        static const ParameterRange range = {0, 0, 300};
        return &range;
    }

    case 1: {
        static const ParameterRange range = {100, 0, 100};
        return &range;
    }

    case 2: {
        static const ParameterRange range = {10000, 1, 20000};
        return &range;
    }

    case 3: {
        static const ParameterRange range = {100, 1, 1000};
        return &range;
    }

    case 4: {
        static const ParameterRange range = {75, 0, 100};
        return &range;
    }

    case 5: {
        static const ParameterRange range = {62.5, 0, 100};
        return &range;
    }

    case 6: {
        static const ParameterRange range = {70, 0, 100};
        return &range;
    }

    case 7: {
        static const ParameterRange range = {50, 0, 100};
        return &range;
    }

    case 8: {
        static const ParameterRange range = {5500, 10, 20000};
        return &range;
    }

    case 9: {
        static const ParameterRange range = {1, 0.0099999998, 4};
        return &range;
    }

    case 10: {
        static const ParameterRange range = {0.5, 0, 10};
        return &range;
    }

    case 11: {
        static const ParameterRange range = {100, 0, 100};
        return &range;
    }

    case 12: {
        static const ParameterRange range = {50, 0, 100};
        return &range;
    }

    default:
        return 0;
    }
}

bool Fshim::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fshim::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fshim::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fshim::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {

    case 2:
        return true;

    case 3:
        return true;

    case 8:
        return true;

    default:
        return false;
    }
}

float Fshim::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {

    case 0:
        return dsp.fHslider5;

    case 1:
        return dsp.fHslider4;

    case 2:
        return dsp.fHslider6;

    case 3:
        return dsp.fHslider7;

    case 4:
        return dsp.fHslider8;

    case 5:
        return dsp.fHslider9;

    case 6:
        return dsp.fHslider10;

    case 7:
        return dsp.fHslider1;

    case 8:
        return dsp.fHslider11;

    case 9:
        return dsp.fHslider3;

    case 10:
        return dsp.fHslider2;

    case 11:
        return dsp.fHslider12;

    case 12:
        return dsp.fHslider0;

    default:
        (void)dsp;
        return 0;
    }
}

void Fshim::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {

    case 0:
        dsp.fHslider5 = value;
        break;

    case 1:
        dsp.fHslider4 = value;
        break;

    case 2:
        dsp.fHslider6 = value;
        break;

    case 3:
        dsp.fHslider7 = value;
        break;

    case 4:
        dsp.fHslider8 = value;
        break;

    case 5:
        dsp.fHslider9 = value;
        break;

    case 6:
        dsp.fHslider10 = value;
        break;

    case 7:
        dsp.fHslider1 = value;
        break;

    case 8:
        dsp.fHslider11 = value;
        break;

    case 9:
        dsp.fHslider3 = value;
        break;

    case 10:
        dsp.fHslider2 = value;
        break;

    case 11:
        dsp.fHslider12 = value;
        break;

    case 12:
        dsp.fHslider0 = value;
        break;

    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float Fshim::get_predelay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float Fshim::get_input() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float Fshim::get_input_lowpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float Fshim::get_input_highpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float Fshim::get_input_diffusion_1() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float Fshim::get_input_diffusion_2() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float Fshim::get_tail_density() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float Fshim::get_decay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float Fshim::get_damping() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float Fshim::get_mod_frequency() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float Fshim::get_mod_depth() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float Fshim::get_dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}

float Fshim::get_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void Fshim::set_predelay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void Fshim::set_input(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void Fshim::set_input_lowpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void Fshim::set_input_highpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void Fshim::set_input_diffusion_1(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void Fshim::set_input_diffusion_2(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void Fshim::set_tail_density(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void Fshim::set_decay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void Fshim::set_damping(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void Fshim::set_mod_frequency(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void Fshim::set_mod_depth(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void Fshim::set_dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}

void Fshim::set_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}
