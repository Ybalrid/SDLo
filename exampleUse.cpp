#include <iostream>
#include <SDL.h>
#include "screen.hpp"

//this main is just for ilustration

int main()
{
    std::cout << "Hello new world!" << std::endl;
    Screen screenObject;
    
    screenObject.startVideo();
    screenObject.setTitle("Test SDL++");
    

    getchar();
    return 0;
}

