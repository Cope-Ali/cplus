/***********************************************************************
 * Header:
 *    Stack
 * Summary:
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    Ashleigh Walter, Ali Cope
 ************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cassert>

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

   /************************************************
    * STACK
    ***********************************************/
   template <class T>
      class stack
   {
     private:
      T * data;              // dynamically allocated stack of T
      int numElements;       // number of elements in the stack
      int numCapacity;       // capacity of stack
      void resize(int numCapacity);
      
     public:
      // constructors and destructors
     stack() : numElements(0), numCapacity(0), data(NULL) {}
      stack(int numCapacity)            throw (const char *);
      stack(const stack <T> & rhs)      throw (const char *);
      ~stack()                            { delete [] data; }
      
      // assignment operator
      stack & operator = (const stack & rhs) throw (const char *);
      
      int  size()     const { return numElements; } // return size
      int  capacity() const { return numCapacity; } // return capacity
      bool empty()    const;
      void clear() { numElements = 0; } // clear elements in stack
      void push(T t);
      void pop();
      T top()         const  throw (const char *);
      T& top()               throw (const char *);
   };
   
   /**********************************************
    * STACK : NON-DEFAULT CONSTRUCTOR
    * Preallocate the stack to "capacity"
    **********************************************/
   template <class T>
      stack <T> :: stack(int numCapacity) throw (const char *)
   {
      assert(numCapacity >= 0);
      
      // do nothing if there is nothing to do.
      // since we can't grow an array, this is kinda pointless
      if (numCapacity != 0)
      {
         this->numCapacity = 0;
         this->numElements = 0;
         this->data = NULL;
         return;
      }
      
      // attempt to allocate
      try
      {
         data = new T[numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack.";
      }
      
      
      // copy over the stuff
      this->numCapacity = numCapacity;
      this->numElements = numElements;
   }
   
   /*******************************************
    * STACK :: COPY CONSTRUCTOR
    *******************************************/
   template <class T>
      stack <T> :: stack(const stack <T> & rhs) throw (const char *)
   {
      assert(rhs.numElements >= 0);
      
      // do nothing if there is nothing to do
      if (rhs.numElements == 0)
      {
         numElements = 0;
         data = NULL;
         return;
      }
      
      // attempt to allocate
      try
      {
         data = new T[rhs.numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack.";
      }
      
      // copy the items over one at a time using the assignment operator
      for (int i = 0; i < rhs.numElements; i++)
         data[i] = rhs.data[i];
      
      //set top to match the rhs top
      this->numElements = rhs.numElements;
   }
   
   /*******************************************
    * STACK :: Assignment
    *******************************************/
   template <class T>
      stack <T> & stack <T> :: operator = (const stack <T> & rhs)
      throw (const char *)
      {
         //empty stack so new data can be copied over
         clear();
         
         try
         {
            // make sure that there is capacity for the
            // number of elements we are adding
            if (numCapacity < rhs.numElements)
               resize(rhs.numElements);
         }
         catch (std::bad_alloc)
         {
            throw "ERROR: Unable to allocate a new buffer for stack.";
         }
         
         //copy over each item
         for (int i = 0; i < rhs.numElements-1; i++)
            data[i] = rhs.data[i];
         
         numElements = rhs.numElements;
         
         return *this;
      }
   
   /********************************************
    * STACK : Empty
    * Check if the stack is empty
    *******************************************/
   template <class T>
      bool stack <T> :: empty() const
   {
      // return true if stack is empty
      if (numElements == 0)
         return true;
      else
         return false;
   }
   
   /********************************************
    * STACK : PUSH
    * Check for capacity and resize if needed
    * Add new item to top of stack
    *******************************************/
   template <class T>
      void stack <T> :: push(T t)
   {
      if (numElements == numCapacity)
         // set capacity to 1 if empty
         if(numCapacity == 0)
            resize(1);
      // If there are elements in the stack, double it
         else if (numCapacity > 0)
            resize(numCapacity * 2);
      
      // add item to the stack
      data[numElements++] = t;
   }
   
   /********************************************
    * STACK : Pop
    * Remove the last element from the stack
    *******************************************/
   template <class T>
      void stack <T> :: pop()
   {
      if (!empty())
         numElements--;
   }
   
   /********************************************
    * STACK : Top (Getter)
    * Return the last element added to the stack
    *******************************************/
   template <class T>
      T stack <T> :: top() const throw(const char *)
   {
      // the stack is empty, so throw an error
      if (empty())
         throw "ERROR: Unable to reference the element from an empty Stack";
      
      return data[numElements - 1];
   }
   
   /********************************************
    * STACK : Top (Setter)
    * Return the last element added to the stack
    *******************************************/
   template <class T>
      T & stack <T> :: top() throw(const char *)
   {
      // the stack is empty, so throw an error
      if (empty())
         throw "ERROR: Unable to reference the element from an empty Stack";
      
      return data[numElements - 1];
   }
   
   /***************************************************
    *STACK: RESIZE
    * Increase the size of the capacity
    **************************************************/
   template <class T>
      void stack <T> :: resize(int newCapacity)
   {
      T *temp = new T[newCapacity];
      
      // there are items in the stack
      if (data != NULL)
      {
         // copy the data over
         for (int i = 0; i < numElements; i++)
         {
            temp[i] = data[i];
         }
         
         delete [] data;
      }
      
      data = temp;
      numCapacity = newCapacity;
   };
   
} // namespace custom

#endif // STACK_H
