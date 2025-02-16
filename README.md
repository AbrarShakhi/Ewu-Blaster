# Space-Blaster

Using olcPixelGameEngine

## Install dependencies

### Ubuntu 20.04 and distros based on Ubuntu 20.04

Update and install the compiler, related build tools, and libraries required to build PixelGameEngine applications.

```sh
sudo apt update

sudo apt install build-essential libglu1-mesa-dev libpng-dev
```

### Arch Linux

Update and install the compiler, related build tools, and libraries required to build PixelGameEngine applications.

```sh
sudo pacman -Syu gcc glibc libpng mesa
```

### Fedora 34+

Update and install the compiler, related build tools, and libraries required to build PixelGameEngine applications.

```sh
sudo dnf install gcc-c++ glew-devel glm-devel libpng-devel
```

## Build project

On linux
Go to Scripts directoy and run Setup-Linux.sh
you may have to give executable permission to Setup-Linux.sh and premake5
On windows
Go to Scripts directoy and run Setup-Windows.sh
You have to be inside the Script Directory

on windows there will be visual studio solution to open
on linux there will be makefile to run
