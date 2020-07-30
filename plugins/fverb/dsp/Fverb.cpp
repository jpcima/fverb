
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


#include "Fverb.hpp"


#include <utility>
#include <cmath>

class Fverb::BasicDsp {
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

typedef Fverb::BasicDsp dsp;

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

        int iRec28[2];

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
        for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
            iRec28[l15] = 0;
        }
    }

    void fillmydspSIG0(int count, float *table)
    {
        for (int i = 0; (i < count); i = (i + 1)) {
            iRec28[0] = (iRec28[1] + 1);
            table[i] = std::sin((9.58738019e-05f * float((iRec28[0] + -1))));
            iRec28[1] = iRec28[0];
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
    float fRec0[2];
    FAUSTFLOAT fHslider1;
    float fRec1[2];
    FAUSTFLOAT fHslider2;
    float fRec2[2];
    FAUSTFLOAT fHslider3;
    float fRec5[2];
    int fSampleRate;
    float fConst0;
    float fConst1;
    FAUSTFLOAT fHslider4;
    float fRec6[2];
    float fRec4[2];
    FAUSTFLOAT fHslider5;
    float fRec7[2];
    float fRec3[2];
    int IOTA;
    float fVec0[131072];
    int iConst2;
    int iConst3;
    int iConst4;
    int iConst5;
    int iConst6;
    int iConst7;
    int iConst8;
    int iConst9;
    int iConst10;
    int iConst11;
    int iConst12;
    int iConst13;
    int iConst14;
    int iConst15;
    int iConst16;
    int iConst17;
    int iConst18;
    float fRec9[2];
    float fRec8[2];
    float fVec1[131072];
    int iConst19;
    int iConst20;
    int iConst21;
    int iConst22;
    int iConst23;
    int iConst24;
    int iConst25;
    int iConst26;
    int iConst27;
    int iConst28;
    int iConst29;
    int iConst30;
    int iConst31;
    int iConst32;
    int iConst33;
    FAUSTFLOAT fHslider6;
    float fRec10[2];
    FAUSTFLOAT fHslider7;
    float fRec19[2];
    FAUSTFLOAT fHslider8;
    float fRec27[2];
    FAUSTFLOAT fHslider9;
    float fRec30[2];
    float fRec29[2];
    float fConst34;
    float fConst35;
    float fRec23[2];
    float fRec24[2];
    int iRec25[2];
    int iRec26[2];
    FAUSTFLOAT fHslider10;
    float fRec39[2];
    FAUSTFLOAT fHslider11;
    float fRec40[2];
    float fVec2[1024];
    int iConst36;
    float fRec37[2];
    float fVec3[1024];
    int iConst37;
    float fRec35[2];
    FAUSTFLOAT fHslider12;
    float fRec41[2];
    float fVec4[4096];
    int iConst38;
    float fRec33[2];
    float fVec5[2048];
    int iConst39;
    float fRec31[2];
    int iConst40;
    FAUSTFLOAT fHslider13;
    float fRec42[2];
    float fVec6[131072];
    float fRec21[2];
    float fVec7[32768];
    int iConst41;
    FAUSTFLOAT fHslider14;
    float fRec43[2];
    float fRec20[2];
    float fVec8[32768];
    int iConst42;
    float fRec17[2];
    float fRec11[32768];
    float fRec12[16384];
    float fRec13[32768];
    float fRec49[2];
    float fRec50[2];
    int iRec51[2];
    int iRec52[2];
    float fVec9[1024];
    int iConst43;
    float fRec59[2];
    float fVec10[1024];
    int iConst44;
    float fRec57[2];
    float fVec11[4096];
    int iConst45;
    float fRec55[2];
    float fVec12[2048];
    int iConst46;
    float fRec53[2];
    int iConst47;
    float fVec13[131072];
    float fRec47[2];
    float fVec14[32768];
    int iConst48;
    float fRec46[2];
    float fVec15[16384];
    int iConst49;
    float fRec44[2];
    float fRec14[32768];
    float fRec15[8192];
    float fRec16[32768];
    int iConst50;
    int iConst51;
    int iConst52;
    int iConst53;
    int iConst54;
    int iConst55;
    int iConst56;
    int iConst57;
    int iConst58;
    int iConst59;
    int iConst60;
    int iConst61;
    int iConst62;
    int iConst63;

public:
    void metadata(Meta *m)
    {
        m->declare("author", "Jean Pierre Cimalando");
        m->declare("basics.lib/name", "Faust Basic Element Library");
        m->declare("basics.lib/version", "0.1");
        m->declare("delays.lib/name", "Faust Delay Library");
        m->declare("delays.lib/version", "0.1");
        m->declare("filename", "fverb.dsp");
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
                   "MIT-style STK-4.3 license");
        m->declare("filters.lib/name", "Faust Filters Library");
        m->declare("license", "BSD-2-Clause");
        m->declare("maths.lib/author", "GRAME");
        m->declare("maths.lib/copyright", "GRAME");
        m->declare("maths.lib/license", "LGPL with exception");
        m->declare("maths.lib/name", "Faust Math Library");
        m->declare("maths.lib/version", "2.3");
        m->declare("name", "fverb");
        m->declare("oscillators.lib/name", "Faust Oscillator Library");
        m->declare("oscillators.lib/version", "0.1");
        m->declare("platform.lib/name", "Generic Platform Library");
        m->declare("platform.lib/version", "0.1");
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
        iConst2 = std::min<int>(65536, std::max<int>(0, int((0.00184512476f * fConst0))));
        iConst3 = std::min<int>(65536, std::max<int>(0, int((0.00164965983f * fConst0))));
        iConst4 = std::min<int>(65536, std::max<int>(0, int((8.79818617e-05f * fConst0))));
        iConst5 = std::min<int>(65536, std::max<int>(0, int((0.00978616811f * fConst0))));
        iConst6 = std::min<int>(65536, std::max<int>(0, int((0.000817460299f * fConst0))));
        iConst7 = std::min<int>(65536, std::max<int>(0, int((0.00443764171f * fConst0))));
        iConst8 = std::min<int>(65536, std::max<int>(0, int((0.0166945569f * fConst0))));
        iConst9 = std::min<int>(65536, std::max<int>(0, int((0.0010276644f * fConst0))));
        iConst10 =
            std::min<int>(65536, std::max<int>(0, int((0.00417913822f * fConst0))));
        iConst11 =
            std::min<int>(65536, std::max<int>(0, int((0.000210204074f * fConst0))));
        iConst12 =
            std::min<int>(65536, std::max<int>(0, int((0.00270544225f * fConst0))));
        iConst13 =
            std::min<int>(65536, std::max<int>(0, int((0.0164893419f * fConst0))));
        iConst14 =
            std::min<int>(65536, std::max<int>(0, int((0.00261746021f * fConst0))));
        iConst15 =
            std::min<int>(65536, std::max<int>(0, int((0.00896870717f * fConst0))));
        iConst16 =
            std::min<int>(65536, std::max<int>(0, int((0.00145170069f * fConst0))));
        iConst17 =
            std::min<int>(65536, std::max<int>(0, int((0.00123786845f * fConst0))));
        iConst18 =
            std::min<int>(65536, std::max<int>(0, int((0.00426712027f * fConst0))));
        iConst19 =
            std::min<int>(65536, std::max<int>(0, int((0.00173764175f * fConst0))));
        iConst20 =
            std::min<int>(65536, std::max<int>(0, int((0.00175170065f * fConst0))));
        iConst21 =
            std::min<int>(65536, std::max<int>(0, int((9.34240379e-05f * fConst0))));
        iConst22 =
            std::min<int>(65536, std::max<int>(0, int((0.00921609998f * fConst0))));
        iConst23 =
            std::min<int>(65536, std::max<int>(0, int((0.000769841252f * fConst0))));
        iConst24 =
            std::min<int>(65536, std::max<int>(0, int((0.0177272111f * fConst0))));
        iConst25 =
            std::min<int>(65536, std::max<int>(0, int((0.000967800443f * fConst0))));
        iConst26 =
            std::min<int>(65536, std::max<int>(0, int((0.000197959191f * fConst0))));
        iConst27 =
            std::min<int>(65536, std::max<int>(0, int((0.00287278905f * fConst0))));
        iConst28 =
            std::min<int>(65536, std::max<int>(0, int((0.0155287981f * fConst0))));
        iConst29 =
            std::min<int>(65536, std::max<int>(0, int((0.00277936505f * fConst0))));
        iConst30 =
            std::min<int>(65536, std::max<int>(0, int((0.00844625849f * fConst0))));
        iConst31 =
            std::min<int>(65536, std::max<int>(0, int((0.0015414966f * fConst0))));
        iConst32 =
            std::min<int>(65536, std::max<int>(0, int((0.00116575963f * fConst0))));
        iConst33 =
            std::min<int>(65536, std::max<int>(0, int((0.00453106593f * fConst0))));
        fConst34 = (1.0f / float(int((0.00999999978f * fConst0))));
        fConst35 = (0.0f - fConst34);
        iConst36 =
            std::min<int>(65536, std::max<int>(0, (int((0.00462820474f * fConst0)) + -1)));
        iConst37 =
            std::min<int>(65536, std::max<int>(0, (int((0.00370316859f * fConst0)) + -1)));
        iConst38 =
            std::min<int>(65536, std::max<int>(0, (int((0.013116831f * fConst0)) + -1)));
        iConst39 =
            std::min<int>(65536, std::max<int>(0, (int((0.00902825873f * fConst0)) + -1)));
        iConst40 =
            (std::min<int>(65536, std::max<int>(0, int((0.106280029f * fConst0)))) + 1);
        iConst41 = std::min<int>(65536, std::max<int>(0, int((0.141695514f * fConst0))));
        iConst42 =
            std::min<int>(65536, std::max<int>(0, (int((0.0892443135f * fConst0)) + -1)));
        iConst43 =
            std::min<int>(65536, std::max<int>(0, (int((0.00491448538f * fConst0)) + -1)));
        iConst44 =
            std::min<int>(65536, std::max<int>(0, (int((0.00348745007f * fConst0)) + -1)));
        iConst45 =
            std::min<int>(65536, std::max<int>(0, (int((0.0123527432f * fConst0)) + -1)));
        iConst46 =
            std::min<int>(65536, std::max<int>(0, (int((0.00958670769f * fConst0)) + -1)));
        iConst47 =
            (std::min<int>(65536, std::max<int>(0, int((0.124995798f * fConst0)))) + 1);
        iConst48 = std::min<int>(65536, std::max<int>(0, int((0.149625346f * fConst0))));
        iConst49 =
            std::min<int>(65536, std::max<int>(0, (int((0.0604818389f * fConst0)) + -1)));
        iConst50 =
            std::min<int>(65536, std::max<int>(0, int((0.00893787201f * fConst0))));
        iConst51 = std::min<int>(65536, std::max<int>(0, int((0.099929437f * fConst0))));
        iConst52 = std::min<int>(65536, std::max<int>(0, int((0.067067638f * fConst0))));
        iConst53 =
            std::min<int>(65536, std::max<int>(0, int((0.0642787516f * fConst0))));
        iConst54 =
            std::min<int>(65536, std::max<int>(0, int((0.0668660328f * fConst0))));
        iConst55 =
            std::min<int>(65536, std::max<int>(0, int((0.0062833908f * fConst0))));
        iConst56 =
            std::min<int>(65536, std::max<int>(0, int((0.0358186886f * fConst0))));
        iConst57 =
            std::min<int>(65536, std::max<int>(0, int((0.0118611604f * fConst0))));
        iConst58 = std::min<int>(65536, std::max<int>(0, int((0.121870905f * fConst0))));
        iConst59 =
            std::min<int>(65536, std::max<int>(0, int((0.0898155272f * fConst0))));
        iConst60 = std::min<int>(65536, std::max<int>(0, int((0.041262053f * fConst0))));
        iConst61 = std::min<int>(65536, std::max<int>(0, int((0.070931755f * fConst0))));
        iConst62 =
            std::min<int>(65536, std::max<int>(0, int((0.0112563418f * fConst0))));
        iConst63 =
            std::min<int>(65536, std::max<int>(0, int((0.00406572362f * fConst0))));
    }

    FAUSTPP_VIRTUAL void instanceResetUserInterface()
    {
        fHslider0 = FAUSTFLOAT(100.0f);
        fHslider1 = FAUSTFLOAT(50.0f);
        fHslider2 = FAUSTFLOAT(50.0f);
        fHslider3 = FAUSTFLOAT(100.0f);
        fHslider4 = FAUSTFLOAT(10000.0f);
        fHslider5 = FAUSTFLOAT(100.0f);
        fHslider6 = FAUSTFLOAT(100.0f);
        fHslider7 = FAUSTFLOAT(50.0f);
        fHslider8 = FAUSTFLOAT(0.5f);
        fHslider9 = FAUSTFLOAT(1.0f);
        fHslider10 = FAUSTFLOAT(0.0f);
        fHslider11 = FAUSTFLOAT(75.0f);
        fHslider12 = FAUSTFLOAT(62.5f);
        fHslider13 = FAUSTFLOAT(70.0f);
        fHslider14 = FAUSTFLOAT(5500.0f);
    }

    FAUSTPP_VIRTUAL void instanceClear()
    {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fRec0[l0] = 0.0f;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0f;
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec2[l2] = 0.0f;
        }
        for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
            fRec5[l3] = 0.0f;
        }
        for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
            fRec6[l4] = 0.0f;
        }
        for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
            fRec4[l5] = 0.0f;
        }
        for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
            fRec7[l6] = 0.0f;
        }
        for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
            fRec3[l7] = 0.0f;
        }
        IOTA = 0;
        for (int l8 = 0; (l8 < 131072); l8 = (l8 + 1)) {
            fVec0[l8] = 0.0f;
        }
        for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
            fRec9[l9] = 0.0f;
        }
        for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
            fRec8[l10] = 0.0f;
        }
        for (int l11 = 0; (l11 < 131072); l11 = (l11 + 1)) {
            fVec1[l11] = 0.0f;
        }
        for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
            fRec10[l12] = 0.0f;
        }
        for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
            fRec19[l13] = 0.0f;
        }
        for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
            fRec27[l14] = 0.0f;
        }
        for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
            fRec30[l16] = 0.0f;
        }
        for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
            fRec29[l17] = 0.0f;
        }
        for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
            fRec23[l18] = 0.0f;
        }
        for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
            fRec24[l19] = 0.0f;
        }
        for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
            iRec25[l20] = 0;
        }
        for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
            iRec26[l21] = 0;
        }
        for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
            fRec39[l22] = 0.0f;
        }
        for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
            fRec40[l23] = 0.0f;
        }
        for (int l24 = 0; (l24 < 1024); l24 = (l24 + 1)) {
            fVec2[l24] = 0.0f;
        }
        for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
            fRec37[l25] = 0.0f;
        }
        for (int l26 = 0; (l26 < 1024); l26 = (l26 + 1)) {
            fVec3[l26] = 0.0f;
        }
        for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
            fRec35[l27] = 0.0f;
        }
        for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
            fRec41[l28] = 0.0f;
        }
        for (int l29 = 0; (l29 < 4096); l29 = (l29 + 1)) {
            fVec4[l29] = 0.0f;
        }
        for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
            fRec33[l30] = 0.0f;
        }
        for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
            fVec5[l31] = 0.0f;
        }
        for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
            fRec31[l32] = 0.0f;
        }
        for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
            fRec42[l33] = 0.0f;
        }
        for (int l34 = 0; (l34 < 131072); l34 = (l34 + 1)) {
            fVec6[l34] = 0.0f;
        }
        for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
            fRec21[l35] = 0.0f;
        }
        for (int l36 = 0; (l36 < 32768); l36 = (l36 + 1)) {
            fVec7[l36] = 0.0f;
        }
        for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
            fRec43[l37] = 0.0f;
        }
        for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
            fRec20[l38] = 0.0f;
        }
        for (int l39 = 0; (l39 < 32768); l39 = (l39 + 1)) {
            fVec8[l39] = 0.0f;
        }
        for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
            fRec17[l40] = 0.0f;
        }
        for (int l41 = 0; (l41 < 32768); l41 = (l41 + 1)) {
            fRec11[l41] = 0.0f;
        }
        for (int l42 = 0; (l42 < 16384); l42 = (l42 + 1)) {
            fRec12[l42] = 0.0f;
        }
        for (int l43 = 0; (l43 < 32768); l43 = (l43 + 1)) {
            fRec13[l43] = 0.0f;
        }
        for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
            fRec49[l44] = 0.0f;
        }
        for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
            fRec50[l45] = 0.0f;
        }
        for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
            iRec51[l46] = 0;
        }
        for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
            iRec52[l47] = 0;
        }
        for (int l48 = 0; (l48 < 1024); l48 = (l48 + 1)) {
            fVec9[l48] = 0.0f;
        }
        for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
            fRec59[l49] = 0.0f;
        }
        for (int l50 = 0; (l50 < 1024); l50 = (l50 + 1)) {
            fVec10[l50] = 0.0f;
        }
        for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
            fRec57[l51] = 0.0f;
        }
        for (int l52 = 0; (l52 < 4096); l52 = (l52 + 1)) {
            fVec11[l52] = 0.0f;
        }
        for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
            fRec55[l53] = 0.0f;
        }
        for (int l54 = 0; (l54 < 2048); l54 = (l54 + 1)) {
            fVec12[l54] = 0.0f;
        }
        for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
            fRec53[l55] = 0.0f;
        }
        for (int l56 = 0; (l56 < 131072); l56 = (l56 + 1)) {
            fVec13[l56] = 0.0f;
        }
        for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
            fRec47[l57] = 0.0f;
        }
        for (int l58 = 0; (l58 < 32768); l58 = (l58 + 1)) {
            fVec14[l58] = 0.0f;
        }
        for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
            fRec46[l59] = 0.0f;
        }
        for (int l60 = 0; (l60 < 16384); l60 = (l60 + 1)) {
            fVec15[l60] = 0.0f;
        }
        for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
            fRec44[l61] = 0.0f;
        }
        for (int l62 = 0; (l62 < 32768); l62 = (l62 + 1)) {
            fRec14[l62] = 0.0f;
        }
        for (int l63 = 0; (l63 < 8192); l63 = (l63 + 1)) {
            fRec15[l63] = 0.0f;
        }
        for (int l64 = 0; (l64 < 32768); l64 = (l64 + 1)) {
            fRec16[l64] = 0.0f;
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
        ui_interface->openVerticalBox("fverb");
        ui_interface->declare(&fHslider10, "01", "");
        ui_interface->declare(&fHslider10, "symbol", "predelay");
        ui_interface->declare(&fHslider10, "unit", "ms");
        ui_interface->addHorizontalSlider("Predelay", &fHslider10, 0.0f, 0.0f, 300.0f, 1.0f);
        ui_interface->declare(&fHslider3, "02", "");
        ui_interface->declare(&fHslider3, "symbol", "input");
        ui_interface->declare(&fHslider3, "unit", "%");
        ui_interface->addHorizontalSlider("Input amount", &fHslider3, 100.0f,
                                          0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider4, "03", "");
        ui_interface->declare(&fHslider4, "scale", "log");
        ui_interface->declare(&fHslider4, "symbol", "input_lowpass");
        ui_interface->declare(&fHslider4, "unit", "Hz");
        ui_interface->addHorizontalSlider("Input low-pass cutoff", &fHslider4,
                                          10000.0f, 1.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fHslider5, "04", "");
        ui_interface->declare(&fHslider5, "scale", "log");
        ui_interface->declare(&fHslider5, "symbol", "input_highpass");
        ui_interface->declare(&fHslider5, "unit", "Hz");
        ui_interface->addHorizontalSlider("Input high-pass cutoff", &fHslider5,
                                          100.0f, 1.0f, 1000.0f, 1.0f);
        ui_interface->declare(&fHslider11, "05", "");
        ui_interface->declare(&fHslider11, "symbol", "input_diffusion_1");
        ui_interface->declare(&fHslider11, "unit", "%");
        ui_interface->addHorizontalSlider("Input diffusion 1", &fHslider11,
                                          75.0f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider12, "06", "");
        ui_interface->declare(&fHslider12, "symbol", "input_diffusion_2");
        ui_interface->declare(&fHslider12, "unit", "%");
        ui_interface->addHorizontalSlider("Input diffusion 2", &fHslider12,
                                          62.5f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider13, "07", "");
        ui_interface->declare(&fHslider13, "symbol", "tail_density");
        ui_interface->declare(&fHslider13, "unit", "%");
        ui_interface->addHorizontalSlider("Tail density", &fHslider13, 70.0f,
                                          0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider7, "08", "");
        ui_interface->declare(&fHslider7, "symbol", "decay");
        ui_interface->declare(&fHslider7, "unit", "%");
        ui_interface->addHorizontalSlider("Decay", &fHslider7, 50.0f, 0.0f,
                                          100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider14, "09", "");
        ui_interface->declare(&fHslider14, "scale", "log");
        ui_interface->declare(&fHslider14, "symbol", "damping");
        ui_interface->declare(&fHslider14, "unit", "Hz");
        ui_interface->addHorizontalSlider("Damping", &fHslider14, 5500.0f,
                                          10.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fHslider9, "10", "");
        ui_interface->declare(&fHslider9, "symbol", "mod_frequency");
        ui_interface->declare(&fHslider9, "unit", "Hz");
        ui_interface->addHorizontalSlider("Modulator frequency", &fHslider9, 1.0f,
                                          0.00999999978f, 4.0f, 0.00999999978f);
        ui_interface->declare(&fHslider8, "11", "");
        ui_interface->declare(&fHslider8, "symbol", "mod_depth");
        ui_interface->declare(&fHslider8, "unit", "ms");
        ui_interface->addHorizontalSlider("Modulator depth", &fHslider8, 0.5f,
                                          0.0f, 10.0f, 0.100000001f);
        ui_interface->declare(&fHslider0, "12", "");
        ui_interface->declare(&fHslider0, "symbol", "dry");
        ui_interface->declare(&fHslider0, "unit", "%");
        ui_interface->addHorizontalSlider("Dry", &fHslider0, 100.0f, 0.0f,
                                          100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider1, "13", "");
        ui_interface->declare(&fHslider1, "symbol", "wet");
        ui_interface->declare(&fHslider1, "unit", "%");
        ui_interface->addHorizontalSlider("Wet", &fHslider1, 50.0f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider2, "14", "");
        ui_interface->declare(&fHslider2, "symbol", "early_reflections");
        ui_interface->declare(&fHslider2, "unit", "%");
        ui_interface->addHorizontalSlider("Early reflections", &fHslider2,
                                          50.0f, 0.0f, 100.0f, 0.00999999978f);
        ui_interface->declare(&fHslider6, "15", "");
        ui_interface->declare(&fHslider6, "symbol", "late_reflections");
        ui_interface->declare(&fHslider6, "unit", "%");
        ui_interface->addHorizontalSlider("Late reflections", &fHslider6,
                                          100.0f, 0.0f, 100.0f, 0.00999999978f);
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
        float fSlow2 = (9.99999975e-06f * float(fHslider2));
        float fSlow3 = (9.99999975e-06f * float(fHslider3));
        float fSlow4 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider4))))));
        float fSlow5 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider5))))));
        float fSlow6 = (9.99999975e-06f * float(fHslider6));
        float fSlow7 = (9.99999975e-06f * float(fHslider7));
        float fSlow8 = (9.99999997e-07f * float(fHslider8));
        float fSlow9 = (0.00100000005f * float(fHslider9));
        float fSlow10 = (9.99999997e-07f * float(fHslider10));
        float fSlow11 = (9.99999975e-06f * float(fHslider11));
        float fSlow12 = (9.99999975e-06f * float(fHslider12));
        float fSlow13 = (9.99999975e-06f * float(fHslider13));
        float fSlow14 =
            (0.00100000005f *
             std::exp((fConst1 * (0.0f - (6.28318548f * float(fHslider14))))));
        for (int i = 0; (i < count); i = (i + 1)) {
            float fTemp0 = float(input0[i]);
            fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
            fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
            fRec2[0] = (fSlow2 + (0.999000013f * fRec2[1]));
            fRec5[0] = (fSlow3 + (0.999000013f * fRec5[1]));
            fRec6[0] = (fSlow4 + (0.999000013f * fRec6[1]));
            fRec4[0] = ((fTemp0 * fRec5[0]) + (fRec6[0] * fRec4[1]));
            float fTemp1 = (1.0f - fRec6[0]);
            fRec7[0] = (fSlow5 + (0.999000013f * fRec7[1]));
            fRec3[0] = ((fRec4[0] * fTemp1) + (fRec7[0] * fRec3[1]));
            float fTemp2 = (fRec7[0] + 1.0f);
            float fTemp3 = (0.0f - (0.5f * fTemp2));
            float fTemp4 = ((0.5f * (fRec3[0] * fTemp2)) + (fRec3[1] * fTemp3));
            fVec0[(IOTA & 131071)] = fTemp4;
            float fTemp5 =
                ((((0.181280002f * fVec0[((IOTA - iConst2) & 131071)]) +
                   ((0.175569996f * (fVec0[((IOTA - iConst3) & 131071)] +
                                     fVec0[((IOTA - iConst4) & 131071)])) +
                    ((0.185399994f * fVec0[((IOTA - iConst5) & 131071)]) +
                     ((0.223509997f * fVec0[((IOTA - iConst6) & 131071)]) +
                      ((((((((((0.866230011f * fVec0[((IOTA - iConst7) & 131071)]) +
                               (0.488880008f * fVec0[((IOTA - iConst8) & 131071)])) +
                              (0.504700005f * fVec0[((IOTA - iConst9) & 131071)])) +
                             (0.367630005f * fVec0[((IOTA - iConst10) & 131071)])) +
                            (0.391400009f * fVec0[((IOTA - iConst11) & 131071)])) +
                           (0.335619986f * fVec0[((IOTA - iConst12) & 131071)])) +
                          (0.297670007f * fVec0[((IOTA - iConst13) & 131071)])) +
                         (0.26383999f * fVec0[((IOTA - iConst14) & 131071)])) +
                        (0.197760001f * fVec0[((IOTA - iConst15) & 131071)])) +
                       (0.32495001f * fVec0[((IOTA - iConst16) & 131071)])))))) +
                  (0.172010005f * fVec0[((IOTA - iConst17) & 131071)])) +
                 (0.129979998f * fVec0[((IOTA - iConst18) & 131071)]));
            float fTemp6 = float(input1[i]);
            fRec9[0] = ((fTemp6 * fRec5[0]) + (fRec6[0] * fRec9[1]));
            fRec8[0] = ((fTemp1 * fRec9[0]) + (fRec7[0] * fRec8[1]));
            float fTemp7 = ((0.5f * (fRec8[0] * fTemp2)) + (fTemp3 * fRec8[1]));
            fVec1[(IOTA & 131071)] = fTemp7;
            float fTemp8 =
                ((((0.170719996f * fVec1[((IOTA - iConst19) & 131071)]) +
                   ((0.186430007f * (fVec1[((IOTA - iConst20) & 131071)] +
                                     fVec1[((IOTA - iConst21) & 131071)])) +
                    ((0.174600005f * fVec1[((IOTA - iConst22) & 131071)]) +
                     ((0.210490003f * fVec1[((IOTA - iConst23) & 131071)]) +
                      ((((((((((0.81576997f * fVec1[((IOTA - iConst10) & 131071)]) +
                               (0.519119978f * fVec1[((IOTA - iConst24) & 131071)])) +
                              (0.475300014f * fVec1[((IOTA - iConst25) & 131071)])) +
                             (0.390370011f * fVec1[((IOTA - iConst7) & 131071)])) +
                            (0.368600011f * fVec1[((IOTA - iConst26) & 131071)])) +
                           (0.356379986f * fVec1[((IOTA - iConst27) & 131071)])) +
                          (0.280330002f * fVec1[((IOTA - iConst28) & 131071)])) +
                         (0.28016001f * fVec1[((IOTA - iConst29) & 131071)])) +
                        (0.186240003f * fVec1[((IOTA - iConst30) & 131071)])) +
                       (0.345050007f * fVec1[((IOTA - iConst31) & 131071)])))))) +
                  (0.161990002f * fVec1[((IOTA - iConst32) & 131071)])) +
                 (0.138019994f * fVec1[((IOTA - iConst33) & 131071)]));
            fRec10[0] = (fSlow6 + (0.999000013f * fRec10[1]));
            fRec19[0] = (fSlow7 + (0.999000013f * fRec19[1]));
            float fTemp9 =
                std::min<float>(0.5f, std::max<float>(0.25f, (fRec19[0] + 0.150000006f)));
            fRec27[0] = (fSlow8 + (0.999000013f * fRec27[1]));
            fRec30[0] = (fSlow9 + (0.999000013f * fRec30[1]));
            float fTemp10 = (fRec29[1] + (fConst1 * fRec30[0]));
            fRec29[0] = (fTemp10 - float(int(fTemp10)));
            int iTemp11 =
                (int((fConst0 *
                      ((fRec27[0] *
                        ftbl0mydspSIG0[int((65536.0f * (fRec29[0] + (0.25f - float(int((fRec29[0] + 0.25f)))))))]) +
                       0.0305097271f))) +
                 -1);
            float fTemp12 =
                ((fRec23[1] != 0.0f) ?
                     (((fRec24[1] > 0.0f) & (fRec24[1] < 1.0f)) ? fRec23[1] : 0.0f) :
                     (((fRec24[1] == 0.0f) & (iTemp11 != iRec25[1])) ?
                          fConst34 :
                          (((fRec24[1] == 1.0f) & (iTemp11 != iRec26[1])) ? fConst35 : 0.0f)));
            fRec23[0] = fTemp12;
            fRec24[0] =
                std::max<float>(0.0f, std::min<float>(1.0f, (fRec24[1] + fTemp12)));
            iRec25[0] =
                (((fRec24[1] >= 1.0f) & (iRec26[1] != iTemp11)) ? iTemp11 : iRec25[1]);
            iRec26[0] =
                (((fRec24[1] <= 0.0f) & (iRec25[1] != iTemp11)) ? iTemp11 : iRec26[1]);
            fRec39[0] = (fSlow10 + (0.999000013f * fRec39[1]));
            int iTemp13 =
                std::min<int>(65536, std::max<int>(0, int((fConst0 * fRec39[0]))));
            fRec40[0] = (fSlow11 + (0.999000013f * fRec40[1]));
            float fTemp14 =
                (fVec1[((IOTA - iTemp13) & 131071)] - (fRec40[0] * fRec37[1]));
            fVec2[(IOTA & 1023)] = fTemp14;
            fRec37[0] = fVec2[((IOTA - iConst36) & 1023)];
            float fRec38 = (fRec40[0] * fTemp14);
            float fTemp15 = ((fRec38 + fRec37[1]) - (fRec40[0] * fRec35[1]));
            fVec3[(IOTA & 1023)] = fTemp15;
            fRec35[0] = fVec3[((IOTA - iConst37) & 1023)];
            float fRec36 = (fRec40[0] * fTemp15);
            fRec41[0] = (fSlow12 + (0.999000013f * fRec41[1]));
            float fTemp16 = ((fRec36 + fRec35[1]) - (fRec41[0] * fRec33[1]));
            fVec4[(IOTA & 4095)] = fTemp16;
            fRec33[0] = fVec4[((IOTA - iConst38) & 4095)];
            float fRec34 = (fRec41[0] * fTemp16);
            float fTemp17 = ((fRec34 + fRec33[1]) - (fRec41[0] * fRec31[1]));
            fVec5[(IOTA & 2047)] = fTemp17;
            fRec31[0] = fVec5[((IOTA - iConst39) & 2047)];
            float fRec32 = (fRec41[0] * fTemp17);
            fRec42[0] = (fSlow13 + (0.999000013f * fRec42[1]));
            float fTemp18 =
                (fRec31[1] + ((fRec19[0] * fRec14[((IOTA - iConst40) & 32767)]) +
                              (fRec32 + (fRec42[0] * fRec21[1]))));
            fVec6[(IOTA & 131071)] = fTemp18;
            fRec21[0] =
                (((1.0f - fRec24[0]) *
                  fVec6[((IOTA - std::min<int>(65536, std::max<int>(0, iRec25[0]))) & 131071)]) +
                 (fRec24[0] *
                  fVec6[((IOTA - std::min<int>(65536, std::max<int>(0, iRec26[0]))) & 131071)]));
            float fRec22 = (0.0f - (fRec42[0] * fTemp18));
            float fTemp19 = (fRec22 + fRec21[1]);
            fVec7[(IOTA & 32767)] = fTemp19;
            fRec43[0] = (fSlow14 + (0.999000013f * fRec43[1]));
            fRec20[0] = (fVec7[((IOTA - iConst41) & 32767)] + (fRec43[0] * fRec20[1]));
            float fTemp20 = (1.0f - fRec43[0]);
            float fTemp21 = ((fTemp9 * fRec17[1]) + ((fRec19[0] * fRec20[0]) * fTemp20));
            fVec8[(IOTA & 32767)] = fTemp21;
            fRec17[0] = fVec8[((IOTA - iConst42) & 32767)];
            float fRec18 = (0.0f - (fTemp9 * fTemp21));
            fRec11[(IOTA & 32767)] = (fRec18 + fRec17[1]);
            fRec12[(IOTA & 16383)] = (fRec20[0] * fTemp20);
            fRec13[(IOTA & 32767)] = fTemp19;
            int iTemp22 =
                (int((fConst0 * ((fRec27[0] * ftbl0mydspSIG0[int((65536.0f * fRec29[0]))]) +
                                 0.025603978f))) +
                 -1);
            float fTemp23 =
                ((fRec49[1] != 0.0f) ?
                     (((fRec50[1] > 0.0f) & (fRec50[1] < 1.0f)) ? fRec49[1] : 0.0f) :
                     (((fRec50[1] == 0.0f) & (iTemp22 != iRec51[1])) ?
                          fConst34 :
                          (((fRec50[1] == 1.0f) & (iTemp22 != iRec52[1])) ? fConst35 : 0.0f)));
            fRec49[0] = fTemp23;
            fRec50[0] =
                std::max<float>(0.0f, std::min<float>(1.0f, (fRec50[1] + fTemp23)));
            iRec51[0] =
                (((fRec50[1] >= 1.0f) & (iRec52[1] != iTemp22)) ? iTemp22 : iRec51[1]);
            iRec52[0] =
                (((fRec50[1] <= 0.0f) & (iRec51[1] != iTemp22)) ? iTemp22 : iRec52[1]);
            float fTemp24 =
                (fVec0[((IOTA - iTemp13) & 131071)] - (fRec40[0] * fRec59[1]));
            fVec9[(IOTA & 1023)] = fTemp24;
            fRec59[0] = fVec9[((IOTA - iConst43) & 1023)];
            float fRec60 = (fRec40[0] * fTemp24);
            float fTemp25 = ((fRec60 + fRec59[1]) - (fRec40[0] * fRec57[1]));
            fVec10[(IOTA & 1023)] = fTemp25;
            fRec57[0] = fVec10[((IOTA - iConst44) & 1023)];
            float fRec58 = (fRec40[0] * fTemp25);
            float fTemp26 = ((fRec58 + fRec57[1]) - (fRec41[0] * fRec55[1]));
            fVec11[(IOTA & 4095)] = fTemp26;
            fRec55[0] = fVec11[((IOTA - iConst45) & 4095)];
            float fRec56 = (fRec41[0] * fTemp26);
            float fTemp27 = ((fRec56 + fRec55[1]) - (fRec41[0] * fRec53[1]));
            fVec12[(IOTA & 2047)] = fTemp27;
            fRec53[0] = fVec12[((IOTA - iConst46) & 2047)];
            float fRec54 = (fRec41[0] * fTemp27);
            float fTemp28 =
                (fRec53[1] + ((fRec19[0] * fRec11[((IOTA - iConst47) & 32767)]) +
                              (fRec54 + (fRec42[0] * fRec47[1]))));
            fVec13[(IOTA & 131071)] = fTemp28;
            fRec47[0] =
                (((1.0f - fRec50[0]) *
                  fVec13[((IOTA - std::min<int>(65536, std::max<int>(0, iRec51[0]))) & 131071)]) +
                 (fRec50[0] *
                  fVec13[((IOTA - std::min<int>(65536, std::max<int>(0, iRec52[0]))) & 131071)]));
            float fRec48 = (0.0f - (fRec42[0] * fTemp28));
            float fTemp29 = (fRec48 + fRec47[1]);
            fVec14[(IOTA & 32767)] = fTemp29;
            fRec46[0] = (fVec14[((IOTA - iConst48) & 32767)] + (fRec43[0] * fRec46[1]));
            float fTemp30 =
                ((fTemp9 * fRec44[1]) + ((fRec19[0] * fTemp20) * fRec46[0]));
            fVec15[(IOTA & 16383)] = fTemp30;
            fRec44[0] = fVec15[((IOTA - iConst49) & 16383)];
            float fRec45 = (0.0f - (fTemp9 * fTemp30));
            fRec14[(IOTA & 32767)] = (fRec45 + fRec44[1]);
            fRec15[(IOTA & 8191)] = (fTemp20 * fRec46[0]);
            fRec16[(IOTA & 32767)] = fTemp29;
            output0[i] = FAUSTFLOAT(
                ((fTemp0 * fRec0[0]) +
                 (fRec1[0] *
                  ((fRec2[0] * ((0.75f * fTemp5) + (0.25f * fTemp8))) +
                   (0.600000024f *
                    (fRec10[0] *
                     (((fRec13[((IOTA - iConst50) & 32767)] + fRec13[((IOTA - iConst51) & 32767)]) +
                       fRec11[((IOTA - iConst52) & 32767)]) -
                      (((fRec12[((IOTA - iConst53) & 16383)] + fRec16[((IOTA - iConst54) & 32767)]) +
                        fRec15[((IOTA - iConst55) & 8191)]) +
                       fRec14[((IOTA - iConst56) & 32767)]))))))));
            output1[i] = FAUSTFLOAT(
                ((fTemp6 * fRec0[0]) +
                 (fRec1[0] *
                  ((fRec2[0] * ((0.75f * fTemp8) + (0.25f * fTemp5))) +
                   (0.600000024f *
                    (fRec10[0] *
                     (((fRec16[((IOTA - iConst57) & 32767)] + fRec16[((IOTA - iConst58) & 32767)]) +
                       fRec14[((IOTA - iConst59) & 32767)]) -
                      (((fRec15[((IOTA - iConst60) & 8191)] + fRec13[((IOTA - iConst61) & 32767)]) +
                        fRec12[((IOTA - iConst62) & 16383)]) +
                       fRec11[((IOTA - iConst63) & 32767)]))))))));
            fRec0[1] = fRec0[0];
            fRec1[1] = fRec1[0];
            fRec2[1] = fRec2[0];
            fRec5[1] = fRec5[0];
            fRec6[1] = fRec6[0];
            fRec4[1] = fRec4[0];
            fRec7[1] = fRec7[0];
            fRec3[1] = fRec3[0];
            IOTA = (IOTA + 1);
            fRec9[1] = fRec9[0];
            fRec8[1] = fRec8[0];
            fRec10[1] = fRec10[0];
            fRec19[1] = fRec19[0];
            fRec27[1] = fRec27[0];
            fRec30[1] = fRec30[0];
            fRec29[1] = fRec29[0];
            fRec23[1] = fRec23[0];
            fRec24[1] = fRec24[0];
            iRec25[1] = iRec25[0];
            iRec26[1] = iRec26[0];
            fRec39[1] = fRec39[0];
            fRec40[1] = fRec40[0];
            fRec37[1] = fRec37[0];
            fRec35[1] = fRec35[0];
            fRec41[1] = fRec41[0];
            fRec33[1] = fRec33[0];
            fRec31[1] = fRec31[0];
            fRec42[1] = fRec42[0];
            fRec21[1] = fRec21[0];
            fRec43[1] = fRec43[0];
            fRec20[1] = fRec20[0];
            fRec17[1] = fRec17[0];
            fRec49[1] = fRec49[0];
            fRec50[1] = fRec50[0];
            iRec51[1] = iRec51[0];
            iRec52[1] = iRec52[0];
            fRec59[1] = fRec59[0];
            fRec57[1] = fRec57[0];
            fRec55[1] = fRec55[0];
            fRec53[1] = fRec53[0];
            fRec47[1] = fRec47[0];
            fRec46[1] = fRec46[0];
            fRec44[1] = fRec44[0];
        }
    }
};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


