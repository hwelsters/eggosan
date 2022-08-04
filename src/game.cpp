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
    this->_player = Player(this->_graphics, globals::ACTOR_FILE_PATH, Vector2(0, 0), Vector2(32, 32), Vector2(668, 668), 100);

    // TESTING
    this->_level.loadMap(this->_graphics, "./assets/map/pipe_level1.tmx");


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

    this->_level.draw(this->_graphics);
    this->_player.draw(this->_graphics);
    
    this->_graphics.flip();
}