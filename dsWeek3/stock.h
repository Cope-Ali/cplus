/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell() and 
 *    display().
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM

using namespace custom;

// the interactive stock buy/sell function
void stocksBuySell();

// display the shares and their information
void display(queue <int> newNumShares, queue <Dollars> newValue,
             queue <int> soldShares, queue <Dollars> soldValue,
             queue <Dollars> profit, Dollars proceeds);

#endif // STOCK_H

