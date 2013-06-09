#include <iostream>
#include <SDLo>

//This main is just for ilustration

using namespace SDLo; 

int main()
{
    Screen screenObject; //Create Screen


    screenObject.startVideo(); //Launch SDL video system    
    screenObject.setTitle("Test SDL++"); //Set window Title 
    
    //Changing size after showing the window
    screenObject.setWidth(500);
    screenObject.setHeight(500); 
    
    Sprite* perso = screenObject.addSprite(new Sprite);
    
    perso->addFrame(IMG_Load("tux.png"));
    perso->setCanBeDisplayed(true);
    perso->setPos(40,10);



    screenObject.updateVideo();

    getchar();//pause the program, we cant use events for now cause we can't create a proper loop.
                //you will have problems about sopping your program if you create an infinite loop :-P 
    

    return 0;
}

