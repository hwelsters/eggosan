#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "globals.h"

class Rectangle
{
    public:
        Rectangle();
        Rectangle(Vector2 position, Vector2 size);
        
        Vector2 getCenterPosition();
        Vector2 handleCollision(Rectangle &otherRect);
        Direction isColliding(Rectangle &otherRect);

        Vector2 getPosition();
        Vector2 getSize();

        void setPosition(Vector2 position);
        void setSize(Vector2 size);
    private:
        Vector2 _position;
        Vector2 _size;
};

#endif