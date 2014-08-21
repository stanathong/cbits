/********************************************************
 * Project:			Automated AT
 * Last updated:	17 Jaunary 2011
 * Developer:		Supannee Tanathong
 ********************************************************/

#ifndef _DEFINITION_H_
#define	_DEFINITION_H_


#pragma once
#pragma warning (disable:4786)

#include <algorithm>
#include <vector>
#include <set>
#include <windows.h>

using namespace std;

#define NUMBITS	(32)	// The number of bits per DWORD

/*
 * struct DWORD_BITS
 * This structure is to store DWORD to be used as array of bits.
 * The structure defines 4 DWORD. It limits to maximum of 128 bits.
 */
struct DWORD_BITS
{
	DWORD	dword0 : 32;	// Bit#0 - 31
	DWORD	dword1 : 32;	// Bit#32 - 63
	DWORD	dword2 : 32;	// Bit#64 - 95
	DWORD	dword3 : 32;	// Bit#96 - 127

	DWORD_BITS()
	{
		dword0	= 0x0;
		dword1	= 0x0;
		dword2	= 0x0;
		dword3	= 0x0;
	}

	DWORD_BITS(DWORD d0, DWORD d1, DWORD d2, DWORD d3)
	{
		dword0	= d0;
		dword1	= d1;
		dword2	= d2;
		dword3	= d3;
	}
};

typedef vector< DWORD > VEC_DWORD;	// Vector of DWORD
typedef vector< DWORD_BITS > VEC_DWORD_BITS;	// Vector of array of bits / DWORD_BITS
typedef bitset< NUMBITS >	BITS32;	// A 32-bit bitset


#endif
