#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

// required
#define DISTRHO_PLUGIN_NAME                     "sfplugin"
#define DISTRHO_PLUGIN_NUM_INPUTS               0
#define DISTRHO_PLUGIN_NUM_OUTPUTS              2
#define DISTRHO_PLUGIN_URI                      "https://github.com/stygian-phrygian/sfplugin"

// realtime
#define DISTRHO_PLUGIN_IS_RT_SAFE               1

// instrument
#define DISTRHO_PLUGIN_IS_SYNTH                 1
#define DISTRHO_PLUGIN_WANT_PROGRAMS            1

// user interface
#define DISTRHO_PLUGIN_HAS_UI                   1
#define DISTRHO_UI_DEFAULT_WIDTH                512
#define DISTRHO_UI_DEFAULT_HEIGHT               512
#define DISTRHO_UI_USER_RESIZEABLE              1
#define DISTRHO_UI_FILE_BROWSER                 1

// clap
#define DISTRHO_PLUGIN_CLAP_ID                  "com.github.stygian-phrygian.sfplugin"
#define DISTRHO_PLUGIN_CLAP_FEATURES            "instrument", "stereo"

// vst
#define DISTRHO_PLUGIN_VST3_CATEGORIES          "Instrument|Sampler|Stereo"

// TODO
// enum of parameters goes here (to share between plugin and UI code)

#endif
