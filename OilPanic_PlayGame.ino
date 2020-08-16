#include <Arduboy2.h>



// ----------------------------------------------------------------------------
//  Initialise game ..
//
void playGame_Init() {

    // lifeReset();

    // arduboy.setFrameRate(50);
    
    // gameState = GameState::PlayGame;
    // frameRate = 50;
    // frameRate = 50;
    // counter = 159;

}


// ----------------------------------------------------------------------------
//  Reset life at start of game and after each death ..
//
void lifeReset() {

    // chair.reset();

    // lionAttacking = Direction::None;
    // lionAttackingIndex = 0;

    // player1.reset(Constants::Player1_Index, Constants::Player1_YPos); 
    // player2.reset(Constants::Player2_Index, Constants::Player2_YPos); 

    // lion1.reset(Direction::Left, YPosition::Level_1, 8, Constants::Lion1_Index);
    // lion2.reset(Direction::Right, YPosition::Level_3, 8, Constants::Lion2_Index);

}


// ----------------------------------------------------------------------------
//  Update game and render ..
//
void playGame(void) {



    // Update catcher ..

    if (arduboy.isFrameCount(8)) {
        catcher.update();
    }


    uint8_t pressedButton = arduboy.justPressedButtons();

    switch (gameScene) {

        case GameScene::Indoors:

            if (arduboy.isFrameCount(6)) {

                oils.update();

            }

            if (arduboy.isFrameCount(96)) {

                oils.launchOil(random(0,3));
                
            }

            if (arduboy.isFrameCount(2)) {

                player.update();

            }



            if (pressedButton & LEFT_BUTTON)               { player.decXPosition(); }
            if (pressedButton & RIGHT_BUTTON)              { player.incXPosition(); }


            // Change scene?

            if (player.getXPosition() == XPosition::Position_Tipping_LH || player.getXPosition() == XPosition::Position_Tipping_RH) {

                gameScene = GameScene::Outdoors;

            }


            // Did we catch some oil ?

            switch (player.getXPosition()) {

                case XPosition::Position_5_Oil:
                case XPosition::Position_10_Oil:
                case XPosition::Position_15_Oil:
                    catchOil(player.getXPosition());
                    break;

                default: break;

            }


            break;

        case GameScene::Outdoors:

            if (pressedButton & LEFT_BUTTON && player.getXPosition() == XPosition::Position_Tipping_RH) { 
                
                gameScene = GameScene::Indoors; 
                player.decXPosition();
                
            }

            if (pressedButton & RIGHT_BUTTON && player.getXPosition() == XPosition::Position_Tipping_LH) { 
                
                gameScene = GameScene::Indoors; 
                player.incXPosition();
                
            }

            break;

    }



    // --------------------------------------------------------------------------
    //  Render the screen ..

    switch (gameScene) {

        case GameScene::Indoors:

            Sprites::drawOverwrite(0, 0, Images::Background, 0);
            renderPlayer();
            renderOil();
            renderCatcherMap();
            break;
            

        case GameScene::Outdoors:
    
            Sprites::drawOverwrite(0, 0, Images::Background, 1);
            renderCatcher();
            break;

    }

}


void catchOil(XPosition xPosition) {

    for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

        Oil &oil = oils.getOil(x); 

        if (oil.getYPosition() != YPosition::None && oil.getXPosition() == xPosition) {

            switch (oil.getYPosition()) {

                case YPosition::Falling_08 ... YPosition::Falling_08:
                    if (player.incOilLevel()) {
                        oil.setYPosition(YPosition::None);
                    }
                    break;

                default: break;
                
            }
 
        }       

    }

}