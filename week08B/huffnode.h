/***********************************************************************
 * Header:
 *    HUFFMAN
 * Summary:
 *    This will contain just the prototype for huffman().
 * Author
 *    Ali Cope, Ashleigh Walter & George Brown
 ************************************************************************/

#ifndef HUFFNODE_H
#define HUFFNODE_H
//#include "bnode.h"
#include "pair.h"
#include "set.h"
#include "tree.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

// the interactive huffman program
class HuffNode
{
  public:
   string data;
   float frequency;
   HuffNode * pLeft;
   HuffNode * pRight;
   HuffNode * pParent;
   
   
   // constructors
  HuffNode() : pLeft(NULL), pRight(NULL), pParent(NULL), data('\0'), frequency(0.0)  {}
   HuffNode(const string & t, const float f)
   { data = t; pLeft = NULL; pRight = NULL; pParent = NULL; frequency = f;}

};


/**********************************************
 * copyHTree
 * Copy nodes in a tree over to another one
 **********************************************/

HuffNode * copyHTree(const HuffNode * pSrc) throw(const char *)
{
   // there is nothing to copy
   if (pSrc == NULL)
      return NULL;

   // create node
   HuffNode * pDestination;
   
   // try to allocate new node
   try
   {
      pDestination = new HuffNode (pSrc->data, pSrc->frequency);
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node";
   }
   
   // get the left side data
   pDestination->pLeft = copyHTree(pSrc->pLeft);

   // copy over the left side and connect nodes
   if (pDestination->pLeft != NULL)
      pDestination->pLeft->pParent = pDestination;

   // get the right side data
   pDestination->pRight = copyHTree(pSrc->pRight);
   // copy over the right side and connect nodes
   if (pDestination->pRight != NULL)
      pDestination->pRight->pParent = pDestination;

   return pDestination;
}

 /**********************************************
 * addHLeft
 * Adds a node to the left of current node,
 * connecting them
 **********************************************/
/*void addHLeft(HuffNode * pNode, HuffNode * pAdd)
{
   // there is a node to add
   if (pAdd != NULL)
      pAdd->pParent = pNode;
   pNode->pLeft = pAdd;
} */

/**********************************************
 * addHLeft
 * Allocates a new node and then adds it to the left
 **********************************************/
/* void addHLeft(HuffNode * pNode, const string & t, const float f) throw(const char *)
{
   try
   {
      // try to allocate new node
      HuffNode * pAdd = new HuffNode (t, f);

      // add node to the left connecting them
      pAdd->pParent = pNode;
      pNode->pLeft = pAdd;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node";
   }
} */

/**********************************************
 * ADDRIGHT
 * Adds a node to the right of current node,
 * connecting them
 **********************************************/
/* void addHRight(HuffNode * pNode, HuffNode * pAdd)
{
   // there is a node to add
   if (pAdd != NULL)
      pAdd->pParent = pNode;
   pNode->pRight = pAdd;
} */

/**********************************************
 * ADDRIGHT
 * Allocates a new node and then adds it to the right
 **********************************************/
/* void addHRight(HuffNode * pNode, const string & t, const float f) throw(const char *)
{
   try
   {
      // try to allocate new node
      HuffNode * pAdd = new HuffNode (t, f);
      
      // add node to the right connecting them
      pAdd->pParent = pNode;
      pNode->pRight = pAdd;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a node";
   }
      
} */

/**********************************************
 * DELETEBTREE
 * Clear all the nodes in the tree
 **********************************************/
void deleteHTree(HuffNode * & pNode)
{
   // there is nothing to delete
   if (pNode == NULL)
      return;

   deleteHTree(pNode->pLeft);
   deleteHTree(pNode->pRight);
   delete pNode;
   pNode = NULL;
}

/**********************************************
 * sizeHTree
 * Determine the size of the tree
 **********************************************/
int sizeHTree(const HuffNode * pRoot)
{
   // there is nothing to calculate
   if (pRoot == NULL)
      return 0;
   // return the size
   else
      return sizeHTree(pRoot->pLeft) + 1 + sizeHTree(pRoot->pRight);
}

/**********************************************
 * OSTREAM OPERATOR OVERLOAD
 * Display the nodes in the tree
 **********************************************/
/* std::ostream & operator << (std::ostream & out, HuffNode * rhs)
{
   if (rhs == NULL)
      return out;
   
   out << rhs->pLeft;
   out << rhs->data << " ";
   out << rhs->pRight;
     
   return out;
} */

#endif // HUFFNODE_H

