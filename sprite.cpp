#include "sprite.hpp"

using namespace SDLo;

Sprite::Sprite() : 
    canBeDisplayed(false),
    animated(false), 
    fps(+0.0), 
    animatedPos(0), 
    beginAnimation(0), 
    endAnimation(0),
    curTime(0),
    lastTime(0)
{
   currentPosOnScreen.x = 0;
   currentPosOnScreen.y = 0;
}

void Sprite::setCanBeDisplayed(bool canBe)
{
    if (frames.size() > 0)
        canBeDisplayed = canBe;
    else
        canBeDisplayed = false;
}

SDL_Surface* Sprite::getSurface()
{
    if(!canBeDisplayed)
        return NULL;
    return frames[animatedPos];
}

void Sprite::addFrame(SDL_Surface* newFrame)
{
    if(newFrame != NULL)
        frames.push_back(newFrame);
}

void Sprite::setNewTime(int time)
{
    lastTime = curTime;
    curTime = time;

    updateAnimation();
}

void Sprite::updateAnimation()
{
    if(curTime - lastTime > (1/fps)*1000)
    {
        if(animatedPos + 1 >= endAnimation)
            animatedPos = beginAnimation;
        else 
            animatedPos++;
    }
}
