/***********************************************************************
* Program:
*    Assignment 42, Dem Bones
*    Brother Honeycutt, CS124
* Author:
*    Ali Cope
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.5 hrs
*      I had to watch my loop so that I wasn't looping past the end of
*      the array list.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;
   string connect = " connected to the ";

 // append the list to add 'bone' to end of each item
   for(int i = 0; i < 9; i++)
      list[i] += " bone";

   // combine the strings together to make the output
   for(int i=0; i < 8; i++)
   {
      output += list[i] + connect + list[i+1] + "\n";
   }
   // your code goes here

   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] =
   {
      "toe",
      "foot",
      "leg",
      "knee",
      "hip",
      "back",
      "neck",
      "jaw",
      "head"
   };

   // generate the song
   string song = generateSong(list, 9);

   // display the results
   cout << song;
   
   return 0;
}
