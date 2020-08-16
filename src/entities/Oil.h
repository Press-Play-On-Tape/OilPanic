#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"

struct Oil {

    const int8_t xDisplay[3] =      { 27, 53, 83 };
    const XPosition xPositions[3] =  { XPosition::Position_5_Oil, XPosition::Position_10_Oil, XPosition::Position_15_Oil };

    const int8_t yPositions[15] = { 7, 7, 7, 7, 11, 15,
                                    19, 23, 27, 31,
                                    35, 39, 43, 47, 51 };
    private:

        uint8_t x = 0;
        YPosition yPosition = YPosition::None;

    public:

        uint8_t getX()                              { return this->x; }
        YPosition getYPosition()                    { return this->yPosition; }

        void setX(uint8_t var)                      { this->x = var; }
        void setYPosition(YPosition var)            { this->yPosition = var; }

        XPosition getXPosition() { 
            
            return this->xPositions[this->x];
            
        }

        void incYPosition() {

            if (yPosition < YPosition::Fire) {
                this->yPosition++;
            }

        }

        uint8_t getXDisplay() {

            return this->xDisplay[x];

        }

        uint8_t getYDisplay() {

            return this->yPositions[static_cast<uint8_t>(this->yPosition)];

        }

        void update() {

            if (yPosition < YPosition::None) {
                this->yPosition++;
            }

        }

};