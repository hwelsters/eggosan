#include "../include/game.h"

Game::Game()
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("SDL failed to initialize! SDL_Error: %s", SDL_GetError());
    }

    this->update();
}

Game::~Game()
{
    SDL_Quit();
}

void Game::update()
{
    this->_player = Player(this->_graphics, "../assets/sprites/actors.png", Vector2(0, 0), Vector2(32, 32), Vector2(100, 100), 100);
    int ticksCount = SDL_GetTicks();
    while (!this->_input.windowShouldClose())
    {
        this->_input.update();
        this->draw();

        int timeElapsed = SDL_GetTicks() - ticksCount;
        ticksCount = SDL_GetTicks();

        this->_player.update(this->_input, timeElapsed);
    }
}

void Game::draw()
{
    this->_graphics.clear();

    this->_player.draw(this->_graphics);
    this->_graphics.flip();
}