//------------------------------------------------------------------------------
// End the Faust code section


Fverb::Fverb()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();
}

Fverb::~Fverb()
{
}

void Fverb::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();
}

void Fverb::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();
}

void Fverb::process(const float *in0, const float *in1, float *out0,
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

const char *Fverb::parameter_label(unsigned index) noexcept
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

    case 13:
        return "Early reflections";

    case 14:
        return "Late reflections";

    default:
        return 0;
    }
}

const char *Fverb::parameter_short_label(unsigned index) noexcept
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

    case 13:
        return "";

    case 14:
        return "";

    default:
        return 0;
    }
}

const char *Fverb::parameter_symbol(unsigned index) noexcept
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

    case 13:
        return "early_reflections";

    case 14:
        return "late_reflections";

    default:
        return 0;
    }
}

const char *Fverb::parameter_unit(unsigned index) noexcept
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

    case 13:
        return "%";

    case 14:
        return "%";

    default:
        return 0;
    }
}

const Fverb::ParameterRange *Fverb::parameter_range(unsigned index) noexcept
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

    case 13: {
        static const ParameterRange range = {50, 0, 100};
        return &range;
    }

    case 14: {
        static const ParameterRange range = {100, 0, 100};
        return &range;
    }

    default:
        return 0;
    }
}

