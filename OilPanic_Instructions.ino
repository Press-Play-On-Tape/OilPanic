#include <Arduboy2.h>


#define SCENE1_ELEMENT_COUNT 88
#define SCENE1_OFFSET -70
#define SCENE2_OFFSET 70
#define SCENE2_ELEMENT_COUNT 72
#define SCENE3_OFFSET -70
#define SCENE3_ELEMENT_COUNT 56
#define SCENE4_OFFSET 34
#define SCENE4_BORDER 70
#define SCENE4_ELEMENT_COUNT 100
#define SCENE5_DELAY 32

const XPosition PROGMEM scene1_PlayerXPosition[SCENE1_ELEMENT_COUNT] = {         
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_17, XPosition::Position_17, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_17, XPosition::Position_17, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_15_Oil, 
        
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_17, XPosition::Position_17, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_17, XPosition::Position_17, XPosition::Position_16, XPosition::Position_16, 
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_15_Oil, 
        
    XPosition::Position_15_Oil, XPosition::Position_15_Oil, XPosition::Position_14, XPosition::Position_14, 
    XPosition::Position_13, XPosition::Position_13, XPosition::Position_12, XPosition::Position_12, 
    XPosition::Position_11, XPosition::Position_11, XPosition::Position_10_Oil, XPosition::Position_10_Oil, 
    XPosition::Position_9, XPosition::Position_9, XPosition::Position_8, XPosition::Position_8, 
    XPosition::Position_7, XPosition::Position_7, XPosition::Position_7, XPosition::Position_7, 

    XPosition::Position_8, XPosition::Position_8, XPosition::Position_9, XPosition::Position_9, 
    XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_11, XPosition::Position_12, 
    XPosition::Position_13, XPosition::Position_14, XPosition::Position_15_Oil, XPosition::Position_16, 
    XPosition::Position_17, XPosition::Position_18, XPosition::Position_19, XPosition::Position_Tipping_RH, 
    XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, 

    XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, XPosition::Position_Tipping_RH, 
    XPosition::Position_19, XPosition::Position_18, XPosition::Position_17, XPosition::Position_16, 
};

const YPosition PROGMEM scene1_DripYPosition[SCENE1_ELEMENT_COUNT] = { 
    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
    YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00,
    YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01,
    YPosition::Falling_04, YPosition::Falling_05, YPosition::Falling_06, YPosition::Falling_07,
    YPosition::Falling_08, YPosition::Falling_09, YPosition::None, YPosition::None,

    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
    YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00,
    YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01,
    YPosition::Falling_04, YPosition::Falling_05, YPosition::Falling_06, YPosition::Falling_07,
    YPosition::Falling_08, YPosition::Falling_09, YPosition::None, YPosition::None,

    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
    YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00, YPosition::StartDrip_00,
    YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01, YPosition::StartDrip_01,
    YPosition::Falling_04, YPosition::Falling_05, YPosition::Falling_06, YPosition::Falling_07,
    YPosition::Falling_08, YPosition::Falling_09, YPosition::Falling_10, YPosition::Falling_11,

    YPosition::Falling_12, YPosition::Falling_13, YPosition::Fire_00, YPosition::Fire_01, 
    YPosition::Fire_02, YPosition::Fire_03, YPosition::Fire_04, YPosition::Fire_05, 
    YPosition::Fire_06, YPosition::Fire_07, YPosition::None, YPosition::None, 
    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 

    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
    YPosition::None, YPosition::None, YPosition::None, YPosition::None, 
};

const uint8_t PROGMEM scene1_OilLevel[SCENE1_ELEMENT_COUNT] = {         
    0, 0, 0, 0,                                          
    0, 0, 0, 0,                                          
    0, 0, 0, 0,                                          
    0, 0, 0, 0,                                          
    0, 0, 1, 1,

    1, 1, 1, 1,
    1, 1, 1, 1, 
    1, 1, 1, 1, 
    1, 1, 1, 1, 
    1, 1, 2, 2,

    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    0, 0, 0, 0, 
    0, 0, 0, 0, 
};                                          

