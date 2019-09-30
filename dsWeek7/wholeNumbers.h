/***********************************************************************
 * Header:
 *    WHOLE NUMBERS
 * Summary:
 *    This will contain the class definition of:
 *       wholeNumbers             : class of whole Number lists
 * Author
 *    Ali Cope, Ashleigh Walter & George Brown
 ************************************************************************/

#ifndef WHOLENUMBERS_H
#define WHOLENUMBERS_H
#include "list.h"
using namespace custom;

/***********************************************
 * WHOLENUMBERS
 **********************************************/

class WholeNumbers
{
  public:
   int firstNumber;
   int secondNumber;
   int total;
   int carry;

   // constructors
  WholeNumbers() : firstNumber(0), secondNumber(0), total(0), carry(0){}
   WholeNumbers(const int a, const int b){firstNumber = a; secondNumber = b;
      total = 0; carry = 0;}

   void addNums()
   {
      total = firstNumber + secondNumber;
      carry = total/1000;
      firstNumber = secondNumber;
      secondNumber = total % 1000;
   }

   void subNum()
   {
      total = firstNumber - secondNumber;
      firstNumber = secondNumber;
   }

   void multiplyNum()
   {
      total = firstNumber * secondNumber;
      carry = total/1000;
      firstNumber = secondNumber;
      secondNumber = total % 1000;
   }
};

#endif //WHOLENUMBERS_H
