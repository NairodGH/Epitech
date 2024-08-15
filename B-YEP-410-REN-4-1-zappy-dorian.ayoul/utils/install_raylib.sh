#!/bin/bash

# init
source /etc/os-release

# install dependencies for computer os

if [ "$EUID" -ne 0 ]
  then echo -e "\033[1;31mPlease run as root to install dependencies\033[1;0m"
elif [[ "$PRETTY_NAME" == "Fedora"* ]]; then
    sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel
else
    sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
fi

# Install raylib:
git clone https://github.com/raysan5/raylib.git /tmp/raylib
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED -C /tmp/raylib/src

cp /tmp/raylib/src/raylib.h include/raylib.h
cp /tmp/raylib/src/libraylib.so libs/libraylib.so
cp /tmp/raylib/src/libraylib.so.400 libs/libraylib.so.400
cp /tmp/raylib/src/libraylib.so.4.0.0 libs/libraylib.so.4.0.0
