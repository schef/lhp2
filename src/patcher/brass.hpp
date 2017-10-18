#ifndef _brass_hpp
#define _brass_hpp

uint8_t getLipPosition(void);
void setLipPosition(uint8_t position, bool state);
uint8_t getFingerPosition(void);
void setFingerPosition(uint8_t position, bool state);
void setBrassKey(char key, bool state);
uint8_t getMidiFromBrass(void);
void resetBrassPositions(void);

#endif
