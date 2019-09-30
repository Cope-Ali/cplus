/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include "phone.h"
#include <iostream>
#include <string>

// TODO: Put your SmartPhone methods here
void SmartPhone :: prompt()
{
   Phone::promptNumber();
   std::cin.ignore();
   std::cout << "Email: ";
   getline(std::cin, email);
}

void SmartPhone :: display()
{
   Phone::display();
   std::cout << email << std::endl;
}
