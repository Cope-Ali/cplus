/***********************************************************************
 * Header:
 *    TUTOR CENTER
 * Summary:
 *    This will contain just the prototype for tutorCenter(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef TUTOR_CENTER_H
#define TUTOR_CENTER_H
#include "student.h"
#include "deque.h"
using namespace custom;
//#include <deque>
//using namespace std;

class TutorCenter
{
  public:
   deque <Student> line;
   Student currentStudent;
  void passTime();
  void getNewStudent();      

  TutorCenter()
  {
  }                                         
};

#endif
