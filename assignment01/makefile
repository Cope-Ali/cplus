###############################################################
# Program:
#     Assignment 01, Vector
#     Brother Kirby, CS235
# Author:
#     Ali Cope
# Summary:
#     Vector template creates vectors of various types. Vectors
#     can change dynamically to grow and shrink. The template
#     allows different kinds of data types
# Time:
#     About 16 hours. 
#
# The most difficult part
#     I got really stuck on the push back
#     functionality. I actually found myself rewriting things
#     that maybe didn't need to be changed so I actually started
#     the project over after seeing some of the feedback from
#     other students regarding how minimally they changed the 
#     program and got it to compile and pass testbed.
#     I reasearched the problem online and tried three different
#     approaches and none of them worked. I met with a tutor
#     and we were able to seperate my resizing functionality and
#     copying the information back. This allowed me to also resize
#     as needed for the assignment operator as well.
#      
###############################################################

LFLAGS = -lglut -lGLU -lGL 
##############################################################
# The main rule
##############################################################
a.out: vector.h assignment01.o $(LFLAGS)
	g++ -o a.out assignment01.o -std=c++11
	tar -cf assignment01.tar vector.h assignment01.cpp makefile

##############################################################
# The individual components
#      assignment01.o     : the driver program
##############################################################
assignment01.o: vector.h assignment01.cpp
	g++ -c assignment01.cpp -std=c++11

clean:
	rm a.out *.o
