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
#include "mushroom.h"
#include "Centipede.h"

class game
{
public:
    game();
    game(float dt);
    ~game();


    //Functions
    const bool running() const;
    void poll_Events();
    void update();
    void render();


private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Clock clock;
    Player* player;
    mushroom* mushroom_;
    Centipede* centipede;
    splashScreen* splash_;

    bool endGame;
    sf::Event event;
    float width;
    float height;
    float dt_;

    void initialize_Variables();
    void initialize_Window();
    void initPlayer();
    void initMushroom();
    void initCentipede();

};

#endif // GAME_H
