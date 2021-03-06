/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include <iostream>
#include "date.h"

using namespace std;

// Put your method bodies here...
void Date :: set(int imonth, int iday, int iyear)
{
   month = imonth;
   day = iday;
   year = iyear;
}

void Date :: displayAmerican()
{
   cout << endl << month << "/" << day << "/" << year << endl;
}

void Date :: displayEuropean()
{
   cout << day << "/" << month << "/" << year << endl;
}

void Date :: displayISO()
{
   cout << year << "-" << month << "-" << day << endl;
}
