#include "DistrhoPlugin.hpp"
#include "DistrhoPluginUtils.hpp"
// #include "fluidsynth.h"
#include <cstdio>

START_NAMESPACE_DISTRHO

namespace
{
uint32_t const N_PRESETS_PER_BANK = 128;
}

class SFPluginDSP : public Plugin
{
public:
    SFPluginDSP() :
        Plugin(1, N_PRESETS_PER_BANK, 0), // 1 parameter, 128 programs and 0 states
        fGain(1.0f)
    {}

protected:
    char const* getLabel()      const override { return "sfplugin"; }
    char const* getMaker()      const override { return "stygian-phrygian"; }
    char const* getLicense()    const override { return "GPL3"; }
    uint32_t    getVersion()    const override { return d_version(1, 0, 0); }
    int64_t     getUniqueId()   const override { return d_cconst('s', 'f', 'p', 'r'); }

    void initProgramName(uint32_t index, String& programName)
    {
        // TODO each time a new sf2 file is loaded
        // populate the plugin's programs with the available sf2 presets
        programName = "hello world";
    }

    void loadProgram(uint32_t index)
    {
        // TODO load sf2 preset at index
        printf("%s %d\n", __func__, index);
    }

    /* ----------------------------------------------------------------------------------------
     * Init */

    /**
      Initialize a parameter.
      This function will be called once, shortly after the plugin is created.
      */
    void initParameter(uint32_t index, Parameter& parameter) override
    {
        // we only have one parameter so we can skip checking the index

        parameter.hints      = kParameterIsAutomatable;
        parameter.name       = "Gain";
        parameter.symbol     = "gain";
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 2.0f;
        parameter.ranges.def = 1.0f;
    }

    /* ----------------------------------------------------------------------------------------
     * Internal data */

    /**
      Get the current value of a parameter.
      */
    float getParameterValue(uint32_t index) const override
    {
        printf("%s index=%d\n", __func__, index);
        return fGain;
    }

    /**
      Change a parameter value.
      */
    void setParameterValue(uint32_t index, float value) override
    {
        // same as before, ignore index check

        printf("%s index=%d, value=%f\n", __func__, index, value);
        fGain = value;
    }

    // void run(const float** inputs, float** outputs, uint32_t frames) override
    // {
    //     // get the mono input and output
    //     const float* const in  = inputs[0];
    //     /* */ float* const out = outputs[0];
    //     // apply gain against all samples
    //     for (uint32_t i = 0; i < frames; ++i)
    //     {
    //         out[i] = in[i] * fGain;
    //     }
    // }

    void run(
            const float** inputs,
            float** outputs,
            uint32_t frames,
            const MidiEvent* midiEvents,
            uint32_t midiEventCount) override
    {
        for (AudioMidiSyncHelper amsh(outputs, frames, midiEvents, midiEventCount); amsh.nextEvent(); )
        {
            float* const outL = amsh.outputs[0];
            float* const outR = amsh.outputs[1];

            for (uint32_t i = 0; i < amsh.midiEventCount; ++i)
            {

                // ignore bigger midi events
                if (amsh.midiEvents[i].size > MidiEvent::kDataSize)
                {
                    printf("%s ignoring midi\n", __func__);
                    continue;
                }

                // TODO
                // ... do something with the midi event
                const MidiEvent& ev = amsh.midiEvents[i];
                printf(
                        "%s bytes=%x %x %x %x\n",
                        __func__,
                        ev.data[0],
                        ev.data[1],
                        ev.data[2],
                        ev.data[3]);
            }

            // renderSynth(outL, outR, amsh.frames);
        }
    }

private:
    float fGain;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SFPluginDSP)
};

Plugin* createPlugin()
{
    return new SFPluginDSP();
}

END_NAMESPACE_DISTRHO
