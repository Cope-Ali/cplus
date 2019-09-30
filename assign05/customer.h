// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "address.h"

// put your Customer class here

class Customer
{
  public:
   Customer()
   {
      this -> name = "unspecified";
      this -> address = Address();
   }
   
   Customer(std::string name, Address address)
   {
      this -> name = name;
      this -> address = Address(address);
   }

   std::string getName() const {return name;}
   Address getAddress() const {return address;}
   
   void setName(std::string name){this -> name = name;}
   void setAddress(Address address){this -> address = address;}
   void display();

  private:
   std::string name;
   Address address;

};

#endif
