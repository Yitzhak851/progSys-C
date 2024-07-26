#include "functions.h"

#define _CRT_SECURE_NO_WARNINGS
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

// ################################ ================== Functions for the Date struct ================== ################################
// Creates a new Date struct
Date *createDate(int Year, int Month, int Day, int Hour, int Min){
	Date *date = (Date *)malloc(sizeof(Date));
	date->Year = Year;
	date->Month = Month;
	date->Day = Day;
	date->Hour = Hour;
	date->Min = Min;
	return date;
}

// Prints the date in the format "YYYY/MM/DD HH:MM"
void printDate(Date *date){
	printf("%d/%d/%d %d:%d", date->Year, date->Month, date->Day, date->Hour, date->Min);
}

// Frees the memory allocated for the Date struct
void freeDate(Date *date){
	free(date);
	if (date != NULL){
		free(date);
		date = NULL;
	}
}


// ################################ ================== Functions for the Doc struct ================== ################################
// Creates a new Doc struct
Doc *createDoc(char *Name, char *nLicense, int nPatients){
	Doc *doc = (Doc *)malloc(sizeof(Doc));
	// check if the memory allocation was successful
	if (doc == NULL){
		printf("Memory allocation failed\n");
		return NULL;
	}
	strcpy(doc->Name, Name);
	strcpy(doc->nLicense, nLicense);
	doc->nPatients = nPatients;
	return doc;
}
// Prints the Doc struct
void printDoc(Doc *doc){
	printf("Doctor: %s\nLicense: %s\nPatients: %d\n", doc->Name, doc->nLicense, doc->nPatients);
}
// Frees the memory allocated for the Doc struct
void freeDoc(Doc *doc){
	free(doc);
	if (doc != NULL){
		free(doc);
		doc = NULL;
	}
}
// Load the doctors into the linked list from FILE - #### new one ####
ll *loadDoctors(FILE *fDoctors){
	ll *myList = NULL;
	char Name[MAX_NAME];
	char nLicense[MAX_LICENSE];
	int nPatients;
	while (fscanf(fDoctors, "%s %s %d", Name, nLicense, &nPatients) != EOF){
		Doc *doc = createDoc(Name, nLicense, nPatients);
		ll *newList = createLL(doc);
		newList->next = myList;
		myList = newList;
	}
	return myList;
}


// ################################ ================== Functions for the Visit struct ================== ################################
// Creates a new Visit struct
Visit *createVisit(Date *tArrival, Date *tDismissed, float Duration, Doc *Doctor, char *vSummary){
	Visit *visit = (Visit *)malloc(sizeof(Visit));
	// check if the memory allocation was successful
	if (!visit){
		printf("Memory allocation failed\n");
		return NULL;
	}
	visit->tArrival = tArrival;
	visit->tDismissed = tDismissed;
	visit->Duration = Duration;
	visit->Doctor = Doctor;
	strcpy(visit->vSummary, vSummary);
	return visit;
}

// Prints the Visit struct
void printVisit(Visit *visit){
	printf("Arrival: ");
	printDate(visit->tArrival);
	printf("\nDismissed: ");
	printDate(visit->tDismissed);
	printf("\nDuration: %.2f\nDoctor: %s\nSummary: %s\n", visit->Duration, visit->Doctor->Name, visit->vSummary);
}

// Frees the memory allocated for the Visit struct
void freeVisit(Visit *visit){
	freeDate(visit->tArrival);
	freeDate(visit->tDismissed);
	freeDoc(visit->Doctor);
	free(visit);
	if (visit != NULL){
		free(visit);
		visit = NULL;
	}
}


// ################################ ================== Functions for the Stack struct ================== ################################
// Creates a new Stack struct
Stack *createStack(Visit *visit){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	// check if the memory allocation was successful
	if (!stack){
		printf("Memory allocation failed\n");
		return NULL;
	}
	stack->visit = visit;
	stack->next = NULL;
	return stack;
}

// Prints the Stack struct
void printStack(Stack *stack){
	Stack *temp = stack;
	while (temp != NULL){
		printVisit(temp->visit);
		temp = temp->next;
	}
}

