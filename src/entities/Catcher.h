#pragma once

#include <Arduboy2.h>
#include "../images/Images.h"
#include "../utils/Consts.h"

struct Catcher {

    const int8_t xPositions[13] = { 12, 
                                    18, 24, 31, 
                                    38, 45, 52, 
                                    60, 67, 74, 81, 87, 
                                    93, };

    const int8_t xPositionsMap[13] = { 87, 
                                    88, 90, 91, 
                                    92, 93, 94,
                                    95, 97, 98, 99, 100,
                                    102,  };

    const int8_t frames[2][13] =  { 
                                    { 0,
                                      2, 1, 2, 
                                      1, 2, 1, 
                                      2, 1, 2, 3, 4,
                                      6 },
                                    { 0, 
                                      1, 3, 4, 5, 4, 
                                      5, 4, 5,
                                      4, 5, 4, 
                                      6 }
                                  };

    private:

        Direction direction = Direction::Left;
        uint8_t x = 8;
        uint8_t oilLevel = 0;
        uint8_t turnDelay = 0;

    public:

        uint8_t getX()                              { return this->x; }


        void setX(uint8_t val)                      { this->x = val; }

    public:

        void incXPosition() {

            if (x < 12) {
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

                case Direction::None:

                    this->turnDelay--;

                    if (this->turnDelay == 0) {

                        switch (this->x) {

                            case 0:
                                this->direction = Direction::Right;
                                this->x++;
                                break;

                            case 12:
                                this->direction = Direction::Left;
                                this->x--;
                                break;
                            
                        }

                    }
                    break;

                case Direction::Left:
                    this->x--;
                    if (x == 0) {
                        this->direction = Direction::None;
                        this->turnDelay = random(5, 8);
                    }
                    break;

                case Direction::Right:
                    this->x++;
                    if (x == 12) {
                        this->direction = Direction::None;
                        this->turnDelay = random(5, 8);
                    }
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
                    return x == 0;
                
                case Direction::Right:
                    return x == 12;

                default: break;
                    
            }

        }


};

