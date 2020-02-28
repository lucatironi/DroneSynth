/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DroneSynthAudioProcessorEditor::DroneSynthAudioProcessorEditor (DroneSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);

    osc1FrequencySlider.setSliderStyle (Slider::SliderStyle::Rotary);
    osc1FrequencySlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc1FrequencySlider.setTextValueSuffix (" Hz");
    addAndMakeVisible (&osc1FrequencySlider);

    osc1LevelSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    osc1LevelSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc1LevelSlider.setTextValueSuffix ("%");
    addAndMakeVisible (&osc1LevelSlider);

    osc1MuteButton.setButtonText ("Mute");
    addAndMakeVisible (&osc1MuteButton);


    osc2FrequencySlider.setSliderStyle (Slider::SliderStyle::Rotary);
    osc2FrequencySlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc2FrequencySlider.setTextValueSuffix (" Hz");
    addAndMakeVisible (&osc2FrequencySlider);

    osc2LevelSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    osc2LevelSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc2LevelSlider.setTextValueSuffix ("%");
    addAndMakeVisible (&osc2LevelSlider);

    osc2MuteButton.setButtonText ("Mute");
    addAndMakeVisible (&osc2MuteButton);


    osc3FrequencySlider.setSliderStyle (Slider::SliderStyle::Rotary);
    osc3FrequencySlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc3FrequencySlider.setTextValueSuffix (" Hz");
    addAndMakeVisible (&osc3FrequencySlider);

    osc3LevelSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    osc3LevelSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    osc3LevelSlider.setTextValueSuffix ("%");
    addAndMakeVisible (&osc3LevelSlider);

    osc3MuteButton.setButtonText ("Mute");
    addAndMakeVisible (&osc3MuteButton);


    filterCutoffFrequencySlider.setSliderStyle (Slider::SliderStyle::Rotary);
    filterCutoffFrequencySlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    filterCutoffFrequencySlider.setTextValueSuffix (" Hz");
    addAndMakeVisible (&filterCutoffFrequencySlider);

    filterResonanceSlider.setSliderStyle (Slider::SliderStyle::Rotary);
    filterResonanceSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    addAndMakeVisible (&filterResonanceSlider);


    masterGainSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    masterGainSlider.setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    masterGainSlider.setTextValueSuffix (" Db");
    addAndMakeVisible (&masterGainSlider);


    osc1FrequencySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc1Frequency", osc1FrequencySlider);
    osc1LevelSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc1Level", osc1LevelSlider);
    osc1MuteButtonValue = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment> (processor.parameters, "osc1Mute", osc1MuteButton);

    osc2FrequencySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc2Frequency", osc2FrequencySlider);
    osc2LevelSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc2Level", osc2LevelSlider);
    osc2MuteButtonValue = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment> (processor.parameters, "osc2Mute", osc2MuteButton);

    osc3FrequencySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc3Frequency", osc3FrequencySlider);
    osc3LevelSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "osc3Level", osc3LevelSlider);
    osc3MuteButtonValue = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment> (processor.parameters, "osc3Mute", osc3MuteButton);
    
    filterCutoffFrequencySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "filterCutoffFrequency", filterCutoffFrequencySlider);
    filterResonanceSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "filterResonance", filterResonanceSlider);

    masterGainSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.parameters, "masterGain", masterGainSlider);
}

DroneSynthAudioProcessorEditor::~DroneSynthAudioProcessorEditor()
{
}

//==============================================================================
void DroneSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void DroneSynthAudioProcessorEditor::resized()
{
    osc1FrequencySlider.setBounds (20, 20, 100, 100);
    osc1LevelSlider.setBounds (40, 120, 60, 200);
    osc1MuteButton.setBounds (20, 340, 100, 40);

    osc2FrequencySlider.setBounds (140, 20, 100, 100);
    osc2LevelSlider.setBounds (160, 120, 60, 200);
    osc2MuteButton.setBounds (140, 340, 100, 40);

    osc3FrequencySlider.setBounds (260, 20, 100, 100);
    osc3LevelSlider.setBounds (280, 120, 60, 200);
    osc3MuteButton.setBounds (260, 340, 100, 40);
    
    filterCutoffFrequencySlider.setBounds (380, 100, 100, 100);
    filterResonanceSlider.setBounds (380, 220, 100, 100);

    masterGainSlider.setBounds (500, 120, 60, 200);
}
