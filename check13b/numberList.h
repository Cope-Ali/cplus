/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }
   NumberList(int size)
   {
       this->size = size;
       array=new int[size];
       for (int i=0; i<size; i++)
       {
           setNumber(i,0);
       }
   }
   ~NumberList()
   {
       delete array;
       array = NULL;
       std::cout << "Freeing Memory";
   }


   // TODO: Add your constructor and destructor



   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
