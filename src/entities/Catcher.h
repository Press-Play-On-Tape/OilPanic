#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"

struct Catcher {

    const int8_t xPositions[23] = { 12, 12, 12, 12, 12, 12, 
                                    18, 24, 31, 
                                    38, 45, 52, 
                                    60, 67, 74, 81, 87, 
                                    93, 93, 93, 93, 93, 93 };

    const int8_t xPositionsMap[23] = { 87, 87, 87, 87, 87, 87,
                                    88, 90, 91, 
                                    92, 93, 94,
                                    95, 96, 97, 98, 99,
                                    101, 102, 102, 102, 102, 102, };

    const int8_t frames[2][23] =  { 
                                    { 0, 0, 0, 0, 0, 0,
                                      2, 1, 2, 
                                      1, 2, 1, 
                                      2, 1, 2, 3, 4,
                                      6, 6, 6, 6, 6, 6 },
                                    { 0, 0, 0, 0, 0, 0, 
                                      1, 3, 4, 5, 4, 
                                      5, 4, 5,
                                      4, 5, 4, 
                                      6, 6, 6, 6, 6, 6 }
                                  };

    private:

        Direction direction = Direction::Left;
        uint8_t x = 8;
        uint8_t oilLevel = 0;

    public:

        uint8_t getX()                              { return this->x; }


        void setX(uint8_t val)                      { this->x = val; }

    public:

        void incXPosition() {

            if (x < 22) {
                this->direction = Direction::Right;
                this->x++;
            }

        }

        void decXPosition() {

            if (x > 0) {
                this->direction = Direction::Left;
                this->x--;
            }

        }

        void update() {

            switch (this->direction) {

                case Direction::Left:
                    this->x--;
                    if (x == 0) this->direction = Direction::Right;
                    break;

                case Direction::Right:
                    this->x++;
                    if (x == 22) this->direction = Direction::Left;
                    break;

                default: break;

            }

        }

        int8_t getXDisplay() {

            return this->xPositions[x];

        }

        int8_t getXDisplayMap() {

            return this->xPositionsMap[x];

        }

        uint8_t getFrame() {

            return this->frames[this->direction == Direction::Right][x];

        }

        bool isCatching(Direction direction) {

            switch (direction) {
                
                case Direction::Left:
                    return x <= 5;
                
                case Direction::Right:
                    return x >= 17;

                default: break;
                    
            }

        }


};

