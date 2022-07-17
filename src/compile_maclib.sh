mkdir MacLib
rm MacLib/*
cp MusicString/*.cpp MacLib/
cp MusicString/*.h MacLib/
cd MacLib
g++ -O3 -c *.cpp
ar rcs libmstr_mac.a *.o
