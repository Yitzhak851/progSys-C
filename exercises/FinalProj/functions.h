/**
 * @file functions.h
 * @brief This file contains the function prototypes and the necessary includes for the program to work properly.
 * Last modified: <2024/07/26 10:56:52>
 */


// This file contains the function prototypes and the necessary includes for the program to work properly.
// and the necessary includes for the program to work properly: struct Date, Doc, Visit, Stack, Patient, plnTree, pTree, plnLine, pLine, ll
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// defines the _CRT_SECURE_NO_WARNINGS to avoid the warnings of the scanf functions
#define _CRT_SECURE_NO_WARNINGS

// Includes the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

// Function prototypes - defined in functions.c
#define NONE 0
#define PENICILLIN 1
#define SULFA 2
#define OPIOIDS 4
#define ANESTHETICS 8
#define EGGS 16
#define LATEX 32
#define PRESERVATIVES 64
#define MAX_NAME 50
#define MAX_ID 10
#define MAX_LICENSE 10
#define MAX_SUMMARY 100
#define MAX_LINE 100


// TODO: need to complete the function prototypes and make their definitions in functions.c
// Functions for the Date struct
Date *createDate(int Year, int Month, int Day, int Hour, int Min);
void printDate(Date *date);
void freeDate(Date *date);
// ################################ ================== Functions for the Doc struct ================== ################################
Doc *createDoc(char *Name, char *nLicense, int nPatients);
void printDoc(Doc *doc);
void freeDoc(Doc *doc);
ll *loadDoctors(FILE *fDoctors);  // new function
// ################################ ================== Functions for the Visit struct ================== ################################
Visit *createVisit(Date *tArrival, Date *tDismissed, float Duration, Doc *Doctor, char *vSummary);
void printVisit(Visit *visit);
void freeVisit(Visit *visit);
// ################################ ================== Functions for the Stack struct ================== ################################
Stack *createStack(Visit *visit);
void printStack(Stack *stack);
void freeStack(Stack *stack);
// ################################ ================== Functions for the Patient struct ================== ################################
Patient *createPatient(char *Name, char *ID, char Allergies, Stack *Visits, int nVisits);
void printPatient(Patient *patient);
void freePatient(Patient *patient);
ll *loadPatients(Doc *doc, FILE *fPatients);  // new function
// ################################ ================== Functions for the plnTree struct ================== ################################
plnTree *createPlnTree(Patient *tpatient);
void printPlnTree(plnTree *myTree);
void freePlnTree(plnTree *myTree);
// ################################ ================== Functions for the pTree struct ================== ################################
pTree *createPTree(plnTree *myTree);
void printPTree(pTree *myTree);
void freePTree(pTree *myTree);
// ################################ ================== Functions for the plnLine struct ================== ################################
plnLine *createPlnLine(Patient *lpatient);
void printPlnLine(plnLine *myLine);
void freePlnLine(plnLine *myLine);
// ################################ ================== Functions for the pLine struct ================== ################################
pLine *createPLine(plnLine *myLine);
void printPLine(pLine *myLine);
void freePLine(pLine *myLine);
// ################################ ================== Functions for the ll struct ================== ################################
ll *createLL(Doc *doc);
void printLL(ll *myList);
void freeLL(ll *myList);
// Functions for the main program
void printMenu();
void printAllergies(char Allergies);

// TODO: sort thoese function and make them every one in his place:

// undefined reference to `loadLine' - need to be in functions.c -> loadLine at functions for the plnLine struct
// this function get (pLine *myLine) and return void

// undefined reference to `updateFiles' - need to be in functions.c -> updateFiles at functions for the main program
// this function get (ll *myList, pTree *myTree, pLine *myLine) and return void

// undefined reference to `freeAll'
// undefined reference to `admitPatient'
// undefined reference to `checkForAllergies'
// undefined reference to `displayAllPatients'
// undefined reference to `displayPatientAdmissions'
// undefined reference to `displayPatientsInLine'
// undefined reference to `advancePatientInLine'
// undefined reference to `displayDoctors'
// undefined reference to `displayPatientsToDoctor'
// undefined reference to `dischargePatient'
// undefined reference to `removeVisit'
// undefined reference to `removePatient'
// undefined reference to `updateFiles'
// undefined reference to `freeAll'




#endif // FUNCTIONS_H
