#include <map>
#include <iostream>

#include "strings.hpp"
#include "lilytools.hpp"

using namespace std;

typedef map<uint8_t, string> StringFirstTone;
typedef map<uint8_t, map<uint8_t, bool>> ToneState;

StringFirstTone stringFirstTone = {
	{ 1,  "e," },
	{ 2,  "a," },
	{ 3,  "d"  },
	{ 4,  "g"  },
};

ToneState toneStateStringOne = {
	{ 1, {
		{ 0, false },
		{ 1, false },
		{ 2, false },
		{ 3, false },
		{ 4, false },
	     },
	},
	{ 2, {
		{ 0, false },
		{ 1, false },
		{ 2, false },
		{ 3, false },
		{ 4, false },
	     },
	},
};
