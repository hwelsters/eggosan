#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

#include "sprite.h"
#include "graphics.h"
#include "player.h"
#include "rectangle.h"

class Level
{
public:
    Level();
    ~Level();

    void update(int elapsedTime);
    void draw(Graphics &graphics);

    void loadMap(Graphics &graphics, std::string mapName);
    Vector2 handleCollision(Rectangle rectangle);

private:
    std::vector<Sprite> _foregroundTileList;
    std::vector<Sprite> _midgroundTileList;
    std::vector<Sprite> _backgroundTileList;
    std::vector<Rectangle> _collisionRects;

    SDL_Texture *_spriteSheet;
};

#endif