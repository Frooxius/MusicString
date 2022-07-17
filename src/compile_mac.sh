mkdir Mac
rm Mac/*
cp MusicString/*.cpp Mac/
cp MusicString/*.h Mac/
cp MusicStringCompiler/*.cpp Mac/
cp MusicStringCompiler/*.h Mac/
cd Mac
g++ -O3 -o musstr *.cpp