// Frees the memory allocated for the Stack struct
void freeStack(Stack *stack){
	Stack *temp = stack;
	while (temp != NULL){
		Stack *next = temp->next;
		freeVisit(temp->visit);
		free(temp);
		temp = next;
	}
}


// ################################ ================== Functions for the Patient struct ================== ################################
// Creates a new Patient struct
Patient *createPatient(char *Name, char *ID, char Allergies, Stack *Visits, int nVisits){
	Patient *patient = (Patient *)malloc(sizeof(Patient));
	// check if the memory allocation was successful
	if (!patient){
		printf("Memory allocation failed\n");
		return NULL;
	}
	strcpy(patient->Name, Name);
	strcpy(patient->ID, ID);
	patient->Allergies = Allergies;
	patient->Visits = Visits;
	patient->nVisits = nVisits;
	return patient;
}
// Prints the Patient struct
void printPatient(Patient *patient){
	printf("Name: %s\nID: %s\nAllergies: ", patient->Name, patient->ID);
	printAllergies(patient->Allergies);
	printf("\nVisits: %d\n", patient->nVisits);
	printStack(patient->Visits);
}
// Frees the memory allocated for the Patient struct
void freePatient(Patient *patient){
	free(patient);
	if (patient != NULL){
		free(patient);
		patient = NULL;
	}
}
// Load the patients into Binary tree from FILE and pointer - #### new one ####
// this function get (Doc *doc, FILE *fPatients) and return pTree
ll *loadPatients(Doc *doc, FILE *fPatients){
	ll *myList = NULL;
	char Name[MAX_NAME];
	char ID[MAX_ID];
	char Allergies;
	int nVisits;
	while (fscanf(fPatients, "%s %s %c %d", Name, ID, &Allergies, &nVisits) != EOF){
		Stack *Visits = NULL;
		for (int i = 0; i < nVisits; i++){
			Date *tArrival = createDate(0, 0, 0, 0, 0);
			Date *tDismissed = createDate(0, 0, 0, 0, 0);
			float Duration;
			char vSummary[MAX_SUMMARY];
			fscanf(fPatients, "%d %d %d %d %d %d %f %s", &tArrival->Year, &tArrival->Month, &tArrival->Day, &tArrival->Hour, &tArrival->Min, &tDismissed->Year, &tDismissed->Month, &tDismissed->Day, &tDismissed->Hour, &tDismissed->Min, &Duration, vSummary);
			Doc *Doctor = doc;
			Visit *visit = createVisit(tArrival, tDismissed, Duration, Doctor, vSummary);
			Stack *newStack = createStack(visit);
			newStack->next = Visits;
			Visits = newStack;
		}
		Patient *patient = createPatient(Name, ID, Allergies, Visits, nVisits);
		ll *newList = createLL(patient);
		newList->next = myList;
		myList = newList;
	}
	return myList;
}


// ################################ ================== Functions for the plnTree struct ================== ################################
// Creates a new plnTree struct
plnTree *createPlnTree(Patient *tpatient){
	plnTree *myTree = (plnTree *)malloc(sizeof(plnTree));
	// check if the memory allocation was successful
	if (!myTree){
		printf("Memory allocation failed\n");
		return NULL;
	}
	myTree->tpatient = tpatient;
	myTree->right = NULL;
	myTree->left = NULL;
	return myTree;
}

// Prints the plnTree struct
void printPlnTree(plnTree *myTree){
	if (myTree != NULL){
		printPlnTree(myTree->left);
		printPatient(myTree->tpatient);
		printPlnTree(myTree->right);
	}
}

// Frees the memory allocated for the plnTree struct
void freePlnTree(plnTree *myTree){
	if (myTree != NULL){
		freePlnTree(myTree->left);
		freePlnTree(myTree->right);
		freePatient(myTree->tpatient);
		free(myTree);
		myTree = NULL;
	}
}


// ################################ ================== Functions for the pTree struct ================== ################################
// Creates a new pTree struct
pTree *createPTree(plnTree *myTree){
	pTree *myPTree = (pTree *)malloc(sizeof(pTree));
	// check if the memory allocation was successful
	if (!myPTree){
		printf("Memory allocation failed\n");
		return NULL;
	}
	myPTree->myTree = myTree;
	// TODO: check if this is necessary
	myPTree->next = NULL; 
	return myPTree;
}

