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
    void setOsc1Params (std::atomic<float>* freq, std::atomic<float>* level, std::atomic<float>* muted)
    {
        osc1Frequency = double(*freq);
        osc1Level = double(*level);
        osc1Muted = bool(*muted);
    }

    void setOsc2Params (std::atomic<float>* freq, std::atomic<float>* level, std::atomic<float>* muted)
    {
        osc2Frequency = double(*freq);
        osc2Level = double(*level);
        osc2Muted = bool(*muted);
    }

    void setOsc3Params (std::atomic<float>* freq, std::atomic<float>* level, std::atomic<float>* muted)
    {
        osc3Frequency = double(*freq);
        osc3Level = double(*level);
        osc3Muted = bool(*muted);
    }

    void setMasterGain (std::atomic<float>* masterGainValue)
    {
        masterGain = double(*masterGainValue);
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
            double theFirstWave  = (osc1Muted ? 0.0f : osc1.square(osc1Frequency)) * (osc1Level / 100.0f);
            double theSecondWave = (osc2Muted ? 0.0f : osc2.square(osc2Frequency)) * (osc2Level / 100.0f);
            double theThirdWave  = (osc3Muted ? 0.0f : osc3.square(osc3Frequency)) * (osc3Level / 100.0f);

            double theSound = (theFirstWave + theSecondWave + theThirdWave) * Decibels::decibelsToGain(masterGain);

            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, theSound);
            }

            ++startSample;
        }
    }
    
private:
    double osc1Frequency;
    double osc1Level;
    bool osc1Muted;

    double osc2Frequency;
    double osc2Level;
    bool osc2Muted;

    double osc3Frequency;
    double osc3Level;
    bool osc3Muted;

    double masterGain;

    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;
};

