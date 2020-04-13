/***********************************************************************
* Program:
*    Lab 08, Vulnerabilities and Exploits
*    Brother Wilson, CS470
* Author:
*    Ali Cope
* Summary: 
*    This program is designed to demonstrate memory injection vulnerabilities.
*
************************************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void stackExploit();
void heapExploit();
void arrayExploit();
void intExploit();
void arcExploit();
void subterfugeExploit();
void vtableExploit();
void ansiExploit();
void stackVulnerability(char text);
void risk();
void safe();

/******************************************************
 * MAIN
 * This function take you to the various exploits
 *****************************************************/
int main()
{
   // prompt
   cout << "  1. Array index\n"
        << "  2. Pointer subterfuge\n"
        << "  3. ARC injection\n"
        << "  4. VTable spraying\n"
        << "  5. Stack smashing\n"
        << "  6. Heap spraying\n"
        << "  7. Integer overflow\n"
        << "  8. ANSI-Unicode conversion\n"
        << "> ";
   int select;
   cin >> select;

   switch (select)
   {
      case 1:
         arrayExploit();
         break;
      case 2:
         subterfugeExploit();
         break;
      case 3:
         arcExploit();
         break;
      case 4:
         vtableExploit();
         break;
      case 5:
         stackVulnerability('A');
         break;
      case 6:
         heapExploit();
         break;
      case 7:
         intExploit();
         break;
      case 8:
         ansiExploit();
         break;
      default:
         cout << "Unknown option " << select << endl;
   }

   return 0;
}

/**************************************************************
 **************************************************************
 *******************    SUBTERFUGE    *************************
 **************************************************************
 **************************************************************/

/****************************************
 * Pointer Subterfuge Vulnerability
 * 1. There must be a pointer used in the code.
 * 2. There must be a way to overwrite the pointer
 * 3. After the pointer is overwritten, the pointer is dereferenced
 ****************************************/
void subterfugeVulnerability(long * array, int size)
{
   long int buffer[2] = {0, 1};
   const char * message = "All is safe; nothing bad happened\n";  // 1. Pointer

   for (int i = 0; i < size; i++)  // 2. Overwrite
      buffer[i] = array[i];

   cout << message;                // 3. Dereference
   
}

/****************************************
 * Pointer Subterfuge Exploitation
 * 1. The attacker must exploit a vulnerability allowing
 *    unintended access to the pointer
 * 2. The attacker must be able to provide a new pointer
 *    referring to data altering the normal flow of the program
 ****************************************/
void subterfugeExploit()
{
   // an attacker's array
   long int array[3] =             // 1. Exploit
   {
      0,
      1,
      (long int)"!!!!!!!!!!!!! You've been hacked !!!!!!!!!!!!!\n"
      // 2. Provide pointer
   };

   // exploit it
   subterfugeVulnerability(array, 3);   
}

/**************************************************************
 **************************************************************
 ********************     ARRAY      **************************
 **************************************************************
 **************************************************************/

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ************************************/
void arrayVulnerability(int index)  
{
   //1. array index is passed into function
   //2. create array
   bool assign[5] = {0,0,0,0,0};
   bool passClass = false;
   //3. program will change assignment from pass to fail
   // with our exploit we will change passClass instead
   assign[index] = true;
   //output the student grades on each assignment
   cout << "Student assignments: \n";
   for (int i = 0; i < 4; i++)
   {
      if(assign[i])
      {
         cout << "Assignment number " << i+1 << " pass" << endl;
      } 
      else
      {
         cout << "Assignment number " << i+1 << " fail" << endl; 
      }
      
   }
   // output if the student will pass or fail the class
   if (passClass)
   {
      cout << "Student will pass the class \n";
   }
   else
   {
      cout << "Student will fail the class \n";
   }
   
}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
   int num;
   cout << "Enter assignment number (0-4) to mark assignment as pass " << endl;
   //1. attacker targets item outside of array
   //2., 3. attacker will utilize the built-in functionality
   // to change pass/fail class instead of changing pass/fail 
   // assignment the way the program is designed to.
   num = 5;
   arrayVulnerability(num);

}

/**************************************************************
 **************************************************************
 ********************      ARC       **************************
 **************************************************************
 **************************************************************/

/*********************************
 * ARC VULNERABILITY
 * 1. There must be a function pointer used in the code.
 * 2. Through some vulnerability, there must be a way for user input
 *    to overwrite the function pointer. This typically happens through
 *    a stack buffer vulnerability.
 * 3. After the memory is overwritten, the function pointer must
 *    be dereferenced
 ********************************/
