#pragma once
#include "Exception.h"

namespace MusStr
{
	enum eMusicStringException
	{
		ERR_MUSSTR_CHORD_EMPTY_ARG,
		ERR_MUSSTR_SUB_TOO_MANY_ARGS,
		ERR_MUSSTR_SUB_NOT_FOUND,
		ERR_MUSSTR_LOOP_EMPTY_PART,
		ERR_MUSSTR_LOOP_TOO_MANY_PARTS,
		ERR_MUSSTR_ILLEGAL_SYMBOL,

		INFO_MUSSTR_THREAD_FINISHED

	};

	extern const char *StrMusicString_Exception[];

	class MusicStringException : protected Exception
	{
	public:
		MusicStringException(eMusicStringException exception, std::string append = "") : 
			Exception(StrMusicString_Exception[(uint)exception], (uint)exception)
			{
				if(append.length())
					Append(append);
			}

			eMusicStringException GetCode() { 
				return (eMusicStringException)Exception::GetCode(); }
			const char *GetMsg() { return Exception::GetMsg(); }
	};
}