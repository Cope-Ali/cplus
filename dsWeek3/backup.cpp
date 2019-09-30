/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Ashleigh Walter & Ali Cope
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
#include "dollars.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
//using namespace std;
using namespace custom;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
// instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   string str;
   int shares = 0;
   Dollars value = 0;
   Dollars proceeds = 0;

   queue <int> newNumShares;
   queue <Dollars> newValue;
   queue <int> soldShares;
   queue <Dollars> soldValue;
   queue <Dollars> profit;
   
   // temp queues for copying data
   queue <int> tempNumShares;
   queue <Dollars> tempValue;
   queue <int> tempSoldShares;
   queue <Dollars> tempSoldValue;
   queue <Dollars> tempProfit;

   // loop through until "quit" is entered by user
   do
   {
      // get input from user
      cout << "> ";
      cin >> str;

      // determine which choice was selected
      if (str == "buy")
      {
         cin >> shares >> value;
         // add items to seperate queues
         newNumShares.push(shares);
         newValue.push(value);
      }
      else if (str == "sell")
      {
         try
         {
            cin >> shares >> value;
            
            //check to see if we can fill the order with the top stock
            if(newNumShares.front() > shares)
            {
            
               // subtract the number of shares sold from
               // the amount currently owned
               newNumShares.front() -= shares;
               // add items to seperate queues
               if(shares > 0)
               {
                  soldShares.push(shares);
                  soldValue.push(value);
                  // compute the profit from the shares sold
                  profit.push((value - newValue.front()) * shares);
               }
            }
            else
            {
               int tempShares = shares - newNumShares.front();
               soldShares.push(newNumShares.front());
               soldValue.push(value);
               // compute the profit from the shares sold
               profit.push((value - newValue.front()) * newNumShares.front());
               newNumShares.pop();
               newValue.pop();
               shares = tempShares;
               
               // take the rest out of the next batch of stocks
               // subtract the number of shares sold from
               // the amount currently owned
               newNumShares.front() -= shares;
               if (shares > 0)
               {
                  // add items to   seperate queues
                  soldShares.push(shares);
                  soldValue.push(value);
                  // comp  ute the profit from the shares sold
                  profit.push((value - newValue.front()) * shares);
               }
            }
         }
         catch (const char *)
         {
            //cout << "ERROR: attempting to access an element in an empty queue\n";     
         }
      }   
      else if (str == "display")
      {
         // display this if there are shares to display
         if (!newNumShares.empty())
         {
            // copy the elements over to a temp queue
            tempNumShares = newNumShares;
            tempValue = newValue;
         
            cout << "Currently held:\n";
        
            // display all of the shares and values until empty
            while (!tempNumShares.empty())
            {
               // display the items at the front of the queue
               cout << "\tBought ";
               cout << tempNumShares.front();
               cout << " shares at ";
               cout << tempValue.front() << endl;
               
               // remove the items that have already been displayed
               tempNumShares.pop();
               tempValue.pop();
            }
            // clear the queues so we can start fresh next time
            tempNumShares.clear();
            tempValue.clear();
         }
         
         // display this if shares have been sold
         if (!soldShares.empty())
         {
            // copy the elements over to a temp queue
            tempSoldShares = soldShares;
            tempSoldValue = soldValue;
            tempProfit = profit;
            
            cout << "Sell History:\n";

            // display sold shares and values until empty
            while(!tempSoldShares.empty())
            {
               cout << "\tSold ";
               cout << tempSoldShares.front();
               cout << " shares at ";
               cout << tempSoldValue.front();
               cout << " for a profit of ";
               cout << tempProfit.front() << endl;

               proceeds = proceeds + tempProfit.front();

               // remove the items that have already been displayed
               tempSoldShares.pop();
               tempSoldValue.pop();
               tempProfit.pop();
            }

            // clear the queues so we can start fresh next time
            tempSoldShares.clear();
            tempSoldValue.clear();
            tempProfit.clear();
       
         }
         cout << "Proceeds: ";
         cout << proceeds << endl;        
         proceeds = 0;
      }
   }
   while (str != "quit");
}




