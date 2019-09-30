/***********************************************************************
 * Header:
 *    Vector
 * Summary:
 *    This class contains the notion of a vector, modified from an array
 *    the size of the vector is dynamic and one more element can always
 *    be added to the end of the current "array"
 *
 *
 *    This will contain the class definition of:
 *       vector             : similar to std::vector
 *       vector :: iterator : an iterator through the vector
 * Author
 *    Br. Helfrich/George Brown
 ************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>  // because I am paranoid
#include <iostream>


// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG
using std::cerr;


namespace custom
{

   /************************************************
    * VECTOR
    * A class that holds stuff
    ***********************************************/
   template <class T>
      class vector
   {
     public:
      // constructors and destructors
      vector() {numElements= 0; numCapacity = 0; data = NULL;}
      vector(int num)                  throw (const char *);
      vector(const vector & rhs)        throw (const char *);
      ~vector()                         { delete [] data;   }
      vector & operator = (const vector & rhs) throw (const char *);

      // standard container interfaces
      // size is number of Elements, Capacity is max size
      int  size()     const { return numElements;                 }
      int  capacity() const { return numCapacity;                 }

      // what would happen if I passed -1 or something greater than num?
      T & operator [] (int index)       throw (const char *)
      {
         return data[index];
      }
      const T & operator [] (int index) const throw (const char *)
      {
         return data[index];
      }

  
      //other functions necessary for vector but not array
      bool empty() { if (numElements < 1) return true; else return false;}
      void resize(int cNew);
      void clear() { this->numElements = 0; }
      void push_back(T t);


      // the various iterator interfaces
      class iterator;
      iterator begin()      { return iterator (data); }
      iterator end();

      // a debug utility to display the array
      // this gets compiled to nothing if NDEBUG is defined
      void display() const;

     private:
      T * data;              // dynamically allocated array of T
      int numCapacity;      //the capacity of the vector
      int numElements;     //the number of elements the vector has
      
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through array
 *************************************************/
template <class T>
class vector <T> :: iterator
{
  public:
   // constructors, destructors, and assignment operator
  iterator()      : p(NULL)      {              }
  iterator(T * p) : p(p)         {              }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
   T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
      iterator tmp(*this);
      p++;
      return tmp;
   }

  private:
   T * p;
};


/********************************************
 * VECTOR :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: iterator vector <T> :: end ()
{
   return iterator (data + numElements);
}

/*******************************************
 * VECTOR :: Resize
 *******************************************/
template <class T>
void vector <T> :: resize(int cNew)
{

   //for a vector that is at 0, it must start somewhere
   if (cNew == 0)
      cNew = 1;

   //the temporary pointer to be the new size
   T * newData = new T[cNew];

   //loop to copy the data over
   for (int i = 0; i < numElements; i++)
   {
      newData[i] = data[i];

   }

   //delete the old pointer
   delete [] data;
   data = NULL;

   //set the old pointer to the new pointer, c
   data = newData;

   //sets capacity to new max size
   this->numCapacity = cNew;

}

/*******************************************
 * VECTOR :: Push_Back
 *******************************************/
template <class T>
void vector <T> :: push_back(T t)
{

   //condition one, there is enough room
   if (size() < capacity())
   {

      //add the new element in and expand the size
      //to reflect this
      data[numElements] = t;
      this->numElements++;
   }

   //condition 2, there is not enough room
   else
   {
      //resize vector to have enough room
      resize(numCapacity * 2);

      //add the new element in and expand the size
      //to reflect this
      data[numElements] = t;
      this->numElements++;


   }


}



/*******************************************
 * VECTOR :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
   throw (const char *)
{
   assert (rhs.numElements >= 0);

   // check size 0 and assign
   if (rhs.numElements == 0)
   {
      numElements = 0;
      data = NULL;
      return * this;
   }




   // attempt to allocate
          try
   {
      data = new T[rhs.numElements];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   // copy over the capacity
   numCapacity = rhs.numCapacity;
   numElements = rhs.numElements;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numElements; i++)
      data[i] = rhs.data[i];

   return * this;

}

/*******************************************
 * ARRAY :: COPY CONSTRUCTOR
 *******************************************/
   template <class T>
   vector <T> :: vector(const vector <T> & rhs) throw (const char *)
   {



      assert (rhs.numElements >= 0);

      // check for 0 and assign
      if (rhs.numElements == 0)
      {
         numElements = 0;
         numCapacity = 0;
         data = NULL;
         return;
      }




      // attempt to allocate
         try
         {
            data = new T[rhs.numElements];
         }
         catch (std::bad_alloc)
         {
            throw "ERROR: Unable to allocate buffer";
         }

         // copy over the capacity
         numCapacity = rhs.numCapacity;
         numElements = rhs.numElements;

         // copy the items over one at a time using the assignment operator
         for (int i = 0; i < numElements; i++)
            data[i] = rhs.data[i];
   }

/**********************************************
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector(int num) throw (const char *)
{

   //set array size and capacity to parameter
   this->numElements = num;
   this->numCapacity = num;

   //check for 0 and assign to 0 if it is empty
   assert(num >= 0);

   if (num == 0)
   {
      this->numElements = 0;
      this->numCapacity = 0;
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
         throw "ERROR: Unable to allocate buffer";
      }




}

/********************************************
 * VECTOR : DISPLAY
 * A debug utility to display the contents of the array
 *******************************************/
template <class T>
void vector <T> :: display() const
{
   #ifndef NDEBUG
   std::cerr << "array<T>::display()\n";
   std::cerr << "\tnum = " << numElements << "\n";
   for (int i = 0; i < numElements; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";
#endif // NDEBUG
}

}; // namespace custom

#endif // VECTOR_H

