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

faustpp -a scripts/architecture/generic.hpp -DIdentifier=Fshim fshim.dsp \
        > plugins/fshim/dsp/Fshim.hpp
faustpp -a scripts/architecture/generic.cpp -DIdentifier=Fshim fshim.dsp \
        > plugins/fshim/dsp/Fshim.cpp

clang-format -i plugins/fshim/dsp/Fshim.hpp
clang-format -i plugins/fshim/dsp/Fshim.cpp
