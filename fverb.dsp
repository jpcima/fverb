//
//  Référence:
//     Dattorro, Jon. "Effect design, part 1: Reverberator and other filters."
//     Journal of the Audio Engineering Society 45.9 (1997): 660-684.
//

declare name "fverb";
declare author "Jean Pierre Cimalando";
declare version "0.5";
declare license "BSD-2-Clause";

import("stdfaust.lib");

ptMax = 300e-3;
pt = hslider("[01] Predelay [symbol:predelay] [unit:ms]", 0., 0., ptMax*1e3, 1.) : *(1e-3) : si.smoo;
ing = hslider("[02] Input amount [symbol:input] [unit:%]", 100., 0., 100., 0.01) : *(0.01) : si.smoo;
tone = hslider("[03] Input low-pass cutoff [symbol:input_lowpass] [unit:Hz] [scale:log]", 10000., 1., 20000., 1.);
htone = hslider("[04] Input high-pass cutoff [symbol:input_highpass] [unit:Hz] [scale:log]", 100., 1., 1000., 1.);
id1 = hslider("[05] Input diffusion 1 [symbol:input_diffusion_1] [unit:%]", 75., 0., 100., 0.01) : *(0.01) : si.smoo;
id2 = hslider("[06] Input diffusion 2 [symbol:input_diffusion_2] [unit:%]", 62.5, 0., 100., 0.01) : *(0.01) : si.smoo;
dd1 = hslider("[07] Tail density [symbol:tail_density] [unit:%]", 70., 0., 100., 0.01) : *(0.01) : si.smoo;
dd2 = (dr + 0.15) : max(0.25) : min(0.5); /* (cf. table 1 Reverberation parameters) */
dr = hslider("[08] Decay [symbol:decay] [unit:%]", 50., 0., 100., 0.01) : *(0.01) : si.smoo;
damp = hslider("[09] Damping [symbol:damping] [unit:Hz] [scale:log]", 5500., 10., 20000., 1.);
modf = /*1.0*/hslider("[10] Modulator frequency [symbol:mod_frequency] [unit:Hz]", 1., 0.01, 4., 0.01) : si.smoo;
maxModt = 10e-3;
modt = hslider("[11] Modulator depth [symbol:mod_depth] [unit:ms]", 0.5, 0., maxModt*1e3, 0.1) : *(1e-3) : si.smoo;
dry = hslider("[12] Dry [symbol:dry] [unit:%]", 100., 0., 100., 0.01) : *(0.01) : si.smoo;
wet = hslider("[13] Wet [symbol:wet] [unit:%]", 50., 0., 100., 0.01) : *(0.01) : si.smoo;
/* 0:full stereo, 1:full mono */
cmix = 0.; //hslider("[12] Stereo cross mix", 0., 0., 1., 0.01) : *(0.5);

erg = hslider("[14] Early reflections [symbol:early_reflections] [unit:%]", 50., 0., 100., 0.01) : *(0.01) : si.smoo;
lrg = hslider("[15] Late reflections [symbol:late_reflections] [unit:%]", 100., 0., 100., 0.01) : *(0.01) : si.smoo;

/* for complete control of decay parameters */
// dd1 = hslider("[05] Decay diffusion 1 [unit:%]", 70., 0., 100., 0.01) : *(0.01) : si.smoo;
// dd2 = hslider("[06] Decay diffusion 2 [unit:%]", 50., 0., 100., 0.01) : *(0.01) : si.smoo;

fverb(lIn, rIn) =
  ((early : par(i, 2, *(erg))),
   (late : par(i, 2, *(lrg)))) :> (_, _)
