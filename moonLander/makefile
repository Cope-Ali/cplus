###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Ali Cope
# Summary:
#     Compiles and creates executable version of the moon
#     lander game. Creates a random landscape with a landing
#     platform. Using the down, left and right arrows the user
#     navigates a falling moon lander to land sucessfully on
#     the platform.
# Above and Beyond
#     1 - Added starting prompt to allow user to control 
#         start of game.
#     2 - Added warning when fuel gets below 50
#     3 - Added notice when lander is out of fuel
#     4 - Added score when lander lands sucessfully on
#         platform. Score is computed as:
#            remaining fuel + 500 = score
#         score is output after landing.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o:velocity.h point.h
	g++ -c velocity.cpp

lander.o:lander.cpp lander.h velocity.h point.h
	g++ -c lander.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
