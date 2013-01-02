#include <stdio.h>
#include <SDL.h>

class Screen
{
    public:
        Screen();                   //construc Screen object
        void setWidth(int width);   //set window height
        void setHeight(int height);
        void setPColor(int p_color);
        
        void startVideo();
        void setTitle(char const title[]);
        
        bool videoStarted();
        Screen* getScreen();
    private:
        int w;
        int h;
        int p_col;

        bool fullScreen;
        bool video;
        
        bool waitEvent;

        SDL_Surface* screenSurface;
};
