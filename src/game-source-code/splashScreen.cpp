#include "splashScreen.h"
//std::literals::string_literals;

splashScreen::splashScreen()
{
    //ctor
}

splashScreen::~splashScreen()
{
    //dtor
}

void splashScreen::show(sf::RenderWindow* windowRender)
{
    if(!this->splashFont_.loadFromFile("/data/font.ttf"))
    {
        std::cout<<"Error!!, Font file can't be open"<<"/n";
    }
    sf::Text gameGuide;

    gameGuide.setCharacterSize(55);
    gameGuide.setFillColor(sf::Color::Green);
    gameGuide.setStyle(sf::Text::Bold);
    gameGuide.setString("Press Left");
    gameGuide.setPosition(70.f, 100.f);
    /*
    sf::FloatRect rect = title.getLocalBounds();
    title.setOrigin(rect.left + rect.width/2.0f,rect.top + rect.height/2.f);
    title.setPosition(windowRender->getSize().x/2.0f, windowRender->getSize().y/7);*/


   // windowRender->clear();
    //windowRender->draw(gameGuide);
    windowRender->display();

   /* sf::Event event;
    while(1)
    {
        while(windowRender->pollEvent(event))
        {
            if(event.key.code == sf::Keyboard::Enter){return;}
            if(event.type == sf::Event::Closed)
            {
                windowRender->close();
                return;
            }
        }
    }*/
}
