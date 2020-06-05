declare name "fshim";
declare author "Jean Pierre Cimalando";
declare version "0.5";
declare license "BSD-2-Clause";

import("stdfaust.lib");
fv = library("fverb.dsp");

shift = ef.transpose(windowSize, xfadeSize, 12) with {
  windowSize = 2048;
  xfadeSize = 1024;
};

process(inL, inR) =
  ((+(inL*fv.wet), +(inR*fv.wet)) ~ ((shift, shift) : fv.fverb)) :
  ((+(inL*fv.dry), +(inR*fv.dry)));
//process(inL, inR) = ((inL:pitchOctaveUp), (inR:pitchOctaveUp));
