#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include <unordered_map>

class Input
{
public:
    void update();

    bool wasKeyPressed(SDL_Keycode key);
    bool wasKeyReleased(SDL_Keycode key);
    bool isKeyHeld(SDL_Keycode key);
    bool windowShouldClose();
private:
    void beginNewFrame();
    void handleEvent();

    void keyUpEvent();
    void keyDownEvent();
    void setWindowShouldClose();

    SDL_Event _event;
    std::unordered_map<SDL_Keycode, bool> _pressedKeys;
    std::unordered_map<SDL_Keycode, bool> _releasedKeys;
    std::unordered_map<SDL_Keycode, bool> _heldKeys;
    bool _windowShouldClose;
};

#endif