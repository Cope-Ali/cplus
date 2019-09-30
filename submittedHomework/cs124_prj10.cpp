/***********************************************************************
* Program:
*    Project 10, Mad Lib final        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    MadLib program will prompt a player for madlib file then all the words to
*    substitute. When all prompts are complete the program will display the
*    completed story.
*
*    Estimated:  3.0 hrs   
*    Actual:     5.0 hrs
*      This program when much better than project 9. The hardest part was
*    figuring out all of the different situations for spacing and punctuation
*    and ensuring that the logic will display everything correctly.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void readFile(char story[][256], int &length);
bool playAgain();
void displayStory(char story[][256], int length);
void isPunc(char character, int &newLine);
void askQuestion(char text[256], bool &firstPrompt);
void isPuncNoSpace(char character, int &newLine);

/**********************************************************************
 * Main function, creates story array and calls the readFile program
 ***********************************************************************/
int main()
{
   char story[256][256];
   int length = 0;
   int playNew = 0;
   do
   {
      readFile(story, length);
      cout << endl;
      displayStory(story, length);
      //cout <<    endl;
      playNew = playAgain();
   }
   while (playNew > 0);
   return 0;
}

/**********************************************************************
* Reads the file, checks that the file is valid, feeds each word into
* the askQuestion function.
***********************************************************************/
void readFile(char story[][256], int &length)
{
   length = 0; //reset word length
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
   bool firstPrompt = true;
   //increment story index loop
   for (int i = 0; fin >> story[i]; i++)
   {
      askQuestion(story[i], firstPrompt);
      length++;
   }
   
   fin.close();
   return ;
}

/********************************************************************
 * Function checks text word by word for user prompts, prompts the
 * user and stores the response back into the array.
************************************************/
void askQuestion(char text[256], bool &firstPrompt)
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
         if (firstPrompt)
         {
            cin.ignore();
            cin.getline(text, 32);
            firstPrompt = false;
            return;
         }
         else
         {
            cin.getline(text,32);
            return;
         }
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
   char response;
   cout << "Do you want to play again (y/n)? ";
   cin >> response;
   if (response == 'y')
      return 1;
   else
      cout << "Thank you for playing.\n";
   return 0;
}

/****************************************************************************
* displays the finished story to the user. Includes calling isPunc function
* to check for punctuation and adding spaces between words
*****************************************************************************/
void displayStory(char story[][256], int length)
{
   int newLine = 0;
   for (int i = 0; i < length; i++)
   {
      // if the last word was a new line character 
      if (newLine > 0)
         // if current word is alpha output word and reset newLine
         if (isalpha(story[i][0]))
         {
            cout << story[i];
            newLine = 0;
         }
      // if not alpha (so is symbol) send to punc with no spaces and
      // reset newLine
         else
         {
            isPuncNoSpace(story[i][1], newLine);
            newLine = 0;
         }
      // if last word was NOT a new line
      // if current word is a symbol and next word is alpha (space)
      else if (story[i][0] == '<' && !isalpha(story[i][1]) &&
               story[i + 1][0] != '<')
         isPunc(story[i][1], newLine);
      // if current word is symbol and next word is symbol (no space)
      else if (story[i][0] == '<' && story[i + 1][0] == '<')
         isPuncNoSpace(story[i][1], newLine);
      // no symbols just output the word
      else
         cout << story[i];
      // add spaces between two words
      if (isalpha(story[i + 1][0]) && isalpha(story[i][0]))
         cout << " ";
      //if we are not on the last word
      if (story[i + 1] > 0)
         // add a space after . and , marks
         if ((story[i][0] == '.' || story[i][0] == ',') &&
             (i < (length - 1) && isalpha(story[i + 1][0])))
            cout << " ";
   }
   cout << endl;
   return;
}

/**********************************************************************
* checks character for symbol and converts to punctuation add space
***********************************************************************/
void isPunc(char character, int &newLine)
{
   switch (character)
   {
      case '#':
         cout << endl;
         newLine = 1;
         break;
      case '}':
         cout << "\" ";
         break;
      case '{':
         cout << " \"";
         break;
      case '[':
         cout << " \'";
         break;
      case ']':
         cout << "\' ";
         break;
   }
}

/**********************************************************************
* checks character for symbol and converts to punctuation with no space
* for use at the end of sentences
***********************************************************************/
void isPuncNoSpace(char character, int &newLine)
{
   switch (character)
   {
      case '#':
         cout << endl;
         newLine = 1;
         break;
      case '}':
         cout << "\"";
         break;
      case '{':
         cout << "\"";
         break;
      case '[':
         cout << "\'";
         break;
      case ']':
         cout << "\'";
         break;
   }
}
