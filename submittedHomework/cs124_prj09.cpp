/***********************************************************************
* Program:
*    Project 09, Mad Lib assign 2        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    MadLib program will prompt a player for madlib file then all the words to
*    substitute. When all prompts are complete the program will display the
*    completed story.
*
*    Estimated:  3.0 hrs   
*    Actual:     10.0 hrs
*      Man this program really gave me a hard time. I had a difficult time
*   setting up my array. I had a hard time passing the words to my
*   ask questions function. I had a hard time getting only the word prompts
*   and not any of the punctuation prompts to show up. I watched the help
*   videos, followed the developers forum, and watched the recorded office
*   hours about 4 times. Each time I tried to "fix" something I "broke"
*   something. I really feel like (and I am hoping I am right" that this was
*   the hardest part of this program and that next week will go better. I am
*   kind of disappointed that I struggled so much. Up to this point everything
*   has just clicked. But I didn't give up or quit and I have a program that
*   passes test bed!
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void readFile(char story[][256]);
//bool playAgain();
//void displayStory(char story, int length, bool isPuc);
//bool isPunc(char character);
void askQuestion(char text[256]);

/**********************************************************************
 * Main function, creates story array and calls the readFile program
 ***********************************************************************/
int main()
{
   char story[256][256];
   readFile(story);
   return 0;
}

/**********************************************************************
* Reads the file, checks that the file is valid, feeds each word into
* the askQuestion function.
***********************************************************************/
void readFile(char story[][256])
{
   char fileName[256];
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;  
   //open file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "ERROR: Unable to read file " << fileName << endl;
      return;
   }

   //increment story index loop
   for (int i = 0; fin >> story[i]; i++)
   {
      askQuestion(story[i]);
   }
   
   fin.close();
   cout << "Thank you for playing.\n";
   return ;
}

/********************************************************************
 * Function checks text word by word for user prompts, prompts the
 * user and stores the response back into the array.
************************************************/
void askQuestion(char text[256])
{
   if (text[0] == '<')
   {
      if (isalpha(text[1]))
      {
         cout << "\t" << (char)toupper(text[1]);
         for (int iText = 2; text[iText] != '>'; iText++)
         {
            if (text[iText] == '_')
               cout << " ";
            else
               cout << (char)tolower(text[iText]);
         }
         cout << ": ";
         cin.ignore();
         cin.getline(text, 32);
         return; 
      }
      else
         return;
   }
}

/**********************************************************************
* Asks player if they want to play again
***********************************************************************/
bool playAgain()
{

}

/**********************************************************************
* displays the finished story to the user. Includes calling isPunc function
* to check for punctuation and adding spaces between words
***********************************************************************/
void displayStory(char story, int length, bool isPuc)
{

}

/**********************************************************************
* checks character for symbol and converts to punctuation
***********************************************************************/
bool isPunc(char character)
{

}

