// class numList.c
/*** stddef for NULL ***/
#include <stddef.h>

/*************************************************
*  numList.c
*  ---------
*  A program containing functions for implementing
*  a new data type that holds a list of numbers
*  using a single string.
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/


/********************************/
/**    SYMBOLIC CONSTANTS      **/
/********************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* function isValidNumList
* params:
* str (char*)
* Return 1 if a string is a valid number list
* and return 0 otherwise
*********************************/
int isValidNumList(const char* str);

/*********************************
* Problem 1.2
* function numWordsInList
* params:
* str (char*)
* Return the number of words in list
*********************************/
int numWordsInList(const char* str);

/*********************************
* Problem 1.3
* function get1stNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the first number in list (skipping spaces).
* If 1st word is not a valid number, return -1.0
* If list is empty, return -2.0
*********************************/
double get1stNumberValue(const char* numList);

/*********************************
* Problem 1.4
* function compactNumList
* params:
* numList (char*)
* Compacts the number list by removing
* consecutive spaces and leading 0s
* Returns a pointer to the num list
*********************************/
char* compactNumList(char* numList);

/*********************************
* Problem 1.5
* function getNextNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the next number in list.
* If next word is invalid number, return -1.0
* If reached end of list, return -2.0 and make
* sure that next call will return first number.
* Uses static variables to keep information
* from prev execution
*********************************/
double getNextNumberValue(const char* numList);

/*********************************
* Problem 1.6
* function performOperation
* params:
* numList (char*)
* op      (char)
* If op is '+' return the sum of all numbers in the list (0 if empty)
* If op is '*' return the product of all numbers in the list (1 if empty)
* If op is not '+' or '*' or one the list is not a valid number list, return -1
*********************************/
double performOperation(const char* numList, char op);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 1.1
* function isValidNumList
* params:
* str (char*)
* Return 1 if a string is a valid number list
* and return 0 otherwise
*********************************/
int isValidNumList(const char* str) {
   /***      !!!            DO NOT DEFINE ADDITIONAL LOCAL VARIABLES               !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   /*** should reach here iff str is a valid number list ***/
   return 1;
}

/*********************************
* Problem 1.2
* function numWordsInList
* params:
* str (char*)
* Return the number of words in list
*********************************/
int numWordsInList(const char* str) {
   int numWords = 0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN numWords)  !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numWords;
}

/*********************************
* Problem 1.3
* function get1stNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the first number in list (skipping spaces).
* If 1st word is not a valid number, return -1.0
* If list is empty, return -2.0
*********************************/
double get1stNumberValue(const char* numList) {
   double value = 0.0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN value)     !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*********************************
* Problem 1.4
* function compactNumList
* params:
* numList (char*)
* Compacts the number list by removing
* consecutive spaces and leading 0s
* Returns a pointer to the num list
*********************************/
char* compactNumList(char* numList) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    char* src = numList;
    char* dest = numList;
    int inWord = 0;
    while (*src != '\0') {
        // Skip leading spaces
        while (*src == ' ') {
            src++;
        }
        // Start processing a word
        while (*src != ' ' && *src != '\0') {
            // Skip leading zeros in the word
            if (inWord == 0 && *src == '0') {
                src++;
                continue;
            }
            inWord = 1;
            *dest++ = *src++;
        }
        // End of a word
        if (inWord) {
            inWord = 0;
            // Add a single space if the next character is not the end of the string
            if (*src != '\0') {
                *dest++ = ' ';
            }
        }
    }
    // Remove trailing space if any
    if (dest != numList && *(dest - 1) == ' ') {
        dest--;
    }
    // Null-terminate the resulting string
    *dest = '\0';
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numList;
}

/*********************************
* Problem 1.5
* function getNextNumberValue
* params:
* numList (char*)
* Return the value (in type double) of
* the next number in list.
* If next word is invalid number, return -1.0
* If reached end of list, return -2.0 and make
* sure that next call will return first number.
* Uses static variables to keep information
* from prev execution
*********************************/
double getNextNumberValue(const char* numList) {
   /*** static local variables keeping track of
        inforamtion from the last call to this function:
        prevNumList    - last numList argument passed to function
        nextNumInList  - pointer to first char in next number in list
   ***/
   static const char* prevNumList   = NULL;
   static const char* nextNumInList = NULL;
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*********************************
* Problem 1.6
* function performOperation
* params:
* numList (char*)
* op      (char)
* If op is '+' return the sum of all numbers in the list (0 if empty)
* If op is '*' return the product of all numbers in the list (1 if empty)
* If op is not '+' or '*' or one the list is not a valid number list, return -1
*********************************/
double performOperation(const char* numList, char op) {
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*** end of file ***/

