project(sfplugin)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

# dependencies
add_subdirectory(extern/fluidsynth)
add_subdirectory(extern/dpf)


# plugin
add_subdirectory(src)
