/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
public:
   void promptBookInfo()
   {
      cout << "Title: ";
      getline(cin, title);
      cout << "Author: ";
      getline(cin, author);
      cout << "Publication Year: ";
      cin >> publicationYear;
      cin.ignore();
   }
    void displayBookInfo() const
   {
      cout << endl << title << " (" << publicationYear
           << ") by " << author << endl;
   }
   
private:
   string title;
   string author;
   int publicationYear;
};

// TODO: Define your TextBook class here
class TextBook : public Book
{
public:
   void promptSubject ()
   {
      cout << "Subject: ";
      getline(cin, subject);
   }
   
   void displaySubject () const {cout << "Subject: " << subject << endl;}
   
private:
   string subject;
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
public:
   void promptIllustrator ()
   {
      cout << "Illustrator: ";
      getline(cin, illustrator);
   }
   void displayIllustrator () const
   {cout << "Illustrated by " << illustrator << endl;}
   
private:
   string illustrator;
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;   
   book.promptBookInfo();
   book.displayBookInfo();
   cout << endl;
   
   // Declare a TextBook object here and call its methods
   TextBook textbook;
   textbook.promptBookInfo();
   textbook.promptSubject();
   textbook.displayBookInfo();
   textbook.displaySubject();
   cout << endl;
   
   // Declare a PictureBook object here and call its methods
   PictureBook picbook;
   picbook.promptBookInfo();
   picbook.promptIllustrator();
   picbook.displayBookInfo();
   picbook.displayIllustrator();
   
   return 0;
}


