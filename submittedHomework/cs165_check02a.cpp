/***********************************************************************
* Program:
*    Checkpoint 02a, Structs          (e.g. Checkpoint 01a, review)  
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct Student
{
   string firstName;
   string lastName;
   int id;
};

void prompt(Student &user);
void display(const Student &output);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   Student user;
   prompt (user);
   display (user);
   
   return 0;
}

/***********************************************************************
 * Get name and id number from user
 ***********************************************************************/
void prompt(Student &user)
{
   cout << "Please enter your first name: ";
   getline(cin, user.firstName);
   cout << "Please enter your last name: ";
   getline(cin, user.lastName);
   cout << "Please enter your id number: ";
   cin >> user.id;
   cout << endl;
}

/********************************************************************
 * Display user id number and name
 **********************************************************************/
void display (const Student &output)
{
   cout << "Your information:\n" << output.id << " - "
        << output.firstName << " " << output.lastName << endl;
}
