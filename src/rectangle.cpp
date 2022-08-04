#include "../include/rectangle.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(Vector2 position, Vector2 size) : _position(position),
                                                       _size(size)
{
}

Vector2 Rectangle::getCenterPosition()
{
    return Vector2(this->_position.x + this->_size.x / 2, this->_position.y + this->_size.y);
}

Vector2 Rectangle::handleCollision(Rectangle &otherRect)
{
    Vector2 newPosition = otherRect.getPosition();
    Vector2 otherSize = otherRect.getSize();

    Direction collisionDirection = isColliding(otherRect);

    switch (collisionDirection)
    {
    case LEFT:
        newPosition.x = this->_position.x - otherSize.x;
        break;
    case RIGHT:
        newPosition.x = this->_position.x + this->_size.x;
        break;
    case UP:
        newPosition.y = this->_position.y - otherSize.y;
        break;
    case DOWN:
        newPosition.y = this->_position.y + this->_size.y;
        break;
    default:
        break;
    }

    return newPosition;
}

Direction Rectangle::isColliding(Rectangle &otherRect)
{
    Vector2 otherPosition = otherRect.getPosition();
    Vector2 otherSize = otherRect.getSize();

    Vector2 maxPosition = Vector2(this->_position.x + this->_size.x, this->_position.y + this->_size.y);
    Vector2 otherMaxPosition = Vector2(otherPosition.x + otherSize.x, otherPosition.y + otherSize.y);

    Vector2 centerPosition = this->getCenterPosition();
    Vector2 otherCenterPosition = otherRect.getCenterPosition();

    float overlapX = std::min(maxPosition.x, otherMaxPosition.x) - std::max(this->_position.x, otherPosition.x);
    float overlapY = std::min(maxPosition.y, otherMaxPosition.y) - std::max(this->_position.y, otherPosition.y);

    if (overlapX < 0 || overlapY < 0)
        return NONE;
    if (overlapX > overlapY)
    {
        if (centerPosition.x < otherCenterPosition.x)
            return LEFT;
        else
            return RIGHT;
    }
    else
    {
        if (centerPosition.y < otherCenterPosition.y)
            return UP;
        else
            return DOWN;
    }
}

Vector2 Rectangle::getPosition()
{
    return this->_position;
}

Vector2 Rectangle::getSize()
{
    return this->_size;
}

void Rectangle::setPosition(Vector2 position)
{
    this->_position = position;
}

void Rectangle::setSize(Vector2 size)
{
    this->_size = size;
}