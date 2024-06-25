/*************************************************
 *  gradeList.c
 *  -----------
 *  A program containing functions for implementing
 *  a new data structure that holds a list of grades
 *************************************************/

#include "/share/ex_data/ex6/gradeList.h"
#include "/share/ex_data/ex6/virtualHeap.h"
#include <stdio.h>
#include <string.h>



// TYPE DEFINITIONS
/*** object type - pointer to node in grade list ***/
typedef struct GradeNode_st *GradeNode;
/*** struct type for node in grade list ***/
struct GradeNode_st
{
    /*** firstName and Last name hold strings that are allocated outside of the struct ***/
    char *firstName;
    char *lastName;
    /*** grade should be an integer in range [0,100] ***/
    char grade;
    GradeNode next;
};

// FUNCTION IMPLEMENTATIO
void freeGradeList(GradeNode gradeList);
GradeNode largerGradeNode(GradeNode gradeNode1, GradeNode gradeNode2);
void printGradeList(GradeNode gradeList);
GradeNode appendGradeNode(GradeNode gradeList, GradeNode gradeNode);
GradeNode mergeSortedGradeLists(GradeNode gradeList1, GradeNode gradeList2);
GradeNode mergeSortGradeList(GradeNode gradeList);

GradeNode newGradeNode(const char *firstName, const char *lastName, int grade)
{
    if (grade < 0 || grade > 10)
    {
        return;
    }
}