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
int  charToASI(char ch);
char ASItoChar(int ASIval);
int  getASIblock(int newWord, int ind);
int  isWordFull(int newWord);
int  newWordType(int newWord);
int  appendWordChar(int newWord, char ch);
void printNewWord(int newWord);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/
/*********************************
* Problem 2 - main function for program
*********************************/
int main() {
        /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
        int newWord = 0;  // newWord
        int numType1 = 0; // num wordsWithOnlyLetters (and periods)
        int numType2 = 0; // num wordsWithOnlyDigits (and periods)
        int numType3 = 0; // num mixedWords (letters and digits)
        int wordType;     // 1 or 2 or 3
        char ch;          // input from scanf
        int tmpWord = 0; //tempWord
        do {
                scanf("%c", &ch);
                tmpWord = appendWordChar(newWord, ch);
                if (newWord != tmpWord) {
                        newWord = tmpWord;
                } else {
                        wordType = newWordType(newWord);
                        if (wordType == 1) {
                                numType1++;
                        } else if (wordType == 2) {
                                numType2++;
                        } else if (wordType == 3) {
                                numType3++;
                        }
                        if(newWord != 0){
                                printNewWord(newWord);
                                newWord = appendWordChar(0, ch);
                        }
                }
                if(ch == '$'){
                        printf("\nNumber of words is %d\n", numType1);
                        printf("Number of numbers is %d\n", numType2);
                        printf("Number of mixed words is %d\n", numType3);
                }
        } while(ch != '$');
        /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
        return 0;
} //end main method
