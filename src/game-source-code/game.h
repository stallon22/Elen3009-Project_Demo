#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "splashScreen.h"

class game
{
public:
    game();
    ~game();


    //Functions
    const bool running() const;
    void poll_Events();
    void update();
    void render();


private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    Player* player;
    splashScreen* splash_;

    bool endGame;
    sf::Event event;
    float width;
    float height;

    void initialize_Variables();
    void initialize_Window();
    void initPlayer();

};

#endif // GAME_H