// Prints the pTree struct
void printPTree(pTree *myTree){
	printPlnTree(myTree->myTree);
}

// Frees the memory allocated for the pTree struct
void freePTree(pTree *myTree){
	if (myTree != NULL){
		freePlnTree(myTree->myTree);
		free(myTree);
		myTree = NULL;
	}
	// TODO: check if this is necessary
}


// ################################ ================== Functions for the plnLine struct ================== ################################
plnLine *createPlnLine(Patient *lpatient){
	plnLine *myLine = (plnLine *)malloc(sizeof(plnLine));
	// check if the memory allocation was successful
	if (!myLine){
		printf("Memory allocation failed\n");
		return NULL;
	}
	myLine->lpatient = lpatient;
	myLine->next = NULL;
	return myLine;
}

void printPlnLine(plnLine *myLine){
	plnLine *temp = myLine;
	while (temp != NULL){
		printPatient(temp->lpatient);
		temp = temp->next;
	}
}

void freePlnLine(plnLine *myLine){
	plnLine *temp = myLine;
	while (temp != NULL){
		plnLine *next = temp->next;
		freePatient(temp->lpatient);
		free(temp);
		temp = next;
	}
}

// ################################ ================== Functions for the pLine struct ================== ################################
pLine *createPLine(plnLine *myLine){
	pLine *myPLine = (pLine *)malloc(sizeof(pLine));
	// check if the memory allocation was successful
	if (!myPLine){
		printf("Memory allocation failed\n");
		return NULL;
	}
	myPLine->myLine = myLine;
	// TODO: solve this issue
	// why myPLine->next is NULL? It should be the next pLine struct in the list
	// myPLine->next = NULL;
	//
	myPLine->next = NULL;
	return myPLine;
}

void printPLine(pLine *myLine){
	pLine *temp = myLine;
	while (temp != NULL){
		printPlnLine(temp->myLine);
		temp = temp->next;
	}
}

void freePLine(pLine *myLine){
	pLine *temp = myLine;
	while (temp != NULL){
		pLine *next = temp->next;
		freePlnLine(temp->myLine);
		free(temp);
		temp = next;
	}
}

// ################################ ================== Functions for the ll struct ================== ################################
ll *createLL(Doc *doc){
	ll *myList = (ll *)malloc(sizeof(ll));
	// check if the memory allocation was successful
	if (!myList){
		printf("Memory allocation failed\n");
		return NULL;
	}
	myList->doc = doc;
	myList->next = NULL;
	return myList;
}

void printLL(ll *myList){
	ll *temp = myList;
	while (temp != NULL){
		printDoc(temp->doc);
		temp = temp->next;
	}
}

void freeLL(ll *myList){
	ll *temp = myList;
	while (temp != NULL){
		ll *next = temp->next;
		freeDoc(temp->doc);
		free(temp);
		temp = next;
	}
}


// ################################ ================== Functions for the main program ================== ################################
void printMenu(){
	printf("1. Add a new patient\n");
	printf("2. Add a new visit\n");
	printf("3. Print all patients\n");
	printf("4. Print all visits\n");
	printf("5. Print all doctors\n");
	printf("6. Print all patients in line\n");
	printf("7. Print all patients in the tree\n");
	printf("8. Print all patients in the line of trees\n");
	printf("9. Exit\n");
}

void printAllergies(char Allergies){
	if (Allergies & PENICILLIN){
		printf("Penicillin ");
	}
	if (Allergies & SULFA){
		printf("Sulfa ");
	}
	if (Allergies & OPIOIDS){
		printf("Opioids ");
	}
	if (Allergies & ANESTHETICS){
		printf("Anesthetics ");
	}
	if (Allergies & EGGS){
		printf("Eggs ");
	}
	if (Allergies & LATEX){
		printf("Latex ");
	}
	if (Allergies & PRESERVATIVES){
		printf("Preservatives ");
	}
}