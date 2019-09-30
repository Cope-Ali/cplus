###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother Kirby, CS235
# Author:
#     Ashleigh Walter & Ali Cope
# Summary:
#     This program will use queues to store input from the user and 
#     display what shares were bought, sold, and how much profit was
#     earned.  The user can select from multiple choices in the menu 
#     and store and display data as they wish.
# Time:
#     Paired Programming: 2 hours
#     Ashleigh Walter: 12.5 hours
#     Ali Cope: 10 hours
#     
# Hardest Part:
#     Ashleigh Walter: For me, it was really difficult trying to add a 
#         portfolio class and calling it or setting it up correctly, I'm
#         not sure what we were doing wrong but that's why we gave up on
#         that and just went with using queues to hold all of our data. 
#         Once we did that, everything seemed to fall into place and it 
#         was just a little bit of a struggle making sure we were clearing
#         queues and setting up the equations right, like for the profit.   
#     Ali Cope: The hardest part was being able to access the attributes
#         and methods through all the different layers we had
#        for example we wanted to get the first stock in our portfolio
#        which was a queue, then we wanted to access the value of the 
#        stock which was the first stock in the portfolio queue but we 
#        kept getting errors that certian parts weren't in a class. 
#       The only way around that was to put the function inside the class,
#       but then the assignment03.cpp driver couldn't find the function.
#       Eventually we abandoned this approach and split out stocks into several
#       different queues, one for each stock attribute. It ended up making our
#       code longer but we were able to micomanage where the data was, which
#       led to our sucess in finishing the project.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h assignment03.o dollars.o stock.o
	g++ -o a.out assignment03.o dollars.o stock.o -std=c++11
	tar -cf assignment03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      assignment03.o : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
assignment03.o: queue.h assignment03.cpp
	g++ -c assignment03.cpp -std=c++11

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp -std=c++11

stock.o: stock.h stock.cpp queue.h portfolio.h
	g++ -c stock.cpp -std=c++11

###########################################################
# Clean out old versions so we can make new
###########################################################
clean:
	rm a.out *.o *.tar 
