/***********************************************************************
 * Implementation:
 *    GRAPH
 * Summary:
 *    This will contain the implementation for graph
 * Author
 *    Ashleigh Walter, Ali Cope & George Brown
 **********************************************************************/


#include "graph.h"
#include "queue.h"
#include "set.h"
#include <ostream>
#include <array>
using std::cerr;

using namespace custom;
/*******************************************
 * DEFAULT CONSTRUCTOR
 *******************************************/
Graph :: Graph(int numVertices) throw (const char *)
{
   if(numVertices == 0)
   {
      this->numVertices = 0;
      this->numEdges = 0;
      this->adjList = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      adjList = new set <Vertex> [numVertices];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

   this->numVertices = numVertices;
   
}


/*******************************************
 * NON DEFAULT CONSTRUCTOR
 *******************************************/
Graph :: Graph(const Graph & rhs) throw (const char *)
{
   if(numVertices == 0)
   {
      this->numVertices = 0;
      this->numEdges = 0;
      this->adjList = NULL;
      return;
   }

   // attempt to allocate
      try
      {
         adjList = new set <Vertex> [rhs.numVertices];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }

      this->numVertices = rhs.numVertices;

   for(int i = 0; i < numVertices; i++)
      {
         adjList[i] = rhs.adjList[i];
      }
      
}


/*******************************************
 * ASSIGNMENT OPERATOR
 *******************************************/
Graph & Graph :: operator = (const Graph & rhs) throw (const char *)
{
   if(numVertices == 0)
   {
      this->numVertices = 0;
      this->numEdges = 0;
      this->adjList = NULL;
      return *this;
   }

   // attempt to allocate
      try
      {
         adjList = new set <Vertex> [rhs.numVertices];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }

      this->numVertices = rhs.numVertices;

      for(int i = 0; i < numVertices; i++)
      {
         adjList[i] = rhs.adjList[i];
      }
   

}

/*******************************************
 * isEdge
 *******************************************/
bool Graph :: isEdge(Vertex from, Vertex to) const
{

   //find returns the iterator that matches to, OR the end
   //if it is not found. So check to see if it returns NOT
   //the end (meaning to was found)
   if(adjList[from.index()].find(to) !=
      adjList[from.index()].end())
   {
      return true;
   }
   else
      return false;

      
}

/*******************************************
 * Add - vertex, vertex
 *******************************************/
//void Graph :: add(const Vertex & from, const Vertex & to)
void Graph :: add(Vertex from, Vertex to)
{

   adjList[from.index()].insert(to);
   
   
}

/*******************************************
 * Add - vertex, set of vertices
 *******************************************/
//void Graph :: add(const Vertex & from, const set <Vertex> & vSet)
void Graph :: add(Vertex from, set <Vertex> vSet)
{

   for(set <Vertex> :: const_iterator it = vSet.cbegin();
       it !=vSet.cend(); ++it)
   {
      adjList[from.index()].insert(*it);
   }

}



/*******************************************
 * Clear
 *******************************************/
void Graph :: clear()
{

   for (int i = 0; i < numVertices; i++)
   {
      adjList[i].clear();
   }

}

/*******************************************
 * findEdges
 *******************************************/
//set<Vertex> Graph :: findEdges(const Vertex & from)
set<Vertex> Graph :: findEdges(Vertex from)
{

   return adjList[from.index()];
   

}

/*******************************************
 * getStart
 *******************************************/
Vertex Graph :: getStart()
{

Vertex start = *adjList->begin();
   return start;


}
/*******************************************
 * getEnd
 *******************************************/
Vertex Graph :: getEnd()
{
Vertex end = *adjList->end();
   return end;


}

/*******************************************
 * findPath
 *******************************************/
vector<Vertex> Graph :: findPath(Vertex from, Vertex to)
{
   vector<Vertex> path;

   
//create a queue of the vertex we still need to explore
   queue <Vertex> toVisit;
   
   //not exactly sure what this is, maybe the distance of how far we have gone?
   int distance = 0;

   //add our first vertex to our queue to explore
   // toVisit.push_back(from);
   toVisit.push(from);
  
   
   //an array of pairs with a vertex and their distance
       //Array<pair<Vertex, int>> distances;
   //So the index of the array should be the same index of the vertex
   //making it simpler to match up.
   int distances[numVertices];

   
   //loop through all the vertex, add them to the array and give them
   //a distance of 0

   for (int i = 0; i < numVertices; i++)
      distances[i] = -1;

   Vertex v;
   set <Vertex> s;
    Vertex predecessor[numVertices];   
   while(!toVisit.empty() && distances[to.index()] == -1)
   {
      
      v = toVisit.front();
      //toVisit.pop_front();
      toVisit.pop();
      
      if (distances[v.index()] > distance)
         distance++;
      

      s = findEdges(v);
        int i = 0; 
      for(set <Vertex> :: const_iterator it = s.cbegin();
          it != s.cend(); ++it)
      {
         if (distances[(*it).index()] == -1)
         {
            distances[(*it).index()] = distance + 1;
            //couldn't figure out what predecessor was?
            predecessor[i] = v;
            //distances[((*it).index())-1] = v;
            
            toVisit.push(*it);
            i++;
         }

         distance++;
         
      }
   }

   if (distances[to.index()] = -1)
      return path; //needs to be return error.. put s just because it is a set

    path.push_back(to);
   //path.insert(to);
      
   for (int i = -1; i < distance; i++)
      path.push_back( predecessor[(path[i]).index()-1]);
      //not sure what predecessor is
      
   return path;

}
