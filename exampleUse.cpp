//C++ std include
#include <iostream>
#include <sstream>
#include <string>

//SDLo
#include <SDLo>


//This main is just for ilustration. it's not part of the lib itself

using namespace SDLo; //if you're lasy, all SDLo is in this namespace... 

//All SDLo componant is member of the SDLo namespace

int main()
{
    Screen screenObject; //Create Screen
    
    /*  Screen is the main class of SDLo,
     *  This is by a object Screen that you
     *  will be able to display stuff on 
     *  youre actual screen.
     *
     *  You can set many parameters before 
     *  starting the video system. there is some
     *  of them that you cannot modify after the 
     *  video started.
     */

    screenObject.setWidth(500); //set geometry
    screenObject.setHeight(500); 
    
    screenObject.startVideo(); //Launch SDL video subsystem    
    screenObject.setTitle("Test SDL++"); //Set window Title 
    
    
    /*  The second most important element is
     *  the Sprite. With this class, you can display
     *  fixed or animated objects on the Screen.
     *
     *  The animation are time based. This is pretty simple,
     *  you load as many imagies you need on your sprite object.
     *  You define the bounds (witch are images index on the order
     *  you load them) of the animation loop and a speed on fps 
     *  ("frames per seconds"). 
     *
     *  All sprites with "canBeDisplayed" set to 'true' present on
     *  the screenObject "render list" will be displayed on screen.
     *  
     *  The positions of the sprites are relatives to the upper-left
     *  corner of the Screen.
     */

    Sprite* perso = screenObject.addSprite(new Sprite); //creating a SDLo::Sprite  object
    
    //all sprites can play animations, so you can load as many images you need to play animations.
    
    //let just start with a still image
    perso->addFrame(IMG_Load("ressources/tux.png")); //only one frame

    perso->setCanBeDisplayed(); //if you dont tel SDLo to display it, it will not be displayed. You can change the state by passing 'false' in argument

    perso->setPos(40,10); //location on the window
    

    //Adding a tux from the 'supertux' game.
    Sprite* walkTux = screenObject.addSprite(new Sprite);
    
    //this is a walkcycle of 6 images, so we load the 6 frames on the Sprite object
    for(int i = 0; i < 6; i++)
    {
        //I use this technic to load a bunch of images
        std::stringstream file;
        file <<"ressources/tux_walk/walk-" << i << ".png";

        walkTux->addFrame(IMG_Load(file.str().c_str()));
    } //I have named my files to be easily lodable this way
    
    //lets configure the sprite
    walkTux->setCanBeDisplayed();
    walkTux->setFps(20);//speed of the animation
    walkTux->setAnimBounds(0,5); //bounds of the loop, you can have as many animation you want, just load the frames in the order you want
    //remember, the first frame is "0", not "1", so here the last frame is 5, not 6;
    walkTux->setAnimated(); //if you dont set your sprite in the "animated state", it will not play the animation

    /*  The principal code of your aplication will be on a loop like this one.
     *
     *  In order to use the integreted event system, you have to call the 'testEvents()'
     *  method. You will no be able to recive the updated event information 
     *  from yout Screen object if you don't do that.
     *  
     *  While your Screen dosent request to terminate the programm (alive = false),
     *  you have to call the 'updateVideo()' method to refresh the screen.
     */

    //render loop
    while(screenObject.isAlive())
    {
        SDL_Delay(10);                   //just saving cpu time here
        screenObject.testEvents();      //do stuff
        screenObject.updateVideo();     //refresh window
    }

    return 0;
}

