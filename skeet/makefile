###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Ali Cope
# Summary:
#     Finished skeet game. Game consists of a rifle drawn in the bottom right
#     corner of the screen. The rifle angle can be moved using the right
#     and left arrows. The rifle can be shot using the spacebar.
#     birds fly randomly across the screen. The goal of the game
#     is to "kill" the birds with the rifle. 
# Above and Beyond
#     Created a new bird type "special bird" special bird is 
#     drawn less often than other bird types. It is smaller and
#     requires more hits to be destroyed. It is drawn as a small
#     rotating rectangle. 
###############################################################


LFLAGS = -lglut -lGLU -lGL -g

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bird.o bullet.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bird.o bullet.o  $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.h velocity.cpp point.h 
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.h flyingObjects.cpp point.h velocity.h
	g++ -c flyingObjects.cpp

bird.o: bird.h bird.cpp flyingObjects.h 
	g++ -c bird.cpp

bullet.o: bullet.h bullet.cpp flyingObjects.h uiDraw.h 
	g++ -c bullet.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar 
	# *.h.gch *.h~
