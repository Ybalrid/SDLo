UNAME := $(shell uname)
PROGRAM :=SDL++

#ifeq ($(UNAME), Darwin)
#all:
#	@echo "Found Darwin System"
#	g++ -o $(PROGRAM) -I/Library/Frameworks/SDL.framework/Headers *.cpp SDLmain.m -framework SDL -framework Cocoa -I. -g
#endif


ifeq ($(UNAME), Linux)
all:
	@echo "Found Linux System"
	g++ -o $(PROGRAM) -I/usr/include/SDL -lSDL -lSDL_image -lSDL_ttf *.cpp -Wall -I. -g
endif

