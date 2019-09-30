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
  Money()
  {
     this -> cents = 0;
     this -> dollars = 0;
  }
   Money(int value)
   {
      setDollars(value);
      cents = 0;
   }
   Money(int valueA, int valueB)
   {
      setDollars(valueA);
      setCents(valueB);
   }
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
         this -> dollars *= -1;
   }
   void setCents(int inCents)
   {
      this -> cents = inCents;
       if (cents < 0 )
         this -> cents *= -1;
   }
};

#endif
