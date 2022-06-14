#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

#include "sprite.h"
#include "graphics.h"
#include "player.h"

class Level
{
public:
    Level();
    ~Level();

    void update(int elapsedTime);
    void draw(Graphics &graphics);

    void loadMap(Graphics &graphics, std::string mapName);

private:
    std::vector<Sprite> _foregroundTileList;
    std::vector<Sprite> _midgroundTileList;
    std::vector<Sprite> _backgroundTileList;

    SDL_Texture *_spriteSheet;
};

#endif