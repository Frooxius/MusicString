mkdir LinuxLib
rm LinuxLib/*
cp MusicString/*.cpp LinuxLib/
cp MusicString/*.h LinuxLib/
cd LinuxLib
g++ -O3 -c *.cpp
ar rcs libmstr_linux.a *.o
