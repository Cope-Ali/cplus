/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Ashleigh Walter & Ali Cope
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace std;
//using namespace custom;

/********NOTE FOR ALI*********************************
******************************************************************
I have this going with namespace std; at the moment. It still needs work if you
can see by running it... but it's something.

I still don't know if you like doing it this way or if you'd prefer to add other
classes and header files...?
******************************************************************
******************************************************/

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // input variables
   string input;
   string course;
   string student;
   int minutes = 0;

   // count the time
   int count = 0;

   // for storing the input to display
   deque <string> courseName;
   deque <string> studentName;
   deque <int> timeLeft;

   // run loop until user is "finished"
   do
   {
      cout << "<" << count << ">";
      // get initial input
      cin >> input;

      // it's an emergency, deal with this first!
      if (input == "!!")
      {
         // continue counter
         count++;
         // get user input for emergency
         cin >> course >> student >> minutes;
         // push the input onto the front of each deque
         courseName.push_front(course);
         studentName.push_front(student);
         timeLeft.push_front(minutes);

         // only display if there is time remaining
         if (minutes != 0)
         {
            // display 
            cout << "\tEmergency for "
                 << studentName.front()
                 << " for class "
                 << courseName.front()
                 << ". Time left: "
                 << timeLeft.front()
                 << endl;

            // there is still time left, so continue
            // counting down
            minutes--;
            timeLeft.push_front(minutes);
         }
         else
         {
            // pop of the person who's already been served
            courseName.pop_front();
            studentName.pop_front();
            // start the time over
            timeLeft.clear();
         }
      }

      // as long as someone is being added to the deque
      else if (input != "none")
      {
         // continue counter
         count++;
         // first string is equal to the course
         course = input;
         // get student name and time needed
         cin >> student >> minutes;
         // push the input onto the front of each deque
         courseName.push_back(course);
         studentName.push_back(student);
         timeLeft.push_back(minutes);

         // only display if there is time remaining
         if (minutes != 0)
         {
            // display 
            cout << "\tCurrently serving "
                 << studentName.front()
                 << " for class "
                 << courseName.front()
                 << ". Time left: "
                 << timeLeft.front()
                 << endl;
            
            // there is still time left, so continue
            // counting down
            minutes--;
            timeLeft.push_front(minutes);
         }
         else
         {
            // pop of the person who's already been served
            courseName.pop_front();
            studentName.pop_front();
            // start the time over
            timeLeft.clear();
         }
      }
      // no one is currently being added to the deque
      else if (input == "none")
      {
         //continue counter
         count++;

         // only display if there is time remaining
         if (minutes != 0)
         {
            // display
            cout << "\tCurrently serving "
                 << studentName.front()
                 << " for class "
                 << courseName.front()
                 << ". Time left: "
                 << timeLeft.front()
                 << endl;

            // there is still time left, so continue
            // counting down
            minutes--;
            timeLeft.push_front(minutes);
         }
         else
         {
            // pop of the person who's already been served
            courseName.pop_front();
            studentName.pop_front();
            // start the time over
            timeLeft.clear();
         }
      }
   }
   while (input != "finished");
   // end
   cout << "End of simulation\n";
}


