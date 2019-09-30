/***********************************************************************
 * Header:
 *    Deque
 * Summary:
 *    This will contain the class definition of:
 *       deque             : similar to std::deque
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <cassert>
#include <cmath>
// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

   /************************************************
    * DEQUE
    ***********************************************/
   template <class T>
      class deque
   {
      
     public:
      // constructors and destructors
     deque() : numCapacity(0), data(NULL), iFront(0), iBack(-1) {}
      deque(int newCapacity)
         throw (const char *);
     deque(const deque <T> & rhs)
         throw (const char *);
      ~deque() { delete [] data; }
      
      // assignment operator
      deque <T> & operator = (const deque <T> & rhs)
         throw (const char *);

      //return size
      int size() const { return iBack - iFront + 1; }

      //check if empty, return true if size > 1
      bool empty();
      
      //clear elements in dequeue
      void clear() { iFront = 0; iBack = -1; }

      //push new elements onto the front or back
      void push_back(const T & t)    throw (const char *);
      void push_front(const T & t)   throw (const char *);

      //pop new elements off of the front or back
      void pop_back();
      void pop_front();

      // Access the front or back, either editable or constant
      T front();
      T back();

      private:
      T * data;              // dynamically allocated queue of T
      int iFront;
      int iBack;
      int numCapacity;       // capacity of queue
      
      void resize(int newCapacity);
      int capacity() { return numCapacity; }


      int iNormalize(int i) const
      {
         if ((i % numCapacity) >= 0)
            return (i % numCapacity);
         else
            return (i % numCapacity) + numCapacity;
      }
      int iFrontNormalize() { return iNormalize(iFront); } 
      int iBackNormalize() { return iNormalize(iBack); } 
     
   };

   /**********************************************
    * DEQUE : NON-DEFAULT CONSTRUCTOR
    * Preallocate the deque to "capacity"
    **********************************************/
   template <class T>
      deque <T> :: deque(int newCapacity) throw (const char *)
   {
      // do nothing if there is nothing to do.
      // since we can't grow an array, this is kinda pointless
      if (numCapacity != 0)
      {
         this->numCapacity = 0;
         this->iFront = 0;
         this->iBack = -1;
         this->data = NULL;
         return;
      }
      
      // attempt to allocate
      try
      {
         data = new T[newCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque.";
      }
      
      // copy over the stuff
      this->numCapacity = newCapacity;
      this->iFront = 0;
      this->iBack = -1;
   }
   
   /*******************************************
    * DEQUE :: COPY CONSTRUCTOR
    *******************************************/
   template <class T>
      deque <T> :: deque(const deque <T> & rhs) throw (const char *)
   {
      // do nothing if there is nothing to do
      if (rhs.size() == 0)
      {
         iFront = 0;
         iBack = -1;
         data = NULL;
         numCapacity = 0;
         return;
      }

      //make sure we are starting with a blank slate
      clear();
      
      // attempt to allocate
      try
      {
         data = new T[rhs.numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque.";
      }

      int j = iNormalize(rhs.iFront);
      for (int i = 0; i < abs(rhs.size()); i++,
           j = (j + 1 + rhs.numCapacity) % rhs.numCapacity)
          data[i] = rhs.data[j];


      //set top to match the rhs top
      this->numCapacity = rhs.numCapacity;
      this->iBack = rhs.size() - 1;
      this->iFront = 0;
   }
   
   /*******************************************
    * DEQUE :: Assignment
    *******************************************/
   template <class T>
   deque <T> & deque <T> :: operator = (const deque <T> & rhs)
      throw (const char *)
   {
      //empty deque so new data can be copied over
      if (numCapacity)
      {
         delete [] data;
      }

      // do nothing if there is nothing to do
      if (rhs.size() == 0)
      {
         iFront = 0;
         iBack = -1;
         data = NULL;
         numCapacity = 0;
         return *this;
      }

      //make sure we are starting with a blank slate
      clear();
      
      // attempt to allocate
      try
      {
         data = new T[rhs.numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque.";
      }
      
      
      int j = iNormalize(rhs.iFront);
      
      for (int i = 0; i < abs(rhs.size()); i++,
           j = (j + 1 + rhs.numCapacity) % rhs.numCapacity)
          data[i] = rhs.data[j];


      //set top to match the rhs top
      this->numCapacity = rhs.numCapacity;
      this->iBack = rhs.size() - 1;
      this->iFront = 0;

      return *this;
   }   
   /********************************************
    * Deque : Empty
    * Check if the deque is empty
    *******************************************/
   template <class T>
      bool deque <T> :: empty()
   {
      // return true if deque is empty
      if (size() == 0)
      {
         return true;
      }
      else
         return false;
   }

   /********************************************
    * DEQUE : PUSH_BACK
    * Check for capacity and resize if needed
    * Add element to back of deque
    *******************************************/
   template <class T>
      void deque <T> :: push_back(const T & t) throw (const char *)
   {
      try
      {
           
         if(numCapacity == 0)
            resize(1);
         if (size() == numCapacity)
            resize(numCapacity * 2);
         

         iBack++;
         data[iBackNormalize()] = t;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque";
      }
            
   }

   /********************************************
    * DEQUE : PUSH_FRONT
    * Check for capacity and resize if needed
    * Add element to the front of the deque,
    * increasing the size by 1
    *******************************************/
   template <class T>
      void deque <T> :: push_front(const T & t) throw (const char *)
   {
      try
      {
         if(empty())
      
            if (size() == numCapacity)
               // set capacity to 1 if empty
               if(numCapacity == 0)
                  resize(1);
               // If there are elements in the deque, double it
               else if (numCapacity > 0)
                  resize(numCapacity * 2);
         
         // add item to the front of the deque
         iFront--;
         data[iFrontNormalize()] = t;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque";
      }
            
   }

   /********************************************
    * DEQUE : Pop_back
    * Remove an element from the back of the deque
    *******************************************/
   template <class T>
      void deque <T> :: pop_back()
   {
      if (!empty())
         iBack--;
   }

   /********************************************
    * DEQUE : Pop_front
    * Remove an element from the front of the deque
    *******************************************/
   template <class T>
      void deque <T> :: pop_front()
   {
      if (!empty())
         iFront++;
   }  
      
   /********************************************
    * DEQUE : Front (Getter)
    * Return the most recent element added to
    * the front of the deque
    *******************************************/
   template <class T>
      T deque <T> :: front()
   {
      // the deque is empty, so throw an error
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      
      return data[iFrontNormalize()];
   }


   /********************************************
    * DEQUE : Back (Getter)
    * Return the most recent element added to
    * the back of the deque
    *******************************************/
   template <class T>
      T deque <T> :: back()
   {
      // the deque is empty, so throw an error
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      
      return data[iBackNormalize()];
   }
       
   
   /***************************************************
    * DEQUE: RESIZE
    * Increase the size of the capacity
    **************************************************/
   template <class T>
      void deque <T> :: resize(int newCapacity)
   {
      //create a temp queue that we can use to copy data
      //from the too small deque
      T *temp = new T[newCapacity];
      int j;
      if(numCapacity)
          j = iFrontNormalize();
      else
         j = 0;
      for (int i = 0; i < abs(size()); i++,
           j = (j + 1 + numCapacity) % numCapacity)
         temp[i] = data[j];

      // there are items in the deque
      if (numCapacity)
      {
         //delete all data so we are ready to copy it back
         delete [] data;
      }


      //set our capacity to the new capacity   
      numCapacity = newCapacity;

      //copy data from the temp back into our newly expanded data      
      data = temp;
      iBack = size() - 1;
      iFront = 0;
   };
   
   // namespace custom
}
#endif // DEQUE_H
