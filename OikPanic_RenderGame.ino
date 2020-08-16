#include <Arduboy2.h>


// ----------------------------------------------------------------------------
//  Render player ..
//
void renderPlayer() {

    Sprites::drawErase(player.getXDisplay(), 28, Images::Player, player.getFrame());

    switch (player.getXPosition()) {

        case XPosition::Position_Tipping_LH:

            if (player.getOilLevel() > 0) {

                Sprites::drawOverwrite(0, 37, Images::Bucket_Tilt_LH, player.getOilLevel() - 1);

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