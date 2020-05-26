#!/bin/bash
set -e
set -x

if ! test -f fverb.dsp; then
    echo "Please run this in the top directory."
    exit 1
fi

faustpp -a scripts/architecture/generic.hpp -DIdentifier=Fverb fverb.dsp \
        > plugins/fverb/dsp/Fverb.hpp
faustpp -a scripts/architecture/generic.cpp -DIdentifier=Fverb fverb.dsp \
        > plugins/fverb/dsp/Fverb.cpp

clang-format -i plugins/fverb/dsp/Fverb.hpp
clang-format -i plugins/fverb/dsp/Fverb.cpp
