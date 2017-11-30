IF (BUILD_IMGUI)
LIST(APPEND APPIMGUI_SOURCE
    src/app/imgui/main-imgui.cpp
    src/app/imgui/display_imgui.cpp
    src/app/imgui/display_imgui.h
    src/app/imgui/list.cmake
    ${IMGUI_SOURCE}
    )

LIST(APPEND APPIMGUI_INCLUDE
    src/app/imgui)

ENDIF()
