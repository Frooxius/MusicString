#include "Compiler.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace MusStr;

int main(int argc, char *argv[])
{
	cout << "MusicString to WAV compiler, v0.2.3a, by Frooxius (http://patreon.com/frooxius)"
		<< endl << "--------------------------------------------" << endl;

	if(argc != 2)
	{
		cout << "Wrong arguments!" << endl
			<< "Usage: musstr input.mstr" << endl;
		return 1;
	}

	// Load the file
	fstream input(argv[1], ios::in);
	if(!input)
	{
		cout << "Error: Can't open the input file!" << endl;
		return 1;
	}

	char temp[1024];
	string musstr;
	// load all contents to the string
	while(!input.eof())
	{
		input.getline(temp, 1024);
		musstr += temp;
	}
	input.close();

	Compiler compiler(musstr, string("out.wav"), 48000, 30*60, 0.95f,
		formatWAV, sampleSINT16, normClipping);

	char *msg;
	while(compiler.Compile(&msg))
		cout << msg << " " << flush;
}