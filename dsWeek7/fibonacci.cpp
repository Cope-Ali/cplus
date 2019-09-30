/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Ashleigh Walter, Ali Cope & George Brown
 **********************************************************************/

#include <iostream>
#include "fibonacci.h" // for fibonacci() prototype
#include "list.h"      // for LIST
#include "wholeNumbers.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
//using namespace std;
using namespace custom;

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{

   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin >> number;

   //create the list to hold the numbers in fibonacci first number A
   //and next number is B
   list<int> fNumA;
   list<int> fNumB;

   //start our list with the first two
   fNumA.push_back(1);
   fNumB.push_back(1);

   // loop to output the number of fibonacci numbers
   for (int i = 0; i < number; i++)
   {
      cout << "\t" << fNumA.front() << "\n";

      WholeNumbers wNum(fNumA.front(), fNumB.front());
      wNum.addNums();
      fNumA.front() = wNum.firstNumber;
      fNumB.front() = wNum.secondNumber;
   }

   // prompt for a single large Fibonacci
   int fibNum;
   cout << "Which Fibonacci number would you like to display? ";
   cin >> fibNum;
   
   // 3 lists, is the new number, one the last and the other the penultimate
   list <int> numNew;
   list <int> numPen;
   list <int> numUlt;
   
   //we set ultimate and penultimate to 1 and 1 to begin
   numPen.push_back(1);
   numUlt.push_back(1);
   //carry needs only to be boolean because value will never be greater than 1
   bool carry = false;
   // numTemp will hold the int while we manipulate it
   int numTemp = 0;
   
   //loop from 2  because we already added the two first elements
   for (int i = 2; i < fibNum; i++)
   {
      //carry is false becasue we are starting with a new pair of numbers
      //everytime the loop executes
      carry = false;
      
      //iterator loop will add last number to penultimate (last number)
      for(list<int>::iterator it = numUlt.begin(); it != numUlt.end();)
      {
         // if numPen is empty we continue to feed numbers in from last number
         if (numPen.empty())
         {
            numTemp = *it;
         }
         //if not, then we add them together
         else
         {
            numTemp = *it + numPen.front();
            //where we don't have an iterator for numPen, we
            //keep track by poping the front each time it is added.
            //because it is the penultimate number we know it will always
             //be lesser than the last number, so we don't have to worry about
             //which is larger
            if(!numPen.empty())
               numPen.pop_front();
         }
         //where carry is bool, if it is true we need to add the 1
         if (carry)
         {
            numTemp++;
            //once we add the one, we set carry back to false
            //because max int in each node is 999, and 999 + 999 is
            //1998, carry will never be greater than one on the next
            //node.
            carry = false;
         }
         // if numTemp is over 1000, we need to trim it down
         if (numTemp > 1000)
         {
            //we "put" the 1000 into the carry (to be added as a 1)
            //this should execute the next loop
            carry = true;
            
            //now we just reduce numTemp by 1000 and it will be ready to
            //push into the node
            numTemp = numTemp - 1000;
         }
         //if we push back, we keep the first 3 digits (1s, 10s and 100s)
        //as the head. This way we just keep adding nodes as necessary
         numNew.push_back(numTemp);
         
         //here we advance to the next node
         it++;
         
        //if we are at the end now the loop will exit.
        //if we are carrying, we need to consider it will not be added
        //in because no more numbers are being added
         //for this, we need to push back a 1 here.
         if(it == numUlt.end() && carry)
         {
            numNew.push_back(1);
         }
      }
        //now we move one number in the sequence forward..
        //last number becomes penultimate new number becomes last number,
        //and we clear new number for the next in the sequence
      numPen = numUlt;
      numUlt = numNew;
      numNew.clear();
   }
   
   cout << "\t";
   //where we exited the loop, the new number is stored in the last (ultimate)
   //number we loop here to display.
   for(list<int>::reverse_iterator it = numUlt.rbegin(); it != numUlt.rend();)
   {
      if(*it<100)
         if(*it<10)
            cout << "00" << *it++;
         else
            cout << "0" << *it++;
      else
         cout << *it++;
      
      if(it != numUlt.rend())
         cout << ",";
      else
         cout << endl;
   }
   
}
