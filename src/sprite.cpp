#include <string>

#include "../include/sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position)
{
    this->_texture = graphics.loadTexture(filePath);
    this->_sourceRect = {sourcePosition.x, sourcePosition.y, sourceSize.x, sourceSize.y};
    this->_position = position;
}

Sprite::~Sprite()
{
    this->_texture = nullptr;
}

void Sprite::update(int elapsedTime) {}

void Sprite::draw(Graphics &graphics)
{
    SDL_Rect destinationRect = {this->_position.x, this->_position.y, (int)(this->_sourceRect.w * globals::SPRITE_SCALE), (int)(this->_sourceRect.h * globals::SPRITE_SCALE)};
    graphics.blitSurface(this->_texture, &this->_sourceRect, &destinationRect);
}

void Sprite::setPosition(Vector2 position)
{
    this->_position = position;
}