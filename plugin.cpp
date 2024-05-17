#include "Plugin.h"
#include <iostream>

LittleHollandVST3::LittleHollandVST3() : midiCount(0), audioDataSize(0), connectionAvailable(false)
{
    initializeNetworkConnection("littleholland.overtheworld.uk");
}

LittleHollandVST3::~LittleHollandVST3() {}

tresult PLUGIN_API LittleHollandVST3::initialize(FUnknown* context)
{
    return AudioEffect::initialize(context);
}

tresult PLUGIN_API LittleHollandVST3::setupProcessing(ProcessSetup& newSetup)
{
    return kResultOk;
}

tresult PLUGIN_API LittleHollandVST3::setActive(TBool state)
{
    return kResultOk;
}

tresult PLUGIN_API LittleHollandVST3::process(ProcessData& data)
{
    handleMIDIEvents(data);
    handleAudioEvents(data);
    updateUI();
    return kResultOk;
}

void LittleHollandVST3::handleMIDIEvents(ProcessData& data)
{
    for (int32 i = 0; i < data.inputEvents->getEventCount(); i++)
    {
        Event event;
        if (data.inputEvents->getEvent(i, event) == kResultOk && event.type == Event::kNoteOnEvent)
        {
            midiCount++;
            std::vector<char> serializedData = serializeMIDIEvent(event);
            sendDataToServer(serializedData);
        }
    }
}

void LittleHollandVST3::handleAudioEvents(ProcessData& data)
{
    if (data.numInputs > 0 && data.inputs[0].channelBuffers32)
    {
        audioDataSize += data.numSamples * sizeof(float);
        std::vector<char> serializedData = serializeAudioData(data.inputs[0].channelBuffers32, data.numSamples);
        sendDataToServer(serializedData);
    }
}

void LittleHollandVST3::updateUI()
{
    std::cout << "MIDI Notes Transferred: " << midiCount << std::endl;
    std::cout << "Audio Data Transferred: " << audioDataSize / (1024 * 1024) << " MB" << std::endl;
}

bool LittleHollandVST3::initializeNetworkConnection(const char* serverAddress)
{
    connectionAvailable = networkConnection.open(serverAddress);
    return connectionAvailable;
}

void LittleHollandVST3::sendDataToServer(const std::vector<char>& data)
{
    if (connectionAvailable)
    {
        networkConnection.send(data);
    }
    else
    {
        std::cerr << "Failed to send data: No connection available" << std::endl;
    }
}
