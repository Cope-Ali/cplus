/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy  
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    This program will allow the user to compare their DNA markers and
*    the markers of potential relatives to analyze how closely they are
*    related. The program will first prompt the user for a 10 character
*    DNA marker sequence, the number of relatives to compare and the name
*    and DNA marker sequence for each relative. The DNA marker sequences
*    will be compared and the percent match will be displayed to the user.
*
*    Estimated:  4.0 hrs   
*    Actual:     2.75 hrs
*      I started by stubbing out all of my functions and determining how I
*    wanted them to work together. I complied and fixed errors after each
*    function was created. I kept having a problem where my percentage was
*    always zero. I assumed this was a problem with my arrays. This was
*    probably because arrays are the newest to me, so I have less confidence
*    with them. In the end it was an operator error. I was dividing the
*    number of matches by 10 instead of multiplying by 10. As soon as I
*    fixed this one issue everything else worked. I then went back and tried
*    to remove any complicated code I added, when I was trying to solve
*    my problem. Next time I need to have a little more confidence and check
*    for a small error instead of assuming my approach is wrong and doing
*    a bunch of unnecessary work.
************************************************************************/

#include <iostream>
using namespace std;

int getDNA(char userDNA[]);
int getRelatives(int &numRelatives, char relatives[][256]);
int getRelativeDNA(char relatives [][256], char relativeDNA[][10],
                   int numRelatives);
int compareDNA(char userDNA[], char relativeDNA[]);
void display(char userDNA[], char relativeDNA[][10], int numRelatives,
             char relatives[][256]);

/**********************************************************************
 * Creates arrays: userDNA, relatives, and  relativeDNA
 * Calls all other functions to prompt user and display output
 ***********************************************************************/
int main()
{
//create an array to hold the user's DNA sequence and run getDNA()
   char userDNA[10];
   getDNA(userDNA);

// create a multidimensional array to hold names of relatives
   char relatives[20][256];

// create numRelatives and run getRelatives() to get names and number
   int numRelatives;
   getRelatives(numRelatives, relatives); 

// create nultidimensional array to hold relatives' DNA sequence
   char relativeDNA[20][10];
   getRelativeDNA(relatives, relativeDNA, numRelatives);

   display(userDNA, relativeDNA, numRelatives, relatives);
   

   return 0;
}

/**********************************************************************
 * prompts user for their DNA sequence and stores it in userDNA array
 ***********************************************************************/
int getDNA(char userDNA[10])
{
   cout << "Enter your DNA sequence: ";
   cin >> userDNA;
   return 0;
}

/**********************************************************************
 * prompts user for the number of relatives to compare and their names.
 * Assigns their names to the relatives array.
 ***********************************************************************/
int getRelatives(int &numRelatives, char relatives[][256])
{
   cout << "Enter the number of potential relatives: ";
   cin >> numRelatives;
   cout << endl;
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the name of relative #" << i + 1
           << ": ";
      cin >> relatives[i];
   }
   cout << endl;
   
   return 0;
}

/**********************************************************************
 * Prompts user for the DNA sequence of each relative and stores them in
 * relativeDNA array
 ***********************************************************************/
int getRelativeDNA(char relatives[][256], char relativeDNA[][10],
                   int numRelatives)
{
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the DNA sequence for " << relatives[i]
           << ": ";
      cin >> relativeDNA[i];
   }
   
   return 0;
}

/**********************************************************************
 * compares two strands of DNA, calculates the percentage match and
 * returns percentage to user.
 ***********************************************************************/
int compareDNA(char userDNA[10], char relativeDNA[10])
{
   int match = 0;
   for (int i = 0; i < 10; i++)
      if (userDNA[i] == relativeDNA[i])
         match++;
   
   return match * 10;
}

/**********************************************************************
 * calls compareDNA and displays the result to the user.
 ***********************************************************************/
void display(char userDNA[], char relativeDNA[][10], int numRelatives,
             char relatives[][256])
{
   for (int i = 0; i < numRelatives; i++)
   {
      int results = compareDNA(userDNA, relativeDNA[i]);
      cout << "\nPercent match for " << relatives[i] << ": "
           << results << "%" ;
   }
   cout << endl;
   return;
}
