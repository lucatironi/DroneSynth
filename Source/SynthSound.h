/*
  ==============================================================================

    SynthSound.h
    Created: 26 Feb 2020 10:27:32pm
    Author:  Luca Tironi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
public:

    bool appliesToNote (int /* midiNoteNumber */) override
    {
        return true;
    }
    
    //================================================

    bool appliesToChannel (int /* midiChannel */) override
    {
        return true;
    }
};
