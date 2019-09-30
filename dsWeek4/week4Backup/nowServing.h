/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include "deque.h"     // for DEQUE
using namespace custom;

class NowServing
{
  private:
   std::string course;
   std::string student;
   int minutes;
   bool emergency;

  public:
  NowServing() : minutes(0), emergency(false) {}
   NowServing(std::string course, std::string student, int minutes, bool emergency)
   {
      this->course = course;
      this->student = student;
      this->minutes = minutes;
      this->emergency = emergency;
   }
   std::string getCourse() const { return course; }
   std::string getStudent() const { return student; }
   int getMinutes() const { return minutes; }
   bool isEmergency() const { return emergency; }

   void setCourse(std::string course) { this->course = course; }
   void setStudent(std::string student) { this->student = student; }
   void setMinutes(int minutes) { this->minutes = minutes; }
   void setEmergency(bool emergency) {this->emergency = emergency; }
};

// the interactive nowServing program
void nowServing();

#endif // NOW_SERVING_H

