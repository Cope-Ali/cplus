/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary:
*      This program will take input from the user and determine their
*      letter grade for the class. This will take two functions. The first
*      computeLetterGrade will determine the letter grade A-F, the second
*      function computeGradeSign will determine if a + or - should be
*      added to the grade. Then the final grade will be outputted to the user

*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      Program went pretty smoothly. My only hiccups were in remembering to
*    declare a 'char' not a "string" based on the ' vs " also it took
*    me a minute to figure out that I needed to not output the * character
************************************************************************/

#include <iostream>
using namespace std;

char computeLetterGrade(int numGrade);
char computeGradeSign(int numGrade);

/**********************************************************************
* Prompt user for number grade, call functions and display letter grade
* results back to the user
***********************************************************************/
int main()
{
   int numGrade;
   cout << "Enter number grade: ";
   cin >> numGrade;
   char letter = computeLetterGrade(numGrade);
   char sign = '*';
   if (numGrade >= 60 && numGrade <= 96)
      sign = computeGradeSign(numGrade);
   cout << numGrade << "% is " << letter;
   if (sign != '*')
      cout << sign;
   cout << endl;
   return 0;
}

/********************************************************************
* convert number grade into letter
********************************************************************/
char computeLetterGrade(int numGrade)
{
   char letter = 'X';
   switch (numGrade / 10)
   {
      case 10:
      case 9:
         letter = 'A';
         break;
      case 8:
         letter = 'B';
         break;
      case 7:
         letter = 'C';
         break;
      case 6:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }
   return letter;
}

/*****************************************************************
* Program determines if grade needs a (+) (-) or (*)
****************************************************************/
char computeGradeSign(int numGrade)
{
   numGrade %= 10;
   char sign = ((numGrade < 3) ? '-' : ((numGrade > 6) ? '+' : '*' ));
   return sign;
}
