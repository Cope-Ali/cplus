###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Alvey, CS165
# Author:
#     Ali Cope
# Summary:
#     A light version of the 1979 Atari video game by the same name.
#     The board is set with 5 asteroids moving through space. The player
#     is given control of a small ship which can be turned side to side
#     using the right and left arrows, and can be moved front and back
#     using the up and down arrows.
#     When a large astroid is hit, two medium and one small asteroid is
#     created. When a medium asteroid is hit two small asteroids are 
#     created. If an asteroid hits the ship the ship is destroyed.
#     
# Above and Beyond
#     Pressing down activates rear thrusters to move ship in reverse
#     Scoring is added. The farther away the target at impact the 
#     higher the score.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObjects.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c flyingObjects.cpp

ship.o: ship.cpp ship.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
