#include <iostream>
#include <sstream>
#include <string>
#include <SDLo>

//This main is just for ilustration

using namespace SDLo; //if you're lasy, all SDLo is in this namespace... 

int main()
{
    Screen screenObject; //Create Screen

    screenObject.setWidth(500); //set geometry
    screenObject.setHeight(500); 
    
    screenObject.startVideo(); //Launch SDL video subsystem    
    screenObject.setTitle("Test SDL++"); //Set window Title 
    

    Sprite* perso = screenObject.addSprite(new Sprite); //creating a SDLo::Sprite  object
    
    //all sprites can play animations, so you can load as many images you need to play animations.
    
    //let just start with a still image
    perso->addFrame(IMG_Load("tux.png")); //only one frame

    perso->setCanBeDisplayed(); //if you dont tel SDLo to display it, it will not be displayed. You can change the state by passing 'false' in argument

    perso->setPos(40,10); //location on the window
    

    //Adding a tux from the 'supertux' game.
    Sprite* walkTux = screenObject.addSprite(new Sprite);
    
    //this is a walkcycle of 6 images, so we load the 6 frames on the Sprite object
    for(int i = 0; i < 6; i++)
    {
        std::stringstream file;
        file <<"tux_walk/walk-" << i << ".png";
        std::cerr << "Loading file :" << file.str() << std::endl;

        walkTux->addFrame(IMG_Load(file.str().c_str()));
    } //I have named my files to be easily lodable this way
    
    //lets configure the sprite
    walkTux->setCanBeDisplayed(true);
    walkTux->setFps(20);//speed of the animation
    walkTux->setAnimBounds(0,5); //bounds of the loop, you can have as many animation you want, just load the frames in the order you want
    //remember, the first frame is "0", not "1", so here the last frame is 5, not 6;
    walkTux->setAnimated(); //if you dont set your sprite in the "animated state", it will not play the animation


    //render loop
    while(screenObject.isAlive())
    {
        SDL_Delay(10);                   //just saving cpu time here
        screenObject.testEvents();      //do stuff
        screenObject.updateVideo();     //refresh window
    }

    return 0;
}

