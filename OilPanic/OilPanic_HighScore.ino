#include <Arduboy2.h>


#define HS_NAME_LEFT 81
#define HS_SCORE_LEFT HS_NAME_LEFT + 24
#define HS_CHAR_TOP 22
#define HS_CHAR_V_SPACING 8
#define HS_PRESS_A_DELAY 100
#define FLASH_FRAME_COUNT 40


// ----------------------------------------------------------------------------
//  High Score init ..
//
void highScore_Init(void) {

    charIdx = 0;
    clearScores = 0;
    pressACounter = HS_PRESS_A_DELAY;
    winnerIdx = (score > 0 ? EEPROM_Utils::saveScore(score) : Constants::no_Winner);
    gameState = GameState::HighScore;

    arduboy.clearButtonState();
    arduboy.setRGBled(GREEN_LED, 0);
    arduboy.setRGBled(RED_LED, 0);


    // Retrieve existing names and scores ..

    EEPROM_Utils::readSaveEntries(entries);
    font4x6.setTextColor(BLACK);

}


// ----------------------------------------------------------------------------
//  High Score ..
//
void highScore(void) {


    auto justPressed = arduboy.justPressedButtons();
    auto pressed = arduboy.pressedButtons();


    // Is the new score a high score ?

    if (winnerIdx < Constants::no_Winner) {

        if (arduboy.everyXFrames(4)) {
                
            char * player = entries[winnerIdx].name;

            if (pressed & UP_BUTTON) {

                player[charIdx]++;
                if (player[charIdx] > 90)  player[charIdx] = 65;
                if (player[charIdx] == 64) player[charIdx] = 65;

            }

            if (pressed & DOWN_BUTTON) {

                player[charIdx]--;
                if (player[charIdx] < 65)  player[charIdx] = 90;

            }

            if (pressed & LEFT_BUTTON && charIdx > 0) {
                charIdx--;
            }

            if (pressed & RIGHT_BUTTON && charIdx < 2) {
                charIdx++;
            }

            if (pressed & A_BUTTON) {

                if (player[0] != 63 && player[1] != 63 && player[2] != 63) {

                    for (uint8_t i = 0; i < 3; i++) {
                        EEPROM_Utils::saveChar(winnerIdx, i, player[i]);
                    }

                    winnerIdx = Constants::no_Winner;
                    pressACounter = HS_PRESS_A_DELAY;

                }

            }

        }   

    }
    else {


        // Handle other input ..

        if ((justPressed & A_BUTTON || justPressed & B_BUTTON) && pressACounter == 0) {

            gameState = GameState::Title_Init;

        }

    }


    // Clear scores ..

    if ((pressed & LEFT_BUTTON) && (pressed & RIGHT_BUTTON)) {

        clearScores++;

        switch (clearScores) {

            case 21 ... 60:

                arduboy.setRGBled(128 - (clearScores * 2), 0, 0);
                break;

            case 61:

                clearScores = 0;
                arduboy.setRGBled(0, 0, 0);
                EEPROM_Utils::clearEEPROM();
                EEPROM_Utils::readSaveEntries(entries);

                break;

        }

    }
    else {

        if (clearScores > 0) {

            arduboy.setRGBled(0, 0, 0);
            clearScores = 0;

        }

    }


    // Decrement the 'Press A' counter if it has been set ..

    if (pressACounter > 0) pressACounter--;



    // Render screen -------------------------------------------------------------------------


    const bool flash = arduboy.getFrameCountHalf(FLASH_FRAME_COUNT);

    Sprites::drawOverwrite(0, 0, Images::HighScores, 0);


    // Render scores ..

    for (uint8_t index = 0; index < EEPROM_Utils::saveEntriesCount; ++index) {

        renderHighScore(HS_CHAR_TOP + (HS_CHAR_V_SPACING * index), entries[index]);

    }


    // Render edit field if the slot is being editted ..

    if (winnerIdx < Constants::no_Winner && flash) {

        char *player = entries[winnerIdx].name;

        arduboy.fillRect(HS_NAME_LEFT + (charIdx * 6) - 1, HS_CHAR_TOP + (winnerIdx * HS_CHAR_V_SPACING), 6, 8, BLACK);
        font4x6.setCursor(HS_NAME_LEFT + (charIdx * 6), HS_CHAR_TOP + (HS_CHAR_V_SPACING * winnerIdx));
        font4x6.print(player[charIdx] == 63 ? ' ' : player[charIdx]);

    }


    // Display Press A message?

    if (winnerIdx == Constants::no_Winner && pressACounter == 0) {

        font4x6.setCursor(HS_NAME_LEFT + 3, 51);
        font4x6.print("Press");
        Sprites::drawOverwrite(HS_NAME_LEFT + 33, 50, Images::PressA, 0);

    }

}



void renderHighScore(uint8_t y, const SaveEntry & saveEntry) {

    for (uint8_t i = 0; i < 3; i++) {
        font4x6.setCursor(HS_NAME_LEFT  + (i * 6) , y);
        font4x6.print(saveEntry.name[i]);
    }


    uint8_t digits[4] = {};
    extractDigits(digits, saveEntry.score);

    for (uint8_t j = 4, x2 = HS_SCORE_LEFT; j > 0; --j, x2 += 5) {

        font4x6.setCursor(x2, y);
        font4x6.print(digits[j - 1]);

    }

}