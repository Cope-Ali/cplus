/***********************************************************************
 * COMPONENT:
 *    MESSAGE
 * Author:
 *    Br. Helfrich, Ali Cope
 * Summary:
 *    This class stores the notion of a message
 ************************************************************************/

#include <iostream>   // standard input and output
#include <cassert>    // because I am paraniod
#include "message.h"  // for the header file
using namespace std;

/**************************************************
 * MESSAGE DEFAULT CONSTRUCTOR
 * Set a message to empty
 **************************************************/
Message ::  Message()
{
   empty = true;
   text = "Empty";
   id = idNext++;
   control = PUBLIC;
}


/**************************************************
 * MESSAGE NON-DEFAULT CONSTRUCTOR
 * Create a message and fill it
 **************************************************/
Message::Message(const string & text,
                 const string & author,
                 const string & date,
                 const Control & control)
{
   this->text = text;
   this->author = author;
   this->date = date;
   this->id = idNext++;
   this->control = control;
   empty = false;
}

/****************************************************
 * Message :: CAN READ
 * Can the message be read by teh entity?
 ****************************************************/
bool Message :: canRead(const Control & userControl) const
{
   return userControl >= this->control;
}

/****************************************************
 * Message :: CAN WRITE
 * Can the message be written/edited/deleted by entity?
 ****************************************************/
bool Message :: canWrite(const Control & userControl) const
{
   return userControl <= this->control;
}




/**************************************************
 * MESSAGE :: DISPLAY PROPERTIES
 * Display the attributes/properties but not the
 * content of this message
 **************************************************/
void Message::displayProperties(const Control & userControl) const
{
   // skip this one if there is nothing to see
   if (empty)
      return;
   else if (canRead(userControl))
   {

   // display the message
   cout << "\t[" << id << "] ";
      cout << "Message from " << author << " at " << date;
   cout << endl;
   }
   else
   {
      cout << "\t[" << id << "] ";
      cout << "Classified";
      cout << endl;
   }
   
}

/**************************************************
 * MESSAGE :: DISPLAY TEXT
 * Display the contents or the text of the message
 **************************************************/
void Message::displayText(const Control & userControl) const
{
   if(canRead(userControl))
   {
       cout << "\tMessage: "
        << text
        << endl;
   }  
   else
   {
      cout << "\tMessage: Classified" << endl;
   }
   
}

/**************************************************
 * MESSAGE :: UPDATE TEXT
 * Update the contents or text of the message
 **************************************************/
void Message::updateText(const string & newText, const Control & userControl)
{
   if(canWrite(userControl))
   {
      text = newText;
   }
   else
   {
      cout << "\tDENIED! You do not have permission to update this message" << endl;
   }
   
}

/**************************************************
 * MESSAGE :: CLEAR
 * Delete the contents of a message and mark it as empty
 *************************************************/
void Message::clear(const Control & userControl)
{
   if(canWrite(userControl))
   {
   text = "Empty";
   author.clear();
   date.clear();
   control = PUBLIC;
   empty = true;
   }
   else
   {
      cout << "\tDENIED! You do not have permission to delete this message" << endl;  
   }
   
}

int Message::idNext = 100;
