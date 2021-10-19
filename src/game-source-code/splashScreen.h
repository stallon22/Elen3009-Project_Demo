#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include<iostream>
#include <SFML/Graphics.hpp>

class splashScreen
{
    public:
        splashScreen();
        ~splashScreen();
        void show(sf::RenderWindow* windowRender);

    private:
        sf::Font splashFont_;
        sf::Texture splashTexture_;
};

#endif // SPLASHSCREEN_H
