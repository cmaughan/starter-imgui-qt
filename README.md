[Starter-ImGui-Qt](https://github.com/cmaughan/starter-imgui-qt) - A Simple Cross Platform Qt or ImGui App 
========================================================================================================

[![Build status](https://ci.appveyor.com/api/projects/status/vmn1b7gvoftncwn6?svg=true)](https://ci.appveyor.com/project/cmaughan/starter-imgui-qt)
[![Build Status](https://travis-ci.org/cmaughan/starter-imgui-qt.svg?branch=master)](https://travis-ci.org/cmaughan/starter-imgui-qt)
[![codecov](https://codecov.io/gh/cmaughan/starter-imgui-qt/branch/master/graph/badge.svg)](https://codecov.io/gh/cmaughan/starter-imgui-qt)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/cmaughan/zep/blob/master/LICENSE)

Introduction
------------
I built this mainly as a teaching tool for York Developers.  It's a more advanced way of creating a cross platform desktop application, where
your main requirement is running everywhere, while being able to get something on the screen easily.
There are 2 approaches.  Either an OpenGL/SDL2 application is generated, and drawing is done through ImGui, or a Qt Application is built and drawing is
done by QPainter.  In either case, the specific method is isolated to the Main executable, and a common library implements the guts of what you want to do.
In this way you can build an app and ship it as a Qt or an ImGui application.
On my todo list is combining the two, so you can draw in a Qt window with ImGui.  That should be a fairly simple extension.

Building
---------
You can follow the build buttons above to see build scripts, but the process is fairly simple:

##### Install Packages  
If you don't have them already, the following packages are required, depending on your system.  Note, that SDL is part of the build,
and not installed seperately.  It is only used for the ImGui app and unit tests, not the Qt version.
If you have compilation problems, you might need to investigate the compiler you are using.
Ubuntu 16 & 17 both have a recent enough version for it to work.  On Ubuntu 14 I tend to upgrade to g++6

###### Linux
```
sudo apt install cmake  
sudo apt install git  
```

###### Mac
```
brew install cmake
brew install git
```
(If in doubt, see the .travis.yml build file for how the remote build machines are setup)

##### Get the Source
git clone https://github.com/cmaughan/starter-imgui-qt starter  
cd starter  

##### Make
There are some sample scripts which call CMake, but you can generate makefiles for your favourite compiler by passing a different generator to it.
Before running conficture, set QT_INSTALL_LOCATION in your enviroment to point to your Qt Install.  On my machine, this is:

C:\Qt\Qt5.9.1\5.9.1\msvc2017_64

You don't need this of course if you aren't building the QT version.
To build the ImGui version, pass -DBUILD_IMGUI to CMake
To build the Qt version, pass -DBUILD_QT to CMake

Without these options, you'll get both.

Unit tests are always built too.

###### Linux 
```
./config.sh
make
```  

###### Mac (XCode)
```
./config_mac.sh
cd build
cmake --build .
```
###### PC
```
config.bat
cd build
cmake --build .
(Or load solution in VC 2017)
```

##### Tests
Type `CTest --verbose` in the build folder to run unit tests.

Libraries
-----------
This sample uses SDL for the window setup in the ImGui App, and Qt for the Qt App

[SDL2: Media/Window Layer](https://www.libsdl.org/download-2.0.php)  
SDL2 is used to get a window on the screen in a cross platform way, and for OpenGL to generate a Context.

[ImGui: 2D GUI](https://github.com/ocornut/imgui)  
ImGui is a great 2D User interface for 3D applications

