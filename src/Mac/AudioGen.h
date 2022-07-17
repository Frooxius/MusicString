#include <string>
#include <list>
#include "Utility.h"
#include "Generator.h"
#include "MusicString.h"

using namespace std;

namespace MusStr
{
	class AudioGen
	{
		struct GenItem
		{
			Generator *gen;
			bool active;
			GenItem(Generator *gen) { this->gen = gen; active = true; }
		};

		list<MusListItem> muslist;
		list<GenItem> generators;
		uint sampleRate,
			 bufsize;

		float *intern_buffer;
		uint intern_buf_pos;
		uint next_update;
		uint warning_items;

		bool UpdateWarningItems();

		bool LoadNextItem();

		bool FillInternBuff();

	public:
		AudioGen(uint sampleRate, uint bufsize = 512);

		bool Append(list<string> *appendlist, bool autodelete = false);
		bool Append(list<MusListItem> *appendlist, bool autodelete = false);
		
		uint Generate(float *buffer, uint samples, bool finalize = false);

		list<Tone> GetActiveTones();

		bool NeedList() { return UpdateWarningItems(); }
	};
}