/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    This will contain the class definition of:
 *       node             : similar to std::node
 * Author
 *    Ali Cope, Ashleigh Walter & George Brown
 ************************************************************************/

#ifndef NODE_H
#define NODE_H

/***********************************************
 * NODE
 **********************************************/
template <class T>
   class Node
{
  public:
   T data;
   Node * pNext;
   Node * pPrev;

   // constructors
  Node() : pNext(NULL), pPrev(NULL), data(0) {}
   Node(const T & t) { data = t; pNext = 0; pPrev = 0; }
};


/**********************************************
 * COPY
 * Copy a list over to another one
 **********************************************/
template <class T>
Node <T> * copy(Node <T> * pSource)
{
   // allocate a new Node
   Node <T> * pDestination = new Node <T> (pSource->data);
   // create Nodes for copying
   Node <T> * pSrc = pSource;
   Node <T> * pDes = pDestination;

   //loop through and copy the data over
   for (pSrc = pSrc->pNext; pSrc; pSrc = pSrc->pNext)
      pDes = insert(pDes, pSrc->data, true);

   return pDestination;
}

/**********************************************
 * INSERT
 * Insert an element in the list
 **********************************************/
template <class T>
Node <T> * insert(Node <T> * pCurrent, const T & t, bool after = false)
{
   // allocate a new Node
   Node <T> * pNew = new Node <T> (t);

   // there are elements in the list, and we are
   // adding before an element
   if (pCurrent && !after)
   {
      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;
      pCurrent->pPrev = pNew;

      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
   }
   // there are elements in the list, and we are
   // adding after an element
   if (pCurrent && after)
   {
      pNew->pPrev = pCurrent;
      pNew->pNext = pCurrent->pNext;
      pCurrent->pNext = pNew;

      if (pNew->pNext)
         pNew->pNext->pPrev = pNew;
   }

   return pNew;
}

/**********************************************
 * FIND
 * Find an element in the list
 **********************************************/
template <class T>
Node <T> * find(Node <T> * pHead, const T & t)
{
   // loop through all elements in list from
   // begining to end and if the element is found
   // return it
   for (Node <T> * p = pHead; p; p = p->pNext)
      if (p->data == t)
         return p;

   return NULL;
}

/**********************************************
 * FREEDATA
 * Clear all elements in the list
 **********************************************/
template <class T>
void freeData(Node <T> * & pHead)
{
   // while there are elements remaining
   // go through and delete each one
   while(pHead)
   {
      Node <T> * pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
}

/**********************************************
 * REMOVE
 * Remove an element from the list
 **********************************************/
template <class T>
Node <T> * remove(const Node <T> * pRemove)
{
   Node <T> * pReturn;
   if(pRemove == NULL)
      return 0;

   // if pPrev is not null set pPrev's pointer of
   // pNext to pRemove's pNext
   if(pRemove->pPrev)
      pRemove->pPrev->pNext = pRemove->pNext;
   // do the same thing if pNext is not null
   if(pRemove->pNext)
      pRemove->pNext->pPrev = pRemove->pPrev;

   if (pRemove->pPrev)
      pReturn = pRemove->pPrev;
   else
      pReturn = pRemove->pNext;

   delete pRemove;
   return pReturn;
}

/**********************************************
 * OSTREAM OPERATOR OVERLOAD
 * Display the elements in the list
 **********************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * pHead)
{
   // loop through elements from begining to end
   for (Node <T> * p = pHead; p; p = p->pNext)
   {
      // if it's not the last element, add a comma after
      if (p->pNext != NULL)
         out << p->data << ", ";
      else
         out << p->data;
   }
   // display the elements
   return out;
}

#endif // NODE_H
