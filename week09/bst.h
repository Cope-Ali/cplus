/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother Kirby, CS 235
 * Author:
 *    Ashleigh Walter, Ali Cope & George Brown
 * Summary:
 *    Create a binary search tree
 *    This will contain the class definition of: BST
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "stack.h"

namespace custom
{
/************************************************
 * BST (Binary Search Tree)
 ***********************************************/
   template <class T>
      class BST
   {
     public:
      // constructors and destructors
     BST() : root(NULL), numElements(0) {}
      BST(const BST <T> & rhs) throw (const char *);
      ~BST() { clear(); }
      
      // assignment operator
      BST <T> & operator = (const BST <T> & rhs)
         throw (const char *);
      
      //return size
       int size() const { return numElements; }// return empty() ? 0 : root->size(); }

//         int size() { return root->BSTsize();}
            
         
      //check if empty
      bool empty() { return root == NULL; }
      
      //clear elements in BST
      void clear() { deleteBinaryTree(root); root = NULL; }
      
      // define bnode class
      class BNode;
      
      // the various iterator interfaces
      class iterator;
      iterator begin() const;
      iterator end() const { return iterator (NULL); }
      iterator rbegin() const;
      iterator rend() const { return iterator (NULL); }
      
      // find an item in the BST
      iterator find(const T & t);
      
      //insert item into BST
      void insert(const T & t) throw (const char *);
      
      // erase item in the BST
      void erase(iterator & it);

      // return root
      BNode * getRoot() const { return root; }
      
     private:
      BNode * root;
      int numElements;

      void deleteNode(BNode * pDel, bool right);
      void deleteBinaryTree(BNode * pDel);
      void copyBinaryTree(BNode * pSrc, BNode * pDest);
   };
   
   /**************************************************
    * BNODE
    * defines the bnode class
    *************************************************/
   template <class T>
      class BST <T> :: BNode
   {
     public:
      T data;
      BNode * pLeft;
      BNode * pRight;
      BNode * pParent;
      bool isRed;
      
      // constructors
     BNode() : pLeft(NULL), pRight(NULL), pParent(NULL), data(NULL), isRed(false) {}
      BNode(const T & t) { data = t; pLeft = NULL; pRight = NULL; pParent = NULL; isRed = false; }

      void addLeft(BNode * pNode, BNode * pAdd);
      void addLeft(BNode * pNode, const T & t) throw (const char *);
      void addRight(BNode * pNode, BNode * pAdd);
      void addRight(BNode * pNode, const T & t) throw (const char *);

      // size of tree
      //int BSTsize() { return pLeft->BSTsize() + 1 + pRight->BSTsize(); }
      
     private:
      friend class BST;
      void verifyRB(int depth);
      void verifyBST();
      void balance();
   };

   /**************************************************
    * ITERATOR
    * An iterator through the BST
    *************************************************/
   template <class T>
      class BST <T> :: iterator
   {
     private:
      stack <BNode *> nodes;
      friend class BST;
      
     public:
      // constructors and destructors
     iterator(BNode * p = NULL) { nodes.push(p); }
     iterator(stack <BNode *> & s) { nodes = s; }
      iterator(const iterator & rhs) { nodes = rhs.nodes; }
      
      // assignment operator
      iterator & operator = (const iterator & rhs)
      {
         nodes = rhs.nodes;
         return *this;
      }
      
      // equals, not equals operator
      bool operator == (const iterator & rhs) const { return rhs.nodes.top() == nodes.top(); }
      bool operator != (const iterator & rhs) const { return rhs.nodes.top() != nodes.top(); }
      
      // increment
      iterator & operator ++ ();
      
      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator it = *this;
         ++(*this);
         return it;
      }
      
