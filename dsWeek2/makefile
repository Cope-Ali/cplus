###############################################################
# Program:
#     Assignment 02, STACK
#     Brother Kirby, CS235
# Author:
#     Ashleigh Walter, Ali Cope
# Summary:
#     This project has two parts. The first creates a stack
#	  template that can accept any data type. The stack
#     follows all of the rules for stack data structure and 
#     implements all of the necessary methods.
#     
#     The second part of this project translates infix
#     equations into postfix equations using the newly
#     created stack template. This equation translator 
#     handles order of operations and outputs the postfix
#     version of the equation.
# Time:
#     Paired programming: 1 hour
#     Ashleigh Walter: 15 hours
#     Ali Cope: 12 hours
#
# Hardest Part:
#     Ashleigh Walter: Figuring out the infix to postfix was a 
#     real struggle, from the spacing to understanding how to 
#     impliment order of operations. 
#
#     Ali Cope: I think the spacing was the most difficult part
#     because there were no constraints on what kind of equation
#     or how it was entered we had to be prepared for anything
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h assignment02.o infix.o 
	g++ -o a.out assignment02.o infix.o 
	tar -cf assignment02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment02.o : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
assignment02.o: stack.h infix.h assignment02.cpp
	g++ -c assignment02.cpp

infix.o: stack.h infix.h infix.cpp
	g++ -c infix.cpp

clean:
	rm a.out *.o *.tar 
