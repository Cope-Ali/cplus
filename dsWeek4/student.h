/***********************************************************************
 * Header:
 *    Student
 * Summary:
 *    This will contain the class definition of:
 *       student            : student who needs tutoring
 *          consisting of name, class and time
 * Author
 *    Ashleigh Walter & Ali Cope
 ************************************************************************/

#ifndef STUDENT_H
#define STUDENT_H
//#include <string>
//using namespace std;

class Student
{
  public:
   std::string name;
   std::string className;
   int min;
   bool urgent;

   Student()
   {
      urgent = false;
      name = "";
      className = "";
      min = 0;
   }
   
   Student (bool urgent, std::string className, std::string name, int min)
   {
      this-> urgent = urgent;
      this-> className = className;
      this-> name = name;
      this-> min = min;
   }

   //getters and setters
   void setUrgent(bool urgent){this->urgent = urgent;}
   bool getUrgent(){return urgent;}
   void setName(std::string name){this-> name = name;}
   std::string getName() {return name;}
   void setClassName(std::string className){this-> className = className;}
   std::string getClassName(){return className;}
   void setMin(int min){this-> min = min;}
   int getMin(){return min;}

};

#endif // STUDENT_H
