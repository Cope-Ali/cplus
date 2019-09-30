/***********************************************************************
 * Header:
 *    SET
 * Summary:
 *    This will contain the class definition of:
 *       set             : similar to std::set
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef SET_H
#define SET_H
//using std::cerr;

namespace custom
{

/****************************************
 * SET
 ****************************************/
template <class T>
   class set
{
   
  private:
   T * data;
   int numElements;
   int numCapacity;

   void resize(int newCapacity);
   int findIndex(/*const*/ T & t);

  public:
   // constructors and destructors
  set() : numCapacity(0), numElements(0), data(NULL) {}
   set(int newCapacity) throw (const char *);
   set(const set <T> & rhs) throw (const char *);
   ~set() { delete [] data; }

   // assignment operator
   set <T> & operator = (const set <T> & rhs) 
      throw (const char *);

   //return size
   int size() const { return numElements; }

   //check if empty, return true if size > 1
   bool empty() const { return numElements == 0; }
      
   //clear elements in set
   void clear() { numElements = 0; }

   // the various iterator interfaces
   class iterator;
   iterator begin() { return iterator (data); }
   iterator end() { return iterator (data + numElements); }

   // the various const iterator interfaces
   class const_iterator;
   const_iterator cbegin() const { return const_iterator(data); }
   const_iterator cend() const { return const_iterator(data + numElements); }
   
   // find an item in the set
   iterator find(/*const*/ T & t);
   //insert item into set
   void insert(T t); 
   // erase item in the set
   iterator erase(iterator & it);
   // union operator
   set <T> operator || (const set <T> & rhs)
      throw (const char *);
   // intersection operator
   set <T> operator && (const set <T> & rhs)
      throw (const char *);
   // difference operator
   set <T> operator - (const set <T> & rhs) 
      throw (const char *);

   // place the set in order
   void reOrderSet();
   void swap(T & set1, T & set2);
};

/**************************************************
 * ITERATOR
 * An iterator through the set
 *************************************************/
template <class T>
   class set <T> :: iterator
{
  private:
   T * p;
   
  public:
   // constructors and destructors
  iterator() : p(NULL) {}
  iterator(T * p) : p(p) {}
   iterator(const iterator & rhs) { *this = rhs; }

   // assignment operator
   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator == (const iterator & rhs) const { return rhs.p == this->p; }
   bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
   
   // increment
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
   
   // decrement
   iterator & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
      iterator tmp(*this);
      p--;
      return tmp;
   }
   
   // dereference operator
   T & operator * ()       { return *p; }
};

/**************************************************
 * CONSTANT ITERATOR
 * constant iterator through the set
 *************************************************/
template <class T>
   class set <T> :: const_iterator
{
  private:
   T * p;

  public:
   // constructors and destructors
  const_iterator() : p(NULL) {}
  const_iterator(T * p) : p(p) {}
   const_iterator(const const_iterator & rhs) { *this = rhs; }

   // assignment operator
   const_iterator & operator = (const const_iterator & rhs) 
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator == (const const_iterator & rhs) const { return rhs.p == this->p; }
   bool operator != (const const_iterator & rhs) const { return rhs.p != this->p; }

   // increment
   const_iterator & operator ++ () 
   {
      p++;
      return *this;
   }

   // postfix increment
   const_iterator operator ++ (int postfix) const
   {
      iterator tmp(*this);
      p++;
      return tmp;
   }

   // decrement
   const_iterator & operator -- () const
   {
      p--;
      return *this;
   }

   // postfix decrement
   const_iterator operator -- (int postfix) const
   {
      iterator tmp(*this);
      p--;
      return tmp;
   }

   // dereference operator
   T & operator * () const        { return *p; }
   
};

