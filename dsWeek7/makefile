###############################################################
# Program:
#     Assignment 07, LIST
#     Brother Kirby, CS235
# Author:
#     Ashleigh Walter, Ali Cope & George Brown
# Summary:
#     This program will impliment our own custom class for a list
#     using iterators and nodes to accomplish inserting, removing,
#     and traversing a list that will ultimately go on to display 
#     any list of numbers in the fibonacci sequence for the user.
# Time:
#     Paired Programming: 1 hour
#     Ashleigh Walter: 7 hours
#     Ali Cope: 6.5 hours
#     George Brown: 8 hours
# Hardest Part:
#     Ashleigh Walter: We had a little trouble with our constructors
#         in the beginning, but figured out it had to do with us not
#         properly clearing the data, hopefully this will help us so 
#         we don't struggle with those in the future assignments.  We 
#         also had some issues with the reverse iterator and when trying
#         to get our fibonacci to display but ultimately figured that out.
#     Ali Cope: Once again the hardest part was getting the iterators to work
#	eventually we had to abandon our initial aproach and work differently.
#	I wish I understood better how to use iterators in the this context.
#	It is hard to feel like we are progressing when we keep getting stuck
#	on the same issues each week. We keep finding ways to work around
#	our issues, which I know is a vital skill, but I wish we could see
#	a "best approach" so we could know how to do even better next time
#     George Brown: Hardest part for me was figuring out the best way to 
#	implement the fibonacci sequence (large sequence).  The real trouble
#	was the getting the iterator to work without segment faults or 
#	infinate loops eventually I realized I was using pop_front() to 
#	manipulate the very thing I was iterating. From fixing that everything
#	fell into place
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h assignment07.o fibonacci.o
	g++ -o a.out assignment07.o fibonacci.o -g -std=c++11
	tar -cf assignment07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment07.o : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
assignment07.o: list.h assignment07.cpp
	g++ -c assignment07.cpp -g  -std=c++11

fibonacci.o: fibonacci.h fibonacci.cpp list.h wholeNumbers.h
	g++ -c fibonacci.cpp -g  -std=c++11

