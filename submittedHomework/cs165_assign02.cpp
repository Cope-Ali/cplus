/***********************************************************************
* Program: Digital Forensics
*    Assignment 02, Digital Forensics      
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary: 
*    Program will scan through system logs to identify users who accessed
*    files in a particular window of time. Program will do this by first
*    obtaining filename from user, then read file and save to array of records
*    next, the program will prompt for start and end time of the desired
*    records. Program will loop through the array of records and display
*    all records during the time indicated. Records will include timestamp
*    filename and username.
*
*    Estimated:  3.0 hrs start 747 end 945   
*    Actual:     2.0 hrs
*      The most difficult part was passing my array of structs and reading
*    the filename as a string. Once I was able to solve those issues (thanks
*    to the developers forum) it was pretty smooth sailing.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Struct for Access Record. Contains username, filename and timestamp
struct Record
{
   string username;
   string file;
   double timestamp;
};

void getFilename(string &filename);
void readFile (Record recordList[], const string &filename);
void timePrompt (double &start, double &end);
void displayAccessed (Record recordList[], double start, double end);

/**********************************************************************
 * Function: main
 * Purpose: create fileName, start, and end variables, create recordList
 *          array and call all functions to run
 ***********************************************************************/
int main()
{
   string filename;
   getFilename(filename);
   Record recordList[500];
   readFile(recordList, filename);
   double start;
   double end;
   timePrompt (start, end);
   displayAccessed(recordList, start, end);
   return 0;
}

/************************************************************************
 * Function: getFilename
 * Purpose: get file name from user
************************************************************************/
void getFilename(string &filename)
{
   cout << "Enter the access record file: ";
   getline(cin, filename);
}


/*********************************************************************
 * Function: readFile
 * Purpose: read file into an array of records
*********************************************************************/
void readFile (Record recordList[], const string &filename)
{
   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << endl;
   }
   while (!fin.eof())
   {
      for (int i = 0; i < 500; i++)
      {
         fin >> recordList[i].file >> recordList[i].username
             >> recordList[i].timestamp;
      }
   }
   fin.close();
}

/**********************************************************************
 * Function: timePrompt
 * Purpose: get start time and end time from user
**********************************************************************/
void timePrompt (double &start, double &end)
{
   cout << "\nEnter the start time: ";
   cin >> start;
   cout << "Enter the end time: ";
   cin >> end;
}

/**********************************************************************
 * Function: displayAccessed
 * Purpose: display all files accessed during requested time period
 *      along with the username and timestamp of the access
**********************************************************************/
void displayAccessed (Record recordList[], double start, double end)
{
   cout.setf(ios::fixed);
   cout.precision(0);
   cout << "\nThe following records match your criteria:\n\n"
        << setw(15) << "Timestamp" << setw(20) << "File"
        << setw(20) << "User" << endl << "---------------" << setw(20)
        << "-------------------" << setw(20) << " -------------------\n";
   for (int i = 0; i < 500; i++)
      if (recordList[i].timestamp >= start)
         if (recordList[i].timestamp <= end)
         {
            cout << setw(15) << recordList[i].timestamp
                 << setw(20) << recordList[i].file
                 << setw(20) << recordList[i].username << endl;
         }
   cout << "End of records\n";
}
