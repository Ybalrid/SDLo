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
            SDL_Rect* getPos(){return &currentPosOnScreen;};
            
            SDL_Surface* getSurface();

            void setNewTime(int time);
            void setPos(int x, int y) 
            {
                currentPosOnScreen.x = x;
                currentPosOnScreen.y = y;
            }
            void updateAnimation();
            void addFrame(SDL_Surface* newFrame);
            void setCanBeDisplayed(bool canBe);

            bool display(){return canBeDisplayed;}
            
        protected:
            bool canBeDisplayed;
            bool animated;
            double fps;
            int animatedPos;

            unsigned int beginAnimation;
            unsigned int endAnimation;

            std::vector <SDL_Surface* > frames;
            SDL_Rect currentPosOnScreen;

            int curTime;
            int lastTime;

    };
};

#endif
