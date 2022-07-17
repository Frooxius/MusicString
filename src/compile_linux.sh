mkdir Linux
rm Linux/*
cp MusicString/*.cpp Linux/
cp MusicString/*.h Linux/
cp MusicStringCompiler/*.cpp Linux/
cp MusicStringCompiler/*.h Linux/
cd Linux
g++ -O3 -o musstr *.cpp