#include "game.h"
#include "mushroom.h"




game::game()
{
    //ctor
    this->initialize_Variables();
    this->initialize_Window();
    this->initPlayer();
    this->initMushroom();
    this->initCentipede();

}

game::game(float dt)
{
    this->dt_ =  dt;

}
game::~game()
{
    //dtor
    delete this->window;
    delete this->player;
    delete this->mushroom_;
    delete this->centipede;
}

void game::initPlayer()
{

    this->player = new Player();
}

void game::initMushroom()
{
  this->mushroom_ = new mushroom();
}

void game::initCentipede()
{
    this->centipede = new Centipede();
}

void game::initialize_Variables()
{
    this->endGame = false; //while the game is still running
}

//initialising window
void game::initialize_Window()
{
    this->videoMode =sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "Centipede", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60); //running frames per second
    this->window->setVerticalSyncEnabled(false);

}

//functions
//To check if the game window is open
const bool game::running() const
{
    return this->window->isOpen();
}

//The events passed by a user(when pressing a certain button, take action
void game::poll_Events()
{
    dt_ = clock.restart().asSeconds();
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::X)
                this->window->close();
            break;
        }
    }
    centipede->update(dt_);
}
//update the window after an event
void game::update()
{
    this->poll_Events();
    player->update(this->window);
}


void game::render()
{
    this->window->clear();
    //rendering
    //this->splash_->show(this->window);
  //this->mushroom_->render(this->window);
  this->centipede->render(this->window);
  this->player->render(this->window);
    //this->mushroom_->render(this->window);
    this->window->display();
}
