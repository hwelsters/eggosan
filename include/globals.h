#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

struct RGBA
{
    int r;
    int g;
    int b;
    int a;
};

struct Vector2
{
    float x;
    float y;

    Vector2() : x(0),
                y(0)
    {
    }

    Vector2(float x, float y) : x(x),
                                y(y)
    {
    }
};

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};

namespace globals
{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const float SPRITE_SCALE = 3.0f;

    const std::string TITLE = "Eggo-san's splendid adventure";

    const std::string TILESET_FILE_PATH = "./assets/sprites/tiles.png";
    const std::string ACTOR_FILE_PATH = "./assets/sprites/actors.png";

    const int TILE_WIDTH = 16;
    const int TILE_HEIGHT = 16;

    const int TILESET_WIDTH = 2048;
    const int TILESET_HEIGHT = 2048;

    const RGBA RENDER_DRAW_COLOR = {31, 16, 42, 255};
}

#endif