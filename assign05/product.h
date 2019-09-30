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
  private:
   std::string name;
   float basePrice;
   float weight;
   std::string description;
  
  public:
  Product()
  {
     name = "none";
     description = "";
     weight = 0;
     basePrice = 0;
  }

  Product(std::string name, std::string description,
          float basePrice, float weight)
  {
     this -> name = name;
     this -> description = description;
     this -> basePrice = basePrice;
     this -> weight = weight;
  }

  float getSalesTax();
  float getShippingCost();
  float getTotalPrice();
  std::string getName() const {return name;}
  std::string getDescription() const {return description;}
  float getBasePrice() const {return basePrice;}
  float getWeight () const {return weight;}
  
  void setName(std::string name){this -> name = name;}
  void setDescription(std::string description)
  {this -> description = description;}
  void setBasePrice(float basePrice){this -> basePrice = basePrice;}
  void setWeight(float weight){this -> weight = weight;}

  void prompt();
  void displayAdvertising();
  void displayInventory();
  void displayReceipt();
   
};

#endif
