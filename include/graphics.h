#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <unordered_map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void update();

    SDL_Renderer *getRenderer() const;
    SDL_Texture *loadTexture(std::string filePath);

    void clear();
    void flip();
    void blitSurface(SDL_Texture *texture, SDL_Rect *sourceRect, SDL_Rect *destinationRect);

    void setPositionX(float positionX);
    void setPositionY(float positionY);
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::unordered_map<std::string, SDL_Texture *> _spriteSheets;

    float _positionX;
    float _positionY;
};

#endif