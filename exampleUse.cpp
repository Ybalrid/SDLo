#include <iostream>
#include <SDL.h>
#include "screen.hpp"

//This main is just for ilustration

int main()
{
    Screen screenObject; //Create Screen
    
    
    screenObject.startVideo(); //Launch SDL video system 
    screenObject.setTitle("Test SDL++"); //Set window Title
    

    getchar();//pause the program, we cant use events for now so we can't create a proper loop.
                //you will have problems about sopping your program if you create an infinite loop :-P 
    return 0;
}

