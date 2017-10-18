#ifndef _lilytools_h
#define _lilytools_h

#include <string>

std::string getLilyFromChar(char key);
uint8_t getOctaveFromLily(std::string lily);
uint8_t getBaseFromLily(std::string lily);
uint8_t getMidiFromLily(std::string lily);

#endif
