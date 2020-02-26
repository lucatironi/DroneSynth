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
    setSize (400, 300);
    
    masterVolumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    masterVolumeSlider.setRange(0.0f, 1.0f);
    masterVolumeSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 20);
    addAndMakeVisible(&masterVolumeSlider);
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
    masterVolumeSlider.setBounds (20, getHeight() / 2 - 100, 60, 200);
}
