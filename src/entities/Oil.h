#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"

struct Oil {

    private:

        uint8_t x = 0;
        YPosition yPosition = YPosition::None;

    public:

        uint8_t getXDisplay()                       { return this->x; }
        YPosition getYPosition()                    { return this->yPosition; }

        void setYPosition(YPosition var)            { this->yPosition = var; }


        void incYPosition() {

            if (yPosition < YPosition::Fire) {
                this->yPosition++;
            }

        }

};