with {
  // this reverb was designed for nominal rate of 29761 Hz
  T(x) = x/refSR with { refSR = 29761.; }; // reference time to seconds

  // stereo input (reference was mono downmixed)
  preInL = ((1.-cmix)*lIn+cmix*rIn : *(ing)) : toneLpf(tone) : toneHpf(htone);
  preInR = ((1.-cmix)*rIn+cmix*lIn : *(ing)) : toneLpf(tone) : toneHpf(htone);

  // late reverb model
  late = ((preInL : preInjectorL), (preInR : preInjectorR)) :
         crossInjector(ff1A, ff1B, ff1C, fb1, ff2A, ff2B, ff2C, fb2) :
         outputReconstruction;

  /* before entry into tank */
  /* Note(jpc) different delays left and right in hope to decorrelate more.
     values not documented anywhere, just out of my magic hat */
  preInjectorL = predelay :
                diffusion(id1, 1.03*T(142)) : diffusion(id1, 0.97*T(107)) :
                diffusion(id2, 0.97*T(379)) : diffusion(id2, 1.03*T(277));
  preInjectorR = predelay :
                diffusion(id1, 0.97*T(142)) : diffusion(id1, 1.03*T(107)) :
                diffusion(id2, 1.03*T(379)) : diffusion(id2, 0.97*T(277));
  /* the default for mixed down mono input */
  // preInjector = predelay : toneLpf(tone) :
  //               diffusion(id1, T(142)) : diffusion(id1, T(107)) :
  //               diffusion(id2, T(379)) : diffusion(id2, T(277));

  /*
    (cf. 1.3.7 Delay Modulation)
    Linear delay interpolation introduces undesired damping artifacts,
    this problem is resolved by using all-pass interpolation instead.

    Note(jpc) I'm told Dual Delay Interpolation aka `sdelay` works better and
              exhibits less artifacts. The choice of time constant is for now
              arbitrary, based on some hints in the documentation of `sdelay`.
   */
  fcomb = ddi(10e-3)/*allpass*/ with {
    linear = fi.allpass_fcomb;
    lagrange = fi.allpass_fcomb5;
    allpass = fi.allpass_fcomb1a;
    ddi(it, maxdel, N, aN) = (+ <: de.sdelay(maxdel, int(ma.SR*it), N-1),*(aN)) ~ *(-aN) : mem,_ : +;
  };

  delayDim(t) = 65536; // TODO(jpc) expression below does not work?
  //delayDim(t) = ma.nextpow2(t*maxSR) with { maxSR = 192000. };

  predelay = de.delay(delayDim(ptMax), int(pt*ma.SR));
  toneLpf(f) = fi.iir((1.-p), (0.-p)) with { p = exp(-2.*ma.PI*f/ma.SR) : si.smoo; };
  toneHpf(f) = fi.iir((0.5*(1.+p),-0.5*(1.+p)), (0.-p)) with { p = exp(-2.*ma.PI*f/ma.SR) : si.smoo; };

  /* note(jpc) round fixed delays to samples to make it faster */
  diffusion(amt, del) = fi.allpass_comb/*fcomb*/(delayDim(del), int(del*ma.SR), amt);

  dd1Mod1 = dd1OscPair : (_, !);
  //dd1Mod2 = dd1Mod1;
  /*
    (cf. 1.3.7 Delay Modulation)
    A different secondary oscillator can decorrelate the signal further and
    create more resonances.
   */
  dd1Mod2 = dd1OscPair : (!, _);

  /* prefer a quadrature oscillator if frequency is fixed */
  //dd1OscPair = os.oscq(modf);
  /* otherwise use a phase-synchronized pair */
  dd1OscPair = sine(p), cosine(p) with {
    sine(p) = rdtable(tablesize, os.sinwaveform(tablesize), int(p*tablesize));
    cosine(p) = sine(wrap(p+0.25));
    tablesize = 1 << 16;
  }
  letrec {
    'p = wrap(p+modf*(1./ma.SR));
  };
  wrap(p) = p-int(p);

  fixedDelay(t) = de.delay(delayDim(t), int(ma.SR*t));
  modulatedFcomb(t, tMaxExc, tMod, g) = fcomb(delayDim(t+tMaxExc), int(ma.SR*(t+tMod)), g);

  ff1A = modulatedFcomb(T(762), maxModt, dd1Mod1*modt, ma.neg(dd1));
  ff1B = fixedDelay(T(4453)) : toneLpf(damp);
  ff1C = *(dr) : diffusion(ma.neg(dd2), T(1800));
  fb1 = fixedDelay(T(3720)) : *(dr);
  ff2A = modulatedFcomb(T(908), maxModt, dd1Mod2*modt, ma.neg(dd1));
  ff2B = fixedDelay(T(4217)) : toneLpf(damp);
  ff2C = *(dr) : diffusion(ma.neg(dd2), T(2656));
  fb2 = fixedDelay(T(3163)) : *(dr);

  outputReconstruction(n1, n2, n3, n4, n5, n6) =
    0.6*sum(i, 7, lTap(i)), 0.6*sum(i, 7, rTap(i))
  with {
    lTap(0) = n4 : fixedDelay(T(266));
    lTap(1) = n4 : fixedDelay(T(2974));
    lTap(2) = n5 : fixedDelay(T(1913)) : ma.neg;
    lTap(3) = n6 : fixedDelay(T(1996));
    lTap(4) = n1 : fixedDelay(T(1990)) : ma.neg;
    lTap(5) = n2 : fixedDelay(T(187)) : ma.neg;
    lTap(6) = n3 : fixedDelay(T(1066)) : ma.neg;
    //
    rTap(0) = n1 : fixedDelay(T(353));
    rTap(1) = n1 : fixedDelay(T(3627));
    rTap(2) = n2 : fixedDelay(T(1228)) : ma.neg;
    rTap(3) = n3 : fixedDelay(T(2673));
    rTap(4) = n4 : fixedDelay(T(2111)) : ma.neg;
    rTap(5) = n5 : fixedDelay(T(335)) : ma.neg;
    rTap(6) = n6 : fixedDelay(T(121)) : ma.neg;
  };

  /*
   *                     A1    B1     C1
   *                     ^     ^      ^
   *                     |     |      |
   * in1 ->  [+] ----> [ . ff1 . ] >--.---.
   *          ^                           |
   *          |                           |
   *          .----< [fb1] <--- [z-1] <-------.
   *                                      |   |
   *          .----< [fb2] <--- [z-1] <---.   |
   *          |                               |
   *          v                               |
   * in2 ->  [+] ----> [ . ff2 . ] >--.-------.
   *                     |     |      |
   *                     v     v      v
   *                     A2    B2     C2
   *
   * note: implicit unit delay in the feedback paths
   */
  crossInjector(
    ff1A, ff1B, ff1C, fb1,
    ff2A, ff2B, ff2C, fb2,
    in1, in2) =
      A1, B1, C1,
      A2, B2, C2
  letrec {
    'A1 = C2 : fb1 : +(in1) : ff1A;
    'B1 = C2 : fb1 : +(in1) : ff1A : ff1B;
    'C1 = C2 : fb1 : +(in1) : ff1A : ff1B : ff1C;
    'A2 = C1 : fb2 : +(in2) : ff2A;
    'B2 = C1 : fb2 : +(in2) : ff2A : ff2B;
    'C2 = C1 : fb2 : +(in2) : ff2A : ff2B : ff2C;
  };

  // James Moore early reverb model
  early =
    /* mono */    //(0.5*(preInL+preInR)) : moorerEr <: (_, _)
    /* stereo */  (preInL, preInR) : moorerErStereo : crossMix(0.25)
  with {
    moorerEr(x) = sum(i, 18, (x : tap(i))) with {
      tap(i) = fixedDelay(moorerDelay(i)) : *(moorerGain(i));
    };

    /* Note(jpc) Stereo version off my magic hat */
    /*           cross-channel mix, decorrelations left and right */
    moorerErStereo(l, r) = sum(i, 18, (l : lTap(i))), sum(i, 18, (r : rTap(i)))
    with {
      lTap(i) = fixedDelay(moorerDelay(i) : decorrelate(i, 0)) : *(moorerGain(i) : decorrelate(i, 0));
      rTap(i) = fixedDelay(moorerDelay(i) : decorrelate(i, 1)) : *(moorerGain(i) : decorrelate(i, 1));
      decorrelate(i, d) = *(ba.if((i & 1) == d, 1.03, 0.97));
    };

    moorerDelay(0)  = moorerT(190);  moorerGain(0) = 0.841;
    moorerDelay(1)  = moorerT(949);  moorerGain(1) = 0.504;
    moorerDelay(2)  = moorerT(993);  moorerGain(2) = 0.490;
    moorerDelay(3)  = moorerT(1183); moorerGain(3) = 0.379;
    moorerDelay(4)  = moorerT(1192); moorerGain(4) = 0.380;
    moorerDelay(5)  = moorerT(1315); moorerGain(5) = 0.346;
    moorerDelay(6)  = moorerT(2021); moorerGain(6) = 0.289;
    moorerDelay(7)  = moorerT(2140); moorerGain(7) = 0.272;
    moorerDelay(8)  = moorerT(2524); moorerGain(8) = 0.192;
    moorerDelay(9)  = moorerT(2590); moorerGain(9) = 0.193;
    moorerDelay(10) = moorerT(2625); moorerGain(10) = 0.217;
    moorerDelay(11) = moorerT(2700); moorerGain(11) = 0.181;
    moorerDelay(12) = moorerT(3119); moorerGain(12) = 0.180;
    moorerDelay(13) = moorerT(3123); moorerGain(13) = 0.181;
    moorerDelay(14) = moorerT(3203); moorerGain(14) = 0.176;
    moorerDelay(15) = moorerT(3268); moorerGain(15) = 0.142;
    moorerDelay(16) = moorerT(3321); moorerGain(16) = 0.167;
    moorerDelay(17) = moorerT(3515); moorerGain(17) = 0.134;

    moorerT(x) = x/refSR with { refSR = 44100.; }; // reference time to seconds

    crossMix(c, l, r) = (l*directGain+r*crossGain), (r*directGain+l*crossGain) with {
      directGain = cos(0.5*ma.PI*c);
      crossGain = sin(0.5*ma.PI*c);
    };
  };
};

process(l, r) = fverb(l, r) : mix with {
  mix(rl, rr) = dry*l+wet*rl, dry*r+wet*rr;
};
