###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Author:
#     Ashleigh Walter, Ali Cope & George Brown
# Summary:
#     <put a description here>
# Time:
#     Paired Programming:
#     Ashleigh Walter: 2 hours
#     Ali Cope:
#     George Brown:
# Hardest Part:
#     Ashleigh Walter: 
#     Ali Cope:
#     George Brown:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o 
	g++ -o a.out assignment08.o huffman.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11

huffman.o: bnode.h huffman.h huffman.cpp pair.h vector.h tree.h
	g++ -c huffman.cpp -g -std=c++11

