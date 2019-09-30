/***********************************************************************
* Program:
*    Project 11, Sudoku Draft        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   
*    Estimated:  3.0 hrs   
*    Actual:     5.0 hrs
*
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void interact(int game[][9]);
void getFile(char gameName[265]);
void readFile(char gameName[265], int game[][9]);
void displayOptions ();
void displayGame(int game[][9]);
int editSquare(int game[][9]);
int convert(char colLetter);
int computeValues(int game[][9]);
bool saveQuit(int game[][9]);

/**********************************************************************
 * Main function, calls other funtions to run
 ***********************************************************************/
int main()
{
   char gameName [256];
   getFile (gameName);
   int game[9][9];
   readFile (gameName, game);
   displayOptions();
   displayGame(game);
   interact(game);

   return 0;
}

/*******************************************************************
 * get board location filename from user
 ********************************************************************/
void getFile (char gameName[256])
{
   cout << "Where is your board located? ";
   cin >> gameName;  

}

/**********************************************************************
* Reads the file, checks that the file is valid, changes '0' to ' '
***********************************************************************/
void readFile(char gameName[256], int game[][9])
{
   //open file
   ifstream fin(gameName);
   if (fin.fail())
   {
      cout << "ERROR: Unable to read file " << gameName << endl;
      return;
   }
   
   //write from file to row and column in game[][]
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {
         int input;
         fin >> input;
         game[row][col] = input;
      }
   
   fin.close();
   return ;
}

/********************************************************************
* main interation menu for user. calls funtions depending on user input
********************************************************************/
void interact(int game[][9])
{
   int exit = 0;
   do {
   char input;
//user prompt
   cout << ">";
   cin >> input;

      switch(input)
      {
         case '?':
            displayOptions();
            break;
         case 'd':
         case 'D':
            displayGame(game);
            break;
         case 'e':
         case 'E':
            editSquare(game);
            break;
         case 's':
         case 'S':
            computeValues(game);
            break;
         case 'q':
         case 'Q':
            saveQuit(game);
            exit = 1;
            break;
         default:
            cout << "ERROR: Invalid command";
            break;
      }
   }
   // end loop if exit is changed to 1 for save and exit.
   while (exit == 0);
   return;
}

/*********************************************************************
 * display the options for the user
 ********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and quit\n";
   return;
}


/**********************************************************************
* display the gameboard
***********************************************************************/
void displayGame(int game[][9])
{
//display column names
   cout << "   A B C D E F G H I\n";
   //display each row
   int rowTitle = 1;
   for (int row = 0; row < 9; row++)
   {
      cout << rowTitle << "  ";
      rowTitle++;
      for (int col = 0; col < 9; col++)
      {
         // check for '0' change to ' '
         if (game[row][col] == 0)
            cout << " ";
         else
            cout << game[row][col];
//make boxes
         if (col == 2 || col == 5)
            cout << "|";
         else
            if (col < 8)
               cout << " ";
            else
               cout << endl;
      }
      if(row == 2 ||row == 5)
         cout << "   -----+-----+-----\n";
   }
   
}

/****************************************************************************
* edit one square of the game board
*****************************************************************************/
int editSquare(int game[][9])
{
   char colLetter;
   int row;
   int value;
 
//get coordinates of square to edit
      cout << "What are the coordinates of the square: ";
      cin >> colLetter >> row;
      if (!isalpha(colLetter))
      {
         //switch colLetter and row values if number entered first (A1 vs 1A)
         char temp = row;
         row = colLetter;
         colLetter = temp;
      }

//convert letter to col array number
      int col = convert(colLetter);

      //adjust row number because array starts at 0 not 1
      row--;
      
//ensure input is valid and empty
      if (row > 9 || col > 9)
         cout << "ERROR: Square " << colLetter << (row + 1) << " is invalid";

      if (game[col][row] >= 1)
         cout << "ERROR: Square " << colLetter << (row + 1) << " is filled";
      
//get new value for square
      else
      {
         cout << "What is the value at \'" << colLetter << row << "\':";
         cin >> value;
         game[col][row] = value;
      }
   return 0;
}

/*********************************************************************
* Convert collumn letter to collumn number
********************************************************************/
int convert(char colLetter)
{
   int col;
      switch (colLetter)
   {
      case 'a':
      case 'A':
         col = 0;
         break;
      case 'b':
      case 'B':
         col = 1;
         break;
      case 'c':
      case 'C':
         col = 2;
         break;
      case 'd':
      case 'D':
         col = 3;
         break;
      case 'e':
      case 'E':
         col = 4;
         break;
      case 'f':
      case 'F':
         col = 5;
         break;
      case 'g':
      case 'G':
         col = 6;
         break;
      case 'h':
      case 'H':
         col = 7;
         break;
      case 'i':
      case 'I':
         col = 8;
         break;
      default:
         col = 9;
         break;
   }
   return col;
   }
/**********************************************************************
*
***********************************************************************/
int computeValues(int game[][9])
{
   return 0;
}

/**********************************************************************
*
***********************************************************************/
bool saveQuit(int game[][9])
{
   char saveFileName[256];
   cout << "What file would you like to write your board to: ";
      cin >> saveFileName;

      ofstream fout(saveFileName);
      if (fout.fail())
         return false;

 for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {
         int output;
         game[row][col] = output;
         fout << output;
      }

      fout.colse();
      //if file saved correctly
       cout << "Board written successfully";
   return true;
}
