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

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DroneSynthAudioProcessor& processor;

    Slider osc1FrequencySlider;
    Slider osc1LevelSlider;
    ToggleButton osc1MuteButton;

    Slider osc2FrequencySlider;
    Slider osc2LevelSlider;
    ToggleButton osc2MuteButton;

    Slider osc3FrequencySlider;
    Slider osc3LevelSlider;
    ToggleButton osc3MuteButton;

    Slider masterGainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DroneSynthAudioProcessorEditor)

public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc1FrequencySliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc1LevelSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> osc1MuteButtonValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc2FrequencySliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc2LevelSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> osc2MuteButtonValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc3FrequencySliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> osc3LevelSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> osc3MuteButtonValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> masterGainSliderValue;
};
