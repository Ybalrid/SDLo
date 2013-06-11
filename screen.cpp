#include "screen.hpp"

using namespace SDLo;

Screen::Screen() : 
    eCatcher(new EventCatcher()),
    w(800),
    h(600),
    p_col(24),
    fullScreen(false),
    video(false),
    waitEvent(false),
    alive(false),
    screenSurface(NULL)
{
}

void Screen::setWidth(int width)
{
    w = width;
    if(videoStarted())
        startVideo(); //we reset the video system
}

void Screen::setHeight(int height)
{
    h = height;
    if(videoStarted())
        startVideo();
}

void Screen::setPColor(int p_color)
{
    p_col = p_color;
}

bool Screen::videoStarted()
{
    return video;
}

Screen* Screen::getScreen()
{
    return this;
}

void Screen::setTitle(char const title[])
{   
    //only when video is running :
    if(videoStarted())
    {
        SDL_WM_SetCaption(title,NULL);
    }
}
//////////////////////////////////////////////////////////////////////////////

void Screen::startVideo()
{

    screenSurface = SDL_SetVideoMode(w,h,p_col, SDL_HWSURFACE | SDL_DOUBLEBUF); //create window
    if (screenSurface != NULL)  //if no problem
    {
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 150,150,150)); //fill it in grey
        video = true;
        alive = true;
    }
    else                        //if problem
        video = false;
}

void Screen::testEvents()
{
    if(waitEvent)
        eCatcher->waitEvent();
    else
        eCatcher->catchEvent();

    SDL_Event e = eCatcher->getEvent();

    switch(e.type)
    {
        case SDL_QUIT:
            alive = false;
            return;
    }

    lastEvent = e; 
}


Sprite* Screen::addSprite(Sprite* sprite)
{
    sprites.push_back(sprite);
    return sprite;
}

void Screen::updateVideo()
{
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 150,150,150)); //fill it in grey
    for(unsigned int i = 0; i < sprites.size(); i++)
        {
            sprites[i]->setNewTime(SDL_GetTicks());
            if(sprites[i]->display())
                SDL_BlitSurface(sprites[i]->getSurface(), NULL, screenSurface, sprites[i]->getPos());
        }
    SDL_Flip(screenSurface);
}

