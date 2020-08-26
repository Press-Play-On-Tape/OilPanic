#pragma once

#include "Arduboy2Ext.h"
#include "consts.h"

#define EEPROM_START                  EEPROM_STORAGE_SPACE_START + 190
#define EEPROM_START_C1               EEPROM_START
#define EEPROM_START_C2               EEPROM_START + 1
#define EEPROM_SCORE                  EEPROM_START_C2 + 1

class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void initEEPROM();
    static uint16_t getScore();
    static void saveScore(uint16_t score);
    static bool toggleSoundSettings(Arduboy2Ext &arduboy);

};


/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised?
 *
 *   Looks for the characters 'O' and 'P' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */

const uint8_t letter1 = 'O'; 
const uint8_t letter2 = 'P'; 

void EEPROM_Utils::initEEPROM() {

    byte c1 = EEPROM.read(EEPROM_START_C1);
    byte c2 = EEPROM.read(EEPROM_START_C2);

    if (c1 != letter1 || c2 != letter2) { 

        uint16_t score = 0;

        EEPROM.put(EEPROM_START_C1, letter1);
        EEPROM.put(EEPROM_START_C2, letter2);
        EEPROM.put(EEPROM_SCORE, score);

    }

}


/* -----------------------------------------------------------------------------
 *   Get slot details. 
 */
uint16_t EEPROM_Utils::getScore() {

    uint16_t score = 0;
    EEPROM.get(EEPROM_SCORE, score);
    return score;

}


/* -----------------------------------------------------------------------------
 *   Save score ..
 */
void EEPROM_Utils::saveScore(uint16_t score) {

    uint16_t oldScore = 0;
    EEPROM.get(EEPROM_SCORE, oldScore);

    if (oldScore < score) {

        EEPROM.update(EEPROM_SCORE, score);

    }

}


/* ----------------------------------------------------------------------------
 *  Toggle the sound setting and commit to the EEPROM.
 */
bool EEPROM_Utils::toggleSoundSettings(Arduboy2Ext &arduboy) {

    if (arduboy.audio.enabled()) {

        arduboy.audio.off(); 
        arduboy.audio.saveOnOff();
        return false;

    }
    else {

        arduboy.audio.on(); 
        arduboy.audio.saveOnOff();
        return true;

    }
    
}