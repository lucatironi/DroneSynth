/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DroneSynthAudioProcessor::DroneSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
       parameters(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
   mySynth.clearVoices();
   
   for (int i = 0; i < 5; i++)
   {
       mySynth.addVoice(new SynthVoice());
   }
   mySynth.clearSounds();
   mySynth.addSound(new SynthSound());
}

DroneSynthAudioProcessor::~DroneSynthAudioProcessor()
{
}

//==============================================================================

AudioProcessorValueTreeState::ParameterLayout DroneSynthAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;

    auto osc1FrequencyParam = std::make_unique<AudioParameterFloat> ("osc1Frequency", "Osc1Frequency", NormalisableRange<float> (10.0f, 300.0f, 1.0f), 55.0f);
    auto osc1LevelParam = std::make_unique<AudioParameterFloat> ("osc1Level", "Osc1Level", NormalisableRange<float> (0.0f, 100.0f, 1.0f), 100.0f);
    auto osc1MuteParam = std::make_unique<AudioParameterBool> ("osc1Mute", "Osc1Mute", false);

    auto osc2FrequencyParam = std::make_unique<AudioParameterFloat> ("osc2Frequency", "Osc2Frequency", NormalisableRange<float> (10.0f, 300.0f, 1.0f), 110.0f);
    auto osc2LevelParam = std::make_unique<AudioParameterFloat> ("osc2Level", "Osc2Level", NormalisableRange<float> (0.0f, 100.0f, 1.0f), 100.0f);
    auto osc2MuteParam = std::make_unique<AudioParameterBool> ("osc2Mute", "Osc2Mute", false);

    auto osc3FrequencyParam = std::make_unique<AudioParameterFloat> ("osc3Frequency", "Osc3Frequency", NormalisableRange<float> (10.0f, 300.0f, 1.0f), 112.0f);
    auto osc3LevelParam = std::make_unique<AudioParameterFloat> ("osc3Level", "Osc3Level", NormalisableRange<float> (0.0f, 100.0f, 1.0f), 100.0f);
    auto osc3MuteParam = std::make_unique<AudioParameterBool> ("osc3Mute", "Osc3Mute", false);
    
    auto filterCutoffFrequencyParam = std::make_unique<AudioParameterFloat> ("filterCutoffFrequency", "FilterCutoffFrequency", NormalisableRange<float> (1.0f, 1000.0f, 1.0f), 1000.0f);
    auto filterResonanceParam = std::make_unique<AudioParameterFloat> ("filterResonance", "FilterResonance", NormalisableRange<float> (0.0f, 20.0f, 0.1f), 0.0f);

    auto masterGainParam = std::make_unique<AudioParameterFloat> ("masterGain", "MasterGain", NormalisableRange<float> (-100.0f, 20.0f, 1.0f), -60.0f);

    params.push_back(std::move(osc1FrequencyParam));
    params.push_back(std::move(osc1LevelParam));
    params.push_back(std::move(osc1MuteParam));

    params.push_back(std::move(osc2FrequencyParam));
    params.push_back(std::move(osc2LevelParam));
    params.push_back(std::move(osc2MuteParam));

    params.push_back(std::move(osc3FrequencyParam));
    params.push_back(std::move(osc3LevelParam));
    params.push_back(std::move(osc3MuteParam));

    params.push_back(std::move(filterCutoffFrequencyParam));
    params.push_back(std::move(filterResonanceParam));

    params.push_back(std::move(masterGainParam));

    return { params.begin(), params.end() };
}

const String DroneSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DroneSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DroneSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DroneSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DroneSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DroneSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DroneSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DroneSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String DroneSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void DroneSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DroneSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void DroneSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DroneSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DroneSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {
            myVoice->setOsc1Params (parameters.getRawParameterValue("osc1Frequency"), parameters.getRawParameterValue("osc1Level"), parameters.getRawParameterValue("osc1Mute"));
            myVoice->setOsc2Params (parameters.getRawParameterValue("osc2Frequency"), parameters.getRawParameterValue("osc2Level"), parameters.getRawParameterValue("osc2Mute"));
            myVoice->setOsc3Params (parameters.getRawParameterValue("osc3Frequency"), parameters.getRawParameterValue("osc3Level"), parameters.getRawParameterValue("osc3Mute"));
            
            myVoice->setFilterParams (parameters.getRawParameterValue("filterCutoffFrequency"), parameters.getRawParameterValue("filterResonance"));

            myVoice->setMasterGain (parameters.getRawParameterValue("masterGain"));
        }
    }

    buffer.clear();

    mySynth.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool DroneSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DroneSynthAudioProcessor::createEditor()
{
    return new DroneSynthAudioProcessorEditor (*this);
}

//==============================================================================
void DroneSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DroneSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DroneSynthAudioProcessor();
}
