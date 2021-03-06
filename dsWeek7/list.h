/***********************************************************************
 * Header:
 *    List
 * Summary:
 *    This will contain the class definition of:
 *       list             : similar to std::list
 * Author
 *    Ashleigh Walter, Ali Cope & George Brown
 ************************************************************************/

#ifndef LIST_H
#define LIST_H

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
* LIST
***********************************************/
   template <class T>
      class list
   {
     public:
      // constructors and destructors
     list() : pHead(NULL), pTail(NULL), numElements(0) {}
      list(const list <T> & rhs) throw (const char *);
      ~list() { clear(); }
      
      // assignment operator
      list <T> & operator = (const list <T> & rhs)
         throw (const char *);
      
      //return size
      int size() const { return numElements; }
      
      //check if empty
      bool empty() { return pHead == NULL; }
      
      //clear elements in list
      void clear();
      
      //push new elements onto the front or back
      void push_back(const T & t)    throw (const char *);
      void push_front(const T & t)   throw (const char *);
      
      //pop new elements off of the front or back
      void pop_back();
      void pop_front();
      
      // Access the front or back
      T front() const;
      T& front();     
      T back() const;
      T& back();      

      // define node class
      class Node;

      // the various iterator interfaces
      class iterator;
      iterator begin() const { return iterator (pHead); }
      iterator end() const { return iterator (NULL); }

      // the various const iterator interfaces
      class const_iterator;
      const_iterator cbegin() const { return const_iterator(pHead); }
      const_iterator cend() const { return const_iterator(NULL); }
      
      // the various reverse iterator interfaces
      class reverse_iterator;
      reverse_iterator rbegin() const { return reverse_iterator(pTail); }
      reverse_iterator rend() const { return reverse_iterator(NULL); }

      // the various const iterator interfaces
      class const_reverse_iterator;
      const_reverse_iterator crbegin() const { return const_reverse_iterator(pTail); }
      const_reverse_iterator crend() const { return const_reverse_iterator(NULL); }
      
      // find an item in the list
      iterator find(const T & t);

      //insert item into list
      iterator insert(iterator it, const T & t) throw (const char *);

      // erase item in the list
      iterator erase(iterator & it);

     private:
      Node * pHead;
      Node * pTail;
      int numElements;
   };
   
   /**************************************************
    * NODE
    * defines the node class
    *************************************************/
   template <class T>
      class list <T> :: Node
   {
     public:
      T data;
      Node * pNext;
      Node * pPrev;
      
      // constructors
     Node() : pNext(NULL), pPrev(NULL), data(NULL) {}
      Node(const T & t) { data = t; pNext = NULL; pPrev = NULL; }
   };
   
   /**************************************************
    * ITERATOR
    * An iterator through the list
    *************************************************/
   template <class T>
      class list <T> :: iterator
   {
     private:
      Node * p;
      friend class list;

     public:
      // constructors and destructors
     iterator() : p(NULL) {}
     iterator(Node * p) : p(p) {}
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
         p = p->pNext;
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

      // decrement
      iterator & operator -- ()
      {
         p = p->pPrev;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

      // dereference operator
      T & operator * ()       { return p->data; }
   };

   /**************************************************
    * CONST_ITERATOR
    * constant iterator through the list
    *************************************************/
   template <class T>
      class list <T> :: const_iterator
   {
     private:
      Node * p;
      friend class list;
      
     public:
      // constructors and destructors
     const_iterator() : p(NULL) {}
     const_iterator(Node * p) : p(p) {}
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
      const_iterator & operator ++ () const
      {
         p = p->pNext;
         return *this;
      }
      
      // postfix increment
      const_iterator operator ++ (int postfix) const
      {
         const_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }
      
      // decrement
      const_iterator & operator -- () const
      {
            p = p->pPrev;
            return *this;
      }
      
      // postfix decrement
      const_iterator operator -- (int postfix) const
      {
            const_iterator tmp(*this);
            p = p->pPrev;
            return tmp;
      }
      
      // dereference operator
      T & operator * () const      { return p->data; }
   };
      
   /**************************************************
    * REVERSE_ITERATOR
    * A reverse iterator through the list
    *************************************************/
   template <class T>
      class list <T> :: reverse_iterator
   {
     private:
      Node * p;
      friend class list;
      
     public:
      // constructors and destructors
     reverse_iterator() : p(NULL) {}
     reverse_iterator(Node * p) : p(p) {}
      reverse_iterator(const reverse_iterator & rhs) { *this = rhs; }
      
      // assignment operator
      reverse_iterator & operator = (const reverse_iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }
      
      // equals, not equals operator
      bool operator == (const reverse_iterator & rhs) const { return rhs.p == this->p; }
      bool operator != (const reverse_iterator & rhs) const { return rhs.p != this->p; }
      
      // increment
      reverse_iterator & operator ++ ()
      {
         p = p->pPrev;
         return *this;
      }
      
      // postfix increment
      reverse_iterator operator ++ (int postfix)
      {
         reverse_iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }
      
      // decrement
      reverse_iterator & operator -- ()
      {
         p = p->pNext;
         return *this;
      }
      
      // postfix decrement
      reverse_iterator operator -- (int postfix)
      {
         reverse_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }
      
      // dereference operator
      T & operator * ()       { return p->data; }
   };
   
   /**************************************************
    * CONST_REVERSE_ITERATOR
    * A constant reverse iterator through the list
    *************************************************/
   template <class T>
      class list <T> :: const_reverse_iterator
   {
     private:
      Node * p;
      friend class list;
      
     public:
      // constructors and destructors
     const_reverse_iterator() : p(NULL) {}
     const_reverse_iterator(Node * p) : p(p) {}
      const_reverse_iterator(const const_reverse_iterator & rhs) { *this = rhs; }
      
      // assignment operator
      const_reverse_iterator & operator = (const const_reverse_iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }
      
      // equals, not equals operator
      bool operator == (const const_reverse_iterator & rhs) const { return rhs.p == this->p; }
      bool operator != (const const_reverse_iterator & rhs) const { return rhs.p != this->p; }
      
      // increment
      const_reverse_iterator & operator ++ () const
      {
         p = p->pPrev;
         return *this;
      }
      
      // postfix increment
      const_reverse_iterator operator ++ (int postfix) const
      {
         const_reverse_iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }
      
      // decrement
      const_reverse_iterator & operator -- () const
      {
         p = p->pNext;
         return *this;
      }
      
      // postfix decrement
      const_reverse_iterator operator -- (int postfix) const
      {
         const_reverse_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }
      
      // dereference operator
      T & operator * () const       { return p->data; }
   };
   
   /*******************************************
    * LIST :: COPY CONSTRUCTOR
    *******************************************/
   template <class T>
      list <T> :: list(const list <T> & rhs) throw (const char *)
   {
      // do nothing if there is nothing to do
      if (rhs.size() == 0)
      {
         numElements = 0;
         pHead = NULL;
         pTail = NULL;
         return;
      }

      // clear all elements
      numElements = 0;
      pHead = NULL;
      pTail = NULL;

      // attempt to allocate
      try
      {
         Node * pNew = new Node (rhs.pHead->data);

      
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }

      // copy the items over one at a time
      // using the assignment operator
      *this = rhs;

   }
   
   /*******************************************
    * LIST :: Assignment
    *******************************************/
   template <class T>
      list <T> & list <T> :: operator = (const list <T> & rhs)
      throw (const char *)
   {
      //check if they are already the same, no need
      // copy again
      if(this == &rhs)
         return *this;

      // do nothing if there is nothing to do
      if (rhs.size() == 0)
      {
         numElements = 0;
         pHead = NULL;
         pTail = NULL;
         return *this;
      }

      // *this needs to be empty before we copy over rhs
      clear();
      
      try
      {
         // allocate new node
          Node * pNew = new Node(rhs.pHead->data);

         // loop through and copy the data over         
         for (pNew = rhs.pHead; pNew; pNew = pNew->pNext)
           push_back(pNew->data);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }
      
      return *this;
   }
   
   /**********************************************
    * LIST : CLEAR
    * Clear all elements in the list
    **********************************************/
   template <class T>
      void list <T> :: clear()
   {
      // while there are elements remaining
      // go through and delete each one
      while(pHead != NULL)
      {
         Node * pDelete = pHead;
         pHead = pHead->pNext;
         delete pDelete;
      }

      pHead = NULL;
      pTail = NULL; 
      numElements = 0;
   }
   
   /********************************************
    * LIST : PUSH_BACK
    * Check for capacity and resize if needed
    * Add element to back of list
    *******************************************/
   template <class T>
      void list <T> :: push_back(const T & t) throw (const char *)
   {
      try
      {
         // allocate new node
         Node * pNew = new Node(t);

         // point to the node before
         pNew->pPrev = pTail;

         // add the element onto the list
         if (pTail != NULL)
            pTail->pNext = pNew;
         else
            pHead = pNew;

         pTail = pNew;
         numElements++;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }
      
   }
   
   /********************************************
    * LIST : PUSH_FRONT
    * Check for capacity and resize if needed
    * Add element to the front of the list,
    * increasing the size by 1
    *******************************************/
   template <class T>
      void list <T> :: push_front(const T & t) throw (const char *)
   {
      try
      {
         // allocate new node
         Node * pNew = new Node(t);

         // point to the node after
         pNew->pNext = pHead;

         // add the element onto the list
         if (pHead != NULL)
            pHead->pPrev = pNew;
         else
            pTail = pNew;

         pHead = pNew;
         numElements++;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }
      
   }
   
   /********************************************
    * LIST : Pop_back
    * Remove an element from the back of the list
    *******************************************/
   template <class T>
      void list <T> :: pop_back()
   {
      // there are elements to remove
      if (pTail != NULL)
      {
         Node * pRemove = pTail;
         // point to the prev node       
         pTail = pTail->pPrev;
         // delete the node off the back
         delete pRemove;
         
         numElements--;
      }
   }
   
   /********************************************
    * LIST : Pop_front
    * Remove an element from the front of the list
    *******************************************/
   template <class T>
      void list <T> :: pop_front()
   {
      // there are elements to remove
      if (pHead != NULL)
      {
         Node * pRemove = pHead;
         // point to the next node
         pHead = pHead->pNext;
         // delete the node off the front
         delete pRemove;

         numElements--;
      }
   }
   
   /********************************************
    * LIST : Front (Getter)
    * Return the most recent element added to
    * the front of the list
    *******************************************/
   template <class T>
      T list <T> :: front() const
   {
      // the list is empty, so throw an error
      if (empty())
         throw "ERROR: unable to access data from an empty list";
      
      return pHead->data;
   }

   /********************************************
    * LIST : Front (Setter)
    * Change the most recent element added to the front
    * of the list
    *******************************************/
   template <class T>
      T & list <T> :: front()
   {
      // the list is empty, so throw an error
      if (empty())
         throw "ERROR: attempting to access an element in an empty list";
      
      return pHead->data;
   }
   
   /********************************************
    * LIST : Back (Getter)
    * Return the most recent element added to
    * the back of the list
    *******************************************/
   template <class T>
      T list <T> :: back() const
   {
      // the list is empty, so throw an error
      if (empty())
         throw "ERROR: unable to access data from an empty list";
      
      return pTail->data;
   }


   /********************************************
    * LIST : Back (Setter)
    * Change the most recent element added to the back
    * of the list
    *******************************************/
   template <class T>
      T & list <T> :: back() 
   {
      // the list is empty, so throw an error
      if (empty())
         throw "ERROR: attempting to access an element in an empty list";
      
      return pTail->data;
   }

  /***************************************************
   * LIST : FIND ITERATOR
   * Use an iterator to find an item in the list
   **************************************************/
   template <class T>
      typename list <T> :: iterator list <T> :: find(const T & t)
   {
      // loop through all elements in list from
      // begining to end and if the element is found
      // return it
      for (Node * p = pHead; p; p = p->pNext)
         if (p->data == t)
            return p;

      return NULL;
      

      
   }
   
   /***************************************************
    * LIST : INSERT
    * Insert an element in the list
    **************************************************/
   template <class T>
      typename list <T> :: iterator list <T> :: insert
      (list <T> :: iterator it, const T & t) throw (const char *)
   {
       Node * pNew = new Node (t);

       //if the back is null we are just pushing onto the back
       //we need to check this condition first
       if(it.p == NULL)
          push_back(t);
       
       //if the previous is null we are just pushing onto the front of the list
       else if(it.p->pPrev == NULL)
         push_front(t);
      
      

      // if pPrev is not null set new node equal to pPrev's pointer of pNext
      else
      {
         //pNew next node is current iterator (it.p)
         pNew->pNext = it.p;
         
         
         //now set pPrev pNext equal to pNew
         it.p->pPrev->pNext = pNew;
         
         //now pNew prev is it.p Prev
         pNew->pPrev = it.p->pPrev;
         
         //finally repalce it.p prev with pNew
         it.p->pPrev = pNew;
         
        
      }
      
      return pNew;
     

   }
   
   /***************************************************
    * LIST : ERASE
    * Erase an element from the list
    **************************************************/
   template <class T>
      typename list <T> :: iterator list <T> ::
      erase(list <T> :: iterator & it)
   {
      
      Node * pReturn;
      
      if(it.p == NULL)
         return NULL;

      // if pPrev is not null set pPrev's pointer of
      // pNext to it.p's pNext
      if(it.p->pPrev)
         it.p->pPrev->pNext = it.p->pNext;
      else
         //if pPrev is NULL we need to adjust head to the next node
         pHead = it.p->pNext;
         
      // do the same thing if pNext is not null
      if(it.p->pNext)
         it.p->pNext->pPrev = it.p->pPrev;
      else
         //if pNext is NULL we need to adjust tail to previous node
         pTail = it.p->pPrev;

      //handles addresses if pReturn next is NULL (at end)
      if (pReturn->pNext)
         pReturn = it.p->pNext;
      else
         pReturn = it.p->pPrev;

      return pReturn;
      
      
   }
   
   // namespace custom
};

#endif // LIST_H
