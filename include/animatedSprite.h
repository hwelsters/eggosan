#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position, int milisecondsPerFrame);

    virtual void update(int elapsedTime);

protected:
    void playAnimation(std::string animationName, bool playAnimationOnce = false);
    virtual void setupAnimations() = 0;
    void addAnimation(std::string animationName, int frameCount, Vector2 startPosition, Vector2 size);

private:
    std::unordered_map<std::string, std::vector<SDL_Rect>> _animations;

    std::string _currentAnimation;
    int _milisecondsPerFrame;
    bool _playAnimationOnce;

    int _currentFrameIndex;
    int _timeElapsed;
};

#endif