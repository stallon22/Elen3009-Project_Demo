#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<iostream>

class Player
{
public:
    Player(); //player with default location at (0,0)
    ~Player();
    void update(const sf::RenderTarget* target);
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);//change
    void update_Input();
    void move_player(float delX, float delY);



private:
    sf::Texture  texture;
    sf::Sprite sprite;
    float xdir;
    float ydir;
    void initialize_Variables();
    void initialize_Shape();
    void initTexture();
    void initSprite();
    float movementSpeed;

};

#endif // PLAYER_H
