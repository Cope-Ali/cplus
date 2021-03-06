/***********************************************************************
 * Header:
 *    HUFFMAN
 * Summary:
 *    This will contain just the prototype for huffman(). 
 * Author
 *    Ali Cope, Ashleigh Walter & George Brown
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "bnode.h"
#include "pair.h"
#include "set.h"
#include "tree.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

// the interactive huffman program
void huffman(std::string filename);

/* 
STEP 1 - Read file contents into a set of pairs
--> each pair has a token (A,B,C etc.) and a frequency (0.2etc)
--> Set will automatically sort by the smallest frequency
*/

/*
STEP 2 - Generate Huffman Trees
--> each token is assigned it own binary tree
--> combine the two smallest trees into a single tree
   >>> a new root is created for the new tree that has a combined frequency
   >>> the smaller goes to the left and the larger goes to the right. If they are the same then the lower token value is smaller (A - left, B - right) 
--> combine the next two smallest etc until all have been combined.
*/

/*
STEP 3 - Determine the Huffman Code
--> branches to the left are 0 and to the right are 1. We will have to create the codes by navigating through left and right branches and building the code as we go. So left left left is 000, left left right is 001 --> right right right 111.
--> we also have to have a way to assign the huffman code and the token to the same object. Maybe another set of pairs?
*/

/*
STEP 4 - Output Huffman Code
--> sort the token and huffman code pairs -maybe another set?
--> display the Token and Code

*/

#endif // HUFFMAN_H
