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
int main(int argc, char *argv[]) {
    // Reading the input from stdin
    fgets(input, sizeof(input), stdin);
    // Trimming newline character
    input[strcspn(input, "\n")] = '\0';
    // Check the length of the number list
    if (strlen(input) > MAX_CHARS_IN_LIST + 4) { // 4 extra for the operator and spaces
        printf("Aborting because number list contains more than 100 characters\n");
        return 2;
    }
    // Validate the number list
    if (!isValidNumList(input)) {
        printf("Aborting because word #3 in list is not a valid number\n");
        return 1;
    }
    // Find the operator and compact the number list
    char* operator_pos = performOperation(input, op);
    if (!operator_pos) {
        operator_pos = strchr(input, '*');
    }
    if (!operator_pos) {
        printf("Aborting because no valid operator found\n");
        return 1;
    }
    char operator = *operator_pos;
    *operator_pos = '\0';
    char* num_list = compactNumList(input);
    // Check the length of the compacted number list
    if (strlen(num_list) > MAX_CHARS_IN_LIST) {
        printf("Aborting because number list contains more than 100 characters\n");
        return 2;
    }
    // Perform the operation
    double result = performOperation(num_list, operator);
    printf("%s=%0.f\n", num_list, result);
    return 0;
}

/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
/*** end of file ***/
