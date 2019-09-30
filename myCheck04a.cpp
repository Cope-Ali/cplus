/***********************************************************************
* Program:
*    Checkpoint 04a, Classes 
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
   string title;
   string author;

public:
   void prompt(Book &book);
   void display();
};

void Book :: prompt(Book &book)
{
   cout << "Title: ";
   getline(cin, book.title);
   cout << "Author: ";
   getline(cin, book.author);
}

void Book :: display()
{
   cout << "\"" << title << "\" by " << author << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book newBook;
   newBook.prompt(newBook);
   newBook.display();
   return 0;
}
