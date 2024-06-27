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
// GradeNode largerGradeNode(GradeNode gradeNode1, GradeNode gradeNode2);
// void printGradeList(GradeNode gradeList);
// GradeNode appendGradeNode(GradeNode gradeList, GradeNode gradeNode);
// GradeNode mergeSortedGradeLists(GradeNode gradeList1, GradeNode gradeList2);
// GradeNode mergeSortGradeList(GradeNode gradeList);

GradeNode newGradeNode(const char *firstName, const char *lastName, int grade)
{
    // Check if the grade is within the valid range
    if (grade < 0 || grade > 100)
    {
        return NULL;
    }

    // Allocate memory for the grade node structure
    GradeNode *node = (GradeNode *)ourMalloc(sizeof(GradeNode));
    if (!node)
    {
        return NULL;
    }

    // Allocate memory for the first name
    node->firstName = (char *)ourMalloc(strlen(firstName) + 1);
    if (!node->firstName)
    {
        ourFree(node);
        return NULL;
    }

    // Allocate memory for the last name
    node->lastName = (char *)ourMalloc(strlen(lastName) + 1);
    if (!node->lastName)
    {
        ourFree(node->firstName);
        ourFree(node);
        return NULL;
    }

    // Copy the first name and last name to the allocated memory
    strcpy(node->firstName, firstName);
    strcpy(node->lastName, lastName);

    // Set the grade value
    node->grade = grade;

    // Return the newly created grade node
    return node;
}
void freeGradeList(GradeNode gradeList)
{
    if (gradeList == NULL)
    {
        return;
    }

    // Free the rest of the list first (recursive step)
    freeGradeList(gradeList->next);

    // Free the allocated memory for first name and last name
    ourFree(gradeList->firstName);
    ourFree(gradeList->lastName);

    // Free the node itself
    ourFree(gradeList);
}