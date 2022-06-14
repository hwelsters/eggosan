#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedSprite.h"
#include "input.h"

namespace player_constants
{
    const float PLAYER_MOVE_SPEED = 0.15f;
    const float GRAVITY = 1.0f;
}

class Player : public AnimatedSprite
{
public:
    Player();
    Player(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position, int milisecondsPerFrame);

    virtual void update( Input& input, int elapsedTime);

    void moveLeft();
    void moveRight();
    void stopMoving();

protected:
    virtual void setupAnimations();
    void handlePhysics(int elapsedTime);

    float _xVelocity;
    float _yVelocity;

    float _xDisplacement;
    float _yDisplacement;

    Direction _facingDirection;
};

#endif