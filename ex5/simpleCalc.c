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
// Main function implementation
// Main function implementation
int main() {
    char numList[MAX_CHARS_IN_LIST + 1] = {0};
    char c;
    int pos = 0;

    while (scanf("%c", &c) != EOF) {
        if (c == '+' || c == '*') {
            if (numWordsInList(numList) == 0) {
                return 0; // Correct termination if the list is empty
            }

            char compactList[MAX_CHARS_IN_LIST + 1];
            strcpy(compactList, numList);
            compactNumList(compactList);

            // Check if the list contains any invalid numbers
            double value;
            getNextNumberValue(NULL);
            int wordIndex = 1;
            while ((value = getNextNumberValue(compactList)) != -2) {
                if (value == -1.0) {
                    printf("Aborting because word #%d in list is not a valid number\n", wordIndex);
                    return 1;
                }
                wordIndex++;
            }

            // Perform the operation and print the result
            double result = performOperation(compactList, c);
            printf("%s%c=%g\n", compactList, c, result);

            // Reset the numList for the next set of input
            memset(numList, 0, sizeof(numList));
            pos = 0;
        } else {
            if (pos >= MAX_CHARS_IN_LIST) {
                printf("Aborting because number list contains more than 100 characters\n");
                return 2;
            }
            numList[pos++] = c;
            numList[pos] = '\0';
        }
    }

    return 0;
}

/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
/*** end of file ***/
