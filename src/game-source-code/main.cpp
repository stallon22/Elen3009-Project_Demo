#include<SFML/Graphics.hpp>
#include "game.h"

int main()
{


    //initialize game object
    game Game;
    //creating a game loop
    while(Game.running()) //while the game is running update and render the game window
    {
        Game.update();
        Game.render();
    }


   return 0;
}
