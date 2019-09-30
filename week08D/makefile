###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Author:
#     Ashleigh Walter, Ali Cope & George Brown
# Summary:
#     This program will use a nodes class in a Binary Tree to
#     run a huffman code generator. It will traverse the tree
#     to properly add nodes, delete and copy them.
# Time:
#     Paired Programming: 2 hours
#     Ashleigh Walter: 3 hours
#     Ali Cope:
#     George Brown:
# Hardest Part:
#     Ashleigh Walter: I think we really struggled with the
#        huffman codes and figuring out how to correctly use a
#        specific data structure and how to properly set up the
#        variables with pairs and nodes.
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

huffman.o: bnode.h huffman.h huffman.cpp pair.h vector.h queue.h
	g++ -c huffman.cpp -g -std=c++11

