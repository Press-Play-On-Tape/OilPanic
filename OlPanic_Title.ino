#include <Arduboy2.h>

void title() {

    counter++;

    Sprites::drawOverwrite(0, 0, Images::Title, 0);

    switch (counter) {

        case 60 ... 63:
            Sprites::drawOverwrite(80, 18, Images::Title_Eyes, 0);
            break;

        case 64 ... 67:
            Sprites::drawOverwrite(80, 18, Images::Title_Eyes, 1);
            break;

        case 68 ... 71:
            Sprites::drawOverwrite(80, 18, Images::Title_Eyes, 2);
            break;


        case 120:
            counter = 0;
            break;
    }

    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(RIGHT_BUTTON)) { 

        gameState = GameState::Instructions_Init;

    }

    if (arduboy.justPressed(B_BUTTON)) { 

        score = 0;
        gameState = GameState::HighScore_Init;

    }

}
