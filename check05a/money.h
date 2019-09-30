/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
   void prompt();
   void display() const;
   int getDollars () const
   { 
      return dollars;
   }
   int getCents() const
   {
      return cents;
   }
   void setDollars(int inDollars)
   {
      this -> dollars = inDollars;
      if (dollars < 0)
         dollars *= -1;
   }
   void setCents(int inCents)
   {
      this -> cents = inCents;
       if (cents < 0 )
         cents *= -1;
   }
};

#endif
