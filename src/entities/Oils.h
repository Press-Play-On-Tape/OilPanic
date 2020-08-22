#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"
#include "Oil.h"

struct Oils {

    private:

        Oil oils[Constants::number_Of_Oils];

        uint8_t launchDelay = 0;

    public:

        Oil &getOil(uint8_t x)                       { return this->oils[x]; }

        void launchOil(uint16_t score) {

            this->launchDelay--;

            if (this->launchDelay == 0) {

                for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

                    if (oils[x].getYPosition() == YPosition::None) {

                        oils[x].setYPosition(YPosition::StartDrip_00);
                        oils[x].setX(random(0,3));
                        break;

                    }

                }

                this->launchDelay = (score < 240 ? 96 - (score / 10) : 60);

            }

        }

        void update() {

            for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {
                
                oils[x].update();

            }

        }

        void reset() {

            this->launchDelay = 96;

        }

};