      // decrement
      iterator & operator -- ();
      
      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator it = *this;
         --(*this);
         return it;
      }
      
      // dereference operator
      T & operator * ()       { return nodes.top()->data; }
   };

   /*******************************************
    * BST :: COPY CONSTRUCTOR
    *******************************************/
   template <class T>
      BST <T> :: BST(const BST <T> & rhs) throw (const char *)
   {
      // do nothing if there is nothing to do
      if (rhs.numElements == 0)
      {
         numElements = 0;
         root = NULL;
         return;
      }
      
      // clear all elements
      numElements = 0;
      root = NULL;
      
      // attempt to allocate
      try
      {
         BNode * pNew = new BNode (rhs.root->data);
         //root = new BNode (rhs.root->data);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate anode";
      }
      
      // copy the items over one at a time
      // using the assignment operator
      *this = rhs; 
   }
   
   /*******************************************
    * BST :: Assignment
    *******************************************/
   template <class T>
      BST <T> & BST <T> :: operator = (const BST <T> & rhs)
      throw (const char *)
   {
      //check if they are already the same, no need
      // copy again
      if(this == &rhs)
         return *this;
      
      // do nothing if there is nothing to do
      if (rhs.numElements == 0)
      {
         numElements = 0;
         root = NULL;
         return *this;
      }
      
      // *this needs to be empty before we copy over rhs
      clear();
      
      try
      {
         // allocate new node
         BNode * pNew = new BNode(rhs.root->data);
         //root = new BNode (rhs.root->data);
         
         // copy the data over
         copyBinaryTree(rhs.root, pNew); //root);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
      
      return *this;
   }

   /**********************************************
    * ADDLEFT
    * Adds a node to the left of current node,
    * connecting them
    **********************************************/
   template <class T>
      void BST <T> :: BNode :: addLeft(BNode * pNode, BNode * pAdd)
   {
      // there is a node to add
      if (pAdd != NULL)
         pAdd->pParent = pNode;
      pNode->pLeft = pAdd;
   }
   
   /**********************************************
    * ADDLEFT
    * Allocates a new node and then adds it to the left
    **********************************************/
   template <class T>
      void BST <T> :: BNode :: addLeft(BNode * pNode, const T & t) throw(const char *)
   {
      try
      {
         // try to allocate new node
         BNode * pAdd = new BNode (t);
         
         // add node to the left connecting them
         pAdd->pParent = pNode;
         pNode->pLeft = pAdd;
      }
      catch(std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
   }

   /**********************************************
    * ADDRIGHT
    * Adds a node to the right of current node,
    * connecting them
    **********************************************/
   template <class T>
      void BST <T> :: BNode :: addRight(BNode * pNode, BNode * pAdd)
   {
      // there is a node to add
      if (pAdd != NULL)
         pAdd->pParent = pNode;
      pNode->pRight = pAdd;
   }
   
   /**********************************************
    * ADDRIGHT
    * Allocates a new node and then adds it to the right
    **********************************************/
   template <class T>
      void BST <T> :: BNode :: addRight(BNode * pNode, const T & t) throw(const char *)
   {
      try
      {
         // try to allocate new node
         BNode * pAdd = new BNode (t);

         // add node to the right connecting them
         pAdd->pParent = pNode;
         pNode->pRight = pAdd;
      }
      catch(std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
      
   }

   /*******************************************
    * DELETE NODE
    * Delete a node from the tree
    *******************************************/
   template <class T>
      void BST <T> :: deleteNode(BNode * pDel, bool right)
   {
   }

   /*******************************************
    * DELETE BINARY TREE
    * Delete all elements from the tree
    *******************************************/
   template <class T>
      void BST <T> :: deleteBinaryTree(BNode * pDel)
   {
   }

   /*******************************************
    * COPY BINARY TREE
    * Copy the data from one tree to another
    *******************************************/
   template <class T>
      void BST <T> :: copyBinaryTree(BNode * pSrc, BNode * pDest)
   {
      // there is nothing to copy
      if (pSrc == NULL)
         pDest = NULL;

      // copy over the data
      pSrc->data = pDest->data;
      
      copyBinaryTree(pSrc->pLeft, pDest->pLeft);
      copyBinaryTree(pSrc->pRight, pDest->pRight);
   }
   
   /*******************************************
    * BEGIN
    * Return the left most element in the tree
    *******************************************/
   template <class T>
      typename BST <T> :: iterator BST <T> :: begin() const
   {
      // create a stack of nodes
      stack <BNode *> nodes;

      // add data
      nodes.push(NULL);
      nodes.push(root);

      // as long as we haven't reached the end and there
      // are still left side elements
      while (nodes.top() != NULL && nodes.top()->pLeft)
         nodes.push(nodes.top()->pLeft);

      // return left most element
      return iterator(nodes);
   }

   /*******************************************
    * RBEGIN
    * Return the right most element in the tree
    *******************************************/
   template <class T>
      typename BST <T> :: iterator BST <T> :: rbegin() const
   {
      // create a stack of nodes
      stack <BNode *> nodes;

      // add data
      nodes.push(NULL);
      nodes.push(root);

      // as long as we haven't reached the end and there
      // are still right side elements
      while (nodes.top() != NULL && nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);

      // return right most element
      return iterator(nodes);
   }   

   /*******************************************
    * FIND
    * Locate an item in the tree
    *******************************************/
   template <class T>
      typename BST <T> :: iterator BST <T> :: find(const T & t)
   {
   }

   /*******************************************
    * INSERT
    * Insert an item in the tree
    *******************************************/
   template <class T>
      void BST <T> :: insert(const T & t) throw (const char *)
   {
      //create the new node we will be inserting
       BNode * pAdd = new BNode (t);
 
// make sure tree isn't empty
      if(!(root == NULL))
      {
         //create a copy of our root we can use to navigate
         BNode * pTemp = root;
     
      // recur down the tree
         // check if data goes left
         if(t < pTemp->data)
         {
            //std:: cout << "insert left\n";
            // find the end 
            while(t < pTemp->data)
            {
               //std::cout << "in while loop\n";
               // check to make sure that the next pointer isn't null
               if(pTemp->pLeft != NULL)
                  //set pTemp to next level and loop again
                  pTemp = pTemp->pLeft;
               //if we are at the bottom set pAdd
// TO DO - CHECK FOR OTHER SIBLINGS
               else
               {
                  pAdd->pParent = pTemp;
                  pTemp->pLeft = pAdd;
                  //exit loops
                  break;
               }
            }
         }
         //check if data goes right
      else if(t > pTemp->data)
      {
         //std::cout << "insert right\n";
         //find the end
         while(t > pTemp-> data)
         {
            //check to make sure next pointer is not null
            if(pTemp->pRight !=NULL)
               //set pTemp to next level and loop again
               pTemp = pTemp ->pRight;
            // if we are at the bottom set pAdd
            else
            {
               pAdd->pParent = pTemp;
               pTemp->pRight = pAdd;
               //exit loops
               break;
            }
         }
      }
      /*if(pParent.isRed() && pGranny.isBlack() && pSibling.isBlack()
         && pAunt.isBlack() && pParent->pLeft == t
         && pGranny->pRight == pParent)
      {
         pGranny.setRight(t->pLeft);
         pParent.setLeft(t->pRight);

         if(pGranny->pParent == NULL)
            t->pParent = NULL;
         else if(pGranny->pParent->pRight == pGranny)
            pGranny->pParent->pRight = t;
         else
            pGranny->pParent->pLeft = t;

         t.setLeft(pGranny);
         t.setRight(pParent);

         pGranny.setRed();
         t.setBlack();
      }
      */

/*TO TEST INSERT
         std::cout << "\nroot : " << root->data;
         if(root->pLeft !=NULL)
            std::cout << "\npLeft : " << root->pLeft->data;
         if(root->pRight !=NULL)
            std::cout << "\npRight : " << root->pRight->data;
*/    
      }
      //if tree is emptyset root = new        
      else
         root = pAdd;
      }

   /*******************************************
    * ERASE
    * Erase an item in the tree
    *******************************************/
   template <class T>
      void BST <T> :: erase(iterator & it)
   {
      // make sure there's something to erase
      if (it == end())
         return;

      // use the stack of nodes
      BNode * pDel = it.nodes.top();
      
      // No Children
      if (pDel->pRight == NULL && pDel->pLeft == NULL)
      {
         // if it's the right side, set to null before deleting
         if (pDel->pParent != NULL && pDel->pParent->pRight == pDel)
            pDel->pParent->pRight = NULL;
         // same for the left side
         if (pDel->pParent != NULL && pDel->pParent->pLeft == pDel)
            pDel->pParent->pLeft = NULL;
         // delete the selected node
         delete pDel;
         // decrease size        
         numElements--;
         return;
      }

      // One Child (Nothing on the Left)
      if (pDel->pRight == NULL && pDel->pLeft != NULL)
      {
         // move child node into erased node's spot
         pDel->pLeft->pParent = pDel->pParent;
         if (pDel->pParent != NULL && pDel->pParent->pRight == pDel)
            pDel->pParent->pRight = pDel->pLeft;
         if (pDel->pParent != NULL && pDel->pParent->pLeft == pDel)
            pDel->pParent->pLeft = pDel->pLeft;
         // delete the selected node
         delete pDel;
         // decrease size
         numElements--;
         return;
      }

      // One Child (Nothing on the Right)
      if (pDel->pLeft == NULL && pDel->pRight != NULL)
      {
         // move child node into erased node's spot
         pDel->pRight->pParent = pDel->pParent;
         if (pDel->pParent != NULL && pDel->pParent->pRight == pDel)
            pDel->pParent->pRight = pDel->pRight;
         if (pDel->pParent != NULL  && pDel->pParent->pLeft == pDel)
            pDel->pParent->pLeft = pDel->pRight;
         // delete the selected node
         delete pDel;
         // decrease size
         numElements--;
         return;
      }

      // Two Children
      {
         //
      }
   }

   /*******************************************
    * Increment Prefix
    * Advance by one
    *******************************************/
   template <class T>
      typename BST <T> :: iterator & BST <T> :: iterator :: operator ++ ()
   {
   }
   
   /**************************************************
   * BST ITERATOR :: DECREMENT PREFIX
   *     advance by one. 
   * Author:      Br. Helfrich
   * Performance: O(log n) though O(1) in the common case
   *************************************************/
   template <class T>
      typename BST <T> :: iterator & BST <T> :: iterator :: operator -- ()
   {/*
      // do nothing if we have nothing
      if (NULL == pNode)
         return *this;
      
      // if there is a left node, take it
      if (NULL != pNode->pLeft)
      {
         // go left
         pNode = pNode->pLeft;

         // jig right - there might be more right-most children
         while (pNode->pRight)
            pNode = pNode->pRight;
         return *this;
      }
      
      // there are no left children, the right are done
      assert(NULL == pNode->pLeft);
      BNode * pSave = pNode;

      // go up
      pNode = pNode->pParent;
      
      // if the parent is the NULL, we are done!
      if (NULL == pNode)
         return *this;

      // if we are the right-child, got to the parent.
      if (pSave == pNode->pRight)
         return *this;
      
      // we are the left-child, go up as long as we are the left child!
      while (NULL != pNode && pSave == pNode->pLeft)
      {
         pSave = pNode;
         pNode = pNode->pParent;
      }
      
      return *this;  */
   }

} // namespace custom

#endif // BST_H
