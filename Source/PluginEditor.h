/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DroneSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    DroneSynthAudioProcessorEditor (DroneSynthAudioProcessor&);
    ~DroneSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> masterVolumeSliderValue;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DroneSynthAudioProcessor& processor;
    
    Slider masterVolumeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DroneSynthAudioProcessorEditor)
};
