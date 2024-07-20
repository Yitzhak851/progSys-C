#ifndef STRACTS_H
#define STRACTS_H


typedef struct {
	int Year;
	int Month;
	int Day;
	int Hour;
	int Min;
} Date;

typedef struct {
	char* Name;
	char* nLicense;
	int nPatients;
} Doc;

typedef struct {
	Date* tArrival;
	Date* tDismissed;
	float Duration;
	Doc* Doctor;
	char* vSummary;
} Visit;

typedef struct Stack {
	Visit* visit;
	struct Stack* next;
}Stack;

typedef struct {
	char* Name;
	char* ID;
	char Allergies;
	Stack* Visits;
	int nVisits;
} Patient;

typedef struct plnTree {
	Patient* tpatient;
	struct plnTree* right;
	struct plnTree* left;
} plnTree;

typedef struct ptree {
	plnTree* myTree;
}pTree;

typedef struct {
	Patient* lpatient;
	struct plnLine* next;
} plnLine;

typedef struct pline {
	plnLine* myLine;
}pLine;

typedef struct ll {
	Doc* doc;
	struct ll* next;
}ll;

#endif 
