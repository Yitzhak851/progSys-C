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
    int numType1 = 0; // num wordsWithOnlyLetters (and periods)
    int numType2 = 0; // num wordsWithOnlyDigits (and periods)
    int numType3 = 0; // num mixedWords (letters and digits)
    int wordType;
    char ch;

    while (scanf("%c", &ch) == 1) {
        if (ch == '$') {
            break;
        } else if (charToASI(ch) == 1 || isWordFull(newWord) ) {
            printNewWord(newWord);      // print currentWord
            wordType = newWordType(newWord);  // set typeOfWord && updateCounters
            if (wordType == 1) {
                numType1++;
            } else if (wordType == 2) {
                numType2++;
            } else if (wordType == 3) {
                numType3++;
            }
            newWord = 0;  // Reset the newWord for the next word
            // if currentChar cannot be encoded, skipToNextChar
            if (charToASI(ch) == 1) {
                continue;
            }
        }
        newWord = appendWordChar(newWord, ch);
    }// end of while

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

    printf("\n");
    printf("Number of words is %d\n", numType1);
    printf("Number of numbers is %d\n", numType2);
    printf("Number of mixed words is %d\n", numType3);
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
    return 0;
}
/*** end of file ***/