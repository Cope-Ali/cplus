// File: address.cpp

#include "address.h"
#include <iostream>
#include <string>

using namespace std;

// Put your method bodies for the address class here
void Address :: display()
{
   cout << getStreet() << endl << getCity() << ", "
        << getState() << " " << getZip() << endl;
}