const uint8_t PROGMEM scene1_Instructions[SCENE1_ELEMENT_COUNT] = {         
    255, 255, 1, 1,                                          
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,

    1, 1, 1, 1,
    1, 1, 1, 1, 
    1, 1, 1, 1, 
    1, 1, 1, 1, 
    255, 255, 2, 2,

    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    2, 2, 255, 255,
    3, 3, 3, 3,
    3, 3, 3, 3,
    3, 3, 3, 3,
    3, 3, 3, 3,

    3, 3, 3, 3,
    3, 3, 3, 3,
};      


const uint8_t PROGMEM scene1_YCursor[3] =   { 21, 17, 12 };                               

const XPosition PROGMEM scene2_PlayerXPosition[SCENE2_ELEMENT_COUNT] = {         
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 

    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, XPosition::Position_Throwing_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 

    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 

    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
    XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, XPosition::Position_Outside_LH, 
};

const Direction PROGMEM scene2_CatcherDirection[SCENE2_ELEMENT_COUNT] = { 
    Direction::Left, Direction::Left, Direction::Left, Direction::Left, 
    Direction::Left, Direction::Left, Direction::Left, Direction::Left, 
    Direction::Left, Direction::Left, Direction::Left, Direction::Left, 
    Direction::Left, Direction::Left, Direction::Left, Direction::Left, 
    Direction::Left, Direction::Left, Direction::Left, Direction::Left, 

    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 

    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 

    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
    Direction::Right, Direction::Right, Direction::Right, Direction::Right, 
};

const uint8_t PROGMEM scene2_CatcherXPosition[SCENE2_ELEMENT_COUNT] = { 
    13, 12, 11, 10, 
    9, 8, 7, 6, 
    5, 4, 3, 2, 
    1, 0, 0, 0, 
    0, 0, 0, 1, 

    2, 3, 4, 5, 
    6, 7, 8, 9, 
    10, 11, 12, 13,
    14, 15, 16, 17, 
    18, 19, 20, 20,

    20, 20, 20, 20, 
    20, 20, 20, 20, 
    20, 20, 20, 20, 
    20, 20, 20, 20, 
    20, 20, 20, 20, 

    20, 20, 20, 20, 
    20, 20, 20, 20, 
    20, 20, 20, 20, 
};

const ThrowOil PROGMEM scene2_OilYPosition[SCENE2_ELEMENT_COUNT] = { 
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::LH_Top, ThrowOil::LH_Middle, ThrowOil::LH_Bottom, ThrowOil::None,
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,

    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::None, ThrowOil::None, ThrowOil::None, ThrowOil::None,
    ThrowOil::LH_Top, ThrowOil::LH_Middle, ThrowOil::LH_Miss_Down_Start, ThrowOil::LH_Miss_Down_01,
    ThrowOil::LH_Miss_Down_02, ThrowOil::LH_Miss_Down_03, ThrowOil::LH_Miss_Down_04, ThrowOil::LH_Miss_Down_05,

    ThrowOil::LH_Miss_Down_06, ThrowOil::LH_Miss_Down_07, ThrowOil::LH_Miss_Down_08, ThrowOil::LH_Miss_Bottom_Start,
    ThrowOil::LH_Miss_Bottom_01, ThrowOil::LH_Miss_Bottom_02, ThrowOil::LH_Miss_Bottom_03, ThrowOil::LH_Miss_Bottom_End_Of_Splash,
    ThrowOil::LH_Miss_Bottom_05, ThrowOil::LH_Miss_Bottom_06, ThrowOil::LH_Miss_Bottom_07, ThrowOil::LH_Miss_Bottom_08,
    ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End,
    ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End, ThrowOil::LH_Miss_Bottom_End,

    ThrowOil::LH_Miss_Up_Start, ThrowOil::LH_Miss_Up_01, ThrowOil::LH_Miss_Up_02, ThrowOil::LH_Miss_Up_03,
    ThrowOil::LH_Miss_Up_04, ThrowOil::LH_Miss_Up_05, ThrowOil::LH_Miss_Up_06, ThrowOil::LH_Miss_Up_07,
    ThrowOil::LH_Miss_Up_08, ThrowOil::LH_Miss_Up_NearlyEnd, ThrowOil::LH_Miss_Up_End, ThrowOil::LH_Miss_Up_End,
};

