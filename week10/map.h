/***********************************************************************
 * Header:
 *    Map
 * Summary:
 *    This will contain the class definition of:
 *       map             : similar to std::map
 * Author
 *    Ashleigh Walter, Ali Cope & George Brown
 ************************************************************************/

#ifndef MAP_H
#define MAP_H

#include "bst.h"
#include "pair.h"


namespace custom
{

   /************************************************
    * MAP
    ***********************************************/
   template <class K, class V>
      class map
   {
     private:
      BST <pair <K, V>> bst;
     public:
      // constructors and destructors
     map() : bst() {}
     map(const map <K, V> & rhs) throw (const char *) { bst = rhs.bst; }
      ~map() { bst.clear(); }

      // assignment operator
      map <K, V> & operator = (const map <K, V> & rhs) throw (const char *) { bst = rhs.bst; return *this; }

      // return size
      int size() const { return bst.size(); }
      
      // check if empty
      bool empty() { return bst.empty(); }

      // clear all elements in the map
      void clear() { bst.clear(); }

      // the various iterator interfaces
      class iterator;
      iterator begin() { return bst.begin(); }
      iterator end() { return bst.end(); }
      iterator rbegin() { return bst.rbegin(); }
      iterator rend() { return bst.rend(); }
      
      // find an item in the map
      iterator find(const K & k);

      // insert item into map using k and v
      void insert(const K & k, const V & v) throw (const char *);
      
      // insert item into the map using pair
      void insert(const pair<K, V> & pair)  throw(const char *);
      
      // access operators
      V & operator [] (const K & k) throw (const char *);
      V operator [] (const K & k) const throw (const char *);
   };

   /**************************************************
    * ITERATOR
    * An iterator through the map using the BST
    *************************************************/
   template <class K, class V>
      class map <K, V> :: iterator
   {
     private:
      typename BST <pair <K, V>> :: iterator it; 
     public:
      // constructors and destructors
     iterator() : it() {}
      iterator(typename BST <pair <K, V>> :: iterator it) { this->it = it; }
      iterator(const iterator & rhs) { (*this) = rhs; }
      
      // assignment operator
      iterator & operator = (const iterator & rhs)
      {
         it = rhs.it;
      }
      
      // equals, not equals operator
      bool operator == (const iterator & rhs) const { return it == rhs.it; }
      bool operator != (const iterator & rhs) const { return it != rhs.it; }
      
      // increment
      iterator & operator ++ ()
      {
         it++;
         return *this;
      }
      
      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         it++;
         return tmp;
      }
      
      // decrement
      iterator & operator -- ()
      {
         it--;
         return *this;
      }
      
      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         it--;
         return tmp;
      }
      
      // dereference operator
      pair <K, V> & operator * () { return *it; }
   };

   /*******************************************
    * FIND
    * Locate the key value in the map using BST
    *******************************************/
   template <class K, class V>
      typename map <K, V> :: iterator map <K, V> :: find(const K & k)
   {
      pair<K, V> p;

      p.first=k;
     //p.second=0; // keep from segfaulting 

      iterator it = bst.find(p);
      // p=*it; 
      return it;      
   }
   
   /*******************************************
    * INSERT
    * Update an existing node if found, else
    * inserting a new one.
    * (takes k and v as parameters)
    *******************************************/
   template <class K, class V>
      void map <K, V> :: insert(const K & k, const V & v) throw (const char *)
   {
      // create a pair with k and v values
      pair<K, V> pair(k, v);

      // create iterator to search for the node
      iterator it = bst.find(pair);

      // if node is found, we update it
      if (it != NULL)
         *it = pair;
      // otherwise we insert a new one
      else
         bst.insert(pair);
   }

   /*******************************************
    * INSERT
    * Update an existing node if found, else
    * inserting a new one.
    * (takes a pair as a parameter)
    *******************************************/
   template <class K, class V>
      void map <K, V> :: insert(const pair<K, V> & pair)  throw(const char *)
   {
      // create iterator to search for the node
      iterator it = bst.find(pair);

      // if node is found, we update it
      if (it != NULL)
         *it = pair;
      // otherwise we insert a new one
      else
         bst.insert(pair);
   }

   /*******************************************
    * ACCESS OPERATOR
    * Find the key/create a new one and then
    * return the second element (not const)
    *******************************************/
   template <class K, class V>
      V & map <K, V> :: operator [] (const K & k) throw (const char *)
   {
      // create a pair with k and default V()
      pair <K ,V> pair(k, V());

      // if we can't find the node, insert it
      if(bst.find(pair) == NULL)
         bst.insert(pair);
      
      // find the second element of the pair and return it
      return (*bst.find(pair)).second;
   }

   /*******************************************
    * ACCESS OPERATOR
    * Find the key/create a new one and then
    * return the second element (const)
    *******************************************/
   template <class K, class V>
      V map <K, V> :: operator [] (const K & k) const throw (const char *)
   {
      // create a pair with k and default V();
      pair <K, V> pair(k, V());

      // if we can't find the node, insert it
      if(bst.find(pair) == NULL)
         bst.insert(pair);

      // find the second element of the pair and return it
      return (*bst.find(pair)).second;
   }
   
}; // end custom namespace

#endif // MAP_H
