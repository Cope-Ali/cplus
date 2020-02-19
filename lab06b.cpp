/***********************************************************************
 * Program:
 *    Lab 06, Sanitization
 *    Brother Wilson, CS470
 * Author:
 *    Ali Cope
 * Summary:
 *    The purpose of this program is to sanitize user input to protect 
 *       against command vulnerabilities
 *    This program will prompt the user for input, run input through a 
 *      sanitization filer to remove all constructs not on the approved 
 *      whiteList, then display the sanitized result.
 *    The whiteList of approved HTML tags are:
 *      a, abbr, acronym, b, blockquote, cite, code, del, em, i, q, 
 *      strike, strong
 ************************************************************************/

#include <iostream>  //required for COUT
#include <string> //required for string
#include <set> //required for using sets
#include <stack> // required for our stack of tags
using namespace std;

//create a set to hold approved tags
set<string> whiteList;
//create a stack to hold any approved tags
stack<string> tagStack;
//should the program loop?
bool loop = true;

int fillwhiteList()
/* fillwhiteList() adds the approved tags to the whiteList set
*/
    {
        whiteList.insert("a");
        whiteList.insert("abbr");
        whiteList.insert("acronym");
        whiteList.insert("b");
        whiteList.insert("blockquote");
        whiteList.insert("cite");
        whiteList.insert("code");
        whiteList.insert("del");
        whiteList.insert("em");
        whiteList.insert("i");
        whiteList.insert("q");
        whiteList.insert("strike");
        whiteList.insert("strong");
        return 0;
    }

string safe(string test)
/* safe() takes a string and compares it to the white list. If it is safe it
returns the string with the opening and closing tags. If it is not safe it
returns the sanitized string.
*/
{
    //std::cout << "\nsearching set for " + test + "\n";
    //auto pos = whiteList.find(test);
    if (whiteList.find(test) != whiteList.end())
    {
        //cout << "found " + test + " in set \n";
        //if the tag is good, push onto the stack
        tagStack.push(test);
        return "<" + test + ">";
    }
    // check for approved "a" tag and include hyperlink
    else if (test[0] == 'a')
    {
        tagStack.push("a");
        return "<" + test + ">";
    }
    else
    {
        //if the tag is not in the approved list, return sanitized version
       return "&lt;" + test + "&gt;";
    }
}

string sanitize(string input)
/* sanitize() takes a string input that needs to be sanitized. It will parse 
through to look for opening and closing tags. When they are found the internal
string is sent to see if it is safe. Text that is not identified as tags are added to the sanitized string and the sanitized string is returned
*/
{
    //create a variable to hold our sanitized output
    string output;
    //create variable tag to hold potential tags
    string tag;
    

     //loop through each character in text
     //cout << "\nabout to loop through each char\n";
        for(int i = 0; i < input.length(); i++)
        {
            //if char is not < add it to output
           // cout << "\n logic test 1 \n";
            if (input[i] != '<')
                output += input[i];
            //if it IS a < we need to find the rest of the tag
            else
            {
                //starting with the char after '<' 
                //loop forward as long as i is not '>'
                //cout << "\n looping to find closing bracket \n";
                for(i = i+1; input[i] != '>'; i++)
                {
                    //add the char to the tag
                    tag += input[i];
                }
                //we need to check if it is a closing tag
                if(tag[0]=='/')
                {
                    //if its a closing tag, we need to see if it is nested properly
                    string temp;
                    //get the tag without '/'
                    for(int i = 1; i < tag.length(); i++)
                    {
                        temp+=tag[i];
                    }
                    //compare temp to the top of the tagStack
                    if(!tagStack.empty() && temp == tagStack.top())
                    {
                        //they are the same so add the closing tag to the output
                        output += "</" + temp + ">";
                        //pop the top tag off the stack
                        tagStack.pop();
                        tag = "";
                    }
                    //temp doesn't match so it isn't nested properly, output sanitized endtag instead
                    else
                    {
                        output += "&lt;/" + temp + "&gt;";
                        tag = "";
                    }         
                }
                //not a closing tag so lets make it safe
                else
                {               
                //now we need to make the tag safe. if it is approved we will receive back the sanitized version
                output += safe(tag);
                tag = "";
                } 
            }
        }
        //check to see if we have any remaining tags
    if (!tagStack.empty())
        {
        //add closing tags for all open tags to the output
        //cout << tagStack.size();
        for (int i = 0; i <tagStack.size(); i++)
            {
                output += "</" + tagStack.top() + ">";
                tagStack.pop();
            } 
        }
    return output;
}

string getInput()
/*getInput() prompts the user for input and returns what they enter
*/
{
    string input;
      //prompt user
        std::cout << "> ";
        //get the whole line of text and save to "input" variable
        getline (cin, input);
        if(input == "quit")
        {
            loop = false;
        }
    return input;
}


int main()
/* The main function loops through the various methods to prompt for input, sanitize the string and output the result. The loop continues until the user enters 'quit'
*/
{
    //fill our whitelist with approved tags
    fillwhiteList();
    //create string to hold user input
    string inputString = "";
    //loop through until the user enters "quit"
    while (loop)
    {
        //get the user's input
        string inputString = getInput();
        //sanitize the inputted string
        string sanitizedString = sanitize(inputString);
        //output the sanitized string
        cout << "\t" + sanitizedString + "\n";
    } 
    return 0;
}