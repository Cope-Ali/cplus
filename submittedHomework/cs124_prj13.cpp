/***********************************************************************
* Program:
*    Project 13, Sudoku        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*   This is the final version of the sudoku game program. This program will
*   display a game board, allow the user to solve the puzzle by editing
*   squares. The user can also display a menu of options and save and quit
*   their game. This version will also allow the user to ask for all
*   possible answers to a square.
*
*    Estimated:  3.0 hrs   
*    Actual:     2.0 hrs
*      The most difficult part for me was getting the formatting correct.
*    sometimes there are two lines, sometimes one. It wasn't too hard to
*    figure out how to pass values to be checked. 
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
int possibleValue(int game[][9], int value, int row, int col);

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
      
// ensure square is empty and valid
   if (game[col][row] >= 1)
      cout << "ERROR: Square \'" << colLetter << (row + 1)
           << "\' is filled\n";
   else if (row > 9 || col > 9)
      cout << "ERROR: Square \'" << colLetter << (row + 1)
           << "\' is invalid\n";
      
//get new value for square
   else
   {
      cout << "What is the value at \'" << colLetter << (row + 1) << "\': ";
      cin >> value;
//ensure input is valid
      if (possibleValue(game, value, row, col) == 1)
         cout << "ERROR: Value '" << value << "' in square '" << colLetter
              << (row + 1) << "' is invalid\n";
      else
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
   char colLetter;
   int row;

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

//convert row to array number because arrays start with 0 not 1
   row--;

   
   cout << "The possible values for '" << colLetter << row + 1 << "' are: ";

//check each number from 1 to 9
   bool first = true;
   for (int count = 1; count <= 9; count++)
   {
      if (possibleValue(game, count, row, col) == 0)
         if (first)
         {
            cout << count;
            first = false;
         }
         else
            cout << ", " << count;
   }
   cout << "\n" << endl;
   return 0;
}

/**********************************************************************
* Determine if a value breaks rules or is possible
**********************************************************************/
int possibleValue(int game[][9], int value, int row, int col)
{
   int inRow;
   int inCol;
   int inSq;
   int rowCount;
   int colCount;
   
   
//Check to see if number is already present in the row
   for (int i = 0; i < 9; i++)
      if (value == game[row][i])
         return 1;

// Check to see if number is already present in the column
   for (int i = 0; i < 9; i++)
      if (value == game[i][col])
         return 1;

// Check to see if number is already present in the square

// Determine which square the coordinates is in set row to top of square
   if (row / 3 == 0)
      rowCount = 0;
   if (row / 3 == 1)
      rowCount = 3;
   if (row / 3 == 2)
      rowCount = 6;

//set column to front of square
   if (col / 3 == 0)
      colCount = 0;
   if (col / 3 == 1)
      colCount = 3;
   if (col / 3 == 2)
      colCount = 6;
   
   for (int rowi = 0; rowi < 3; rowi++)
      for (int coli = 0; coli < 3; coli++)
         if (value == game[rowCount + rowi][colCount + coli])
            return 1;

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

