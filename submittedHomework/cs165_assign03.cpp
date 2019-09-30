/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics With Corrupt Files      
*    Brother Alvey, CS165
* Author:
*    Ali Cope
* Summary:
*   Progam 2.0:
*   Program will function as in original program, but will also handle corrupt
*   files. A note of the corruption will be output when it is encountered
*   but the program will move past it to read the rest of the file.
*
*    Original Program:
*    Program will scan through system logs to identify users who accessed
*    files in a particular window of time. Program will do this by first
*    obtaining filename from user, then read file and save to array of records
*    next, the program will prompt for start and end time of the desired
*    records. Program will loop through the array of records and display
*    all records during the time indicated. Records will include timestamp
*    filename and username.
*
*    Estimated:  2.0 hrs    
*    Actual:     2.5 hrs
*
*    I had a hard time getting the program to compile because I had
*    accidentally reversed the symbols on one of my couts from << to >>
*    this threw so many errors it was crazy! As soon as I fixed that problem
*    it compiled. Then my issue was that I kep throwing parsing errors for
*    empty lines. It was like the file had empty lines in it before the
*    end of file mark was read. I added an if statement to check and make sure
*    that the string length was greater than 0 before I tried to parse it
*    and that solved all of the issues and it passed testbed. It is amazing
*    how one little thing can completely make or break a program.
*
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

// Struct for Access Record. Contains username, filename and timestamp
struct Record
{
   string username;
   string file;
   double timestamp;
};

void getFilename(string &filename);
void parseFile (Record recordList[], const string &filename);
void parseLine(Record &record, string line) throw (string);
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
   parseFile(recordList, filename);
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


/**********************************************************************
 * Function: parseFile
 * Purpose: parse file one line at a time
**********************************************************************/
void parseFile (Record recordList[], const string &filename)
{
   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << endl;
   }
   string line;
   Record record; 
   while (!fin.eof())
   {
      for (int i = 0; i < 500; i++)
      {
         getline(fin, line);
         if (line.size() > 0)
         {
            try
            {
               parseLine(record, line);
               recordList[i] = record;
            }
            catch (string line)
            {
               cout << "Error parsing line: " << line << endl;
            }
         }
      }
   }
   fin.close();
}

/**********************************************************************
 * Function: parseLine
 * Purpose: parse line, check for errors, save to array
**********************************************************************/
void parseLine(Record &record, string line) throw (string)
{
   stringstream ss;
   ss.str(line);
   ss >> record.file;
   if (ss.fail())
      throw (line);
   else
   {
      ss >> record.username;
      if (ss.fail())
         throw (line);
      else
      {
         ss >> record.timestamp;
         if (ss.fail() || record.timestamp < 1000000000 ||
             record.timestamp > 10000000000)
            throw(line);
      }
   }
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
