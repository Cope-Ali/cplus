/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    Ashleigh Walter, Ali Cope & George Brown
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include "map.h"
namespace custom
{
/****************************************************
 * Count class
 * class definition for counting
 ****************************************************/
class Count
{
  private:
   int counts;

  public:
   // constructors and destructors
  Count() : counts(0) {}
   Count(int counts) { this->counts = counts; }
   ~Count() { counts = 0; }

   // return the counts 
   int getCounts() const { return counts; }

   // increment
   Count & operator ++ ()
   {
      counts++;
      return *this;
   }

   // postfix increment
   Count operator ++ (int postfix)
   {
      Count tmp(*this);
      counts++;
      return tmp;
   }
   
//};

void readFile(map, int);
/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount();
};
}
#endif // WORD_COUNT_H

