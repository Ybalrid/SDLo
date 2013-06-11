#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <vector>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "eventCatcher.hpp"
#include "sprite.hpp"

namespace SDLo 
{
    class Screen
    {
        public:
            Screen();                  //class constructor

            //class setters
            void setWidth(int width);       //set window Width
            void setHeight(int height);     //set window Height
            void setPColor(int p_color);    //only usefull BEFORE startign video
            void setTitle(char const title[]);
            
            void startVideo();
            void updateVideo();

            Sprite* addSprite(Sprite* sprite);

            //class getters
            int getWidth(){return w;}
            int getHeight(){return h;}
            
            bool videoStarted();
            bool isAlive() {return alive;}
            
            void testEvents();

            Screen* getScreen();

        private:
            EventCatcher* eCatcher;            
            
            int w;
            int h;
            int p_col;

            bool fullScreen;
            bool video;

            bool waitEvent;
            bool alive;
            SDL_Surface* screenSurface;
            std::vector <Sprite*> sprites;
            SDL_Event lastEvent; 

    };
};

#endif 

