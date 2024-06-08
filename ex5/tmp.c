int isValidNumList(const char* str) {
    // going on str
    int i = 0;
    while (str[]) {
        str++;
    }
    // Check for empty string after skipping whitespaces
    if (*str == '\0') {
        return 1;
    }
    // Process the string
    while (*str != '\0') {
        // Check for a valid number
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
        // Skip digits
        while (*str != '\0' && (*str >= '0' && *str <= '9')) {
            str++;
        }
        // Skip trailing whitespace after a number
        while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
            str++;
        }
        // If we reached the end of the string, it's a valid list
        if (*str == '\0') {
            return 1;
        }
        // If the next character is not a digit, return 0
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
    }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   /*** should reach here iff str is a valid number list ***/
   return 1;
}















// class numList.c



#include <stddef.h>

int isValidNumList(const char* str);
int numWordsInList(const char* str);
double get1stNumberValue(const char* numList);
char* compactNumList(char* numList);
double getNextNumberValue(const char* numList);
double performOperation(const char* numList, char op);


int isValidNumList(const char* str) {
       // Skip leading whitespace
    while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
        str++;
    }
    // Check for empty string after skipping whitespaces
    if (*str == '\0') {
        return 1;
    }
    // Process the string
    while (*str != '\0') {
        // Check for a valid number
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
        // Skip digits
        while (*str != '\0' && (*str >= '0' && *str <= '9')) {
            str++;
        }
        // Skip trailing whitespace after a number
        while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
            str++;
        }
        // If we reached the end of the string, it's a valid list
        if (*str == '\0') {
            return 1;
        }
        // If the next character is not a digit, return 0
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
    }
   /*** should reach here iff str is a valid number list ***/
   return 1;
}

int numWordsInList(const char* str) {
   int numWords = 0;
    // Skip leading whitespace
    while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
        str++;
    }
    // Process the string
    while (*str != '\0') {
        // Check if we're at the start of a word
        if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\v' && *str != '\f' && *str != '\r') {
            numWords++;
            // Skip the rest of the word
            while (*str != '\0' && (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\v' && *str != '\f' && *str != '\r')) {
                str++;
            }
        }
        // Skip trailing whitespace before the next word
        while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
            str++;
        }
    }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numWords;
}

double get1stNumberValue(const char* numList) {
   double value = 0.0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN value)     !!!   ***/
    // Skip leading whitespace
    while (*numList != '\0' && (*numList == ' ' || *numList == '\t' || *numList == '\n' || *numList == '\v' || *numList == '\f' || *numList == '\r')) {
        numList++;
    }
    // Check if the string is empty after skipping whitespaces
    if (*numList == '\0') {
        return -2.0;
    }
    // Check if the first character is a digit
    if (*numList < '0' || *numList > '9') {
        return -1.0;
    }
    // Convert the first word to a number
    while (*numList != '\0' && (*numList >= '0' && *numList <= '9')) {
        value = value * 10 + (*numList - '0');
        numList++;
    }
    // Check if there are any non-digit characters in the first word
    if (*numList != '\0' && (*numList != ' ' && *numList != '\t' && *numList != '\n' && *numList != '\v' && *numList != '\f' && *numList != '\r')) {
        return -1.0;
    }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

// Problem 1.4
char* compactNumList(char* numList) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/

   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numList;
}

// The function removes the leading zeros and unnecessary spaces. In general, you scan the input, word by word.
// If (numWordsInList(numList) == 0 )
// We will return an empty string (that is, we will immediately put the pointer character at the end of the string).
// Otherwise, we will follow the following diagram:
// We will define another pointer, to save a modified string that was built
// (we will initialize it to point to the beginning of the original string in memory).
// The editing order will be as follows:
// Skip leading whitespace
// Deleting unnecessary spaces
// Deleting leading zeros
// Copying the words without the leading zeros into the corrected string
// Is this the first word in the string?
// Yes: Advance the original string pointer through the characters of the original string until a non-space character is reached
// No: Add a space character to the corrected string, and move to its next character
// At this point we reach a character that is not a space.
// If the word we need to process has leading zeros, then we will surely come across the character '0'
// Advance the pointer of the original string through the characters of the original string until a character other than '0' is reached
// Is the current character a space character?
// Yes? We read only zeros, so add a '0' character to the corrected string, and move to its next character
// No? We will copy, character by character, the characters of the original string to the corrected string,
// as long as the character is not a space character
// At this point we have finished copying the word into the corrected string.
// Now we need to check if we have finished copying all the words.
// If so, we will insert the character pointing to the end of a string into the corrected string.








// Problem 1.5
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

