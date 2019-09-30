// File: order.cpp
#include <iostream>
#include <string>

using namespace std;

#include "product.h"
#include "address.h"
#include "customer.h"
#include "order.h"

// Put your the method bodies for your order class here

string Order :: getShippingZip() const
{
   Address tempAddress = customer.getAddress();
   return tempAddress.getZip();
}

float Order :: getTotalPrice() const
{
   Product tempProduct = getProduct();
   float total =  tempProduct.getTotalPrice() * getQuantity();
   return total;
}

void Order :: displayShippingLabel() const
{
   Customer tempCustomer = getCustomer();
   tempCustomer.display();
}

void Order :: displayInformation() const
{
   Customer tempCustomer = getCustomer();
   Product tempProduct = getProduct();
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << tempCustomer.getName() << endl
        << tempProduct.getName() << endl
        << "Total Price: $" << getTotalPrice() << endl;
}
