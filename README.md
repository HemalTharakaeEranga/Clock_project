# GTK Install & Run in VScode

1. **Install Msys2**

- https://www.msys2.org/

- $ pacman -S mingw-w64-ucrt-x86_64-gcc

- gcc —version

1. **GTK install**

- https://www.gtk.org/docs/installations/windows/

**Lenovo@DESKTOP-G7U8U0K UCRT64 ~** (this inside use go to C:\msys64 )
$ 

- sudo apk add gtk+3.0-dev

- pacman -Syu //Update the package database and core system packages

- pacman -Syyu //Synchronize and Update Again

- pacman -S mingw-w64-ucrt-x86_64-gcc
- pacman -S mingw-w64-ucrt-x86_64-gtk3
- pacman -S mingw-w64-ucrt-x86_64-pkg-config

- pacman -S mingw-w64-x86_64-toolchain base-devel

- gcc --version
- pkg-config --version

- pacman -S --needed ca-certificates //Reinstall ca-certificates

- pacman -U package1.pkg.tar.zst package2.pkg.tar.zst ... //Install the package(s) using `pacman -U'`

- pkg-config --cflags gtk+-3.0 //Get Compiler Flags for GTK

- pkg-config --cflags gtk+-3.0
- pkg-config --libs gtk+-3.0 //check Compiler Flags

- pacman -Scc //Clean Up and Rebuild

**above all no need to if check gcc version and pkg version all are ready go environment variables get system variables and user variables path fix C:\msys64\mingw64\bin**

1. **VS code**

c/c++ extension get it.

**terminal run code**

**mkdir -p D:/Github_project/C_programming/Clock_project/build/Debug**

**clock_gui.o create file inside Debug** 

- gcc @((pkg-config --cflags gtk+-3.0) -split " ") -o clock_gui clock_gui.c @((pkg-config --libs gtk+-3.0) -split " ")

- ./clock_gui.exe 

**Extra Youtube Refer this links**

https://youtu.be/NYBFShZXSpQ?si=2ITcXZOhCVGgcizT

https://youtu.be/OwQobefF-iE?si=6Le3tkJ7xkDpC6pg

https://youtu.be/fdGOmBahxeY?si=xgFrGfMrViwRGssP

https://youtu.be/OiKvDPN6YCQ?si=HPwZmECdFMUJ4nWW

https://www.youtube.com/live/9HALyLGhnUo?si=ItOUNA8GD0QiKLzX

https://www.youtube.com/live/TyFXwHklg6A?si=z2SY0HsPyWEwX_90

https://youtu.be/YwwS-b5Xf8o?si=h67fLv3CJi_igX9z

https://youtu.be/kNAMgcLaB-0?si=A5W5BVgduVsIJlrE


![Screenshot 2024-06-16 212658](https://github.com/HemalTharakaeEranga/Clock_project/assets/156353444/e037d776-444f-490b-aa92-0f2a60d82374)

