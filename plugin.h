#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "NetworkConnection.h"

class LittleHollandVST3 : public Steinberg::Vst::AudioEffect
{
public:
    LittleHollandVST3();
    ~LittleHollandVST3() SMTG_OVERRIDE;
    tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;
    tresult PLUGIN_API process(ProcessData& data) SMTG_OVERRIDE;
    tresult PLUGIN_API setupProcessing(ProcessSetup& newSetup) SMTG_OVERRIDE;
    tresult PLUGIN_API setActive(TBool state) SMTG_OVERRIDE;
    static FUnknown* createInstance(void*) { return (IAudioProcessor*)new LittleHollandVST3(); }

private:
    void handleMIDIEvents(ProcessData& data);
    void handleAudioEvents(ProcessData& data);
    void updateUI();
    bool initializeNetworkConnection(const char* serverAddress);
    void sendDataToServer(const std::vector<char>& data);

    int midiCount;
    int audioDataSize;
    bool connectionAvailable;
    NetworkConnection networkConnection;
};
