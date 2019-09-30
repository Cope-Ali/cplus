/***********************************************************************
 * Header:
 *    TREE
 * Summary:
 *    This will contain the tree class. The tree will consist of a root bNode and two children nodes. 
 * Author
 *    Ali Cope, Ashleigh Walter & George Brown
 ************************************************************************/

#ifndef TREE_H
#define TREE_H
#include "bnode.h"
#include "pair.h"
#include "set.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
namespace custom
{

class Tree 
{
private:
BNode <char> lChild;
BNode <char> rChild;
//combined frequencies of the children
float freq;
float lFreq;
float rFreq;

public:
//constructors
Tree(){}
Tree(char left, float lFreq, char right, float rFreq)
{
    lChild.data = left;
    rChild.data = right;
    freq = lFreq + rFreq;
}

//getters and setters
void setLeft(char left)
{
lChild.data = left;
}

void setRight(char right)
{
rChild.data = right;
}

void setCombinedFrequency()
{
    freq = lFreq + rFreq;
}

void setLFreq(float left)
{
    lFreq = left;
}

void setRFreq(float right)
{
    rFreq = right;
}

float getCombinedFrequecy()
{
    return freq;
}

char getLeft()
{
    return lChild.data;
}

char getRight()
{
    return rChild.data;
}

}; //end of class

} //end namespace





#endif