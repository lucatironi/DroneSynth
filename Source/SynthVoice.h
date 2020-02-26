/*
  ==============================================================================

    SynthVoice.h
    Created: 26 Feb 2020 10:27:13pm
    Author:  Luca Tironi

  ==============================================================================
*/

#pragma once
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
    void setMasterVolume (std::atomic<float>* masterVolumeValue)
    {
        masterVolume = double(*masterVolumeValue);
    }
    
    //================================================
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition) override
    {
        
    }
    
    //================================================

    void stopNote (float velocity, bool allowTailOff) override
    {
        
    }

    //================================================

    void pitchWheelMoved (int newPitchWheelValue) override
    {
        
    }
    
    //================================================

    void controllerMoved (int controllerNumber, int newControllerValue) override
    {
        
    }
    
    //================================================

    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {
            double theWave = osc1.square(40.0f) * masterVolume;

            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, theWave);
            }

            ++startSample;
        }
    }
    
private:
    double masterVolume;

    maxiOsc osc1;
};