const uint8_t PROGMEM scene2_YOffset[SCENE2_ELEMENT_COUNT] = { 
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 

    0, 0, 0, 0, 
    0, 0, 0, 0, 
    2, 4, 6, 8, 
    10, 12, 14, 16,
    18, 20, 22, 24, 

    26, 28, 30, 32, 
    34, 36, 38, 38,
    38, 38, 38, 36, 
    34, 32, 30, 28, 
    26, 24, 22, 20,

    18, 16, 14, 12, 
    10, 8, 6, 4, 
    2, 0, 0, 0, 
};

const uint8_t PROGMEM scene2_Instructions[SCENE2_ELEMENT_COUNT] =   {         
    255, 255, 1, 1,                                          
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,

    1, 1, 1, 1,
    1, 1, 1, 1, 
    255, 255, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    2, 2, 2, 2,
    2, 2, 255, 255,
};      

const uint8_t PROGMEM scene2_YCursor[3] =   { 19, 12 };                               

const uint8_t PROGMEM scene3_Instructions[SCENE3_ELEMENT_COUNT] =   {         
    255, 255, 1, 1,                                          
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,

    1, 1, 1, 1, 
    1, 1, 1, 1, 
    255, 255, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,

    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 255, 255,
};      

const uint8_t PROGMEM scene3_YCursor[3] =   { 12, 12 };                               


const uint8_t PROGMEM scene4_YCursor[3] =   { 16, 5 };                               


// ----------------------------------------------------------------------------
//  Initialise game ..
//
void instructions_Init(void) {

    outdoorsYOffset = 0;
    player.setOilLevel(0);
    counter = 0;

}


// ----------------------------------------------------------------------------
//  Render instructions ..
//
void instructions(void) {

    switch (gameState) {

        case GameState::Instructions_Scene1:
            instructions_Scene1();
            break;

        case GameState::Instructions_Scene2:
            instructions_Scene2();
            break;

        case GameState::Instructions_Scene3:
            instructions_Scene3();
            break;

        case GameState::Instructions_Scene4:
            instructions_Scene4();
            break;

        case GameState::Instructions_Scene5:
            instructions_Scene5();
            break;

        default: break;

    }

    if (arduboy.justPressed(A_BUTTON)) {
        gameState = GameState::PlayGame_Init;
    }

}


// ----------------------------------------------------------------------------
//  Render instructions - Scene 1 ..
//
void instructions_Scene1() {

    if (arduboy.isFrameCount(6)) {

        counter++;

        if (counter == SCENE1_ELEMENT_COUNT) {
            counter = 0;
            gameState = GameState::Instructions_Scene2;
        }

    }

    player.setXPosition(static_cast<XPosition>(pgm_read_byte(&scene1_PlayerXPosition[counter])));
    player.setOilLevel(pgm_read_byte(&scene1_OilLevel[counter]));
    oil.setYPosition(static_cast<YPosition>(pgm_read_byte(&scene1_DripYPosition[counter])));
    oil.setX(2);


    Sprites::drawOverwrite(SCENE1_OFFSET, 0, Images::Indoors, 0);
    arduboy.fillRect(SCENE1_OFFSET + 108, 24, 17, 6, WHITE);

    renderPlayer_Indoors(SCENE1_OFFSET);
    renderOil(gameScene, oil, SCENE1_OFFSET, outdoorsYOffset);

    arduboy.drawVerticalDottedLine(0, HEIGHT, SCENE1_OFFSET + 128 + 1, BLACK);
    arduboy.drawVerticalDottedLine(1, HEIGHT, SCENE1_OFFSET + 128 + 2, BLACK);

    font3x5.setCursor(SCENE1_OFFSET + 128 + 6, pgm_read_byte(&scene1_YCursor[pgm_read_byte(&scene1_Instructions[counter]) - 1]));
    font3x5.setTextColor(BLACK);

    switch (pgm_read_byte(&scene1_Instructions[counter])) {

        case 1:
            font3x5.print(F("Catch~the~drops\nbefore~they~hit\nthe~floor."));
            break;

        case 2:
            font3x5.print(F("Failing~to~catch\na~drop~will~start\na~fire~and~cost\nyou~a~life."));
            break;

        case 3:
            font3x5.print(F("Empty~the~bucket\nby~going~outside.\nIt~does~not~need\nto~be~full~for~it\nto~be~emptied."));
            break;

    }

    Sprites::drawOverwrite(62, 58, Images::LeftArrow, 0);
    Sprites::drawOverwrite(123, 58, Images::RightArrow, 0);

    if (arduboy.justPressed(LEFT_BUTTON)) {
        counter = 0;
        gameState = GameState::Title_Init;
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene2;
    }

}


