/***********************************************************************
* Program:
*    Lab 05, Homograph Lab
*    Brother Wilson, CS470
* Author:
*    Ali Cope
* Summary:
*   This lab is to check if two filenames are homographs.
*   The user will be prompted for two filenames. The program will
*   check to see if they actually point to the same file.
*
************************************************************************/

#include <iostream>  //required for COUT
#include <string> //required for string
#include<vector> //required to use a vector to split string
using namespace std;



string simplify(string name)
{
	//create a vector to hold the path parts
	vector <string> path;
	string temp;
	// for loop to split path into each part
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == '/')
		{
			path.push_back(temp);
			temp = "";
		}
		else if (i + 1 == name.length())
		{
			temp = temp + name[i];
			path.push_back(temp);
		}
		else
		{
			temp = temp + name[i];
		}
	}

	//create a vector to hold our simplified path
	vector <string> simplePath;
	//last item in path is our file name. We know we need to keep that
	//simplePath.push_back(path[path.size()-1]);
	//for loop to go though long path and split into smallest possible part 
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == string(".."))
		{
			if (simplePath.size() > 0)
			{
				simplePath.pop_back();
			}
		}
		else if (path[i] == "~")
			// navagate to home so clear out everything up to this point
			simplePath.clear();
		else if (path[i] == ".")
			// do nothing
		{
		}
		else
			simplePath.push_back(path[i]);
	}
	string simple;
	//
	for (int i = 0; i < simplePath.size(); i++)
	{
		//make sure we don't have any extra / or empty spaces
		if (simplePath[i] == "/" || simplePath[i] == "")
			//do nothing
		{
		}
		else
			simple += "/" + simplePath[i];
	}
	//cout << simple +"\n";
	return simple;
}


bool checkFilename(string first, string second)
{
	first = simplify(first);
	second = simplify(second);
	if (first == second)
		return true;
	else
		return false;
}


int main()
{
	string firstFile;
	string secondFile;
	//get filenames from the user
	cout << "Specify the first filename:  ";
	cin >> firstFile;
	cout << "Specify the second filename: ";
	cin >> secondFile;
	bool match;
	match = checkFilename(firstFile, secondFile);
	if (match)
		cout << "The paths are homographs\n";
	else
		cout << "The paths are NOT homographs\n";

	return 0;
}