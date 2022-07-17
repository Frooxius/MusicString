#pragma once
#include "Utility.h"
#include <string>

// Very basic exception
class Exception
{
	std::string msg;	// the message
	uint code;	// error message code

protected:
	void Append(std::string app)
	{
		msg += app;
	}

public:
	Exception(const char *msg, uint code)
	{
		this->msg = msg;
		this->code = code;
	}

	uint GetCode() { return code; }
	const char *GetMsg() { return msg.c_str(); }
};
