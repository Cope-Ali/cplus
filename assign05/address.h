// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
// Put your Address class here

class Address
{
  public:
   Address()
   {
      street = "unknown";
      city = "";
      state = "";
      zip = "00000";
   }
   Address(std::string inA, std::string inB, std::string inC, std::string inD)
   {
      setStreet(inA);
      setCity(inB);
      setState(inC);
      setZip(inD);
   }
   std::string getStreet() const {return street;}
   std::string getCity() const {return city;}
   std::string getState() const {return state;}
   std::string getZip() const {return zip;}
   void setStreet(std::string inStreet)
   {
      this -> street = inStreet;
   }
   void setCity(std::string inCity)
   {
      this -> city = inCity;
   }
   void setState(std::string inState)
   {
      this -> state = inState;
   }
   void setZip (std::string inZip)
   {
      this -> zip = inZip;
   }
   void display();
   
  private:
   std::string street;
   std::string city;
   std::string state;
   std::string zip;
};


#endif
