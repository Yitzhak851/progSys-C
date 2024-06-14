#ifndef GRADE_LIST_H_
#define GRADE_LIST_H_
/*************************************************
*  gradeList.h
*  -----------
*  A header file for the GradeList data structure
*  that holds a list of grades
*************************************************/

/********************************/
/**      TYPE DEFINITIONS      **/
/********************************/
/*** object type - pointer to node in grade list ***/
typedef struct GradeNode_st* GradeNode;

/*** struct type for node in grade list ***/
struct GradeNode_st {
   /*** firstName and Last name hold strings
        that are allocated outside of the struct
   ***/
   char* firstName;
   char* lastName;
   /*** grade should be an integer in range [0,100] ***/
   char grade;
   GradeNode next;
};

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* function newGradeNode
* params:
* firstName (char*)
* lastName  (char*)
* grade     (int)
* If grade is out of bounds (not in [0,100]),
* then do nothing and return NULL
* Otherwise crate new GradeNode object, which
* includes the strings for first and last names
* allocated outside of the struct.
*********************************/
GradeNode newGradeNode(const char* firstName, const char* lastName, int grade);

/*********************************
* Problem 1.2
* function freeGradeList
* params:
* gradeList (GradeNode)
* frees a given grade node and all nodes in
* the list that is "downstream" from it.
* frees all memory - the structs and the strings
* allocated separately
*********************************/
void freeGradeList(GradeNode gradeList);

/*********************************
* Problem 1.3
* function largerGradeNode
* params:
* gradeNode1 (GradeNode)
* gradeNode2 (GradeNode)
* compares the two grade nodes and
* returns a pointer to the grade
* node that is "larger".
* First compare grades,
* Then compare last names,
* Then compare first names.
* If nodes contain identical
* information, then returns
* pointer to gradeNode1
*********************************/
GradeNode largerGradeNode(GradeNode gradeNode1, GradeNode gradeNode2);

/*********************************
* Problem 1.4
* function printGradeList
* params:
* gradeList (GradeNode)
* prints a grade list by printing each node
* in the following format:
* fistName<TAB>lastName<TAB>grade
* If list is empty then jsut prints:
* Empty grade list
* Otherwise, after prinitng all nodes, a summary line is printed:
* Average of <N> grades is <AVG>
* where N is the number of grades in the list
* and <AVG> is the average of grades printed
* with 1 decimal digit precision
*********************************/
void printGradeList(GradeNode gradeList);

/*********************************
* Problem 1.5
* function appendGradeNode
* params:
* gradeList (GradeNode)
* gradeNode (GradeNode)
* adds gradeNode to the end of gradeList
* If gradeNode is not a single node, then does not
* modify gradeList.
* Returns the modified list.
*********************************/
GradeNode appendGradeNode(GradeNode gradeList, GradeNode gradeNode);

/*********************************
* Problem 1.6
* function mergeSortediGradeLists
* params:
* gradeList1 (GradeNode)
* gradeList2 (GradeNode)
* receives two grade lists sorted from "small"
* to "large" based on largerGradeNode()
* and merges them so that sorting is maintained
* Returns the merged list.
* Assume input lists are sorted.
*********************************/
GradeNode mergeSortedGradeLists(GradeNode gradeList1, GradeNode gradeList2);

/*********************************
* Problem 1.7
* function mergeSortGradeList
* params:
* gradeList (GradeNode)
* sorte a given grade list from "small"
* to "large" based on largerGradeNode()
* using the merge-sort algorithm
*********************************/
GradeNode mergeSortGradeList(GradeNode gradeList);

#endif