void arcVulnerability(long userInput[])
{
// 2. create buffer vulnerability 
// user can store their secret number
long buffer[1]; 
// 1. pointer function lets user know their secret number is safe
void (* pointerFunction)() = safe; 
cout << "buffer 1 before input" << buffer[1];
//copy user input into buffer
//buffer[0] = userInput;
for(int i = 0; i < 50; i++)
   {
      cout << "i:" << i << endl;
      buffer[i] = userInput[i];
   }

cout << "buffer 1 after input" << buffer[1];
//buffer = userInput; // input references pointerFunction 
// 3. display the function
pointerFunction(); 
}

void safe()
{
   cout << "\n This function is safe and so is your data \n";
}

void risk()
{
   cout << "\n This function is NOT safe and your data is at risk! \n";
}
/*********************************
 * ARC EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing
 *    unintended access to the function pointer
 * 2. The attacker must have the address to another function
 *    which is to be used to replace the existing function pointer
  ********************************/
void arcExploit()
{
   cout << "\nEnter your secret number and I'll keep it safe. \n";
   // instead of getting user input we will just provide it.
   //instead of entering a secret number we are going to enter the 
   // address of the risk function 
   long userInput [50];
   string test = "11111111111111111111111111111111" + to_string(long(risk));
   cout << test << endl;
   for(int i = 0; test.length(); i++)
      userInput[i] = test[i];
   cout << userInput << endl;
   arcVulnerability(userInput);

}

/**************************************************************
 **************************************************************
 ********************     VTABLE     **************************
 **************************************************************
 **************************************************************/

/***********************************
 * VULNERABILITY
 * 1. The vulnerable class must be polymorphic.
 * 2. The class must have a buffer as a member variable.
 * 3. Through some vulnerability, there must be a way for user input
 *    to overwrite parts of the VTable.
 * 4. After a virtual function pointer is overwritten,
 *    the virtual function must be called.
 **********************************/
class Vulnerability
{
   public: 
      virtual void dangerous() = 0;
      virtual void safe() = 0; // polymorphic function 
      long buffer[2]; // an array in the class that has a buffer overrun vulnerability

};

class Derived: public Vulnerability
{
   public:
      virtual void dangerous()
      {
         cout << "dangerous functions! " << endl;
      }
      virtual void safe()
      {
         cout << "safe functions! " << endl;
      }
};

/************************************
 * VTABLE EXPLOIT
 * 1. Through some vulnerability, the VTable pointer
 *     or a function pointer within the VTable must be overwritten
 * 2. The attacker must have the address to another VTable pointer
 *     or a function pointer
 ***********************************/
void vtableExploit()
{
   //create a new vulnerable object type called bad
   Derived bad;
   //overwrite the virtual function in 2 with virtual function in 3
   bad.buffer[2] = bad.buffer[3];
   bad.safe();
   bad.dangerous();
}


/**************************************************************
 **************************************************************
 ********************    STACK       **************************
 **************************************************************
 **************************************************************/
//functions borrowed from lab7. Lets see if we can do better with it here
/**********************************************************************
 * The failure case. Don't touch this function
 *********************************************************************/
void fail(char grade)
{
   cout << "\tI am sorry, but you got a 'F'\n";
}

/**********************************************************************
 * I think you would really rather call this function.  This
 * is read-only also
 *********************************************************************/
void pass(char grade)
{
   cout << "\tGood job, you got a(n) '" << grade << "'\n";
}

/***********************************************
 * STACK VULNERABILITY
 * 1. There must be a buffer on the stack
 * 2. the buffer must be reachable from an external input
 * 3. The mechanism to fill the buffer must not check the correct buffersize
 **********************************************/
void stackVulnerability(char inputGrade)
{
   char  text[16]; // second

   char  letterGrade;
   void (*pointerFunction)(char);

   // get the values
   *text = inputGrade;


   // Call the function and display the results.
   pointerFunction = fail;
   letterGrade = 'B';
   stackExploit();            // vulnerability is here 
   (*pointerFunction)(letterGrade);
   
}

/*********************************************
 * STACK EXPLOIT
 * 1. The attacker must provide more data into the
 *    outwardly facing buffer than the buffer is designed to hold
 * 2. The attacker must know where the the stack pointer resides
 *    on the stack. This should be just beyond the end of the buffer
 * 3. The attacker must insert machine language instructions in the buffer.
 *    This may occur before, after, or even around the stack pointer. The
 *    machine language could be already compiled code in the program
 * 4. The attacker must overwrite the stack pointer. The old value,
 *    directing the flow of the program after the function is returned,
 *    must be changed from the calling function to the provided
 *    machine language in step 3.
 *********************************************/
