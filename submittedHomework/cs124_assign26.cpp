/***********************************************************************
* Program:
*    Assignment 26, Files        
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    Program will read 10 grades from a file and display the average

*    Estimated:  0.75 hrs   
*    Actual:     2.0 hrs
*      I had a difficult time figuring out when i needed to add square
*      brackets to the fileName. Even after reading th chapter multiple
*      times, watching the videos and checking the dev forum I was still
*      getting compiler errors. Finally I just read ahead in the book to
*      understand more about Arrays. Then I understood it very easially.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void getFileName(char fileName[]);
float readFile(char fileName);
void display (float average);

/*********************************************************************
* Get file name from user
*********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/********************************************************************
* read the file, verify there are exactly 10 grades, compute and
* return average
*******************************************************************/
float readFile(char fileName[])
{
//verify valid file name
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return 0;
   }
   int data;  
   float average = 0;
   int count = 0;
   while (fin >> data)
   {
      average += data;
      count ++ ;
   }
   if (count != 10)
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return 0;
   }
   average /= 10;
   fin.close();
   
   return average;
}

/*********************************************************************
* display the average to the user
*********************************************************************/
void display (float average)
{
   if (average != 0)
   {
      cout.setf(ios::fixed);
      cout.precision(0);
      cout << "Average Grade: " << average << "%" << endl;
   }
}

/**********************************************************************
* Call all functions to run
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   float average = readFile(fileName);
   display(average);
   return 0;
}
