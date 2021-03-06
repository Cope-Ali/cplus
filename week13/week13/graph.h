/***********************************************************************
 * Component:
 *    Assignment 13, Graph
 *    Brother Kirby, CS 235
 * Author:
 *    Ashleigh Walter, Ali Cope & George Brown
 * Summary:
 *    This will contain the class definition of: graph
 ************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <ostream>
#include "set.h"
#include "vector.h"
#include "vertex.h"
#include <cassert>
using namespace custom;
using std::cerr;


/************************************************
 * Hash
 ***********************************************/
class Graph
{
  private:
   //matrix
   set <Vertex> * adjList;

   
   // numVertices
   int numVertices;

   //edges
   int numEdges;

   
  public:
   //constructors and destructors
   Graph(int numVert) throw (const char *);
   Graph(const Graph & rhs) throw (const char *);

   ~Graph() { clear(); }
   
   //assignment operator

   Graph & operator = (const Graph & rhs) throw (const char *);

   //functions for graph

   //return size
   int size() const { return numVertices;}

   //returns capacity
   int capacity() const { return (numVertices * (numVertices -1));}

   //clear everything
   void clear();

   //is edge
   bool isEdge(Vertex from, Vertex to) const;
   
   //find edge
//   set <Vertex>  findEdges(const Vertex & from);
   set <Vertex>  findEdges(Vertex from);
   
   set<Vertex> findPath(Vertex from, Vertex to);

   //add 
//   void add(const Vertex & from, const Vertex & to);
   void add(Vertex from, Vertex to);
   
//   void add(const Vertex & from, const set <Vertex> & vSet);
   void add(Vertex from, set <Vertex>  vSet);
   
   
};
 
   
#endif // GRAPH_H