void stackExploit()
{
   //find fail on the stack and use it to change everything to pass
  long *p;
  for(p = (long*) &p; *p != (long)fail; p++)
   ;
   //change fail function address to pass function address
   *p = long(pass);
   //replace letter B with A
   p--;
   char *pC = (char *)p;
   pC[7] = 'A';
   return;
}

/**************************************************************
 **************************************************************
 ********************      HEAP      **************************
 **************************************************************
 **************************************************************/


/*************************************
 * HEAP VULNERABILITY
 * 1. There must be two adjacent heap buffers.
 * 2. The first buffer must be reachable through external input.
 * 3. The mechanism to fill the buffer from the external input must
 *    not correctly check for the buffer size.
 * 4. The second buffer must be released before the first.
 *************************************/
void heapVulnerability(const char * code)
{
   char * buffer1 = new char[5]; //1. There must be two adjacent heap buffers.
   char * buffer2 = new char[5]; 
   strcpy(buffer2, "safe");
   // 2. The first buffer must be reachable through external input (passed as code parameter)
   // 3. The mechanism to fill the buffer from the external input must not correctly check for the buffer size.
   //strcpy(buffer1, code); //should copy size of buffer but instead checks size of code
   for(int i = 0 ; code[i] != '\0'; i++)
   {
      buffer1[i] = code[i];
   }
   delete [] buffer2; // need to delete second buffer first 
   delete [] buffer1;
}

/*************************************
 * HEAP EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing
 *    heap buffer than the buffer is designed to hold
 * 2. The attacker must know the layout of the Memory Control Block (MCB)
 *    (essentially a linked list) residing just after the buffer
 * 3. The attacker must provide a new MCB containing both the location
 *    of the memory overwrite and the new data to be overwritten
 ***********************************/
void heapExploit()
{
   cout << "Please enter 5 digit class code: " << endl;
   //char * code = new char[40];
   string code = "!!!!!!!!!! HACK HACK HACK HACK HACK HACK !!!!!!!!!!";
   heapVulnerability(code.c_str());
}


/**************************************************************
 **************************************************************
 *******************    INTEGER      **************************
 **************************************************************
 **************************************************************/

/********************************************
 * INTEGER VULNERABILITY
 * 1. There must be a security check represented by an expression.
 * 2. The expression must have the potential for overflow.
 * 3. At least one of the numbers used to compute the sentinel
 *    must be reachable through external input.
 *    <based on book page 152>
 *********************************************/
void intVulnerability(int userOffset, int userIn)
{
   int buffer[24];
   int * security = buffer + 24;
   
   int offset = userOffset;

   if(offset + buffer < security)
      buffer[offset] = userIn;
}

/**********************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value,
 *    that is directly or indirectly used in the vulnerable expression
 * 2. The input must exceed the valid bounds of the data-type,
 *    resulting in an overflow or underflow condition
 **********************************************/
void intExploit()
{
   int userOffset = 9999*9999;
   int userIn = 131313;
   intVulnerability(userOffset, userIn);
}


/**************************************************************
 **************************************************************
 ******************    ANSI-Unicode    ************************
 **************************************************************
 **************************************************************/

/*********************************************************
 * ANSI - UNICODE VULNERABILITY
 * 1. There must be a buffer where the basetype is greater than one.
 * 2. Validation of the buffer must check the size of the buffer
 *    rather than the number of elements in the buffer.
 ********************************************************/
void ansiVulnerability(wchar_t uInput[])
{
   //1. There must be a buffer where the basetype is greater than one.
   wchar_t unicodeText2[40]; 
   //2. Validation of the buffer must check the size of the buffer rather than the number of elements in the buffer.
   wcsncpy(uInput /* source buffer */, unicodeText2 /* destination buffer */, sizeof(unicodeText2) /* checks for size not number of elements */);
}

/***********************************************
 * ASCI - UNICODE EXPLOIT
 * 1. The attacker must provide more than half as much data
 *    into the outwardly facing buffer as it is designed to hold
 **********************************************/
void ansiExploit()
{
   //1. The attacker must provide more than half as much data into the outwardly facing buffer as it is designed to hold
   wchar_t uInput[] = L"This is a unicode string It will be too BIG! The buffer will overflow!!!!!!";
   ansiVulnerability(uInput);
}
