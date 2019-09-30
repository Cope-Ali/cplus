/***********************************************************************
 * Header:
 *    Vector
 * Summary:
 *    This class contains the template for a vector: a bucket to hold
 *    data for the user.
 *
 *    This will contain the class definition of:
 *       vector             : 
 *       vector :: iterator : an iterator through the vector
 * Author
 *    Br. Kirby
 ************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>  // because I am paranoid

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

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
  vector(): num(0), numCapacity(0), data(0x00000000) {}
  vector(int num)                  /*throw (const char *)*/;
  vector(int num, vector <T> t) : num(num), numCapacity(num), data(t){}
  vector(const vector <T> & rhs)     /*   throw (const char *)*/;
  ~vector()                         { delete [] data;   }
  vector & operator = (const vector <T>  & rhs)
     /*throw (const char *)*/;
   
   // standard container interfaces
   // array treats size and max_size the same
   int size()     const { return num;                 }
   int capacity() const { return numCapacity;                 }
   
   // array-specific interfaces
   // what would happen if I passed -1 or something greater than num?
   T & operator [] (int index)       throw (const char *)
   {
      return data[index];
   }
   const T & operator [] (int index) const throw (const char *)
   {
      return data[index];
   }
   
   // the various iterator interfaces
   class iterator;
   iterator begin()      { return iterator (data); }
   iterator end();

   // a debug utility to display the array
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
//method empty to determine if anything is in the array
   bool empty() const {return num == 0;}

   //empty the vector
   void clear() {num = 0;}

   //add items to the vector
   void push_back(T t);
   
  private:
   T * data;              // dynamically allocated array of T
   int num;       //the number of elements
   int numCapacity;
   void resize(int newCapacity);
};

/**************************************************
 * ARRAY ITERATOR
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
   return iterator (data + num);
}

/*******************************************
 * VECTOR :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
   //throw (const char *)
{

   //check if they are already the same, no need
   // copy again
   if(this == &rhs)
      return *this;

//set number of elements to zero to revent old data from being copied
   num = 0;
   
   //if the new vector is larger than the original we need to resize the vector
   if(rhs.num > numCapacity)
      resize(rhs.numCapacity);

   //set the number of elements 
   this->num=rhs.num;

// copy each element one by one
   for (int i = 0; i < num; i++)
      data[i] = rhs.data[i];
   
   return *this;
}

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
vector <T> :: vector(const vector <T> & rhs) //throw (const char *)
{
   assert(rhs.num >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.num == 0)
   {
      num = 0;
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
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity
   this->num = rhs.num;
   this->numCapacity = rhs.numCapacity;

   // copy the items over one at a time using the assignment operator
      *this = rhs;
}

/**********************************************
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the array to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector(int num) //throw (const char *)
{
   assert(num >= 0);
   
   // do nothing if there is nothing to do.
   // since we can't grow an array, this is kinda pointless
   if (num == 0)
   {
      this->num = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[num];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->num = num;
   this->numCapacity = num;
}


 
/***************************************************
 *VECTOR : RESIZE
 * Add items to the end of the vector
 **************************************************/
template <class T>
   void vector <T> :: resize(int newCapacity)
{
   T *temp = new T[newCapacity];
   if (data != NULL)
   {

      for (int i = 0; i < num; i++)
      {
         temp[i] = data[i];
      }
      delete [] data;
   }
      data = temp;
      numCapacity = newCapacity;
      
}

/***************************************************
 *VECTOR : PUSH_BACK
 * Check if vector is full and resize the vector
 **************************************************/
template <class T>
   void vector <T> :: push_back(T t)
{
   if (numCapacity == num)
       if(numCapacity == 0)
          resize(1);
       else if (numCapacity > 0)
          resize(numCapacity * 2);
      
   data[num++] = t;
}

/********************************************
 * VECTOR : DISPLAY
 * A debug utility to display the contents of the array
 *******************************************/
template <class T>
void vector <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "vector<T>::display()\n";
   std::cerr << "\tnum = " << num << "\tcapacity = " << numCapacity << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";
#endif // NDEBUG
}

}; // namespace custom

#endif // VECTOR_H

