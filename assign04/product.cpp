/***************************************************************
 * File: product.cpp
 * Author: Ali Cope
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "product.h"
using namespace std;

// put your method bodies here
void Product :: prompt()
{
   cout << "Enter name: ";
   getline(cin, name);
   cout << "Enter description: ";
   getline(cin, description);
   cout << "Enter weight: ";
   cin >> weight;
   do
   {
      cout << "Enter price: ";
      cin >> basePrice;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         basePrice = -1;
      }
   }
   while (basePrice < 0);
}

float Product :: getSalesTax()
{
   float tax = basePrice * 6 / 100;
   return tax;
}

float Product :: getShippingCost()
{
   float cost;
   if (weight < 5)
      cost = 2;
   else
      cost = 2 + ((weight - 5) / 10);
   return cost;
}

float Product :: getTotalPrice()
{
   float total = basePrice + getSalesTax() + getShippingCost(); 
   return total;
}

void Product :: displayAdvertising()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2); 

   cout << name << " - $" << basePrice << endl << "(" << description
        << ")" << endl; 
}

void Product :: displayInventory()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2); 

   cout << "$" << basePrice << " - " << name << " - ";
   cout.precision(1);
   cout << weight << " lbs\n";
}

void Product :: displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << name << endl
        << "  Price:" << setw(10) << "$" << setw(8) << basePrice << endl
        << "  Sales tax:" << setw(6) << "$" << setw(8)
        << getSalesTax() << endl
        << "  Shipping cost:" << setw(2) << "$" << setw(8)
        << getShippingCost() << endl
        << "  Total:" << setw(10) << "$" << setw(8) << getTotalPrice()
        << endl;
}
