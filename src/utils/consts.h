#include <Arduboy2.h>

#pragma once

#define _SOUNDS

enum class ThrowOil : uint8_t {

    LH_Top,
    LH_Middle,
    LH_Bottom,
    RH_Top,
    RH_Middle,
    RH_Bottom,
    None    

};

enum class GameState : uint8_t {

    Splash_Init,
    Splash,
    Title_Init,
    Title,
    PlayGame_Init,
    PlayGame

};

enum class GameScene : uint8_t {

    Indoors,
    Outdoors,

};

enum class GameMode : uint8_t {

    Easy,
    Hard,

};

enum class Direction : uint8_t {

    Left,
    Right,
    Up,
    Down,
    None

};

enum class XPosition : uint8_t {

    Position_Outside_LH,
    Position_Tipping_LH,
    Position_1,
    Position_2,
    Position_3,
    Position_4,
    Position_5_Oil,
    Position_6,
    Position_7,
    Position_8,
    Position_9,
    Position_10_Oil,
    Position_11,
    Position_12,
    Position_13,
    Position_14,
    Position_15_Oil,
    Position_16,
    Position_17,
    Position_18,
    Position_19,
    Position_Tipping_RH,
    Position_Outside_RH,

};

enum class YPosition : uint8_t {

    StartDrip_00,
    StartDrip_01,
    StartDrip_02,
    StartDrip_03,
    Falling_04,
    Falling_05,
    Falling_06,
    Falling_07,
    Falling_08,
    Falling_09,
    Falling_10,
    Falling_11,
    Falling_12,
    Falling_13,
    Fire,
    None,

};

inline XPosition &operator++(XPosition &c ) {
    c = static_cast<XPosition>( static_cast<uint8_t>(c) + 1 );
    return c;
}

inline XPosition operator++(XPosition &c, int ) {
    XPosition result = c;
    ++c;
    return result;
}

inline XPosition &operator--(XPosition &c ) {
    c = static_cast<XPosition>( static_cast<uint8_t>(c) - 1 );
    return c;
}

inline XPosition operator--(XPosition &c, int ) {
    XPosition result = c;
    --c;
    return result;
}

inline YPosition &operator++(YPosition &c ) {
    c = static_cast<YPosition>( static_cast<uint8_t>(c) + 1 );
    return c;
}

inline YPosition operator++(YPosition &c, int ) {
    YPosition result = c;
    ++c;
    return result;
}

inline YPosition &operator--(YPosition &c ) {
    c = static_cast<YPosition>( static_cast<uint8_t>(c) - 1 );
    return c;
}

inline YPosition operator--(YPosition &c, int ) {
    YPosition result = c;
    --c;
    return result;
}


// ---------------------------------------------------------------------------------
// Extract individual digits of a uint16_t
//
template< size_t size >
void extractDigits(uint8_t (&buffer)[size], uint16_t value) {

    for(uint8_t i = 0; i < size; ++i) {
        buffer[i] = value % 10;
        value /= 10;
    }

}

namespace Constants {

    constexpr uint8_t number_Of_Oils = 6;
 
}