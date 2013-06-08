#include "screen.hpp"

using namespace SDLo;

Screen::Screen() //constructor
{
    screenSurface = NULL; //initialise pointer
    p_col = 24;           //base color : 24bit
    fullScreen = false;   //no fullscreen 
    w = 800;              //base size
    h = 600;
    waitEvent = true;     //pause programm until event  
    video = false;        //video not running
}

void Screen::setWidth(int width)
{
    w = width;
}

void Screen::setHeight(int height)
{
    h = height;
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

//only when video is running :
void Screen::setTitle(char const title[])
{   if(videoStarted())
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
        }
    else                        //if problem
        video = false;
}

