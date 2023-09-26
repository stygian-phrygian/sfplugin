dpf_add_plugin(
    "${PROJECT_NAME}"
    TARGETS
        vst3
    # UI_TYPE
    #     opengl
    FILES_DSP
        SFPluginDSP.cpp
    FILES_UI
        SFPluginUI.cpp
)
target_include_directories(
    "${PROJECT_NAME}"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries(
    "${PROJECT_NAME}"
    PUBLIC
        libfluidsynth
)
