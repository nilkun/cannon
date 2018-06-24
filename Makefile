SOURCEFILES=main.cpp player.cpp eventHandler.cpp
GAMEENGINE=../gameEngine/CreatorTools.o ../gameEngine/fileManager.o ../gameEngine/initialization.o ../gameEngine/rendering.o ../gameEngine/viewport.o ../gameEngine/collisionDetection.o
UPDATING=
TARGETFILE=cannon
LFLAGS= -Wall
CFLAGS=-lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf
COMPILER=g++
all:
	$(COMPILER) $(LFLAGS) -o $(TARGETFILE) $(SOURCEFILES) $(GAMEENGINE) $(UPDATING) $(CFLAGS)
