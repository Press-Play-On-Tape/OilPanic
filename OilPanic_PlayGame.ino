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



    // Update entity positions ..

    if (arduboy.isFrameCount(8)) {
        
        catcher.update();

        switch (throwOil) {

            case ThrowOil::LH_Top:
                throwOil = ThrowOil::LH_Middle;
                break;

            case ThrowOil::LH_Middle:
                throwOil = ThrowOil::LH_Bottom;
                break;
                
            case ThrowOil::LH_Bottom:
                throwOil = ThrowOil::None;
                break;

            case ThrowOil::RH_Top:
                throwOil = ThrowOil::RH_Middle;
                break;

            case ThrowOil::RH_Middle:
                throwOil = ThrowOil::RH_Bottom;
                break;
                
            case ThrowOil::RH_Bottom:
                throwOil = ThrowOil::None;
                break;

        }

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

            if (player.getXPosition() == XPosition::Position_Outside_LH || player.getXPosition() == XPosition::Position_Outside_RH) {

                gameScene = GameScene::Outdoors;
                throwOil = ThrowOil::None;

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

            if (pressedButton & LEFT_BUTTON && player.getXPosition() == XPosition::Position_Outside_RH) { 
                
                gameScene = GameScene::Indoors; 
                player.decXPosition();
                
            }

            if (pressedButton & RIGHT_BUTTON && player.getXPosition() == XPosition::Position_Outside_LH) { 
                
                gameScene = GameScene::Indoors; 
                player.incXPosition();
                
            }


            // Are we about to throw the oil?

            switch (player.getXPosition()) {

                case XPosition::Position_Outside_LH:

                    if (catcher.isCatching(Direction::Left) && player.getOilLevel() > 0) {
Serial.print(score);
Serial.print(" + ");
Serial.print(player.getOilLevel());

                        score = score + player.getOilLevel();
Serial.print(" = ");
Serial.println(score);
                        player.setOilLevel(0);
                        if (throwOil == ThrowOil::None) throwOil = ThrowOil::LH_Top;

                    }

                    break;

                case XPosition::Position_Outside_RH:

                    if (catcher.isCatching(Direction::Right) && player.getOilLevel() > 0) {
Serial.println(score);

                        score = score + player.getOilLevel();
                        player.setOilLevel(0);
                        if (throwOil == ThrowOil::None) throwOil = ThrowOil::RH_Top;

                    }

                    break;

                default: break;

            }


            break;

    }



    // --------------------------------------------------------------------------
    //  Render the screen ..

    switch (gameScene) {

        case GameScene::Indoors:

            Sprites::drawOverwrite(0, 0, Images::Indoors, 0);
            renderPlayer_Indoors();
            renderOil();
            renderCatcherMap();
            break;
            

        case GameScene::Outdoors:
    
            for (uint8_t x = 0; x < 12; x++) {

                Sprites::drawOverwrite(0, 0 - outdoorsYOffset + (x * 8), Images::Outdoors, x);

            }

            renderPlayer_Outdoors();
            renderThrowingOil();
            renderCatcher();
            break;

    }

    renderScoreboard(gameScene);

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