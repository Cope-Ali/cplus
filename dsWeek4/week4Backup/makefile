###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Ali Cope & Ashleigh Walter
# Summary:
#     <put a description here>
# Time:
#     Paired Programming: 3 hours
#     Ashleigh Walter: 13 hours
#     Ali Cope: 2 hours
# The Hardest Part:
#     Ashleigh Walter: Our data keeps copying over everything
#         with what ever was last entered. 
#     Ali Cope:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -o a.out assignment04.o nowServing.o -std=c++11 -g
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp -std=c++11 -g

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -std=c++11 -g

clean:
	rm a.out *.o *.tar 
