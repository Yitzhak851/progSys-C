#include "/share/ex_data/ex6/gradeList.h"
#include "/share/ex_data/ex6/virtualHeap.h"
#include <stdio.h>
#include <string.h>

/*************************************************
*  gradeList.c
*  -----------
*  A program that implements the GradeList data structure's functions
*  that holds a list of grades
*************************************************/

GradeNode newGradeNode(const char* firstName, const char* lastName, int grade){
    // Check if grade is out of bounds
    if (grade < 0 || grade > 100){
        return NULL;
    }
    // Allocate memory for the new GradeNode
    GradeNode newGradeNode = ourMalloc(sizeof(struct GradeNode_st));
    // Check if allocation failed
    if (newGradeNode == NULL){
        return NULL;
    }
    // Allocate memory for the first name and copy the string
    newGradeNode->firstName = ourMalloc(strlen(firstName) + 1);
    // Check if allocation failed
    if (newGradeNode->firstName == NULL){
        ourFree(newGradeNode);
        return NULL;
    }
    strcpy(newGradeNode->firstName, firstName);
    // Allocate memory for the last name and copy the string
    newGradeNode->lastName = ourMalloc(strlen(lastName) + 1);
    // Check if allocation failed
    if (newGradeNode->lastName == NULL){
        ourFree(newGradeNode->firstName);
        ourFree(newGradeNode);
        return NULL;
    }
    strcpy(newGradeNode->lastName, lastName);
    // Set the grade
    newGradeNode->grade = grade;
    // Set the next pointer to NULL
    newGradeNode->next = NULL;
    return newGradeNode;
};

void freeGradeList(GradeNode gradeList){
    // If the list is empty, return
    if (gradeList == NULL){
        return;
    }
    // Free the first name
    ourFree(gradeList->firstName);
    // Free the last name
    ourFree(gradeList->lastName);
    // Recursively free the rest of the list
    freeGradeList(gradeList->next);
    // Free the current node
    ourFree(gradeList);
};

GradeNode largerGradeNode(GradeNode gradeNode1, GradeNode gradeNode2){
    // If both nodes are NULL, return NULL
    if (gradeNode1 == NULL && gradeNode2 == NULL){
        return NULL;
    }
    // If one of the nodes is NULL, return the other
    if (gradeNode1 == NULL){
        return gradeNode2;
    }
    if (gradeNode2 == NULL){
        return gradeNode1;
    }
    // Compare the grades
    if (gradeNode1->grade > gradeNode2->grade){
        return gradeNode1;
    }
    if (gradeNode1->grade < gradeNode2->grade){
        return gradeNode2;
    }
    // Compare the last names
    int lastNameCompare = strcmp(gradeNode1->lastName, gradeNode2->lastName);
    if (lastNameCompare > 0){
        return gradeNode1;
    }
    if (lastNameCompare < 0){
        return gradeNode2;
    }
    // Compare the first names
    int firstNameCompare = strcmp(gradeNode1->firstName, gradeNode2->firstName);
    if (firstNameCompare > 0){
        return gradeNode1;
    }
    if (firstNameCompare < 0){
        return gradeNode2;
    }
    // If all fields are identical, return gradeNode1
    return gradeNode1;
};

void printGradeList(GradeNode gradeList){
    // If the list is empty, print "Empty grade list"
    if (gradeList == NULL){
        printf("Empty grade list\n");
        return;
    }
    // Print the first node
    printf("%s\t%s\t%d\n", gradeList->firstName, gradeList->lastName, gradeList->grade);
    // Initialize the sum of grades and the number of grades
    int sum = gradeList->grade;
    int count = 1;
    // Iterate over the rest of the list
    GradeNode current = gradeList->next;
    while (current != NULL){
        // Print the current node
        printf("%s\t%s\t%d\n", current->firstName, current->lastName, current->grade);
        // Update the sum and the count
        sum += current->grade;
        count++;
        // Move to the next node
        current = current->next;
    }
    // Calculate the average
    double avg = (double)sum / count;
    // Print the summary line
    printf("Average of %d grades is %.1f\n", count, avg);
};

GradeNode appendGradeNode(GradeNode gradeList, GradeNode gradeNode){
    // If the grade node is not a single node, return the original list
    if (gradeNode == NULL || gradeNode->next != NULL){
        return gradeList;
    }
    // If the list is empty, return the grade node
    if (gradeList == NULL){
        return gradeNode;
    }
    // Initialize the current node
    GradeNode current = gradeList;
    // Iterate over the list
    while (current->next != NULL){
        current = current->next;
    }
    // Append the grade node
    current->next = gradeNode;
    return gradeList;
};

GradeNode mergeSortedGradeLists(GradeNode gradeList1, GradeNode gradeList2){
    if (gradeList1 == NULL){
        return gradeList2;
    }
    if (gradeList2 == NULL){
        return gradeList1;
    }
    GradeNode mergedList = NULL;
    GradeNode largerNode = largerGradeNode(gradeList1, gradeList2);
    mergedList = largerNode;
    if (largerNode == gradeList1){
        mergedList->next = mergeSortedGradeLists(gradeList1->next, gradeList2);
    } else {
        mergedList->next = mergeSortedGradeLists(gradeList1, gradeList2->next);
    }
    return mergedList;
};

GradeNode mergeSortGradeList(GradeNode gradeList){
    // If the list is empty or contains a single node, return the list
    if (gradeList == NULL || gradeList->next == NULL){
        return gradeList;
    }
    // Initialize the two halves of the list
    GradeNode firstHalf = gradeList;
    GradeNode secondHalf = gradeList->next;
    // Split the list into two halves
    while (secondHalf != NULL && secondHalf->next != NULL){
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next->next;
    }
    // Save the second half
    secondHalf = firstHalf->next;
    // Split the list
    firstHalf->next = NULL;
    // Recursively sort the two halves
    firstHalf = mergeSortGradeList(gradeList);
    secondHalf = mergeSortGradeList(secondHalf);
    // Merge the two sorted halves
    return mergeSortedGradeLists(firstHalf, secondHalf);
};

// int main() {
//     // Initialize the virtual heap
//     GradeNode gradeList = newGradeNode("John", "Doe", 90);
//     gradeList = appendGradeNode(gradeList, newGradeNode("Jane", "Smith", 85));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Alice", "Brown", 95));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Bob", "White", 80));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Charlie", "Black", 75));
//     gradeList = appendGradeNode(gradeList, newGradeNode("David", "Green", 100));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Eve", "Gray", 70));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Frank", "Blue", 65));
//     gradeList = appendGradeNode(gradeList, newGradeNode("Grace", "Red", 60));
//     // Print the grade list
//     printGradeList(gradeList);
//     // Sort the grade list
//     gradeList = mergeSortGradeList(gradeList);
//     // Print the sorted grade list
//     printGradeList(gradeList);
//     // Free the grade list
//     freeGradeList(gradeList);
//     // Free all resources allocated by the virtual heap
//     freeAll();
//     // Return 0
//     return 0;
// }
// End of file