// ----------------------------------------------------------------------------
//  Render instructions - Scene 2 ..
//
void instructions_Scene2() {

    uint8_t frameCount = counter > 32 ? 3 : 6;

    if (arduboy.isFrameCount(frameCount)) {

        counter++;

        if (counter == SCENE2_ELEMENT_COUNT) {
            counter = 0;
            gameState = GameState::Instructions_Scene3;
        }

    }


    for (uint8_t x = 0; x < 13; x++) {

        Sprites::drawOverwrite(SCENE2_OFFSET, 0 - outdoorsYOffset + (x * 8), Images::Outdoors, x);

    }

    player.setXPosition(static_cast<XPosition>(pgm_read_byte(&scene2_PlayerXPosition[counter])));
    catcher.setX(pgm_read_byte(&scene2_CatcherXPosition[counter]));
    catcher.setDirection(static_cast<Direction>(pgm_read_byte(&scene2_CatcherDirection[counter])));
    throwOil = static_cast<ThrowOil>(pgm_read_byte(&scene2_OilYPosition[counter]));
    outdoorsYOffset = pgm_read_byte(&scene2_YOffset[counter]);

    renderPlayer_Outdoors(SCENE2_OFFSET, outdoorsYOffset);
    renderCatcher(SCENE2_OFFSET, outdoorsYOffset);
    renderThrowingOil(SCENE2_OFFSET, outdoorsYOffset);
    renderBystanders(SCENE2_OFFSET, outdoorsYOffset);

    arduboy.drawVerticalDottedLine(0, HEIGHT, SCENE2_OFFSET - 3, BLACK);
    arduboy.drawVerticalDottedLine(1, HEIGHT, SCENE2_OFFSET - 2, BLACK);

    font3x5.setCursor(2, pgm_read_byte(&scene2_YCursor[pgm_read_byte(&scene2_Instructions[counter]) - 1]));

    switch (pgm_read_byte(&scene2_Instructions[counter])) {

        case 1:
            font3x5.print(F("Throw~the~oil~to\nyour~colleague\nto~gain~points."));
            break;

        case 2:
            font3x5.print(F("If~he~fails~to\ncatch~the~oil~it\nwill~fall~on~the\ncustomers~below\nand~cost~a~life."));
            break;

    }

    Sprites::drawOverwrite(1, 58, Images::LeftArrow, 0);
    Sprites::drawOverwrite(62, 58, Images::RightArrow, 0);

    if (arduboy.justPressed(LEFT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene1;
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
        counter =0;
        gameState = GameState::Instructions_Scene3;
    }

}


// ----------------------------------------------------------------------------
//  Render instructions - Scene 3 ..
//
void instructions_Scene3() {

    if (arduboy.isFrameCount(6)) {
        counter++;
        if (counter == SCENE3_ELEMENT_COUNT) {
            counter = 0;
            gameState = GameState::Instructions_Scene4;
        }

    }

    Sprites::drawOverwrite(SCENE3_OFFSET, 0, Images::Indoors, 0);
    arduboy.fillRect(SCENE3_OFFSET +108, 24, 17, 6, WHITE);

    arduboy.drawVerticalDottedLine(0, HEIGHT, SCENE1_OFFSET + 128 + 1, BLACK);
    arduboy.drawVerticalDottedLine(1, HEIGHT, SCENE1_OFFSET + 128 + 2, BLACK);
    renderCatcherMap(SCENE3_OFFSET);

    if (arduboy.isFrameCount(3)) {
        catcher.update(999);
    }

    font3x5.setCursor(SCENE3_OFFSET + 128 + 6, pgm_read_byte(&scene3_YCursor[pgm_read_byte(&scene3_Instructions[counter]) - 1]));
    font3x5.setTextColor(BLACK);

    switch (pgm_read_byte(&scene3_Instructions[counter])) {

        case 1:
            font3x5.print(F("Hanging~on~the\ngarage~wall~is\na~map~that~shows\nyour~colleagues\nposition."));
            break;

        case 2:
            font3x5.print(F("Use~it~when\nyou~are~emptying\nyour~bucket~to\ndecide~which~way\nto~go."));
            break;

    }

    Sprites::drawOverwrite(62, 58, Images::LeftArrow, 0);
    Sprites::drawOverwrite(123, 58, Images::RightArrow, 0);

    if (arduboy.justPressed(LEFT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene2;
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene4;
        outdoorsYOffset = 0;
        catcher.reset();
    }

}


// ----------------------------------------------------------------------------
//  Render instructions - Scene 4 ..
//
void instructions_Scene4() {


    // Create an oil drop ?

    outdoorsYOffset++;
    if (outdoorsYOffset == 80) {
        oil.setX(random(0, 3));
        oil.setYPosition(YPosition::StartDrip_00);
        outdoorsYOffset = 0;
    }

    if (arduboy.isFrameCount(6)) {

        counter++;

        if (counter == SCENE4_ELEMENT_COUNT) {
            counter = SCENE5_DELAY * 4;
            gameState = GameState::Instructions_Scene5;
        }

    }


    for (uint8_t x = 0; x < 8; x++) {

        Sprites::drawOverwrite(SCENE4_OFFSET, (x * 8), Images::Outdoors, x);

    }

    if (!gameOver && arduboy.isFrameCount(4)) {
        catcher.update(100);
        oil.update();
    }

    renderOil(GameScene::Outdoors, oil, SCENE4_OFFSET, 0);
    renderCatcher(SCENE4_OFFSET, 0);

    arduboy.fillRect(0, 0, SCENE4_BORDER, HEIGHT, WHITE);
    arduboy.drawVerticalDottedLine(0, HEIGHT, SCENE4_BORDER - 3, BLACK);
    arduboy.drawVerticalDottedLine(1, HEIGHT, SCENE4_BORDER - 2, BLACK);
    font3x5.setCursor(2, pgm_read_byte(&scene4_YCursor[counter <= 40 ? 0 : 1]));

    switch (counter) {

        case 2 ... 40:
            font3x5.print(F("Likewise~when~you\nare~outside~you\ncan~see~drips~\nforming~inside."));
            break;

        case 43 ... 100:
            font3x5.print(F("Do~not~spend~too\nlong~outside\nwaiting~for~your\ncolleague~as~you\nmay~cause~a\nfire~inside."));
            break;

    }

    Sprites::drawOverwrite(1, 58, Images::LeftArrow, 0);
    Sprites::drawOverwrite(62, 58, Images::RightArrow, 0);

    if (arduboy.justPressed(LEFT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene3;
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
        counter = SCENE5_DELAY * 4;
        gameState = GameState::Instructions_Scene5;
    }

}


// ----------------------------------------------------------------------------
//  Render instructions - Scene 5 ..
//
void instructions_Scene5() {

    counter--;

    Sprites::drawOverwrite(3, 26, Images::Ready, 0);

    if (counter > 3 * SCENE5_DELAY)  Sprites::drawExternalMask(100, 10, Images::Barrel, Images::Barrel_Mask, 0, 0);
    if (counter > 2 * SCENE5_DELAY)  Sprites::drawExternalMask(91, 33, Images::Barrel, Images::Barrel_Mask, 0, 0);
    if (counter > SCENE5_DELAY)  Sprites::drawExternalMask(109, 33, Images::Barrel, Images::Barrel_Mask, 0, 0);

    if  (counter == 0) gameState = GameState::PlayGame_Init;

    Sprites::drawOverwrite(1, 58, Images::LeftArrow, 0);

    if (arduboy.justPressed(LEFT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene4;
        outdoorsYOffset = 0;
        catcher.reset();
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
        counter = 0;
        gameState = GameState::Instructions_Scene4;
    }

}