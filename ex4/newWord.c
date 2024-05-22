#include <stdio.h>
/*************************************************
*  newWord.c
*  ---------
*  A program containing functions for implementing
*  a new data type for words.
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/

/********************************/
/**    SYMBOLIC CONSTANTS      **/
/********************************/
#define BITS_PER_ASI_BLOCK 6

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/
/*********************************
* Problem 1.1
* function charToASI
* params:
* ch (char)
* Return the ASI value corresponding to a given char.
*********************************/
int charToASI(char ch);

/*********************************
* Problem 1.2
* function ASItoChar
* params:
* ASIval (int)
* Return the char associated with a given ASI value.
*********************************/
int ASItoChar(int ASIval);

/*********************************
* Problem 1.3
* function getASIblock
* params:
* newWord (int)
* ind     (int)
* Return the ASI value of the charInd'th char
* in the word encoded by newWord.
*********************************/
int getASIblock(int newWord, int ind);

/*********************************
* Problem 1.4
* function isWordFull
* params:
* newWord (int)
* Return 1 if last ASI block of newWord is used
* and 0 otherwise
*********************************/
int isWordFull(int newWord);

/*********************************
* Problem 1.5
* function newWordType
* params:
* newWord (int)
* Returns a value associated with the word type
*********************************/
int newWordType(int newWord);

/*********************************
* Problem 1.6
* function appendWordChar
* params:
* newWord (int)
* ch      (char)
* Return the new word obtained by adding the ASI
* value of char ch to the end of newWord.
*********************************/
int appendWordChar(int newWord, char ch);

/*********************************
* Problem 1.7
* function printNewWord
* params:
* newWord (int)
* Prints new word to the screen.
*********************************/
void printNewWord(int newWord);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/
/*********************************
* Problem 1.1
* function charToASI
* params:
* ch (char)
* Return the ASI value corresponding to a given char.
* If char is not a letter, digit, '.' or '\0'
* the function returns -1
*********************************/
int charToASI(char ch) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    if (ch == '.') {
        return 1;
    }
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 2;
    }
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 28;
    }
    if (ch >= '0' && ch <= '9') {
        return ch - '0' + 54;
    }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   /*** the function reaches this point if char is invalid ***/
    return -1;
}

/*********************************
* Problem 1.2
* function ASItoChar
* params:
* ASIval (int)
* Return the char associated with a given ASI value.
* If ASI value is out of bound return '!'
*********************************/
char ASItoChar(int ASIval) {
    int a, b;
    /*** replace 121 below with appropriate expression ***/
    if (ASIval < 1 || ASIval > 63) return '!'; // If ASIval is out of bounds, return '!'
    /*** replace 122 below with appropriate expression ***/
    a = (ASIval == 1) ? 0 : (ASIval >= 2 && ASIval <= 27) ? 1 : (ASIval >= 28 && ASIval <= 53) ? 2 : 3;
    /*** replace 123 below with appropriate expression ***/
    b = (a == 0) ? 0 : (a == 1) ? ASIval - 2 : (a == 2) ? ASIval - 28 : ASIval - 54;
    switch (a) {
        case (0): // case 1 (".")
            return '.';
        case (1): // ASI:[2-27] (A-Z) ASCII:[65-90]
            /*** replace a+124 below with appropriate expression ***/
            return b + 'A';  
        case (2): // ASI:[28-53] (a-z) ASCII:[97-122]
            /*** replace b+125 below with appropriate expression ***/
            return b + 'a'; 
        case (3): // ASI:[54-63] (0-9) ASCII:[48-57]
            /*** replace 126 below with appropriate expression ***/
            return b + '0';
        default:
        /*** do nothing here, This code should not be reached ***/
            break;
    } // end of switch
    /*** this code should not be reached ***/
    return '!';
}

/*********************************
* Problem 1.3
* function getASIblock
* params:
* newWord (int)
* ind     (int)
* Return the ASI value of the charInd'th char
* in the word encoded by newWord.
* Indices are 0-based, and if charInd exceeds
* the maximum number of chars in a word,
* the function returns 0
*********************************/
int getASIblock(int newWord, int ind) {
    /*** replace 131 below with appropriate expression (bitwise and arithmetic operators) ***/
    return 131;
}
/*********************************
* Problem 1.4
* function isWordFull
* params:
* newWord (int)
* Return 1 if last ASI block of newWord is used
* and 0 otherwise
*********************************/
int isWordFull(int newWord) {
    /*** replace 141 below with appropriate expression ***/
    return 141;
}

/*********************************
* Problem 1.5
* function newWordType
* params:
* newWord (int)
* Returns a value associated with the word type:
* - 0 for word with only '.'
* - 1 for word made up of letters (and .)
* - 2 for word made up of digits (and .)
* - 3 for word made up of letters and digits
*********************************/
int newWordType(int newWord) {
   int ASIval=0, ind=0, type=ASIval;
   /*** loop until reaching ASI value 0 ***/
   for(ind=0; ind*BITS_PER_ASI_BLOCK<8*sizeof(int); ind++) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   } // end of for
   return type;
}

/*********************************
* Problem 1.6
* function appendWordChar
* params:
* newWord (int)
* ch      (char)
* Return the new word obtained by adding the ASI
* value of char ch to the end of newWord.
* If newWord is full, then return original newWord.
* In the final partial block, only a '.'
* can be appended
*********************************/
int appendWordChar(int newWord, char ch) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   return 161;
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
}

/*********************************
* Problem 1.7
* function printNewWord
* params:
* newWord (int)
* Prints new word to the screen.
* If last character is '.', prints a newline after it
*********************************/
void printNewWord(int newWord) {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return;
}

/*** end of file ***/

