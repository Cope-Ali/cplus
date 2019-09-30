/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
using std::cerr;
#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   //New Node p0 will be the head that will correspond with array[0]
   Node <T> * p0 = NULL;
   
   //p0 = insert(p0, array[0]);
 
//Loop through all of the items in the array    
   for(int i = 0; i < num; i++)
   {
      //check if we are at the front of the linked list.
      //If pointer is null we haven't added anything yet.
      if (p0 == NULL)
      {
         //add item to the front of the list
         p0 = insert(p0, array[i], false);
      }
      // check to see if the data at pointer is less than data in array
      else if (p0->data < array[i])
      {
// loop through to find where the item in the array should go. 
         for (Node<T> * pi = p0; pi;)
         {
            //if data is greater than the element in the array,
            //insert in front of the greater element and set pointer to
            // NULL to exit loop
          if (pi->data > array[i])
           {
            insert(pi, array[i], false);
            pi = NULL;
           }
// if pointer data is less than the element in the array then move
          //to the next element and if it is null insert the item behind
          //>>>>>> If we set pi to the next element and it is null won't we
          // exit the for statement?<<<<<<
          else
          {
             // pi = pi->pNext;
              if (pi->pNext == NULL)
              {
                 insert(pi->pNext, array[i], true);
                 pi = pi->pNext;
              }
              else
                 pi = pi->pNext;
          } 
        }      
      }
      //if pointer data is greater than the array then insert at the end
      else
      {
         p0 = insert(p0, array[i], false);
      }
   }

// This loop is saving everything back into the array in the new order
   int i = 0;
    for (Node<T> * pi = p0; pi;)
    {

       array[i] = pi->data;

       i++;
       pi = pi->pNext;

    }
   
   freeData(p0);
   
}

#endif // INSERTION_SORT_H

