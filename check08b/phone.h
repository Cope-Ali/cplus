/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H

// TODO: Put your phone class definition here...
class Phone
{
  public:
   void promptNumber();
   void display();
   
  private:
   int areaCode;
   int prefix;
   int suffix;
};


#endif
