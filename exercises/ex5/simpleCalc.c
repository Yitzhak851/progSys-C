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
    char numList = compactNumList(input);  // input from scanf
    char tmpNumList = '';                //tempNumList
    char op = '';
    
    // find operator and compact the number list
    char operator_pos = performOperation(input, op);
    if (!operator_pos) {
        operator_pos = strchr(input, '*');
    } else if (!operator_pos) {
        return 1;
    }
    char operator = *operator_pos;
    *operator_pos = '\0';

    if (!isValidNumList(input)) {
        printf("Aborting because word #3 in list is not a valid number\n");
        return 1;
    }

    if (strlen(num_list) > MAX_CHARS_IN_LIST) {
        printf("Aborting because number list contains more than 100 characters\n");
        return 2;
    }

    do {
            scanf("%c", &op);
            tmpNumList = compactNumList(numList);
            if (numList != tmpNumList) {
                    numList = tmpNumList;
            }
            if(op != ('*' || '+')){
                printf("%d", getNextNumberValue(numList));
                printf("%c", op);
            }
            double result = performOperation(numList, op);
            printf("%d", result);
        } while(op != ('*' || '+'));

    return 0;
}
/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
/*** end of file ***/
int main() {
    char numList[MAX_CHARS_IN_LIST];
    char op;

    if (!isValidNumList(input)) {
        printf("Aborting because word #3 in list is not a valid number\n");
        return 1;
    }

    !isValidNumList(input)
    fgets(numList, sizeof(numList), stdin);
    numList[strcspn(numList, "\n")] = '\0'; // Remove newline character from fgets
    scanf(" %c", &op);
    // Compact the number list to remove any redundant spaces
    compactNumList(numList);
    // Check if the number list is valid
    if (!isValidNumList(numList)) {
        printf("Invalid number list.\n");
        return 1;
    }
    // Perform the operation
    double result = performOperation(numList, op);
    printf("Result: %.2f\n", result);
    return 0;
        while(scanf(" %c", &op) != ('+' || '*')){



    }
}
int main(){
    char numList[MAX_CHARS_IN_LIST] = {''};
    char op;
    int numList = 0;

    while(scanf(" %c", &op) != ('+' || '*')){
        
    }

    return 0;
}
int main() {
    char numList[MAX_CHARS_IN_LIST + 1];
    char op;
    int charCount, wordIndex, numValid;
    while (1) {
        memset(numList, 0, sizeof(numList)); // initialize/reset numberList
        charCount = 0;
        wordIndex = 1;
        while (1) {
            char c;
            scanf("%c", &c);
            // If it's an operator or end of input
            if (c == '+' || c == '*' || c == '\0') {
                if (charCount == 0) {
                    // If input isEmpty and it's end of input, exit successfully
                    if (c == '\0') {
                        printf("0\n");
                        return 0;
                    }
                    // If input isEmpty but operator encountered, continue to next iteration
                    continue;
                }
                numList[charCount] = '\0'; // Null-terminate the number list
                // Check if number list exceeds max allowed characters
                if (charCount > MAX_CHARS_IN_LIST) {
                    //printf("Aborting because number list contains more than 100 characters\n");
                    printf("Aborting because word #%d in list is not a valid number\n", charCount);
                    return 2;
                }
                compactNumList(numList);  // Compact numList to remove redundant spaces
                numValid = isValidNumList(numList);  // Check if numList isValid
                if (!numValid) {
                    double val;
                    // Find the invalid word's index
                    for (int i = 0; i < numWordsInList(numList); i++) {
                        val = getNextNumberValue(numList);
                        if (val == -1.0) {
                            printf("Aborting because word #%d in list is not a valid number\n", wordIndex);
                            return 1;
                        }
                        wordIndex++;
                    }
                }
                double result = performOperation(numList, c);  // Perform the operation and print the result
                printf("%s%c=%.0f\n", numList, c, result);
                if (c == '\0') {
                    return 0;
                } else {
                    break; // Continue with the next numList after an operator
                }
            } else {
                // Add character to numList
                if (charCount < MAX_CHARS_IN_LIST) {
                    numList[charCount++] = c;
                } else {
                    // If exceeding max characters before hitting operator, abort
                    printf("Aborting because number list contains more than 100 characters\n");
                    return 2;
                }
            }
        }
    }
}


int main() {
    int i, j, k, numWordsInList, status;
    char numList[MAX_CHARS_IN_LIST], op, prevOp;
    char *numListPtr;
    double result = 0;

    printf("Enter a list of numbers and operators (+ or *): ");

    // Read characters from the input stream one by one using a call to scanf with conversion specifier %c.
    for (i = 0; i < MAX_CHARS_IN_LIST; i++) {
        scanf(" %c", &numList[i]);
        if (numList[i] == '\n' || numList[i] == '\0') {
            break;
        }
    }
    numList[i] = '\0';

    numWordsInList = numWordsInList(numList);

    // Check if the number list is empty
    if (numWordsInList == 0) {
        printf("Correct termination.\n");
        return 0;
    }

    // Compact the number list
    numListPtr = compactNumList(numList);

    // Initialize the previous operator to '+' or '*'
    prevOp = '+';

    // Perform the arithmetic operation
    for (i = 0; i < numWordsInList; i++) {
        op = numList[i];
        if (op == '*') {
            // If the operator is '*', multiply the current result with the previous number
            result = performOperation(result, prevOp, numList[i - 1]);
            prevOp = '*';
        } else {
            // If the operator is '+', add the current number to the previous result
            result = performOperation(result, prevOp, numList[i - 1]);
            prevOp = '+';
        }
    }

    // Print the result
    printf("%s=", numListPtr);
    printf("%f\n", result);

    return 0;
}

int numWordsInList(char *numList) {
    int i;
    for (i = 0; numList[i] != '\0'; i++) {
        if (numList[i] == ' ') {
            return i;
        }
    }
    return i;
}

int numWordsInList(const char* str) {
   int numWords = 0;
   /***      !!!   DO NOT DEFINE ADDITIONAL LOCAL VARIABLES (OTHER THAN numWords)  !!!   ***/
   /***      Apply all changes to the code below this line. DO NOT DELETE THIS COMMENT   ***/
    while (*str != '\0'){
        while (*str != ' ') {
            str++;
        }
        numWords++;
    }
   /***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
   return numWords;
}


double performOperation(double result, char op, char num) {
    if (op == '+') {
        return result + atoi(&num);
    } else {
        return result * atoi(&num);
    }
}

char *compactNumList(char *numList) {
    int i;
    for (i = 0; i < strlen(numList); i++) {
        if (numList[i] == ' ') {
            numList[i] = '\0';
        }
    }
    return numList;
}