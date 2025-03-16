# Ewu-Blaster

Using olcPixelGameEngine

## Install dependencies

### Ubuntu 20.04+ and distros based on Ubuntu 20.04+

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

## Project Structure

```
Space-Blaster (Root)
├── Core
│   └── olc
│       ├── LICENCE.md
│       └── olcPixelGameEngine.h
├── premake5.lua
├── Scripts
│   ├── Setup-Linux.sh
│   ├── Setup-MinGW.bat
│   └── Setup-Windows.bat
├── Assets/**.png
├── Game
│   ├── includes/**.h
│   └── src/**.cpp
└── Vendor
    └── Premake
        ├── LICENSE.txt
        ├── premake5.out
        ├── premake5.osx
        └── premake5.exe
```

## Build project

### Makefile (Linux/Mac/MinGW)

make `Setup-Linux.sh` and `premake executable`

```sh
sudo chmod +x Scripts/Setup-Linux.sh
sudo chmod +x Vendor/Premake/Linux/premake5
```

Now Run the `Setup-Linux.sh` Scripts (Make sure you are in root of the project)

```sh
./Scripts/Setup-Linux.sh && make
```

If compilation is succesfull, you can see a executable file `Ewu-Blaster` in `.out` folder so run it

```sh
./.out/Ewu-Blaster
```

### Visual Studio (Windows only)

Go to `Scripts` folder and run `Setup-Winddows.bat`

If compilation is succesfull, you can see a `Ewu-Blaster.sln` file, open that in visual studio,
Now, you can run the game visual studio,
If you want to see .exe file its in `.out` folder

## Credits

1. olc Pixel Game Engine by [javidx9](https://www.youtube.com/javidx9) youtube.
