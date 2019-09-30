###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Ali Cope & Ashleigh Walter
# Summary:
#     This program will use a custom deque to take input from the
#     user to get help from the tutoring center, keeping in mind, 
#     unless it's an emergency, they will be added to the end and 
#     the display will list the current standings minute by minute.
#     The custom deque will allow items to be added to either end 
#     as well as be removed from either end.
# Time:
#     Paired Programming: 3 hours
#     Ashleigh Walter: 16 hours
#     Ali Cope:14 hours
# The Hardest Part:
#     Ashleigh Walter: We have struggled immensly with this 
#         assignment, mainly with getting our custom deque to 
#         work properly.  We initially had an issue with the data
#         overiding everything previously added, then everything
#         would end up being displayed in the deque but randomly
#         and finally having issue with the word portion not being
#         displayed which ultimately seemed like it was because our
#         loops weren't set up properly, but anyway, that is what
#         was the hardest for me.
#     Ali Cope: The hardest part for me was in getting our loops to add
#         everything in the correct order. We met with a tutor and
#         he couldn't figure out what the problem was either (which
#         at least made us feel like we weren't stupid) but left us 
#         with his "fixes" which wouldn't compile. We didn't give
#         up and we were able to fix things and build the nowServing
#         using the standard deque. Then all we had was pushing on
#        the front. So there were several hiccups but I would say
#         the hardest part was not giving up.
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h student.h assignment04.o nowServing.o tutorCenter.o
	g++ -o a.out assignment04.o nowServing.o tutorCenter.o -std=c++11
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
#      tutorCenter.0  : the program that creates the help deque
##############################################################
assignment04.o: deque.h student.h tutorCenter.h nowServing.h assignment04.cpp
	g++ -c assignment04.cpp -std=c++11

nowServing.o: nowServing.h nowServing.cpp student.h tutorCenter.h deque.h
	g++ -c nowServing.cpp -std=c++11

tutorCenter.o: tutorCenter.h tutorCenter.cpp student.h deque.h
	g++ -c tutorCenter.cpp -std=c++11

clean:
	rm a.out *.o *.tar 