bool Fverb::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fverb::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fverb::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {

    default:
        return false;
    }
}

bool Fverb::parameter_is_logarithmic(unsigned index) noexcept
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

float Fverb::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {

    case 0:
        return dsp.fHslider10;

    case 1:
        return dsp.fHslider3;

    case 2:
        return dsp.fHslider4;

    case 3:
        return dsp.fHslider5;

    case 4:
        return dsp.fHslider11;

    case 5:
        return dsp.fHslider12;

    case 6:
        return dsp.fHslider13;

    case 7:
        return dsp.fHslider7;

    case 8:
        return dsp.fHslider14;

    case 9:
        return dsp.fHslider9;

    case 10:
        return dsp.fHslider8;

    case 11:
        return dsp.fHslider0;

    case 12:
        return dsp.fHslider1;

    case 13:
        return dsp.fHslider2;

    case 14:
        return dsp.fHslider6;

    default:
        (void)dsp;
        return 0;
    }
}

void Fverb::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {

    case 0:
        dsp.fHslider10 = value;
        break;

    case 1:
        dsp.fHslider3 = value;
        break;

    case 2:
        dsp.fHslider4 = value;
        break;

    case 3:
        dsp.fHslider5 = value;
        break;

    case 4:
        dsp.fHslider11 = value;
        break;

    case 5:
        dsp.fHslider12 = value;
        break;

    case 6:
        dsp.fHslider13 = value;
        break;

    case 7:
        dsp.fHslider7 = value;
        break;

    case 8:
        dsp.fHslider14 = value;
        break;

    case 9:
        dsp.fHslider9 = value;
        break;

    case 10:
        dsp.fHslider8 = value;
        break;

    case 11:
        dsp.fHslider0 = value;
        break;

    case 12:
        dsp.fHslider1 = value;
        break;

    case 13:
        dsp.fHslider2 = value;
        break;

    case 14:
        dsp.fHslider6 = value;
        break;

    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float Fverb::get_predelay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float Fverb::get_input() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float Fverb::get_input_lowpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float Fverb::get_input_highpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float Fverb::get_input_diffusion_1() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float Fverb::get_input_diffusion_2() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}

float Fverb::get_tail_density() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider13;
}

float Fverb::get_decay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float Fverb::get_damping() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider14;
}

float Fverb::get_mod_frequency() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float Fverb::get_mod_depth() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float Fverb::get_dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float Fverb::get_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float Fverb::get_early_reflections() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float Fverb::get_late_reflections() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}


void Fverb::set_predelay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void Fverb::set_input(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void Fverb::set_input_lowpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void Fverb::set_input_highpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void Fverb::set_input_diffusion_1(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void Fverb::set_input_diffusion_2(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}

void Fverb::set_tail_density(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider13 = value;
}

void Fverb::set_decay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void Fverb::set_damping(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider14 = value;
}

void Fverb::set_mod_frequency(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void Fverb::set_mod_depth(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void Fverb::set_dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void Fverb::set_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void Fverb::set_early_reflections(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void Fverb::set_late_reflections(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}
