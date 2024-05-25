#include <stdio.h>

/*************************************************
*  newWordParser.c
*  ---------------
*  A program for parsing text in new word format
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Functions implemented in Problem 1
*********************************/
int charToASI(char ch);
int ASItoChar(int ASIval);
int getASIblock(int newWord, int ind);
int isWordFull(int newWord);
int newWordType(int newWord);
int appendWordChar(int newWord, char ch);
void printNewWord(int newWord);


/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/
/*********************************
* Problem 2 - main function for program
*********************************/
int main() {
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    int newWord = 0;
    int numType1 = 0; // Number of words with only letters (and periods)
    int numType2 = 0; // Number of words with only digits (and periods)
    int numType3 = 0; // Number of mixed words (letters and digits)
    int wordType;
    char ch;
        while (scanf("%c", &ch) == 1) {
        if (ch == '$') {
            break;
        }
        int ASIval = charToASI(ch);
        if (ASIval == -1 || isWordFull(newWord)) {
            // Print the current word
            printNewWord(newWord);            
            // Determine the type of the word and update the counters
            wordType = newWordType(newWord);
            if (wordType == 1) {
                numType1++;
            } else if (wordType == 2) {
                numType2++;
            } else if (wordType == 3) {
                numType3++;
            }
            // Reset the newWord for the next word
            newWord = 0;
            // If current character cannot be encoded, skip to next character
            if (ASIval == -1) {
                continue;
            }
        }
        // Append the character to the current word
        newWord = appendWordChar(newWord, ch);
    }
    // print the last word if it exists
    if (newWord != 0) {
        printNewWord(newWord);
        wordType = newWordType(newWord);
        if (wordType == 1) {
            numType1++;
        } else if (wordType == 2) {
            numType2++;
        } else if (wordType == 3) {
            numType3++;
        }
    }
    // print the statistics
    printf("Number of words is %d\n", numType1);
    printf("Number of numbers is %d\n", numType2);
    printf("Number of mixed words is %d\n", numType3);
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
    return 0;
}
/*** end of file ***/