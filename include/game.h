#pragma once
#ifndef GAME_H
#define GAME_H

#include "../include/input.h"
#include "../include/graphics.h"
#include "../include/player.h"

class Game
{
public:
    Game();
    ~Game();
private:
    void update();
    void draw();

    Graphics _graphics;
    Input _input;

    Player _player;
};

#endif