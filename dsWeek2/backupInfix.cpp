/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Kirby, CS 235
 * Author:
 *    Ashleigh Walter, Ali Cope
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using std::getline;
using namespace custom;


/*****************************************************
 * GET OPERATIONS
 * Determine the order of operations
 *****************************************************/
int getOperations(char op)
{
   int order;

   switch(op)
   {
      case '-':
      case '+':
         order = 1;
         break;
      case '%':
      case '/':
      case '*':
         order = 2;
         break;
      case '^':
         order = 3;
         break;
   }
 
   return order;
}


/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   string postfix;
   int size = infix.length();
   stack <char> stack;
   postfix += ' ';

// loop through each char in the infix and determine what to do with it
// either add to postfix string or push onto stack to add later
   for (int i = 0; i < size; i++)
   {
//check for a space, indicates seperation of terms
      if (infix[i] == ' ')
      {
         stack.push(infix[i]);
         stack.pop();
      }
      // check for number letter or decimal point
      else if (isdigit(infix[i]) || isalpha(infix[i]) || infix[i] == '.')
      {
         postfix += infix[i];
      }
      //check for parenthesis and push to stack until closing parenthesis
      else if (infix[i] == '(')
      {
         stack.push(infix[i]);
      }
      else if (infix[i] == ')')
      {
         while (stack.top() != '(')
         {
             // adds space in front of first forward slash
            postfix += ' ';
            postfix += stack.top();
            //postfix += ' '; // adds space in front of farenheight
            stack.pop();
         }
         stack.pop();
      }
      else
      {
         //check order of operations. If operation on stack has priority
         // pop it off and add to postfix string
         while (!stack.empty() && stack.top() != '(' &&
                getOperations(infix[i]) <= getOperations(stack.top()))
         {
            postfix += ' ';
            postfix += stack.top();           
            stack.pop();
         }
         stack.push(infix[i]);
         postfix += ' ';
      }
   }
   // adds space before the final plus and final multiplier
   postfix += ' '; 
   while (!stack.empty())
   {
      postfix += stack.top();
      postfix += ' ';
      stack.pop();
   }
//remove extra space at the end of the string 
   return postfix.substr(0, postfix.length() - 1);
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;
   int termA;
   int termB;
   // loop through and deal with each term
   /* we need to check for spaces they surround each term. we need
   to move through until we have a number/letter next to an operator 
   then load into term A, if we encounter another space we load
   into term B. If both term A and B are not NULL we use the operator to resolve the equation and load the new value into term A and empty term B. Then check next term if it is a number/letter we
   pull the last operator off the operator list and resolve the equation*/
   /*
   for(int i = 0; i < postfix.length(); i++)
   {
   }
   */
   return assembly;
}


/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
