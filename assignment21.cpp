/***********************************************************************
* Program:
*    Assignment 21, Debugging        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   Stub functions
*
*    Estimated:  0.75 hrs   
*    Actual:     0.5 hrs
*         I made the mistake of redeclaring my display function inside of the
*   main function. Once I removed the data type from the display in the
*   main function, everything worked perfectly
*      
************************************************************************/

#include <iostream>
using namespace std;

int getPeriodicCost();
int promptDevalue();
int promptInsurance();
int promptParking();
int getUsageCost();
int promptMileage();
int promptGas();
int promptRepairs();
int promptTires();
void display (int costUsage, int costPeriodic);

int main()
{
   int costUsage = getUsageCost();
   int costPeriodic = getPeriodicCost();
   display(costUsage, costPeriodic);
   return 0;
}
int getPeriodicCost()
{
   int cost = promptDevalue() + promptInsurance() + promptParking();
   return cost;
}
int promptDevalue()
{
   return 0;
}
int promptInsurance()
{
   return 0;
}
int promptParking()
{
   return 0;
}
int getUsageCost()
{
   int cost = promptGas() + promptRepairs() + promptTires();
   int mileage = promptMileage();
   return cost;
}
int promptMileage()
{
   return 0;
}
int promptGas()
{
   return 0;
}
int promptRepairs()
{
   return 0;
}
int promptTires()
{
   return 0;
}
void display(int costUsage, int costPeriodic)
{
   cout << "Success\n";
}
