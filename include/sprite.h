#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

#include "graphics.h"
#include "globals.h"

class Sprite
{
public:
    Sprite();
    Sprite(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position);
    ~Sprite();

    virtual void update(int elapsedTime);
    void draw(Graphics &graphics);

    void setPosition(Vector2 position);

protected:
    SDL_Rect _sourceRect;
    Vector2 _position;

private:
    SDL_Texture *_texture;
};

#endif