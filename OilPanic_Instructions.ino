#include <Arduboy2.h>


    #define SCENE1_ELEMENT_COUNT 88

    const XPosition PROGMEM scene1_PlayerXPosition[SCENE1_ELEMENT_COUNT] = { 
        
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_3, XPosition::Position_3, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_3, XPosition::Position_3, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_5_Oil, 
            
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_3, XPosition::Position_3, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_3, XPosition::Position_3, XPosition::Position_4, XPosition::Position_4, 
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_5_Oil, 
            
        XPosition::Position_5_Oil, XPosition::Position_5_Oil, XPosition::Position_6, XPosition::Position_6, 
        XPosition::Position_7, XPosition::Position_7, XPosition::Position_8, XPosition::Position_8, 
        XPosition::Position_9, XPosition::Position_9, XPosition::Position_10_Oil, XPosition::Position_10_Oil, 
        XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, 
        XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, 

        XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_10_Oil, 
        XPosition::Position_10_Oil, XPosition::Position_10_Oil, XPosition::Position_9, XPosition::Position_8, 
        XPosition::Position_7, XPosition::Position_6, XPosition::Position_5_Oil, XPosition::Position_4, 
        XPosition::Position_3, XPosition::Position_3, XPosition::Position_1, XPosition::Position_Tipping_LH, 
        XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, 

        XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, XPosition::Position_Tipping_LH, 
        XPosition::Position_1, XPosition::Position_2, XPosition::Position_3, XPosition::Position_4, 

    };

    const YPosition PROGMEM scene1_DripYPosition[SCENE1_ELEMENT_COUNT] =   { 

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

    const uint8_t PROGMEM scene1_OilLevel[SCENE1_ELEMENT_COUNT] =   { 
        
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

    const uint8_t PROGMEM scene1_Instructions[SCENE1_ELEMENT_COUNT] =   { 
        
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


    const uint8_t PROGMEM scene1_YCursor[3] =   { 22, 18, 16 };                               

    #define SCENE2_ELEMENT_COUNT 72

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

    const uint8_t PROGMEM scene2_YCursor[3] =   { 18, 16 };                               

// ----------------------------------------------------------------------------
//  Initialise game ..
//
void instructions_Init(void) {

    instructionsMode = InstructionsMode::Scene1;
    outdoorsYOffset = 0;
    player.setOilLevel(0);
    counter = 0;

}


// ----------------------------------------------------------------------------
//  Render instructions ..
//
void instructions(void) {

    switch (instructionsMode) {

        case InstructionsMode::Scene1:
            instructions_Scene1();
            if (arduboy.justPressed(A_BUTTON)) {
                instructionsMode = InstructionsMode::Scene2;
                counter = 0;
            }
            break;

        case InstructionsMode::Scene2:
            instructions_Scene2();
//            if (arduboy.justPressed(A_BUTTON)) instructionsMode = InstructionsMode::Scene2;
            break;

    }

}

#define SCENE1_OFFSET -70

void instructions_Scene1() {

    if (arduboy.isFrameCount(8)) {
        counter++;
        if (counter == SCENE1_ELEMENT_COUNT) counter = 0;
    }

    player.setXPosition(static_cast<XPosition>(pgm_read_byte(&scene1_PlayerXPosition[counter])));
    player.setOilLevel(pgm_read_byte(&scene1_OilLevel[counter]));
    oil.setYPosition(static_cast<YPosition>(pgm_read_byte(&scene1_DripYPosition[counter])));
    oil.setX(0);


    Sprites::drawOverwrite(SCENE1_OFFSET, 0, Images::Indoors, 0);
    renderPlayer_Indoors(SCENE1_OFFSET);
    // Sprites::drawExternalMask(player.getXDisplay() + SCENE1_OFFSET, 29, Images::Player, Images::Player_Mask, player.getFrame(), player.getFrame());
    // if (player.getOilLevel() > 0) Sprites::drawErase(player.getXDisplay() + SCENE1_OFFSET + 1, 33, Images::Bucket, player.getOilLevel() - 1);    

    renderOil(oil, SCENE1_OFFSET);

    arduboy.drawVerticalDottedLine(0, HEIGHT, SCENE1_OFFSET - 3, BLACK);
    arduboy.drawVerticalDottedLine(1, HEIGHT, SCENE1_OFFSET - 2, BLACK);

    font3x5.setCursor(2, pgm_read_byte(&scene1_YCursor[pgm_read_byte(&scene1_Instructions[counter]) - 1]));
    font3x5.setTextColor(BLACK);

    switch (pgm_read_byte(&scene1_Instructions[counter])) {

        case 1:
            font3x5.print(F("Catch~the~oil~drips\nbefore they hit\nthe~floor."));
            break;

        case 2:
            font3x5.print(F("Failing~to~catch\na~drop~will~result\nin~a~fire~and~lead\nto~a~loss~of~life."));
            break;

        case 3:
            font3x5.print(F("Empty~your~bucket\nby~going~outside.\nIt~does~not~need~to\nbe~full~for~you~to\nempty~it."));
            break;

    }


}

#define SCENE2_OFFSET 70

void instructions_Scene2() {
Serial.println(counter);

    uint8_t frameCount = counter > 32 ? 4 : 8;

    if (arduboy.isFrameCount(frameCount)) {
        counter++;
        if (counter == SCENE2_ELEMENT_COUNT) counter = 0;
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

        case 3:
            font3x5.print(F("Empty~your~bucket\nby~going~outside.\nIt~does~not~need~to\nbe~full~for~you~to\nempty~it."));
            break;

    }

}
