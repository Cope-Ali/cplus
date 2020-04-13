/***********************************************************************
* COMPONENT:
*    MESSAGE
* Author:
*    Br. Helfrich, Ali Cope
* Summary: 
*    This class stores the notion of a message
************************************************************************/

#pragma once

#include <string>     // for convenience
#include "control.h"  // for all the control stuff


/**************************************************
 * MESSAGE
 * one message to be displayed to the user or not
 **************************************************/
class Message
{
public:
   // default constructor for an empty message
   Message();

   // the most commonly used constructor: create a message
   Message(const std::string & text,
           const std::string & author,
           const std::string & date,
           const Control & control);

   //determine if the message can be read by entity
   bool canRead(const Control & userControl) const;

   //determine if the message can be w/e/d by entity
   bool canWrite(const Control & userControl) const;

   // determine the unique ID of this message
   int getID() const { return id; }

   // display the properties but not content of the message
   void displayProperties(const Control & userControl) const;

   // display the content of the message
   void displayText(const Control & userControl) const;

   // update the text componnet of the message
   void updateText(const std::string & newText, const Control & userControl);

   // clear out a message
   void clear(const Control & userControl);
   
private:
   int id;                   // the unique ID of this message
   static int idNext;        // the id of the next message created
   bool empty;               // is this message empty / cleared?
   std::string text;         // the textual content of this message
   std::string author;       // the author of this message
   std::string date;         // the date this message was created
   Control control;          //the clearance level of the message
};

