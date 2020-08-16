#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"
#include "Oil.h"

struct Oils {

    private:

        Oil oils[Constants::number_Of_Oils];

    public:

        Oil &getOil(uint8_t x)                       { return this->oils[x]; }

        void launchOil(uint8_t xDisplay) {

            for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

                if (oils[x].getYPosition() == YPosition::None) {

                    oils[x].setYPosition(YPosition::StartDrip_00);
                    oils[x].setX(xDisplay);
                    break;

                }

            }

        }

        void update() {

            for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {
                
                oils[x].update();

            }

        }

};