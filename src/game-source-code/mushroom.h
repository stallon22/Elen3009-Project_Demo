#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include<map>
#include<ctime>
struct Position
{
    float x;
    float y;
};

class mushroom
{
public:
    mushroom();
    ~mushroom();
    void render(sf::RenderTarget* target);
    void Mushrooms();
    void cells();

private:
    sf::Sprite mushroomSprite_;
    std::vector<sf::Sprite> mushroomSprites;
    sf::Texture mushroomTexture_;
    float x;
    float y;
    unsigned int maxMushroomNum;

    std::map<int,bool> Cell;
    std::map<int, Position> cellCentre;
    std::vector<Position> mushPositions;
    void initMushroomTexture();
    void initMushroomSprite();
};

#endif // MUSHROOM_H
