#include <map>
#include <iostream>
#include <algorithm>

#include "lilytools.hpp"

#define TONE_MIDDLE_C 60
#define OCTAVE 12

using namespace std;

typedef map<string, uint8_t> LilyBase;
typedef map<string, uint8_t> LilyOctaves;

LilyOctaves lilyOctaves = {
    { ",,,",  TONE_MIDDLE_C - OCTAVE * 4 },
    { ",,",   TONE_MIDDLE_C - OCTAVE * 3 },
    { ",",    TONE_MIDDLE_C - OCTAVE * 2 },
    { "",     TONE_MIDDLE_C - OCTAVE * 1 },
    { "'",    TONE_MIDDLE_C + OCTAVE * 0 },
    { "''",   TONE_MIDDLE_C + OCTAVE * 1 },
    { "'''",  TONE_MIDDLE_C + OCTAVE * 2 },
    { "''''", TONE_MIDDLE_C + OCTAVE * 3 },
};

LilyBase lilyBase = {
    { "c",   0  },
    { "cis", 1  },
    { "d",   2  },
    { "dis", 3  },
    { "e",   4  },
    { "f",   5  },
    { "fis", 6  },
    { "g",   7  },
    { "gis", 8  },
    { "a",   9  },
    { "ais", 10 },
    { "h",   11 },
};

bool isNotAlnum(char c) {
    return(isalnum(c) == 0);
}

bool isAlnum(char c) {
    return(isalnum(c) != 0);
}

uint8_t getOctaveFromLily(string lily)
{
    lily.erase(remove_if(lily.begin(), lily.end(), isAlnum), lily.end());
    uint8_t octave = lilyOctaves[lily];
    return(octave);
}

uint8_t getBaseFromLily(string lily)
{
    lily.erase(remove_if(lily.begin(), lily.end(), isNotAlnum), lily.end());
    uint8_t base = lilyBase[lily];
    return(base);
}

uint8_t getMidiFromLily(string lily)
{
    uint8_t octave = getOctaveFromLily(lily);
    uint8_t base = getBaseFromLily(lily);
    uint8_t midi = base + octave;
    return(midi);
}
