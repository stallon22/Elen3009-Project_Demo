#include "Player.h"
//using namespace sf;

void Player::initTexture()
{
    //Load a texture from a file
    if(!this->texture.loadFromFile("data/shuta.png"))
    {
        std::cout<<"ERROR::PLAYER::INITTEXTURE:: Could not load texture file"<<"\n";
    }
}


void Player::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.2f,0.2f);
    this->sprite.setPosition(this->xdir, this->ydir);
}
/*
bool Player::move_player(float delX, float delY)
{
    sf::FloatRect player_bounds = this->sprite.getGlobalBounds();
    this->sprite.setPosition(player_bounds.left + player_bounds.width + delX,player_bounds.top + dirY)

}
*/

Player::Player()
{
    this->xdir  = 400;
    this->ydir = 600;
    this->initTexture();
    this->initSprite();
    this->initialize_Variables();
}


Player::~Player()
{
    //dtor
}

void Player::initialize_Variables()
{
    this->movementSpeed = 5.f; //movement speed of the player
}



void Player::update_Input()
{
    //keyboard input
//left key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->sprite.move(-this->movementSpeed,0.f);
    }
    //right
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->sprite.move(this->movementSpeed,0.f);
    }
    //Up
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->sprite.move(0.f,-this->movementSpeed);
    }
    //Down
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->sprite.move(0.f,this->movementSpeed);
    }
}



void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{

    //left boundary
    sf::FloatRect playerBounds = this->sprite.getGlobalBounds();

    if(playerBounds.left <= 0 && (playerBounds.top <= target->getSize().y - (target->getSize().y)/3 ))
    {
        this->sprite.setPosition(0.f,target->getSize().y - (target->getSize().y)/3);
    }
    else if((playerBounds.left + playerBounds.width >= target->getSize().x) && (playerBounds.top <= target->getSize().y - (target->getSize().y)/3 ))
    {
        this->sprite.setPosition(target->getSize().x - playerBounds.width,target->getSize().y - (target->getSize().y)/3);
    }

    else if(playerBounds.top <= target->getSize().y - (target->getSize().y)/3 )
    {
        this->sprite.setPosition(playerBounds.left,target->getSize().y - (target->getSize().y)/3);
    }
    else if(playerBounds.left <= 0 && (playerBounds.top + playerBounds.height )>= target->getSize().y)
    {
        this->sprite.setPosition(0.f,target->getSize().y - playerBounds.height);
    }
    else if(playerBounds.left <= 0.f)
    {
        this->sprite.setPosition(0.f,playerBounds.top);

    }
    //right boundary
    else if(playerBounds.left + playerBounds.width-1 >= target->getSize().x)
    {
        this->sprite.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    }

    //top boundary
    else if(playerBounds.top <= 0.f)
    {
        this->sprite.setPosition(playerBounds.left,0.f);

    }
    //bottom boundary
    else if(playerBounds.top + playerBounds.height >= target->getSize().y)
    {
        this->sprite.setPosition(playerBounds.left,target->getSize().y - playerBounds.height);
    }
}

void Player::update(const sf::RenderTarget* target)
{
    //window bounds collision function
    this->update_Input();
    this->updateWindowBoundsCollision(target);


}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}
