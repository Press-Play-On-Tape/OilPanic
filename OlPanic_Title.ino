#include <Arduboy2.h>

void title() {

    if (counter >= 0) counter++;


    Sprites::drawOverwrite(0, 0, Images::Title, 0);

    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) { 

        gameMode = arduboy.justPressed(A_BUTTON) ? GameMode::Easy : GameMode::Hard;
        gameState = GameState::Instructions_Init;

    }

}
