#include <map>
#include <iostream>

#include "strings.hpp"
#include "lilytools.hpp"

using namespace std;

typedef map<const char, string> CharLily;

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

uint8_t getMidiFromKey(char key)
{
    string lily = getLilyFromChar(key);
    uint8_t midi = getMidiFromLily(lily);
    return(midi);
}
