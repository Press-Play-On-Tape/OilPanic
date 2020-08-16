#include <Arduboy2.h>


// ----------------------------------------------------------------------------
//  Render player indoors ..
//
void renderPlayer_Indoors() {

    Sprites::drawErase(player.getXDisplay(), 28, Images::Player, player.getFrame());

    switch (player.getXPosition()) {

        case XPosition::Position_Tipping_LH:

            if (player.getOilLevel() > 0) {

                Sprites::drawOverwrite(0, 38, Images::Bucket_Tilt_LH, player.getOilLevel() - 1);

            }

            break;

        case XPosition::Position_Tipping_RH:

            if (player.getOilLevel() > 0) {

                Sprites::drawOverwrite(126, 37, Images::Bucket_Tilt_RH, player.getOilLevel() - 1);

            }

            break;

        default:

            if (player.getOilLevel() > 0) {

                Sprites::drawExternalMask(player.getXDisplay() + 1, 37, Images::Bucket, Images::Bucket_Mask, player.getOilLevel() - 1, 0);

            }

            break;

    }            

}


// ----------------------------------------------------------------------------
//  Render player outdoors ..
//
void renderPlayer_Outdoors() {

    switch (player.getXPosition()) {

        case XPosition::Position_Outside_LH:

            if (catcher.isCatching(Direction::Left)) {

                Sprites::drawErase(14, 11, Images::Player_Outside, 1);

            }
            else {

                Sprites::drawErase(14, 11, Images::Player_Outside, 0);

            }

            break;

        case XPosition::Position_Outside_RH:

            if (catcher.isCatching(Direction::Right)) {

                Sprites::drawErase(91, 11, Images::Player_Outside, 3);

            }
            else {

                Sprites::drawErase(91, 11, Images::Player_Outside, 2);

            }

            break;

        default: break;

    }

}


// ----------------------------------------------------------------------------
//  Render player outdoors ..
//
void renderThrowingOil() {

    switch (throwOil) {

        case ThrowOil::LH_Top:
            Sprites::drawErase(13, 31, Images::ThrowOil_LH, 0);
            break;

        case ThrowOil::LH_Middle:
            Sprites::drawErase(12, 35, Images::ThrowOil_LH, 1);
            break;

        case ThrowOil::LH_Bottom:
            Sprites::drawErase(13, 39, Images::ThrowOil_LH, 2);
            break;

        case ThrowOil::RH_Top:
            Sprites::drawErase(112, 31, Images::ThrowOil_RH, 0);
            break;

        case ThrowOil::RH_Middle:
            Sprites::drawErase(113, 35, Images::ThrowOil_RH, 1);
            break;

        case ThrowOil::RH_Bottom:
            Sprites::drawErase(112, 39, Images::ThrowOil_RH, 2);
            break;


        default: break;

    }

}

// ----------------------------------------------------------------------------
//  Render catcher ..
//
void renderCatcher() {

    Sprites::drawErase(catcher.getXDisplay(), 35, Images::Catcher, catcher.getFrame());

}


// ----------------------------------------------------------------------------
//  Render catcher ..
//
void renderCatcherMap() {

    arduboy.drawFastVLine(catcher.getXDisplayMap(), 22, 3, BLACK);

}


// ----------------------------------------------------------------------------
//  Render oil droplets ..
//
void renderOil() {

    for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

        Oil oil = oils.getOil(x); 

        if (oil.getYPosition() != YPosition::None) {

            switch (oil.getYPosition()) {

                case YPosition::StartDrip_00 ... YPosition::StartDrip_01:
                    Sprites::drawOverwrite(oil.getXDisplay(), oil.getYDisplay(), Images::Oil_00, 0);
                    break;

                case YPosition::StartDrip_02 ... YPosition::StartDrip_03:
                    Sprites::drawOverwrite(oil.getXDisplay(), oil.getYDisplay(), Images::Oil_01, 0);
                    break;

                case YPosition::Falling_04 ... YPosition::Fire:
                    Sprites::drawErase(oil.getXDisplay(), oil.getYDisplay(), Images::Oil_02, 0);
                    break;
                
                default: break;

            }
 
        }       

    }

}

// ----------------------------------------------------------------------------
//  Render oil droplets ..
//
void renderScoreboard(GameScene gameScene) {

    uint8_t digits[3] = {};
    extractDigits(digits, score);
    
    for (uint8_t i = 3, x = 1; i > 0; i--, x = x + 4) {

        Sprites::drawErase(x + (gameScene == GameScene::Outdoors ? 0 : 10), gameScene == GameScene::Outdoors ? 1 : 58, Images::Font, digits[i - 1]);

    }

}
