#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"

struct Player {

    const int8_t xPositions[21] = { 0,  5,  10, 15, 20,
                                    26, 31, 36, 41, 46,
                                    52, 57, 62, 67, 72,
                                    83, 88, 93, 98, 103, 
                                    104 };

    const int8_t xEndPoints[21] = {  1,  0,  0,  0,  0,
                                     1,  0,  0,  0,  0,
                                     1,  0,  0,  0,  0,
                                     1,  0,  0,  0,  0,
                                     1 };

    const int8_t frames[21] =     { 2, 0, 1, 0, 1,
                                    0, 1, 0, 1, 0,
                                    1, 0, 1, 0, 1,
                                    0, 1, 0, 1, 0,
                                    3 };


    private:

        Direction direction = Direction::None;
        XPosition xPosition = XPosition::Position_10_Oil;

    public:

        XPosition getXPosition()                    { return this->xPosition; }


        void setXPosition(XPosition val)            { this->xPosition = val; }

    public:

        void incXPosition() {

            if (this->xEndPoints[static_cast<uint8_t>(this->xPosition)] == 1 && xPosition < XPosition::Position_Tipping_RH) {
                this->direction = Direction::Right;
                this->xPosition++;
            }

        }

        void decXPosition() {

            if (this->xEndPoints[static_cast<uint8_t>(this->xPosition)] == 1 && xPosition > XPosition::Position_Tipping_LH) {
                this->direction = Direction::Left;
                this->xPosition--;
            }

        }

        void update() {

            switch (this->direction) {

                case Direction::Left:
                    this->xPosition--;
                    break;

                case Direction::Right:
                    this->xPosition++;
                    break;

            }
Serial.println(static_cast<uint8_t>(this->xPosition));
            if (this->xEndPoints[static_cast<uint8_t>(this->xPosition)] == 1) {
                this->direction = Direction::None;
            }

        }

        int8_t getXDisplay() {

            return this->xPositions[static_cast<uint8_t>(this->xPosition)];

        }

        uint8_t getFrame() {

            return this->frames[static_cast<uint8_t>(this->xPosition)];

        }


};

