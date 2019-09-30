###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Author:
#     Ashleigh Walter, Ali Cope & George Brown
# Summary:
#     <put a description here>
# Time:
#     Paired Programming: 2 hours 
#     Ashleigh Walter: 9.5 hours
#     Ali Cope: 1 hour
#     George Brown:
# Hardest Part:
#     Ashleigh Walter: Struggling with how to impliment the BST
#        iterator in the map iterator. Also can't figure out why
#        NULL is undeclared while calling BST.
#     Ali Cope: 
#     George Brown: 
###############################################################


##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g -std=c++11
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g -std=c++11

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g  -std=c++11
