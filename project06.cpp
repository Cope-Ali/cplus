/***********************************************************************
* Program:
*    Project 06, Calendar        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   fix validate month year, doesnt prompt again after invalid entry.
*   create isLeapYear, failtestBed on leap year display, found a new way
*   to write loops for display table that eliminated about 50 lines of code
*   the way I was doing it before worked, but this way worked better and
*   the code is cleaner.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.0 hrs
*
*
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// declare all functions
int getInputMonth();
int getInputYear();
int computeNumDaysPassed(int year, int month);
int computeOffset(int numDays);
int computeMonthLength(int month, int isLeap);
void displayHeader (int month, int year); 
bool isLeapYear(int year);
void tableDisplay(int offset, int monthlength);

/*********************************************************************
 * get month input from the user and validate that it is between 1-12
 *******************************************************************/
int getInputMonth(){
   int inputMonth;
   cout << "Enter a month number: ";
   cin >> inputMonth;
   while (0 > inputMonth || inputMonth > 12)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> inputMonth;
   }
   return inputMonth;
}

/*******************************************************************
 *get year from user
 ******************************************************************/
int getInputYear (){
   int inputYear;
   cout << "Enter year: ";
   cin >> inputYear;
   while ( inputYear < 1753){
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> inputYear;
   }
      return inputYear;
}

/**********************************************************************
 * PASSED COMPILER calculates how many days have passed since Jan 1 1753. First counts
 * number of days in past years, then counts number of days passed in
 * requested year
 ***********************************************************************/

int computeNumDaysPassed(int year, int  month){
   int days = 0;
   int count = 0;
   while (year > 1753)
   {
      days ++;
      count ++;
      if (count == 365)
      {
         year --;
         count = 0;
         if (year % 4 == 0)
         {
            days ++ ;
            if (year % 100 == 0 && year % 400 !=0)
            {
               days --;
            }
         }
      }
   }
   int i = 0;
   do {
      i++;
      if (i == 2)
         days += 31;
      if (i == 3)
      {
         if (year % 4 != 0)
            days += 28;
         else
         {
            if (year % 100 == 0 && year % 400 != 0)
               days += 28;
            else days += 29;
            }
      }
      if (i == 4)
            days += 31;
      if (i == 5)
            days += 30;
      if (i == 6)
            days += 31;
      if (i == 7)
            days += 30;
      if (i == 8)
            days += 31;
      if (i == 9)
            days += 31;
      if (i == 10)
            days += 30;
      if (i == 11)
            days += 31;
      if (i == 12)
            days += 30;
      }
   while (i <  month);
   return days;
}

/******************************************************
 * PASSED COMPILER calculates offset by parsing the number odays by 7
 *****************************************************/
int computeOffset (int numDays){
   int offset = numDays % 7;
   if (offset == 6)
      offset = 0;
   else
      offset ++;
   return offset;
}

/*****************************************************
 * PASSED COMPILER calculate number of days in desired month
 ***************************************************/
int computeMonthLength (int month, int isLeap){
   int days = 0;
   if (month == 11)
      days = 30;
   if (month == 9)
      days = 30;
   if (month == 4)
      days = 30;
   if (month == 6)
      days = 30;
   if (month == 2){
      if (isLeap == 0)
            days = 28;
      else{
         days = 29;
      }
    }
   if (days == 0)
      days = 31;
   return days;
}

/************************************************************
 * determine if it is a leap year
 ***********************************************************/

bool isLeapYear (int year){
   return ((year % 4 == 0) &&
           (year % 100 !=0 || (year % 100 == 0 && year % 400 == 0)));
}

/*************************************************************
 *PASSED COMPILER display table header
 ************************************************************/
void displayHeader (int month, int year){
   cout << "\n";
 // Month display
  if (month == 1)
     cout << "January, ";
  if (month == 2)
     cout << "February, ";
  if (month == 3)
     cout << "March, ";
  if (month == 4)
     cout << "April, ";
  if (month == 5)
     cout << "May, ";
  if (month == 6)
     cout << "June, ";
  if (month == 7)
     cout << "July, ";
  if (month == 8)
     cout << "August, ";
  if (month == 9)
     cout << "September, ";
  if (month == 10)
     cout << "October, ";
  if (month == 11)
     cout << "November, ";
  if (month == 12)
     cout << "December, ";

//Year display
  cout << year << endl;   
   
// header row
  cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu"
         << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr"
       << setw(4) << "Sa" << endl;
}

/**************************************************************
 *Table display
 *************************************************************/
void tableDisplay(int offset, int monthLength){
   cout << setw((offset * 4)+4) << "1";
   int day = 2;
   int count = offset + 1; 
   do {
      if(count <7){
         cout << setw(4) << day;
         day ++;
         count++;}
      else{
         cout << endl;
         count = 0;}
   }
   while (day <= monthLength);
   cout << endl;
}

/**************************************************************
 * call functions to run
 ************************************************************/
int main(){
   int month = getInputMonth();
   int year = getInputYear();
   int numDays = computeNumDaysPassed(year, month);
   int offset = computeOffset(numDays);
   int isLeap = isLeapYear(year);
   int monthLength = computeMonthLength(month, isLeap);
   displayHeader(month, year);
   tableDisplay(offset, monthLength);
   return 0;
}

