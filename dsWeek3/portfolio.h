/***********************************************************************
 * Header:
 *    PORTFOLIO
 * Summary:
 *    This contains the class for portfolio and will hold the number of
 *    shares, value and profit.
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include "stock.h"
#include <iostream>    // for ISTREAM and OSTREAM
namespace custom
{

//A portfolio is a queue of different stocks. So it will only have one member. That is a queue of stocks)
class Portfolio
{
  public:
   queue <Stock> stocks;
  
  Portfolio(){}
  Portfolio(Stock newStock)
   {
     stocks.push(newStock);
    
    }
    
  double profit (int sharesSold, double startingValue, double saleValue)
    {
      double money = (sharesSold * saleValue) - (sharesSold * startingValue);
      return money;
    }

};
}
#endif // PORTFOLIO_H
