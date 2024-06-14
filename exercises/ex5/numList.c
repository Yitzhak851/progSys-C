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
    char* read = numList;  // Read pointer
    char* write = numList; // Write pointer
    while (*read != '\0') {
        // Skip leading spaces
        while (*read == ' ') {
            read++;
        }
        if (*read == '\0') {
            break; // If the rest of the string is spaces, we're done
        }
        // Find the start of a word
        char* word_start = read;
        // Find the end of the word
        while (*read != ' ' && *read != '\0') {
            read++;
        }
        char* word_end = read; // End of the word
        // Remove leading zeros from the word
        char* ptr = word_start;
        while (ptr < word_end && *ptr == '0') {
            ptr++;
        }
        if (ptr == word_end) {
            ptr--; // If the word is all zeros, leave a single zero
        }
        // Copy the word to the write position
        while (ptr < word_end) {
            *write++ = *ptr++;
        }
        // Add a space if there are more words
        if (*read != '\0') {
            *write++ = ' ';
        }
    }
    // Remove trailing space if there is one
    if (write > numList && *(write - 1) == ' ') {
        write--;
    }
    // Null-terminate the string
    *write = '\0';
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
   static const char* prevNumList = NULL;
   static const char* nextNumInList = NULL;
   double value = 0.0;
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    if(numList == NULL) {
        return -1;
    }
    if(numList != prevNumList) {
        prevNumList = numList;
        nextNumInList = numList;
    }
    value = get1stNumberValue(nextNumInList);
    if(value == -2){
        nextNumInList = numList;
    } else {
        //nextNumInList = compactNumList(nextNumInList);
        while(*nextNumInList != '\0' && *nextNumInList == ' ' ) {
            ++nextNumInList;
        }
        while(*nextNumInList != '\0' && *nextNumInList != ' ') {
            ++nextNumInList;
        }
    }
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
   double result = 0.0;
   getNextNumberValue(numList+1);
    if((op != '+' && op != '*') || !isValidNumList(numList)){
        return -1;
    }
    getNextNumberValue(NULL);
    if(op == '+') {
        result = 0;
        while(-2 != (value = getNextNumberValue(numList))) {
            result += value;
        }
    } else {
        result = 1;
        while(-2 != (value = getNextNumberValue(numList))){
            result *= value;
        }
    }
    getNextNumberValue(NULL);
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return result;
}


/*** end of file ***/
