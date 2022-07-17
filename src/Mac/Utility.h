/*
	Some global stuff, that's shared by most files
*/
#pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

typedef unsigned char byte;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;

typedef byte reg8;
typedef ushort reg16;
typedef uint reg32;
typedef ull reg64;

template <typename X> inline X SetBit(X val, uint bit, bool set)
{
	val &= ~(((X)1)<<bit);
	if(set)
		val |= ((X)1)<<bit;
	return val;
}

template <typename X> inline void SetBit(X *val, uint bit, bool set)
{
	*val = SetBit(*val, bit, set);
}

template <typename X> X FromString(std::string str)
{
	X val;
	std::stringstream ss(str);
	ss >> val;
	return val;
}

template <typename X> std::string ToString(X i)
{
    std::stringstream ss;
	ss << i;
	return ss.str();
}

template <typename X> std::string ToStringFixed(X i)
{
    std::stringstream ss;
    ss << std::fixed << i;
    return ss.str();
}

template <typename X> std::string ToStringHEX(X i, int minwidth)
{
    std::stringstream ss;
	ss << std::hex << std::setfill('0') << std::setw(minwidth) << i;
	return ss.str();
}

template <typename X> X FromHEXString(std::string str)
{
	X val;
	std::stringstream ss;
	ss << std::hex << str;
	ss >> val;
	return val;
}

inline std::string substrBetween(std::string *str, int from, int to)
{
	return str->substr(from, to-from);
}

inline std::string substrBetween(std::string str, int from, int to)
{
	return substrBetween(&str, from, to);
}

inline std::string StripSpaces(std::string str)
{
	std::string out;
	for(uint i = 0; i < str.length(); ++i)
		if(!isspace(str[i]))
			out += str[i];
	return out;
}

inline std::string AutoUnit(double val, std::string unit)
{
	std::string str;
	double level = log10(val)-3;
	
	int l, i;
	for(l = -24, i = 0; l < 24; l+=3, i++)
		if(level < l)
			return ToString(val/std::pow(10.0, l)) + " " +
				((l)?(str = "yzafpnum kMGTPEZY"[i]):"") +
				unit;

	return ToString(val);
}

inline float FLOAT(uint data)
{
	union
	{
		float f;
		uint i;
	} convert;
	convert.i = data;
	return convert.f;
}

inline uint UINT(float data)
{
	union
	{
		float f;
		uint i;
	} convert;
	convert.f = data;
	return convert.i;
}

template <typename X> inline X Min(X a, X b)
{
	return (a<b)?a:b;
}

template <typename X> inline X Max(X a, X b)
{
	return (a>b)?a:b;
}

template <typename X> inline X logN(X val, X base)
{
	return log(val)/log(base);
}

template <typename X> inline X rotate(X val, int shift)
{
	if(shift == 0)
		return val;
	if(shift > 0)
	{
		shift %= sizeof(X)*8;	// limit the shift value
		return (val << shift) | (val >> (8*sizeof(X)-shift));
	}
	if(shift < 0)
	{
		shift = -shift;	// negate it
		shift %= sizeof(X)*8;	// limit the shift value
		return (val >> shift) | (val << (8*sizeof(X)-shift));
	}

	// make compiler happy...
	return 0;
}

class reg4
{
	reg8 data;	// uses 16 bit register for storage

public:
	reg4() { data = 0; }

	reg8 operator=(uint newval)
	{
		return data = newval & 0x0FU;	// allow only first 5 bits
	}

	reg8 operator++()
	{
		return *this = ++data;
	}

	reg8 operator++(int bogus)
	{
		reg8 temp = data;
		*this = ++data;
		return temp;
	}

	reg8 operator--()
	{
		return *this = --data;
	}

	reg8 operator--(int bogus)
	{
		reg8 temp = data;
		*this = --data;
		return temp;
	}

	reg8 operator+=(uint val)
	{
		return *this = data + val;
	}

	reg8 operator-=(uint val)
	{
		return *this = data - val;
	}

	operator reg8()
	{
		return data;
	}
};

class reg5
{
	reg16 data;	// uses 16 bit register for storage

public:
	reg5() { data = 0; }
	reg5(uint data) { this->data = data&0x1FU; } 

	reg16 operator=(uint newval)
	{
		return data = newval & 0x1FU;	// allow only first 5 bits
	}

	reg16 operator++()
	{
		return *this = ++data;
	}

	reg16 operator++(int bogus)
	{
		reg16 temp = data;
		*this = ++data;
		return temp;
	}

	reg16 operator--()
	{
		return *this = --data;
	}

	reg16 operator--(int bogus)
	{
		reg16 temp = data;
		*this = --data;
		return temp;
	}

	reg16 operator+=(uint val)
	{
		return *this = data + val;
	}

	reg16 operator-=(uint val)
	{
		return *this = data - val;
	}

	operator reg16()
	{
		return data;
	}
};

class reg24
{
	reg32 data;	// uses 16 bit register for storage

public:
	reg24() { data = 0; }

	reg32 operator=(uint newval)
	{
		return data = newval & 0xFFFFFFU;	// allow only first 5 bits
	}

	reg32 operator++()
	{
		return *this = ++data;
	}

	reg32 operator++(int bogus)
	{
		reg32 temp = data;
		*this = ++data;
		return temp;
	}

	reg32 operator--()
	{
		return *this = --data;
	}

	reg32 operator--(int bogus)
	{
		reg32 temp = data;
		*this = --data;
		return temp;
	}

	reg32 operator+=(uint val)
	{
		return *this = data + val;
	}

	reg32 operator-=(uint val)
	{
		return *this = data - val;
	}

	operator reg32()
	{
		return data;
	}
};

template <typename X> inline bool Bit(X val, byte bit)
{
	return (val >> bit)&1;
}

template <typename X> inline bool Between(X val, X min, X max)
{
	return (val >= min) && (val <= max);
}

const double FZERO = 0.0;
const double FINF = 1.0/FZERO;
const double FNAN = FZERO/FZERO;
const double PI = 3.14159265358979323846264338327950288;	// is this enough precision? x3
const double PI_HALF = PI/2.0;

inline bool isinf(float val)
{
	return val == FINF;
}

inline bool isnan(float val)
{
	return !(val == val);
}