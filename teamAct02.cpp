/***********************************************************************
 *  Team activity 02 - Structs
 *
 *  Problem: create a struct for a scripture that contains a book, chapter
 *  and verse. Then writea funtion to display a scripture and one to prompt
 *  for a scripture.
 ************************************************************************/
#include <iostream>
using namespace std;

/******************************************
 * Scripture
 * contains book name, chapter and verse
 ******************************************/
struct Scripture
{
   string book;
   int chapter;
   int verse;
};

/********************************************************
 * Insight
 * contains Scripture and an "insight" or string message
 *    about that scripture
 ********************************************************/
struct Insight
{
   Scripture scripture;
   string message;
};


/****************************************************
 * Function: promptScripture
 * Purpose: prompt the user for book, chapter, verse
 *          and assigns it to a new scripture
 ****************************************************/
void promptScripture(Scripture & newScripture)
{
   cout << "Please enter the book of scripture: ";
   getline(cin, newScripture.book);
   cout << "Please enter the chapter: ";
   cin >> newScripture.chapter;
   cout << "Please enter the verse: ";
   cin >> newScripture.verse;
}

/******************************************************
 * Function: displayScripture
 * Purpose: displays a given scripture in the form
 *           "book chapter:verse"
 *****************************************************/
void displayScripture(const Scripture & output)
{
   cout << output.book << " " << output.chapter << ":"
        << output.verse << endl;
}

/***********************************************************
 * Function: promptInsight
 * Purpose: prompt user for scripture and message
 **********************************************************/
void promptInsight(Insight & newInsight)
{
   cin.ignore();
   promptScripture(newInsight.scripture);
   cout << "Please share a brief thought on this scripture: ";
   cin.ignore();
   getline(cin, newInsight.message);
}

/***********************************************************
 * Function: displayInsight
 * Purpose: prompt user for scripture and message
 **********************************************************/
void displayInsight(const Insight & newInsight)
{
   displayScripture(newInsight.scripture);
   cout << newInsight.message << endl;
}

/*************************************************************
 * Function: Main
 * Purpose: callse promptScripture and displayScripture to run
 *************************************************************/
int main ()
{
   Scripture alma =
   {
      "Alma",
         31,
         5
   };
   displayScripture(alma);
   Scripture newScript;
   promptScripture(newScript);
   displayScripture(newScript);
   
   cout << "Lets create a list of your three favorite scriptures\n";
   Scripture favoriteScriptures[3];

   for (int i = 0; i < 3; i++)
   {
      cin.ignore();
      promptScripture(favoriteScriptures[i]);
   }
   cout << "Here is a list of your favorite scriptures\n";
   for (int i = 0; i < 3; i++)
      displayScripture(favoriteScriptures[i]);

   Insight newInsight;
   promptInsight(newInsight);
   displayInsight(newInsight);
   
   return 0;
}
