#ifndef SPRITES_SDLo
#define SPRITES_SDLo

#include <vector>
#include <SDL.h>

namespace SDLo 
{
    class Sprite
    {
        public:
            Sprite();
            SDL_Rect getPos();
            
            SDL_Surface* getSurface();

            void getNewTime(int time);
            void addFrame(SDL_Surface* newFrame);
            void setCanBeDisplayed(bool canBe);

        protected:
            bool canBeDisplayed;
            bool animated;
            double fps;
            int animatedPos;

            unsigned int beginAnimation;
            unsigned int endAnimation;

            std::vector <SDL_Surface* > frames;
            SDL_Rect currentPosOnScreen;
    };
};

#endif
