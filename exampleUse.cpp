#include <iostream>
#include <SDLo>

//This main is just for ilustration

using namespace SDLo; 

int main()
{
    Screen screenObject; //Create Screen

    screenObject.setWidth(500);
    screenObject.setHeight(500); 
    
    screenObject.startVideo(); //Launch SDL video system    
    screenObject.setTitle("Test SDL++"); //Set window Title 
    
    Sprite* perso = screenObject.addSprite(new Sprite);
    
    perso->addFrame(IMG_Load("tux.png"));
    perso->setCanBeDisplayed(true);
    perso->setPos(40,10);


    while(screenObject.isAlive())
    {
        SDL_Delay(1);
        screenObject.testEvents();
        screenObject.updateVideo();
    }

    return 0;
}

