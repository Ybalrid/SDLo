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
    //std::cerr << "newTime = " << time << std::endl;
    curTime = time;

    updateAnimation();
}

void Sprite::updateAnimation()
{
    if(animated)
        if(curTime - lastTime > (1/fps)*1000)
        {
            /*std::cerr << "curTime = " << curTime << std::endl
                << "lastTime = " << lastTime << std::endl
                << "Delay = " << (1/fps)*1000 << std::endl;
            */
            lastTime = curTime;
            if(animatedPos + 1 >= endAnimation)
                animatedPos = beginAnimation;
            else 
                animatedPos++;
        }
}

void Sprite::setFps(double newFps)
{
    fps = newFps;
}

void Sprite::setAnimBounds(unsigned int begin, unsigned int end)
{
    beginAnimation = begin;
    if(end < frames.size())
        endAnimation = end;
    else
        endAnimation = frames.size() - 1;
}

void Sprite::setAnimated(bool anim)
{
    animated = anim;
}
