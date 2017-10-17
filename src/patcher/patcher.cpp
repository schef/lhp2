#include <map>
#include <iostream>
#include <algorithm>

#include "patcher.hpp"

#define TONE_MIDDLE_C 60
#define OCTAVE 12

using namespace std;

typedef map<string, uint8_t> LilyBase;
typedef map<string, uint8_t> LilyOctaves;
typedef map<const char, string> CharLily;

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

CharLily charLily = {
    /* string e */
    { 'z',  "e,"   },
    { 'x',  "f,"   },
    { 'c',  "fis," },
    { 'v',  "g,"   },
    { 'b',  "gis," },
    { 'n',  "a,"   },
    { 'm',  "ais," },
    { ',',  "h,"   },
    { '.',  "c"    },
    { '/',  "cis"  },
    /* string a */
    { 'a',  "a,"   },
    { 's',  "ais," },
    { 'd',  "h,"   },
    { 'f',  "c"    },
    { 'g',  "cis"  },
    { 'h',  "d"    },
    { 'j',  "dis"  },
    { 'k',  "e"    },
    { 'l',  "f"    },
    { ';',  "fis"  },
    { '\'', "g"    },
    /* string a */
    { 'q',  "d"    },
    { 'w',  "dis"  },
    { 'e',  "e"    },
    { 'r',  "f"    },
    { 't',  "fis"  },
    { 'y',  "g"    },
    { 'u',  "gis"  },
    { 'i',  "a"    },
    { 'o',  "ais"  },
    { 'p',  "h"    },
    { '[',  "c'"   },
    { ']',  "cis'" },
    { '\\', "d'"   },
    /* string g */
    { '1',  "g"    },
    { '2',  "gis"  },
    { '3',  "a"    },
    { '4',  "ais"  },
    { '5',  "h"    },
    { '6',  "c'"   },
    { '7',  "cis'" },
    { '8',  "d'"   },
    { '9',  "dis'" },
    { '0',  "e'"   },
    { '-',  "f'"   },
    { '=',  "fis'" },
};

string getLilyFromChar(char key)
{
    return(charLily[key]);
}

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

uint8_t getMidiFromKey(char key)
{
    string lily = getLilyFromChar(key);
    uint8_t octave = getOctaveFromLily(lily);
    uint8_t base = getBaseFromLily(lily);
    uint8_t midi = base + octave;
    return(midi);
}
