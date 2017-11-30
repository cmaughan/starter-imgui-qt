IF (BUILD_QT)
LIST(APPEND APPQT_SOURCE
src/app/qt/main-qt.cpp
src/app/qt/app.qrc
src/app/qt/app.rc
src/app/qt/mainwindow.cpp
src/app/qt/mainwindow.ui
src/app/qt/resource.h
src/app/qt/common_qt.cpp
src/app/qt/common_qt.h
src/app/qt/display_qt.cpp
src/app/qt/display_qt.h
src/app/qt/window_qt.cpp
src/app/qt/window_qt.h
src/app/qt/list.cmake
)

LIST(APPEND APPQT_INCLUDE
    src/app/qt)

ENDIF()
