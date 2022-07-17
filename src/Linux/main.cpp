#include "MStr2Audio.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace MusStr;

struct wavfile
{
    char        id[4];          // should always contain "RIFF"
    int     totallength;    // total file length minus 8
    char        wavefmt[8];     // should be "WAVEfmt "
    int     format;         // 16 for PCM format
    short     pcm;            // 1 for PCM format
    short     channels;       // channels
    int     frequency;      // sampling frequency
    int     bytes_per_second;
    short     bytes_by_capture;
    short     bits_per_sample;
    char        data[4];        // should always contain "data"
    int     bytes_in_data;
};

int main(int argc, char *argv[])
{
	cout << "MusicString to WAV compiler, v0.2.1a, by Frooxius (http://frooxius.solirax.org)"
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

	float *buf = new float[48000*60*30];

	cout << "Parsing... ";
	cout.flush();
	MStr2Audio gen = MStr2Audio(musstr, 48000);
	cout << "Generating... ";
	cout.flush();

	int num;
	try
	{
		num = gen.Generate(buf, 48000*60*30);
	}
	catch(MusicStringException e)
	{
		cout << "ERROR!" << e.GetMsg();
		return 1;
	}

	string name = string(argv[1]).substr(
		0, string(argv[1]).find_last_of('.')) + ".wav";

	cout << "Saving... ";
	cout.flush();
	short *pcmbuf = new short[48000*60*30];
	for(int i = 0; i < 48000*60*30; ++i)
		*(pcmbuf+i) = (short) ((*(buf+i))*0x7FFF);
	fstream file(name.c_str(), std::ios::out | std::ios::binary);

	// wav header
	wavfile header;
	header.bits_per_sample = sizeof(short)*8;
	header.bytes_by_capture = sizeof(short);
	header.bytes_in_data = num*sizeof(short);
	header.bytes_per_second = 48000*sizeof(short);
	header.channels = 1;
	header.data[0] = 'd';
	header.data[1] = 'a';
	header.data[2] = 't';
	header.data[3] = 'a';
	header.format = 16;
	header.frequency = 48000;
	header.id[0] = 'R';
	header.id[1] = 'I';
	header.id[2] = 'F';
	header.id[3] = 'F';
	header.pcm = 1;
	header.totallength = num*sizeof(short)+sizeof(header)-8;
	for(int i = 0; i < 8; ++i)
		header.wavefmt[i] = "WAVEfmt "[i];

	file.write((char *)&header, sizeof(header));
	file.write((char *)pcmbuf, sizeof(short)*num);

	file.close();

	cout << "Done! Happy listening! >:3" << endl;
}