/**********************************************
 * SET : NON-DEFAULT CONSTRUCTOR
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
   set <T> :: set(int newCapacity) throw (const char *)
{
   // do nothing if there is nothing to do.
   if (newCapacity == 0)
   {
      this->numElements = 0;
      this->numCapacity = 0;
      data = NULL;
      return;
   } 

   // attempt to allocate
   try
   {
      data = new T[newCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for set.";
   }
      
   // copy over the stuff
   this->numCapacity = newCapacity;
   this->numElements = 0;
}

/*******************************************
 * SET :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
   set <T> :: set(const set <T> & rhs) throw (const char *)
{
   // do nothing if there is nothing to do
   if (rhs.size() == 0)
   {
      numCapacity = 0;
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
      throw "ERROR: Unable to allocate a new buffer for set.";
   }
   
   // set to match rhs
   this->numCapacity = rhs.numCapacity;
   this->numElements = rhs.numElements;

   // copy the items over one at a time
   // using the assignment operator
   *this = rhs;

}

/*******************************************
 * SET :: Assignment
 *******************************************/
template <class T>
   set <T> & set <T> :: operator = (const set <T> & rhs)
   throw (const char *)
{
   //check if they are already the same, no need
   // copy again
   if(this == &rhs)
      return *this;
   
   if(rhs.numCapacity == 0)
   {
      numCapacity = 0;
      numElements = 0;
      data = NULL;
      return *this;
   }
   
   //set number of elements to zero to
   // prevent old data from being copied
   numElements = 0;

   //if the new set is larger than the original
   //we need to resize the set
   if(rhs.numCapacity > numCapacity)
      resize(rhs.numCapacity);
   
   //set the number to match the rhs
   this->numElements = rhs.numElements;
   
   // copy each element one by one
    for (int i = 0; i < rhs.numElements; i++)
       data[i] = rhs.data[i];

   // set capacity to rhs
   this->numCapacity = rhs.numCapacity;

   return *this; 
}

/**************************************************
 *SET : RESIZE
 * increase capacity 
 **************************************************/
template <class T>
   void set <T> :: resize(int newCapacity)
{
   
   T *temp = new T[newCapacity];

   if (data != NULL)
   {
      for (int i = 0; i < size(); i++)
      {
         temp[i] = data[i];
      }
      // delete all data so we are ready to copy it back
      delete [] data;
   }
   
   // set our capacity to the new capacity
   numCapacity = newCapacity;

   // copy data from the temp back into
   // our newly expanded data   
   data = temp; 
}

/***************************************************
 * SET : FIND INDEX
 * Find an element in the set
 **************************************************/
template <class T>
   int set <T> :: findIndex(/*const*/ T & t) 
{
   int iBegin = 0;
   int iMiddle;
   int iEnd = numElements - 1;

   // start from begining to end looking for element
   while(iBegin <= iEnd)
   {
      iMiddle = (iBegin + iEnd) / 2;
      if (t == data[iMiddle])
         return iMiddle;
      if (t < data[iMiddle])
         iEnd = iMiddle - 1;
      else
         iBegin = iMiddle + 1;
   }
   return numElements;
}

/***************************************************
 * SET : FIND ITERATOR
 * Use an iterator to find an item in the set
 **************************************************/
template <class T>
   typename set <T> :: iterator set <T> :: find (/*const*/ T & t)
{
   // find the element we're looking for
   int index = findIndex(t);

   // element was not found
   if (index < 0)
      return end();

   set <T> :: iterator it (&data[index]);
   
   return it;
}

/***************************************************
 * SET : INSERT
 * Add items to the end of the set
 **************************************************/
template <class T>
   void set <T> :: insert(T t)
{
   // find the element in the set
   int iInsert = findIndex(t);     
  
   // resize if more space is needed
   if (numCapacity == 0)
      resize(1);
   if(numCapacity == numElements)
      resize(numCapacity * 2);   
   
   // We didn't find the element, increase the
   // size and insert the element
   if (iInsert == numElements)
   {
      if(numElements < numCapacity)
      {
         numElements++;
         data[iInsert] = t;
      }
      // place the set in the right order
      reOrderSet();
   }
 }

