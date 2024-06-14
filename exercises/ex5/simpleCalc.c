#include <stdio.h>
#include <string.h>

/*************************************************
*  simpleCalc.c
*  ------------
*  A program for computing simple arithmetic
*  operations on numbers
*************************************************/


/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Functions implemented in Problem 1
*********************************/
int    isValidNumList(const char* str);
int    numWordsInList(const char* str);
double get1stNumberValue(const char* numList);
char*  compactNumList(char* numList);
double getNextNumberValue(const char* numList);
double performOperation(const char* numList, char op);

/*** symbolic constant for the max num of chars
    that are allowed per number list
***/
#define MAX_CHARS_IN_LIST 100
/***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/

int main() {
    char numList[MAX_CHARS_IN_LIST + 1];
    int charCount, wordIndex, numValid;
    while (1) {
        memset(numList, 0, sizeof(numList)); // cool command for initialize numList :)
        charCount = 0;
        wordIndex = 1;
        while (1) {
            char c;
            scanf("%c", &c);
            if (c == '+' || c == '*' || c == '\0') {
                if (charCount == 0) {
                    if (c == '\0') {
                        printf("0\n");
                        return 0;                        
                    }
                }
                numList[charCount] = '\0';
                if (charCount > MAX_CHARS_IN_LIST) {
                    printf("Aborting because word #%d in list is not a valid number\n", charCount);
                    return 2;
                }
                compactNumList(numList);
                numValid = isValidNumList(numList);
                if (!numValid) {
                    double val;
                    for (int i = 0; i < numWordsInList(numList); i++) {
                        val = getNextNumberValue(numList);
                        if (val == -1.0) {
                            printf("Aborting because word #%d in list is not a valid number\n", wordIndex);
                            return 1;
                        }
                        wordIndex++;
                    }
                }
                // isValid
                for (int i = 0; i < numWordsInList(numList); i++) {
                    val = getNextNumberValue(numList);
                    wordIndex++;
                    printf("%s", numList);
                    printf("%c", c);
                }
                double result = performOperation(numList, c);
                printf("%s%c=%.0f\n", numList, c, result);
                if (c == '\0') {
                    return 0;
                }
                // continue with next numList after an operator
            }
            if (charCount < MAX_CHARS_IN_LIST) {
                numList[charCount] = c;
                charCount++;
            } else {
                printf("Aborting because number list contains more than 100 characters\n");
                return 2;
            }
        }
    }
}

/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
/*** end of file ***/

