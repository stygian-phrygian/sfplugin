# SFPlugin

Play SoundFonts in your DAW

## Installation

Copy the plugin files into the DAW's search path

## Usage

TODO

## Building

Check that GLib is installed (which FluidSynth depends on)

In Debian based systems

```
sudo apt install libglib2.0-dev
```

Note to self, building dpf (UI) examples requires

```
sudo apt install libcairo2-dev # cairo
sudo apt install libgl1-mesa-dev # filehandling
```

Now, we build

```
git clone --recurse-submodules <this-repo>
cmake -S . -B build
cmake --build build
```

## TODO
- replace helloworld example with soundfont (libfluidsynth) renderer
- remove set(DPF_EXAMPLES) from CMakeLists.txt
- hardcode soundfont sf2 file for testing
- soundfonts may contain 128 banks of 128 presets per bank, so should our dpf 
  plugin demand 128 programs
- disable unnecessary features of libfluidsynth to minimize compilation, eg. 
  GUI stuff, audio output stuff, etc. Look at FluidSynth CMakeLists.txt, 
  specifically "Options enabled by default" section
- determine which GUI to use for the plugin
- add a license?
- add screenshots?
- correct macros in the DistrhoPluginInfo.h
- instrument parameters
    - 1 x filename
    - 128 x banks (edge case = no banks)
    - 128 presets (per bank) - is this DPF program
    - ADSR (4)
    - chorus (?)
    - reverb (?)

