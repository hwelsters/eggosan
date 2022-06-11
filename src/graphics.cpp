#include <SDL.h>
#include <SDL_image.h>

#include "../include/graphics.h"
#include "../include/globals.h"

Graphics::Graphics()
{
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not intiialize! SDL_image error: %s\n", IMG_GetError());
    }

    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, globals::TITLE.c_str());

    if (this->_window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    if (this->_renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    }
}

Graphics::~Graphics()
{
    for (std::pair<std::string, SDL_Texture *> spriteSheet : this->_spriteSheets)
    {
        SDL_DestroyTexture(spriteSheet.second);
    }

    this->_spriteSheets.clear();

    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);

    this->_window = NULL;
    this->_renderer = NULL;

    IMG_Quit();
}

SDL_Texture *Graphics::loadTexture(std::string filePath)
{
    if (this->_spriteSheets.count(filePath) != 0)
        return this->_spriteSheets[filePath];

    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(filePath.c_str());

    if (loadedSurface == NULL)
    {
        printf("Unable to load image! SDL_image error: %s", IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(this->_renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }

    this->_spriteSheets[filePath] = newTexture;

    return newTexture;
}

void Graphics::clear()
{
    SDL_RenderClear(this->_renderer);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRect, SDL_Rect *destinationRect)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRect, destinationRect);
}