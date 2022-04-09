#include "src/utils/Arduboy2Ext.h"
#include <ArduboyTones.h>
#include "src/images/Images.h"
#include "src/utils/Consts.h"
#include "src/utils/EEPROM_Utils.h"
#include "src/entities/Entities.h"
#include "src/sounds/Sounds.h"
#include "src/fonts/Font3x5.h"
#include "src/fonts/Font4x6.h"

Arduboy2Ext arduboy;
#ifdef SOUNDS
ArduboyTones sound(arduboy.audio.enabled);
#endif

Font3x5 font3x5 = Font3x5();
Font4x6 font4x6 = Font4x6();

Player player;
Catcher catcher;
Oils oils;
Oil oil;

GameState gameState = GameState::Splash_Init;
GameScene gameScene = GameScene::Indoors;
ThrowOil throwOil = ThrowOil::None;

int16_t counter = 10;
uint8_t frameRate = 50;
uint16_t score = 0;
uint8_t numberOfLives_Indoors = 3;
uint8_t numberOfLives_Outdoors = 3;
uint8_t outdoorsYOffset = 0;
uint8_t gameOverCounter = 0;
uint8_t ledRedCounter = 0;
uint8_t ledGreenCounter = 0;

bool gameOver = false;
bool newHighScore = false;



// High scores ..

uint8_t winnerIdx = 0;
uint8_t charIdx = 0;
uint8_t clearScores = 0;
uint8_t pressACounter = 0;

SaveEntry entries[EEPROM_Utils::saveEntriesCount];


#ifdef SOUNDS
uint8_t soundCounter = 0;
bool soundsOnOff = arduboy.audio.enabled();
#endif

void setup(void) {

	arduboy.boot();
	arduboy.flashlight();
	arduboy.systemButtons();
	arduboy.initRandomSeed();
	arduboy.setFrameRate(50);
  arduboy.setRGBled(0, 0, 0);

    #ifdef SOUNDS
    arduboy.audio.begin();
    #endif

    EEPROM_Utils::initialiseEEPROM();
	
}

void loop(void) {

	if (!arduboy.nextFrame()) return;

	arduboy.pollButtons();

    switch (gameState) {

        case GameState::Splash_Init:

            splashScreen_Init();
            gameState = GameState::Splash;
            arduboy.setFrameRate(50);
            [[fallthrough]]

        case GameState::Splash:

            splashScreen();
            arduboy.display();
            break;

        case GameState::Title_Init:

            gameState = GameState::Title;
            counter = 0;
            arduboy.setFrameRate(50);
            #ifdef SOUNDS
            sound.tones(Sounds::score);
            #endif
            [[fallthrough]]

        case GameState::Title:

            title();
            arduboy.displayClearToWhite();
            break;

        case GameState::Instructions_Init:

            instructions_Init();
            gameState = GameState::Instructions_Scene1;
            #ifdef SOUNDS
            sound.noTone();
            #endif
            [[fallthrough]]

        case GameState::Instructions_Scene1 ... GameState::Instructions_Scene6:
            instructions();
            arduboy.displayClearToWhite();
            break;

        case GameState::PlayGame_Init:

            playGame_Init();
            #ifdef SOUNDS
            sound.noTone();
            #endif
            [[fallthrough]]

        case GameState::PlayGame:

            playGame();

            if (frameRate != 40 + (score / 8)) {
                frameRate = 40 + (score / 8);
                arduboy.setFrameRate(frameRate);
            }
            arduboy.displayClearToWhite();
            break;

        case GameState::HighScore_Init:

            highScore_Init();
            arduboy.setFrameRate(50);
            #ifdef SOUNDS
            sound.noTone();
            #endif
            [[fallthrough]]

        case GameState::HighScore:

            highScore();
            arduboy.displayClearToWhite();
            break;

    }


}
