#include <iostream>
#include <SDLo>

//This main is just for ilustration

using namespace SDLo; 

int main()
{
    Screen screenObject; //Create Screen

    screenObject.startVideo(); //Launch SDL video system    
    screenObject.setTitle("Test SDL++"); //Set window Title 
    
    //Changing size after showing the window MAY CAUSE BUG
    //screenObject.setWidth(500);
    //screenObject.setHeight(500); 
    
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

