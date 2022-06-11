#include "../include/input.h"

void Input::update() 
{
    this->beginNewFrame();
    this->handleEvent();   
}

bool Input::wasKeyPressed(SDL_Keycode key) 
{
    return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Keycode key) 
{
    return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Keycode key) 
{
    return this->_heldKeys[key];
}

bool Input::windowShouldClose()
{
    return this->_windowShouldClose;
}

void Input::beginNewFrame()
{
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

void Input::handleEvent()
{
    if (SDL_PollEvent(&this->_event))
    {
        switch (this->_event.key.type)
        {
        case SDL_KEYUP:
            keyUpEvent();
            break;
        case SDL_KEYDOWN:
            keyDownEvent();
            break;
        case SDL_QUIT:
            setWindowShouldClose();
            break;
        default:
            break;
        }
    }
}

void Input::keyUpEvent()
{
    this->_releasedKeys[this->_event.key.keysym.sym] = true;
    this->_heldKeys[this->_event.key.keysym.sym] = false;
}

void Input::keyDownEvent()
{
    if (this->_event.key.repeat != 0)
        return;
    this->_pressedKeys[this->_event.key.keysym.sym] = true;
    this->_heldKeys[this->_event.key.keysym.sym] = true;
}

void Input::setWindowShouldClose()
{
    this->_windowShouldClose = true;
}