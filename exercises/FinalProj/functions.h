#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

#define NONE 0
#define PENICILLIN 1
#define SULFA 2
#define OPIOIDS 4
#define ANESTHETICS 8
#define EGGS 16
#define LATEX 32
#define PRESERVATIVES 64


void displayError(char* error);
char sumAllergies(char* str);
void enterToTree(plnTree** currNode, Patient* tempP);
int extractNum(char* str);
Date* getDate(char* str);
float getDuration(char* str);
Stack* Push(Stack* visits, Visit** tempV);
Visit* pop(Patient* p);
Doc* getDoc(ll* head, char* str);
pTree* loadPatients(ll** head, char* filePath);
void append(ll** curr, Doc** tempD);
plnLine* insertAtEnd(plnLine** curr, Patient** tempP);
Patient* searchPatient(plnTree* curr, char* id);
Doc* createDoc(char* str);
ll* loadDoctors(char* filePath);
pLine* loadLine(pTree* tree, char* filePath);
char* extractAller(char aller);
void writeDuration2File(float num,char* filePath);
void updatePatient(Patient* p, int* num);
int updatePatients(plnTree* curr, int* num);
int updateDoctors(ll* head);
int updateLine(plnLine* line);
void updateFiles(pTree* tree, pLine* line, ll** head);
void assignDoctor2case(ll* ll,Visit* p);
int isFull(ll* head);
void editAllergies(Patient* p);
Patient* registerNewPatient(plnTree* root, char* id);
void admitPatient(plnTree* root, ll* head);
int activeVisit(Stack* visits);
Visit* createNewVisit(ll* head);
char* getTime();

#endif 

