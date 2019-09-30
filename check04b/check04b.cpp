/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   int month;
   int day;
   int year;
   // prompt for month, day, year
   cout << "Month: ";
   cin >> month;
   cout << "Day: ";
   cin >> day;
   cout << "Year: ";
   cin >> year;

   // create a Date object
   Date newDate;
   
   // set its values
   newDate.set(month, day, year);
   
   // call each display function
   newDate.displayAmerican();
   newDate.displayEuropean();
   newDate.displayISO();


   return 0;
}
