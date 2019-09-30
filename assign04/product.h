/***************************************************************************
 * File: product.h
 * Author: Ali Cope
 * Purpose: Product class including name, base price, weight and description
 *          methods include:
 *            prompt(to set values to the current product)
 *            getSalesTax( to caluclate sales tax at 6% of baseprice)
 *            getShippingCost( $2 if under 5lbs $2 + 0.10/lbs if over 5lbs)
 *            getTotalPrice (include baseprice, sales tax and shipping cost)
 *            displayAdvertising( display name, base price, and description)
 *            displayInventory( display base price, sales tax, shipping cost,
 *                             and total price)
 *            displayReceipt(display name, base price, sales tax, shipping
 *                             cost and total price)
 *
 ************************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

// put your class definition here
class Product
{
  public:
   std::string name;
   float basePrice;
   float weight;
   std::string description;
   void prompt();
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();
   
  private:

};

#endif
