/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This is a project to manage personal finances for a month.
*    This is the third version of this project. This version will add the
*    Compute Tax functionality. The second version will create
*    multiple functions and introduce some of the calculations. The first
*    version of this program will accept user input and display in an
*    easy to read format. Future versions of this program will include
*    calculations
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      The last part of this project was much easier than the second part
*    the most difficult part was ensuring that the logic statements
*    were correct, and that all of the declared variables and functions
*    had the right casing. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// define functions
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTax();
double getActualTithing();
double getActualOther();
double computeTithing(double income);
double budgetOther(double income, double budgetTax, double budgetTithing,
                   double budgetLiving);
double computeTax(double income);
double computeDifference (double income,double actualliving, double tax,
                             double tithing, double other);
void display(double income, double budgetliving, double actualliving,
             double other, double tithing, double tax,
             double computetithing, double difference, double budgetother,
             double computetax);


/******************************************************************
* prompt for monthly income
******************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/****************************************************************
* prompt for budgeted living expenses
*****************************************************************/
double getBudgetLiving()
{
   double budgetliving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetliving;
   return budgetliving;
}

/***************************************************************
* prompt for actual living expenses
****************************************************************/
double getActualLiving()
{
   double actualliving;
   cout << "\tYour actual living expenses: ";
   cin >> actualliving;
   return actualliving;
}

/****************************************************************
* prompt for actual taxes
****************************************************************/
double getActualTax()
{
   double tax;
   cout << "\tYour actual taxes withheld: ";
   cin >> tax;
   return tax;
}

/**************************************************************
* prompt for actual tithing
*************************************************************/
double getActualTithing()
{
   double tithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;
   return tithing;
}

/*************************************************************
* prompt for actual other expenses
************************************************************/
double getActualOther()
{
   double other;
   cout << "\tYour actual other expenses: ";
   cin >> other;
   return other;
}

/**********************************************************
* compute difference between sum of budgeted and actual
***********************************************************/
double computeDifference(double income, double actualliving, double other,
                            double tithing, double tax)
{
   double difference = income - (actualliving + other + tithing + tax);
   return difference;
}

/***********************************************************   
* compute tithing
***********************************************************/
double computeTithing(double income)
{
   double ctithing = income / 10;
   return ctithing;
}

/**********************************************************   
* compute tax
*********************************************************/
double computeTax(double income)
{
   double yearlyincome = income * 12;
   double tax;
   if (yearlyincome < 15100)
      tax = (yearlyincome * 0.10) / 12;
   else if (yearlyincome < 61300)
      tax = (1510 + (0.15 * (yearlyincome - 15100))) / 12;
   else if (yearlyincome < 123700)
      tax = (8440 + (0.25 * (yearlyincome - 61300))) / 12;
   else if (yearlyincome < 188450)
      tax = (24040 + (0.28 * (yearlyincome - 123700))) / 12;
   else if (yearlyincome < 336550)
      tax = (42170 + (0.33 * (yearlyincome - 188450))) / 12;
   else
      tax = (91043 + (0.35 * (yearlyincome - 336550))) / 12;  
   return tax;
}

/*********************************************************
* compute other
********************************************************/
double budgetOther(double income, double computetax, double budgetTithing,
                      double budgetLiving)
{
   double other = income - (computetax + budgetTithing + budgetLiving);
   return other;
}

/********************************************************
* display budget report
********************************************************/
void display(double income, double budgetliving, double actualliving,
             double other, double tithing, double tax,
             double computetithing, double difference, double budgetother,
             double computetax)
{
      
    //display monthly expense report title
   cout << "\nThe following is a report on your monthly expenses\n";

   // display column headings
   cout << "\tItem"
        << setw(24) << "Budget"
        << setw(17) << "Actual\n";

   // display  line
   cout << "\t=============== =============== ===============\n";

   // display income line
   cout << "\tIncome"
        << setw(11) << "$"
        << setw(11) << income
        << setw(5) << "$"
        << setw(11) << income
        << endl;

  // display taxes line
   cout << "\tTaxes"
        << setw(12) << "$"
        << setw(11) << computetax
        << setw(5) << "$"
        << setw(11) << tax
        << endl;

   // display tithing line
   cout << "\tTithing"
        << setw(10) << "$"
        << setw(11) << computetithing
        << setw(5) << "$"
        << setw(11) << tithing
        << endl;
      
   // display living line
   cout << "\tLiving"
        << setw(11) << "$"
        << setw(11) << budgetliving
        << setw(5) << "$"
        << setw(11) << actualliving
        << endl;

   // display other line
   cout << "\tOther"
        << setw(12) << "$"
        << setw(11) << budgetother
        << setw(5) << "$"
        << setw(11) << other
        << endl;

   // display  line
   cout << "\t=============== =============== ===============\n";
       
   // display difference line
   cout << "\tDifference"
           << setw(7) << "$"
           << setw(11) << 0.00
           << setw(5) << "$"
           << setw(11) << difference
           << endl;
}

/**********************************************************************
 * User inputs budget and actual numbers. Program outputs an easy to read
 * report utilizing the user input.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed); //no scientific notation
   cout.setf(ios::showpoint); // show decimal
   cout.precision(2); // show cents or 2 digits after decimal

   // output describing program
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";


  // define variables

   double income = getIncome();
   double budgetliving = getBudgetLiving(); // budgeted living expenses
   double actualliving = getActualLiving() ; // actual living expenses
   double tax = getActualTax(); // actual taxes
   double computetax = computeTax(income); // computed budget tax
   double tithing = getActualTithing(); // actual tithing
   double other =  getActualOther(); // actual other expenses
   double computetithing = computeTithing(income); //compute tithing
   double budgetother = budgetOther(income, computetax, computetithing,
                                     budgetliving);
   //compute difference between income and sum of actual expenses
   double difference = computeDifference(income, actualliving, other, tithing,
                                        tax);
  // display the budget
   display(income, budgetliving, actualliving, other, tithing, tax,
           computetithing, difference, budgetother, computetax);
   
   return 0;
}
