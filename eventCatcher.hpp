#ifndef eventCatcher
#define eventCatcher
#include <iostream>
#include <SDL.h>
#include <iostream>

namespace SDLo
{
    class EventCatcher
    {
        public:
            EventCatcher();

            void waitEvent();
            int catchEvent();
            
            SDL_Event getEvent(){return event;}

        private:
            SDL_Event event;
    };
}

#endif
