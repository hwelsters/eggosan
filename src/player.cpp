#include "../include/player.h"

Player::Player() {}

Player::Player(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position, int milisecondsPerFrame) : AnimatedSprite(graphics, filePath, sourcePosition, sourceSize, position, milisecondsPerFrame)
{
    this->_xDisplacement = 0;
    this->_yDisplacement = 0;
    this->_xVelocity = 0;
    this->_yVelocity = 0;
    this->_facingDirection = RIGHT;
}

void Player::update(Input &input, int elapsedTime)
{
    AnimatedSprite::update(elapsedTime);

    if (input.isKeyHeld(SDLK_a) || input.isKeyHeld(SDLK_LEFT))
        this->moveLeft();
    else if (input.isKeyHeld(SDLK_d) || input.isKeyHeld(SDLK_RIGHT))
        this->moveRight();
    else
        this->stopMoving();

    handlePhysics(elapsedTime);
}

void Player::moveLeft()
{
    this->playAnimation("eggosan_runLeft");
    this->_xVelocity = -player_constants::PLAYER_MOVE_SPEED;
    this->_facingDirection = LEFT;
}

void Player::moveRight()
{
    this->playAnimation("eggosan_runRight");
    this->_xVelocity = player_constants::PLAYER_MOVE_SPEED;
    this->_facingDirection = RIGHT;
}

void Player::stopMoving()
{
    switch (this->_facingDirection)
    {
    case LEFT:
        this->playAnimation("eggosan_idleLeft");
        break;
    case RIGHT:
        this->playAnimation("eggosan_idleRight");
        break;
    default:
        break;
    }

    this->_xVelocity = 0;
}

void Player::setupAnimations()
{
    this->addAnimation("eggosan_idleLeft", 1, Vector2(0, 0), Vector2(32, 32));
    this->addAnimation("eggosan_idleRight", 1, Vector2(0, 32), Vector2(32, 32));

    this->addAnimation("eggosan_runLeft", 7, Vector2(0, 0), Vector2(32, 32));
    this->addAnimation("eggosan_runRight", 7, Vector2(0, 32), Vector2(32, 32));
}

void Player::handlePhysics(int elapsedTime)
{
    this->_xDisplacement = this->_xVelocity * elapsedTime;
    this->_yDisplacement = this->_yVelocity * elapsedTime;

    this->_position.x += static_cast<int>(this->_xDisplacement);
    this->_position.y += static_cast<int>(this->_yDisplacement);

    this->_xDisplacement -= static_cast<int>(this->_xDisplacement);
    this->_yDisplacement -= static_cast<int>(this->_yDisplacement);
}