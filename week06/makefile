###############################################################
# Program:
#     Assignment 06, NODE
#     Brother Kirby, CS235
# Author:
#     Ali Cope, Ashleigh Walter & George Brown
# Summary:
#     This program creates a node class and all of its related functions
#     then using the node class creates a sorted linked list from an
#     array.
# Time:
#     Paired Programming: 1 hour
#     Ashleigh Walter: 3 hours
#     Ali Cope: 3.5 hours
#     George Brown: 5 hours
# Hardest Part:
#     Ashleigh Walter: I had some trouble with the pointers in
#         the memeber functions, mainly the insert(), but once we 
#         figured out what needed to point to what we were able 
#         to get that working.
#     Ali Cope: This week wasnt as bad as weeks in the past. We 
#          a little trouble with our sorting and the way our insert 
#          function was working. We were able to troubleshoot through
#          it really helped to have three of us working on it, we 
#          seemed to collaborate really well and explaining things back
#          and forth allowed us to see the errors in our logic.
#     George Brown: The hardest part was avoiding segmentation 
#         errors while using nodes. But we got it fixed. Always 
#         trying to access node variables while node was null 
#         caused the issue.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o a.out assignment06.o  -g -std=c++11
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g -std=c++11
