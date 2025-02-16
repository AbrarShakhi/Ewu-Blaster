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

## Project Structure

```
Space-Blaster (Root)
├── Core
│   └── olcPixelGameEngine
│       ├── LICENCE.md
│       └── olcPixelGameEngine.h
├── premake5.lua
├── Scripts
│   ├── Setup-Linux.sh
│   └── Setup-Windows.bat
├── Space-Blaster
│   ├── includes/**.h
│   └── src/**.cpp
└── Vendor
    └── Premake
        ├── LICENSE.txt
        ├── Linux
        │   └── premake5
        ├── macOS
        │   └── premake5
        └── Windows
            └── premake5.exe
```

## Build project

### Makefile (Linux/Mac)

make `Setup-Linux.sh` and `premake executable`

```sh
sudo chmod +x Scripts/Setup-Linux.sh
sudo chmod +x Vendor/Premake/Linux/premake5
```

Now Run the `Setup-Linux.sh` Scripts (Make sure you are in root of the project)

```sh
./Scripts/Setup-Linux.sh && make
```

If compilation is succesfull, you can see a executable file `Space-Blaster` in `.out` folder so run it

```sh
./.out/Space-Blaster
```

### Visual Studio (Windows only)

Go to `Scripts` folder and run `Setup-Winddows.bat`

If compilation is succesfull, you can see a `Space-Blaster.sln` file, open that in visual studio,
Now, you can run the game visual studio,
If you want to see .exe file its in `.out` folder
