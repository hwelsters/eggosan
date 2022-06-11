#include "../include/animatedSprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, std::string filePath, Vector2 sourcePosition, Vector2 sourceSize, Vector2 position, int milisecondsPerFrame) : Sprite(graphics, filePath, sourcePosition, sourceSize, position),
                                                                                                                                                                  _milisecondsPerFrame(milisecondsPerFrame),
                                                                                                                                                                  _timeElapsed(0)
{
    this->setupAnimations();
    this->playAnimation("eggosan_runLeft");
}

void AnimatedSprite::update(int timeElapsed)
{
    this->_timeElapsed += timeElapsed;

    if (this->_timeElapsed > this->_milisecondsPerFrame)
    {
        this->_currentFrameIndex = (this->_currentFrameIndex + 1) % this->_animations[this->_currentAnimation].size();
        this->_timeElapsed -= this->_milisecondsPerFrame;
        this->_sourceRect = this->_animations[this->_currentAnimation][this->_currentFrameIndex];
    }
}

void AnimatedSprite::playAnimation(std::string animationName, bool playAnimationOnce)
{
    this->_playAnimationOnce = playAnimationOnce;
    this->_currentAnimation = animationName;
}

void AnimatedSprite::setupAnimations()
{
    this->addAnimation("eggosan_runLeft", 7, Vector2(0, 0), Vector2(32, 32));
    this->addAnimation("eggosan_runRight", 7, Vector2(0, 32), Vector2(32, 32));
}

void AnimatedSprite::addAnimation(std::string animationName, int frameCount, Vector2 startPosition, Vector2 size)
{
    if (this->_animations.count(animationName) != 0)
    {
        printf("Animation already exists!\n");
        return;
    }

    std::vector<SDL_Rect> frames;
    for (int i = 0; i < frameCount; i++)
    {
        SDL_Rect frameRect = {startPosition.x + size.x * i, startPosition.y, size.x, size.y};
        frames.push_back(std::move(frameRect));
    }
    this->_animations[animationName] = std::move(frames);
}