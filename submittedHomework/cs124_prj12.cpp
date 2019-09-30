/***********************************************************************
* Program:
*    Project 12, Sudoku        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   This is the first version of the sudoku game program. This program will
*   display a game board, allow the user to solve the puzzle by editing
*   squares. The user can also display a menu of options and save and quit
*   their game. Future versions will also allow the user to ask for all
*   possible answers to a square.
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      The most difficult part for me was getting the file to save correctly.
*    I could get the file to cout correctly but when I switched to fout it
*    didn't work the same way. Thanks to the developers forum I was able to
*    solve the problem. I had one other issue with switching my rows and
*    columns but that was quickly solved.         
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
 * Main function, calls other functions to run
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
 * get board location file name from user
 ********************************************************************/
void getFile (char gameName[256])
{
   cout << "Where is your board located? ";
   cin >> gameName;  

}

/**********************************************************************
* Reads the file, checks that the file is valid, changes '0' to space
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
* main interaction menu for user. calls functions depending on user input
********************************************************************/
void interact(int game[][9])
{
   int exit = 0;
   do
   {
      char input;
//user prompt
      cout << "> ";
      cin >> input;
      
      switch (input)
      {
         case '?':
            displayOptions();
            cout << "\n";
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
        << "   Q  Save and Quit\n"
        << endl;
   
   return;
}


/**********************************************************************
* display the game board
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
         // check for '0' change to space
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
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << endl;   
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
      cout << "ERROR: Square \'" << colLetter << (row + 1)
           << "\' is invalid\n";
   
   if (game[col][row] >= 1)
      cout << "ERROR: Square \'" << colLetter << (row + 1)
           << "\' is filled\n";
      
//get new value for square
   else
   {
      cout << "What is the value at \'" << colLetter << (row + 1) << "\': ";
      cin >> value;
      game[row][col] = value;
   } 
   cout << endl;
   return 0;
}

/*********************************************************************
* Convert column letter to column number
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
* Calculate the possible values for a given square
***********************************************************************/
int computeValues(int game[][9])
{
   return 0;
}

/**********************************************************************
* Get the file name from user and save game board to file
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
   {
      for (int col = 0; col < 9; col++)
         fout << game[row][col] << " ";
      fout << endl;
   }
   
   fout.close();
   cout << "Board written successfully\n";
   return true;
}

