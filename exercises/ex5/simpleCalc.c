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

int main(){

void resetNumList(char numList[]) {
    for (int i = 0; i < MAX_CHARS_IN_LIST; i++) {
        numList[i] = ' ';
    }
}

void processInput(char numList[], int* scanLen) {
    char nextChar;
    while (scanf("%c", &nextChar) != EOF) {
        if (nextChar == '*' || nextChar == '+') {
            if (!numWordsInList(numList)) {
                return;
            }
            if (!isValidNumList(numList)) {
                int indexIsNotValid = 1;
                while (getNextNumberValue(numList) != -1.0) {
                    indexIsNotValid++;
                }
                printf("Aborting because word #%d in list is not a valid number\n", indexIsNotValid);
                return;
            }
            char op = nextChar;
            double value = performOperation(numList, op);
            char* numListPrint = compactNumList(numList);
            while (*numListPrint) {
                printf("%c", (*numListPrint == ' ') ? op : *numListPrint);
                numListPrint++;
            }
            printf("=%.0f\n", value);
            resetNumList(numList);
            *scanLen = 0;
        } else {
            if (*scanLen < MAX_CHARS_IN_LIST) {
                numList[*scanLen] = nextChar;
                (*scanLen)++;
            } else {
                printf("Aborting because number list contains more than %d characters\n", MAX_CHARS_IN_LIST);
                return;
            }
        }
    }
}

int main() {
    char numList[MAX_CHARS_IN_LIST] = {' '};
    int scanLen = 0;
    processInput(numList, &scanLen);
    return 0;
}

// helper logic implementation :)
/* {
    char numList[MAX_CHARS_IN_LIST] = {' '};
    char nextChar;
    int scanLen = 0;
    do{
        scanf("%c", &nextChar);
        if(nextChar == '*' || nextChar == '+'){
            if(!numWordsInList(numList)){
                return 0;
            }else if(!isValidNumList(numList)){
                int indexIsNotValid = 1;
                while(getNextNumberValue(numList) != -1.0){
                    indexIsNotValid++;
                }
                printf("Aborting because word #%d in list is not a valid number\n", indexIsNotValid);
                return 1;
            }else{
                    char op = nextChar;
                    double value = performOperation(numList, op);
                    char* numListPrint = compactNumList(numList);
                    while(*numListPrint){
                        if(*numListPrint == ' '){
                            printf("%c", op);
                        } else {
                            printf("%c", *numListPrint);
                        }
                        numListPrint++;
                    }
                    printf("=%.0f\n", value);
                    int i;
                    for(i = 0 ; i < MAX_CHARS_IN_LIST ; i++){
                        numList[i] = ' ';
                    }
                    scanLen = 0;
             }
        }else{
                 if(scanLen < MAX_CHARS_IN_LIST){
                    numList[scanLen] = nextChar;
                    scanLen++;
                }else{
                    printf("Aborting because number list contains more than %d characters\n" , MAX_CHARS_IN_LIST);
                    return 2;
                }
        }
    }while(nextChar);
} */

}


/***      Apply all changes to the code above this line. DO NOT DELETE THIS COMMENT   ***/
/*** end of file ***/

