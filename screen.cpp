#include "screen.hpp"

using namespace SDLo;

Screen::Screen() : 
    w(800),
    h(600),
    p_col(24),
    fullScreen(false),
    video(false),
    waitEvent(true),
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
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0,0,0)); //fill it in black
        video = true;
        alive = true;
    }
    else                        //if problem
        video = false;
}

