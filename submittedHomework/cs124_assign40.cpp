/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimensional Arrays        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will read a tic-tac-tow board into an array. The program
*    will display the board then write the board to a file.

*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      Assignment went pretty smoothly. I had a little trouble getting
*    all the formatting and pacing just the way test bed wanted, but I
*    was able to get it to work using some if statements
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFile(char fileName[256], char grid[][3]);
void display(char grid [][3]);
void promptSave(char grid[][3]);
                  
/**********************************************************************
 * run promptSource to get file name, open file, run display to display board
 * run prompt save to get save file name and save file.
 ***********************************************************************/
int main()
{
// prompt for file name
   char fileName[256];
   cout << "Enter source filename: ";
   cin >> fileName;

//open file and save to grid
   char grid[3][3];
   getFile(fileName, grid);

//display grid to user
   display(grid);   

// get filename and save file
   promptSave(grid);
   
   return 0;
}

/*********************************************************************
* Prompt the user for source filename
********************************************************************/
void getFile(char fileName[256], char grid[][3])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return;
   }

// write file to grid
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
      {
         char input;
         fin >> input;
         grid[row][col] = input;
      }
   fin.close();
}

/*******************************************************************
* Display the tic tac toe file in the correct grid form
*******************************************************************/
void display(char grid[][3])
{
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
// check for "." and change to " "
         if (!isalpha(grid[row][col]))
            cout << "  ";
         else
            cout << " " << grid[row][col];

//display board between collumns
         if (col < 2)
            cout << " |";
      }
      cout << " \n";

// display board between rows
      if (row < 2)
         cout << "---+---+---\n";
   }
}

/*****************************************************************
* Prompt user for save file name and save file
****************************************************************/
void promptSave(char grid[][3])
{
//get file name
   char saveFile[256];
   cout << "Enter destination filename: ";
   cin >> saveFile;

//get ready to save file
   ofstream fout(saveFile);
   if (fout.fail())
      cout << "Error saving file " << saveFile;

//loop to write file
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         fout << grid[row][col];
   fout.close();
   cout << "File written\n";
}