/**********************************************
 * SET : REORDER SET
 * Place elements in the correct order
 **************************************************/
template <class T>
   void set <T> :: reOrderSet()
{
   int before = 0;
   int after = 0;

   // loop through all elements in the set
   for (int i = 0; i < size(); i++)
   {
      before = i;

      for (int j = i + 1; j < size(); j++)
      {
         after = j;
         // swap elements so they appear in the
         // correct order
         if (data[after] < data[before])
            before = after;
         swap(data[i], data[before]);
      }
   }
}

/**********************************************
 * SET : SWAP
 * swap elements in the set
 **************************************************/
template <class T>
   void set <T> :: swap(T & set1, T & set2)
{
   T temp;
   temp = set1;
   set1 = set2;
   set2 = temp;
}

/***************************************************
 * SET : ERASE
 * Erase an element from the set
 **************************************************/
template <class T>
   typename set <T> :: iterator set <T> ::
   erase( set <T> :: iterator & it)
{
   // find the element in the set
   int iErase = findIndex(*it);

   // if the element is found, loop through and erase
   if (data[iErase] == *it)
   {
      for (int i = iErase; i < numElements - 1; i++)
         data[i] = data[i + 1];

      numElements--;
   }
 
}

/***************************************************
 * SET : UNION OPERATOR
 * Create a new set that includes elements either in
 * one set or the other
 **************************************************/
template <class T>
   set <T> set <T> :: operator || (const set <T> & rhs)
   throw (const char *)
{
  
   set <T> setReturn;
   int iSet1 = 0;
   int iSet2 = 0;

   while(iSet1 < numElements || iSet2 < rhs.numElements)
   {
      if (iSet1 == numElements)
         setReturn.insert(rhs.data[iSet2++]);
      else if (iSet2 == rhs.numElements)
         setReturn.insert(data[iSet1++]);
      else if (data[iSet1] == rhs.data[iSet2])
      {
         setReturn.insert(data[iSet1]);
         iSet1++;
         iSet2++;
      }
      else if (data[iSet1] < rhs.data[iSet2])
         setReturn.insert(data[iSet1++]);
      else
         setReturn.insert(rhs.data[iSet2++]);
   }

   return setReturn;   
}

/***************************************************
 * SET : INTERSECTION OPERATOR
 * Create a new set that includes elements that are
 * in common in both sets
 **************************************************/
template <class T>
   set <T> set <T> :: operator && (const set <T> & rhs)
   throw (const char *)
{
   set <T> setReturn;
   int iSet1 = 0;
   int iSet2 = 0;

   while(iSet1 < numElements || iSet2 < rhs.numElements)
   {
      if (iSet1 == numElements)
         return setReturn;
      else if (iSet2 == rhs.numElements)
         return setReturn;
      else if (data[iSet1] == rhs.data[iSet2])
      {
         setReturn.insert(data[iSet1]);
         iSet1++;
         iSet2++;
      }
      else if (data[iSet1] < rhs.data[iSet2])
         iSet1++;
      else
         iSet2++;
   }

   return setReturn;
}

/***************************************************
 * SET : DIFFERENCE OPERATOR
 * Create a new set that includes elements that are
 * in common in one set and not the other
 **************************************************/
template <class T>
   set <T> set <T> :: operator - (const set <T> & rhs)
   throw (const char *)
{
   set <T> setReturn;
   int iSet1 = 0;
   int iSet2 = 0;

   while(iSet1 < numElements || iSet2 < rhs.numElements)
   {
      if (iSet1 == numElements)
         return setReturn;
      else if (iSet2 == rhs.numElements)
         setReturn.insert(data[iSet1++]);
      else if (data[iSet1] == rhs.data[iSet2])
      {
         iSet1++;
         iSet2++;
      }
      else if (data[iSet1] < rhs.data[iSet2])
         setReturn.insert(data[iSet1++]);
      else
         iSet2++;
   }
   
   return setReturn; 
}

}; // end namespace

#endif // SET_H