// Problem 1.6
double performOperation(const char* numList, char op) {
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/

   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

/*** end of file ***/



    char *read = numList, *write = numList;
    int inWord = numWordsInList(numList);
    int isFirstChar = 0;
    // while (inStr && inWord) otherwise - return str
    while (*read != '\0' && inWord != 0 ) {
        // Skip spaces
        while (*read == ' ') {
            read++;
        }
        // Now isFirstChar
        isFirstChar = 1;
        // if inWord && isFirstChar : copyWord, removing leading zeros
        // Skip leading zeros for numbers
        while (*read == '0' && (read[1] >= '0' && read[1] <= '9')) {
            read++;
        }
        // Copy the current word
        while (*read != ' ' && *read != '\0') {
            *write++ = *read++;
        }
        // If isFirstChar, add a single space before the next word
        if (isFirstChar && inWord != 0) {
            *write++ = ' ';
        }
        // ==============
        inWord--;
    }
    // Null-terminate the modified string
    *write = '\0';
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numList;
}


Given the following code:

/*********************************
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
   static const char* prevNumInList = NULL;
   static const char* nextNumInList = NULL;
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/

   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return value;
}

And given the following instructions:

"Function getNextNumberValue receives a string as parameter (const char* numList). 
When called sequentially, the function returns the value (type double) of the next word in numList according to these guidelines: 
•	If this is the first time that getNextNumberValue was invoked during the execution of the program, or if in the last time that getNextNumberValue was invoked it was called with a different numList (a different number list means a list that starts at a different address), then the function returns the value of the first word in numList. 
•	If in the last time that getNextNumberValue was invoked during the execution of the program it was called with the same numList (starting at the exact same address), then the function returns the value of the word following the word whose value was returned in the previous invocation. 
•	If a word is not a sequence of digits, then its value is defined as -1.0. 
•	If reached the end of the list, the function returns -2.0 and "resets" itself such that if the next invocation is done with the same numList, it will return the value of the first word in the list. 
•	See execution example on the next page for clarifications. 
Note that implementing this function requires saving information from one call to the next using static local variables. The current implementation has two static variables defined (prevNumList and nextNumInList), which should be enough for this task. Avoid defining additional static variables, but you may define non-static variables as you wish. Use function "get1stNumberValue" to extract the value of the next word. 
•	Do not use any library other than: #include <stddef.h>

There implementation of "get1stNumberValue": 
double get1stNumberValue(const char* numList) {
   double value = 0.0;
    // Skip leading whitespace
    while (*numList != '\0' && (*numList == ' ' || *numList == '\t' || *numList == '\n' || *numList == '\v' || *numList == '\f' || *numList == '\r')) {
        numList++;
    }
    // Check if the string is empty after skipping whitespaces
    if (*numList == '\0') {
        return -2.0;
    }
    // Check if the first character is a digit
    if (*numList < '0' || *numList > '9') {
        return -1.0;
    }
    // Convert the first word to a number
    while (*numList != '\0' && (*numList >= '0' && *numList <= '9')) {
        value = value * 10 + (*numList - '0');
        numList++;
    }
    // Check if there are any non-digit characters in the first word
    if (*numList != '\0' && (*numList != ' ' && *numList != '\t' && *numList != '\n' && *numList != '\v' && *numList != '\f' && *numList != '\r')) {
        return -1.0;
    }
   return value;
}

Write an implementation for the attached function,
that will pass the following "execution examples" tests and receive the same answers:
Execution examples:
We initialize the two char arrays numList1 and numList2 as follows:
numList1[] = "9.05 3  -4  9876 .";
numList2[] = " 1  0230  45.6  78  ";
Now, we invoke getNextNumberValue sequentially as follows:
getNextNumberValue(numList1) = -1.0.
getNextNumberValue(numList1) = 3.0.
getNextNumberValue(numList2) = 1.0.
getNextNumberValue(numList2) = 230.0.
getNextNumberValue(numList2) = -1.0.
getNextNumberValue(numList2) = 78.0.
getNextNumberValue(numList2) = -2.0.
getNextNumberValue(numList2) = 1.0.
getNextNumberValue(numList2) = 230.0.
getNextNumberValue(numList1) = -1.0.
getNextNumberValue(numList1) = 3.0.
getNextNumberValue(numList1) = -1.0.
getNextNumberValue(numList1) = 9876.0.
getNextNumberValue(numList1) = -1.0.
getNextNumberValue(numList1) = -2.0.
getNextNumberValue(numList1) = -1.0.
getNextNumberValue(numList1) = 3.0.
getNextNumberValue(numList1 + 2) = 5.0.
getNextNumberValue(numList1 + 2) = 3.0.

Do the same for those additional tests:
Initializing numList1 with string "  "
Initializing numList2 with string " 00098765432100  "
getNextNumberValue(numList1) = -2.0.
getNextNumberValue(numList1) = -2.0.
getNextNumberValue(numList1) = -2.0.
getNextNumberValue(numList2) = 98765432100.0.
getNextNumberValue(numList2) = -2.0.
getNextNumberValue(numList2) = 98765432100.0.
getNextNumberValue(numList2) = -2.0.
getNextNumberValue(numList1) = -2.0.