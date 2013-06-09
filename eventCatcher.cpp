#include "eventCatcher.hpp"

using namespace SDLo;

EventCatcher::EventCatcher() 
{   

}

void EventCatcher::waitEvent()
{
    SDL_WaitEvent(&event);
}

int EventCatcher::catchEvent()
{
   return(SDL_PollEvent(&event));
}


