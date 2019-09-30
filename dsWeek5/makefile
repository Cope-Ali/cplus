###############################################################
# Program:
#     Assignment 05, SET
#     Brother Kirby, CS235
## Author:
#     Ali Cope & Ashleigh Walter
# Summary:
#     In this program we've created and used a custom set class that
#     will store a sorted set, in this case a set of cards for the
#     game, go fish.  The set will incorporate the use of iterators 
#     to search through the set and find elements, insert them, erase 
#     them, and sort them.
# Time:
#     Paired Programming: 2.5 hours
#     Ashleigh Walter: 11.5 hours
#     Ali Cope: 11 hrs
# The Hardest Part:
#     Ashleigh Walter: I think we struggled with our constructors 
#           again, as well as a few ways we were doing loops in 
#           our set class.  Once we found out where our errors were 
#           i felt like we did pretty well after that.  We also 
#           had a little trouble with the implimentation of of our
#           goFish display but eventually got that working as well.
#     Ali Cope: Its difficult to say what the hardest part was. We 
#           seemed to run into trouble early on, but the errors turned 
#           out to be minor things that made huge messes, but because
#           they were minor it was difficult to find. We had some issues
#           with our constructors and our loops. We met with a tutor
#           which helped a little but he couldn't tell us what was wrong
#           either. It seems like explaining it back and forth and
#           brainstorming together and desk check are the most helpful. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment05.o goFish.o card.o 
	g++ -o a.out assignment05.o goFish.o card.o  -std=c++11
	tar -cf assignment05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment05.o : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
#      
##############################################################
assignment05.o: set.h goFish.h hand.h assignment05.cpp
	g++ -c assignment05.cpp -std=c++11

goFish.o: set.h goFish.h goFish.cpp card.h hand.h
	g++ -c goFish.cpp -std=c++11

card.o: card.h card.cpp
	g++ -c card.cpp  -std=c++11



clean:
	rm a.out *.o *.tar 
