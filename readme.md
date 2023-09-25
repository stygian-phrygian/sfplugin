# SFPlugin

Play SoundFonts in your DAW

## Installation

Copy the plugin files into the DAW's search path

Note, glib *must* be installed because FluidSynth's core functionality 
currently depends on it.

In a debian linux, install glib thusly
```
sudo apt install libglib2.0-dev
```

## Usage

TODO

## Building

```
git clone --recurse-submodules <this-repo>
cmake -S . -B build
cmake --build build
```

## TODO
- disable unnecessary features of libfluidsynth to minimize compilation, eg. 
  GUI stuff, audio output stuff, etc. Look at FluidSynth CMakeLists.txt, 
  specifically "Options enabled by default" section
- determine which GUI to use for the plugin
- add a license?
- add screenshots?
- correct macros in the DistrhoPluginInfo.h
- instrument parameters
    - filename, bank, preset (3)
    - ADSR (4)
    - chorus (?)
    - reverb (?)

