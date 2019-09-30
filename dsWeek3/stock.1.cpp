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
#include "portfolio.h"

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

   /* NOTE FOR ASHLEIGH
   I converted everything into the portfolio and got rid of all the temporary queues. Hopefully that is ok. I saved a backup copy of the old code in backup.cpp
    */
    Portfolio myPortfolio;
    double profit;

   string str;
   int shares = 0;
   double value = 0;
   double proceeds = 0;
   queue <double> soldShares;
   string buy = "buy";
   string sell = "sell";
   string display = "display";
   string quit = "quit";

// get input from user
      cout << "> ";
      cin >> str;
      cin >> shares >> value;
      cout << str;

   // loop through until "quit" is entered by user
   do
   {
      
      // determine which choice was selected
      if (str.compare(buy) == 0)
      {
         
         // add items to new stock object and push into portfolio
         Stock newStock(shares,value);
        myPortfolio.stocks.push(newStock);
        
      }
      else if (str == "sell")
      {
         cin >> shares >> value;
// loop through until we have deducted all of the stock we are selling
while (shares)
{
    Stock frontTemp = myPortfolio.stocks.front();
    //check to see if we are selling less than the shares in our top stock object
    if(frontTemp.getNumStock() > shares)
    {
            // subtract the number of shares sold from
            // the amount currently owned
            frontTemp.setNumStock(frontTemp.getNumStock() - shares);
            // calculate profit
            profit = myPortfolio.profit(shares, frontTemp.getValue(), value);
            
            //push sold information into queue for display
            soldShares.push(shares);
            soldShares.push(value);
            soldShares.push(profit);

            //we filled the order so shares to sell = 0
            shares = 0;
    }
    //if we don't have enough in the first stock, we will subtract how many we do have have from the total we are selling, then pop the first stock off the top of the queue so we can start the process over with the next stock in queue
    else
    {
        // calculate profit
            profit = myPortfolio.profit(shares, frontTemp.getValue(), value);

             //push sold information into queue for display
            soldShares.push(shares);
            soldShares.push(value);
            soldShares.push(profit);

            //subract the shares available from first stock to get remaining shares to sell
        shares - frontTemp.getNumStock();
        // we have now sold all of the shares from the top stock so we will pop it off
        myPortfolio.stocks.pop();
    }
}
        
      }
      else if (str == "display")
      {
        queue <Stock> temp = myPortfolio.stocks;
         // display this if there are shares to display
         if (!myPortfolio.stocks.empty())
         {
            cout << "Currently held:\n";

            
        
            // display all of the shares and values until empty
            while (!temp.empty())
            {
                Stock tempFront = temp.front();
               // display the items at the front of the queue
               cout << "\tBought ";
               cout << tempFront.getNumStock();
               cout << " shares at ";
               cout << tempFront.getValue() << endl;

               // remove the items that have already been displayed
               temp.pop();
            }
         }
         
         // display this if shares have been sold
         if (!soldShares.empty())
         {            
            cout << "Sell History:\n";

            // display sold shares and values until empty
            while (!soldShares.empty())
            {
               cout << "\tSold ";
               cout << soldShares.front();
               soldShares.pop();
               cout << " shares at ";
               cout << soldShares.front();
               soldShares.pop();
               cout << " for a profit of ";
               cout << soldShares.front() << endl;
               proceeds =+ soldShares.front();
               soldShares.pop(); 
            }

            Dollars totalProceeds (proceeds);

         }
         Dollars totalProceeds (proceeds);
         cout << "Proceeds: ";
         cout << totalProceeds << endl;
      }
   }
   while (str != "quit");

}


