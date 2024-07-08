#include "/share/ex_data/ex6/virtualHeap.h"
#include "/share/ex_data/ex6/gradeList.h"
#include <stdio.h>
#include <string.h>

#define MAX_CHARS_INPUT_LINE 200

int countWords(const char* str);

int main(int argc, char** argv[]){
    // no arguments
    if (argc < 2){
        fprintf(stderr, "Error: no file name provided\n");
        return 1;
    }
    // more than one argument
    if (argc > 2){
        fprintf(stderr, "Error: expecting only one input argument\n");
        return 2;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL){
        fprintf(stderr, "Error: %s cannot be open for reading\n", argv[1]);
        return 3;
    }
    char line[MAX_CHARS_INPUT_LINE];
    int isFaulty = 0;
    int lineNum = 0;
    GradeNode gradeList = NULL;
    // read lines from file
    while (fgets(line, MAX_CHARS_INPUT_LINE, file) != NULL){
        lineNum++;
        // if there more than 3 words in the line
        if (countWords(line) < 3){
            fprintf(stderr, "Line %d has faulty format\n", lineNum);
            isFaulty = 1;
            continue;
        }
        char* firstName = strtok(line, " ");
        char* lastName = strtok(NULL, " ");
        char* gradeStr = strtok(NULL, " ");
        int grade = -1;
        double gradeDouble = -1;
        // convert grade 
        sscanf(gradeStr, "%lf", &gradeDouble);
        grade = (int)gradeDouble;
        // if grade is not a number or out of bounds
        if (grade > 100 || grade < 0 || gradeDouble != grade){ 
            fprintf(stderr, "Line %d has faulty format\n", lineNum);
            isFaulty = 1;
            continue;
        } else {
            GradeNode newGrade = newGradeNode(firstName, lastName, grade);
            if (newGrade == NULL){
                // free memory
                freeGradeList(gradeList);
                fclose(file);
                fprintf(stderr, "Out of memory after reading %d lines\n", lineNum);
                return 11;
            }
            gradeList = appendGradeNode(gradeList, newGrade);
        }
    }
    // if there was a faulty line
    gradeList = mergeSortGradeList(gradeList);
    printGradeList(gradeList);
    // free memory
    freeGradeList(gradeList);
    fclose(file);
    // if there was a faulty line
    if (isFaulty){
        return 4;
    }
    // success
    return 0;
}

// this function counts the number of words in a string
int countWords(const char* str){
    int res = 0;
    int len = strlen(str);
    if(!len) return 0;
    if(str[0] && (str[0] != ' ')) {
        res++;
    }
    for(int i = 0 ; i< len; i++){
        if((str[i] == ' ') && str[i+1] && (str[i+1] != ' ')){
            res++;
        }
    }
    return res;
}