#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
	int Year;  ///< Year (e.g., 2024)
	int Month; ///< Month (1-12)
	int Day;   ///< Day (1-31)
	int Hour;  ///< Hour (0-23)
	int Min;   ///< Minute (0-59)
} Date;

typedef struct {
	char *Name;		///< Name of the doctor
	char *nLicense; ///< License number of the doctor
	int nPatients;	///< Number of patients assigned to the doctor
} Doc;

typedef struct {
	Date *tArrival;	  ///< Arrival date and time
	Date *tDismissed; ///< Dismissal date and time
	float Duration;	  ///< Duration of the visit in hours
	Doc *Doctor;	  ///< Doctor assigned to the visit
	char *vSummary;	  ///< Summary of the visit
} Visit;

typedef struct Stack {
	Visit *visit;		///< Pointer to a visit
	struct Stack *next; ///< Pointer to the next stack node
} Stack;

typedef struct {
	char *Name;		///< Name of the patient
	char *ID;		///< ID of the patient
	char Allergies; ///< Allergies of the patient
	Stack *Visits;	///< Stack of visits
	int nVisits;	///< Number of visits
} Patient;

typedef struct plnTree {
	Patient *tpatient;	   ///< Pointer to a patient
	struct plnTree *right; ///< Pointer to the right child node
	struct plnTree *left;  ///< Pointer to the left child node
} plnTree;

typedef struct ptree {
	// TODO: add members
	plnTree *myTree; ///< Pointer to the root of the tree
	// pointer to next tree
	struct ptree *next;
	// pointer to previous tree
	struct ptree *prev;
	
} pTree;

typedef struct {
	Patient *lpatient;	  ///< Pointer to a patient
	struct plnLine *next; ///< Pointer to the next node in line
	// char *Name; ///< Name of the doctor
	// struct plnLine *prev; ///< Pointer to the previous node in line
	// struct plnLine *first; ///< Pointer to the first node in line
	// struct plnLine *last; ///< Pointer to the last node in line
	// int nPatients; ///< Number of patients in line
	// int nVisits; ///< Number of visits in line
	// int nDoctors; ///< Number of doctors in line
	
} plnLine;

typedef struct pline {
	plnLine *myLine; ///< Pointer to the first node in the line
	// pointer to next line
	struct pline *next;
	// pointer to previous line
	struct pline *prev;
} pLine;

typedef struct ll {
	Doc *doc;		 ///< Pointer to a doctor
	struct ll *next; ///< Pointer to the next node in the list
} ll;

#endif