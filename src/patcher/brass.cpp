#include <map>
#include <iostream>

#include "brass.hpp"
#include "lilytools.hpp"

using namespace std;

typedef map<uint8_t, bool> Position;
typedef map<uint8_t, string> Aliquotes;
typedef map<uint8_t, uint8_t> Fingering;
typedef map<const char, uint8_t> Keyboard;

Position lipPosition = {
	{ 1, false },
	{ 2, false },
	{ 3, false },
	{ 4, false },
	{ 5, false },
	{ 6, false },
	{ 7, false },
};

Position fingerPosition = {
	{ 1, false },
	{ 2, false },
	{ 3, false },
	{ 4, false },
};

Aliquotes aliquotes = {
	{ 1, "b,," },
	{ 2, "f,," },
	{ 3, "b,"  },
	{ 4, "d,"  },
	{ 5, "f,"  },
	{ 6, "as," },
	{ 7, "b"   },
};

Fingering fingering = {
	{ 1, 2 },
	{ 2, 1 },
	{ 3, 3 },
	{ 4, 5 },
};

Keyboard fingerKeyboard = {
	{ '`', 1 },
	{ '1', 2 },
	{ '2', 3 },
	{ '3', 4 },
	{ '4', 5 },
	{ '5', 6 },
	{ '6', 7 },
};

Keyboard lipKeyboard = {
	{ 'm', 1 },
	{ ',', 2 },
	{ '.', 3 },
	{ '/', 4 },
};

uint8_t getLipPosition(void)
{
	uint8_t position = 0;
	for(auto const &ent : lipPosition)
	{
		if(ent.second)
		{
			position = ent.first;
		}
	}
	return(position);
}

void setLipPosition(uint8_t position, bool state)
{
	lipPosition[position] = state;
}

uint8_t getFingerPosition(void)
{
	uint8_t position = 0;
	for(auto const &ent : fingerPosition)
	{
		if(ent.second)
		{
			position += fingering[ent.first];
		}
	}
	return(position);
}

void setFingerPosition(uint8_t position, bool state)
{
	fingerPosition[position] = state;
}

string getLilyFromAliquotes(uint8_t lipPosition)
{
	string lily = aliquotes[lipPosition];
	return(lily);
}

void setBrassFingerKey(char key, bool state)
{
	for(auto const &ent : lipKeyboard)
	{
		if(ent.first == key)
		{
			lipPosition[ent.second] = state;
		}
	}
}

void setBrassLipKey(char key, bool state)
{
	for(auto const &ent : fingerKeyboard)
	{
		if(ent.first == key)
		{
			fingerPosition[ent.second] = state;
		}
	}
}

void setBrassKey(char key, bool state)
{
	setBrassFingerKey(key, state);
	setBrassLipKey(key, state);
}

uint8_t getMidiFromBrass(void)
{
	uint8_t lipPosition = getLipPosition();
	if (lipPosition == 0) return(0);

	uint8_t midi = getMidiFromLily(getLilyFromAliquotes(lipPosition)) - getFingerPosition();
	return(midi);
}

void resetBrassPositions(void)
{
	for (Position::iterator it=fingerPosition.begin(); it!=fingerPosition.end(); ++it)
	{
		it->second = false;
	}
	for (Position::iterator it=lipPosition.begin(); it!=lipPosition.end(); ++it)
	{
		it->second = false;
	}
}
