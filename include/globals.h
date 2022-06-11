#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

namespace globals
{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    const float SPRITE_SCALE = 3.0f;

    const std::string TITLE = "Eggo-san's splendid adventure";
}

struct Vector2
{
    int x;
    int y;

    Vector2() : x(0),
                y(0)
    {}

    Vector2(float x, float y) : x(x),
                            y(y)
    {}
};

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

#endif