#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"

#define NONE 0
#define PENICILLIN 1
#define SULFA 2
#define OPIOIDS 4
#define ANESTHETICS 8
#define EGGS 16
#define LATEX 32
#define PRESERVATIVES 64

void displayError(char *error)
{
	fprintf(stderr, "%s", error);
}

char sumAllergies(char *str)
{

	str = strtok(str, ",");
	char res = 0;
	char *allergies[] = {"none", "Penicillin", "Sulfa", "Opioids",
						 "Anesthetics", "Eggs", "Latex", "Preservatives"};
	char aller_vals[] = {NONE, PENICILLIN, SULFA, OPIOIDS, ANESTHETICS, EGGS, LATEX, PRESERVATIVES};
	while (str != NULL)
	{
		for (int i = 0; i < 8; i++)
		{
			if (strcmp(str, allergies[i]) == 0)
			{
				res += aller_vals[i];
				break;
			}
		}
		str = strtok(NULL, ",");
	}
	return res;
}

void enterToTree(plnTree **currNode, Patient *tempP)
{
	if (*currNode == NULL)
	{
		(*currNode) = (plnTree *)malloc(sizeof(plnTree));
		if (*currNode == NULL)
		{
			printf("allocation failed\n");
			return;
		}
		(*currNode)->tpatient = tempP;
		(*currNode)->left = NULL;
		(*currNode)->right = NULL;
		return;
	}
	if (strcmp((*currNode)->tpatient->ID, tempP->ID) < 0)
		enterToTree(&((*currNode)->right), tempP);
	else
		enterToTree(&((*currNode)->left), tempP);
}

int extractNum(char *str)
{
	int res = 0;
	int len = 0;
	for (char *temp = str; *temp; temp++)
		len++;

	for (; *str; str++)
	{
		res += *str - 48;
		if (len > 1)
		{
			res *= 10;
			len--;
		}
	}
	return res;
}

Date *getDate(char *str)
{
	Date *tempD = (Date *)malloc(sizeof(Date));
	if (tempD == NULL)
	{
		printf("allocation failed\n");
		return NULL;
	}
	str = strtok(str, "/");
	tempD->Day = extractNum(str);
	str = strtok(NULL, "/");
	tempD->Month = extractNum(str);
	str = strtok(NULL, " ");
	tempD->Year = extractNum(str);
	str = strtok(NULL, ":");
	tempD->Hour = extractNum(str);
	str = strtok(NULL, "\n");
	tempD->Min = extractNum(str);
	return tempD;
}

float getDuration(char *str)
{
	float res = 0;
	str = strtok(str, ":");
	res += extractNum(str) * 100;
	str = strtok(NULL, "\r");
	res += extractNum(str);
	res /= 100;
	return res;
}

Stack *Push(Stack *visits, Visit **tempV)
{
	if (visits == NULL)
	{
		visits = (Stack *)malloc(sizeof(Stack));
		if (visits == NULL)
		{
			printf("allocation failed\n");
			return NULL;
		}
		visits->visit = *tempV;
		visits->next = NULL;
		return visits;
	}
	else
	{
		visits->next = Push(visits->next, tempV);
		return visits;
	}
}

Visit *pop(Patient *p)
{
	if (p->Visits == NULL)
		return NULL;
	Visit *res = p->Visits->visit;
	p->Visits = p->Visits->next;
	return res;
}

Doc *getDoc(ll *head, char *str)
{
	if (head == NULL)
		return NULL;
	if (strcmp(head->doc->Name, str) == 0)
		return head->doc;
	else
		return getDoc(head->next, str);
}

pTree *loadPatients(ll **head, char *filePath)
{
	// TODO: Implement this function
	FILE *file = fopen(filePath, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return NULL;

		plnTree *root = NULL;
		Patient *tempP = NULL;
		Visit *tempV = NULL;
		pTree *tempT = NULL;
		tempT = (pTree *)malloc(sizeof(pTree));
		if (tempT == NULL)
		{
			printf("allocation failed\n");
			return NULL;
		}
		char buffer[256];
		fgets(buffer, sizeof(buffer), file);
		while (fgets(buffer, sizeof(buffer), file))
		{
			if (strstr(buffer, "========================") != NULL)
			{
				if (tempP != NULL)
				{
					enterToTree(&root, tempP);
					tempV = NULL;
				}
			}
			if (strstr(buffer, ";") != NULL)
			{
				tempP = (Patient *)malloc(sizeof(Patient));
				if (tempP == NULL)
				{
					printf("allocation failed\n");
					return NULL;
				}
				char *token = strtok(buffer, ";");
				tempP->Name = strdup(token + 2);
				token = strtok(NULL, ";");
				tempP->ID = strdup(token);
				token = strtok(NULL, "\n");
				tempP->Allergies = sumAllergies(token);
				tempP->Visits = NULL;
				tempP->nVisits = 0;
			}
			if (strstr(buffer, "Arrival") != NULL)
			{
				tempP->nVisits += 1;
				tempV = (Visit *)malloc(sizeof(Visit));
				if (tempV == NULL)
				{
					printf("allocation failed\n");
					return NULL;
				}
				char *token = strtok(buffer, ":");
				token = strtok(NULL, "\n");
				tempV->tArrival = getDate(token);
			}
			if (strstr(buffer, "Dismissed") != NULL)
			{
				char *token = strtok(buffer, ":");
				token = strtok(NULL, "\n");
				if (token != NULL)
					tempV->tDismissed = getDate(token);
				else
					tempV->tDismissed = NULL;
			}
			if (strstr(buffer, "Duration") != NULL)
			{
				char *token = strtok(buffer, ":");
				token = strtok(NULL, "\n");
				if (token != NULL)
					tempV->Duration = getDuration(token);
				else
					tempV->Duration = 0;
			}
			if (strstr(buffer, "Doctor") != NULL)
			{
				char *token = strtok(buffer, ":");
				token = strtok(NULL, "\n");
				tempV->Doctor = getDoc(*head, token);
			}
			if (strstr(buffer, "Summary") != NULL)
			{
				char *token = strtok(buffer, ":");
				token = strtok(NULL, "\n");
				if (token != NULL)
					tempV->vSummary = strdup(token);
				else
					tempV->vSummary = "";
				tempP->Visits = Push(tempP->Visits, &tempV);
			}

			// pTree *loadPatients(ll **head, char *filePath){
			// 	FILE *file = fopen(filePath, "r");
			// 	if (file == NULL) {
			// 		perror("Error opening file");
			// 		return NULL;
			// 	}

			// 	plnTree *root = NULL;
			// 	Patient *tempP = NULL;
			// 	Visit *tempV = NULL;
			// 	pTree *tempT = NULL;
			// 	tempT = (pTree *)malloc(sizeof(pTree));
			// 	if (tempT == NULL) {
			// 		printf("allocation failed\n");
			// 		return NULL;
			// 	}
			// 	char buffer[256];
			// 	fgets(buffer, sizeof(buffer), file);
			// 	while (fgets(buffer, sizeof(buffer), file)) {
			// 		if (strstr(buffer, "========================") != NULL) {
			// 			if (tempP != NULL) {
			// 				enterToTree(&root, tempP);
			// 				tempV = NULL;
			// 			}
			// 		}
			// 		if (strstr(buffer, ";") != NULL)
			// 		{
			// 			tempP = (Patient *)malloc(sizeof(Patient));
			// 			if (tempP == NULL) {
			// 				printf("allocation failed\n");
			// 				return NULL;
			// 			}
			// 			char *token = strtok(buffer, ";");
			// 			tempP->Name = strdup(token + 2);
			// 			token = strtok(NULL, ";");
			// 			tempP->ID = strdup(token);
			// 			token = strtok(NULL, "\n");
			// 			tempP->Allergies = sumAllergies(token);
			// 			tempP->Visits = NULL;
			// 			tempP->nVisits = 0;
			// 		}
			// 		if (strstr(buffer, "Arrival") != NULL)
			// 		{
			// 			tempP->nVisits += 1;
			// 			tempV = (Visit *)malloc(sizeof(Visit));
			// 			if (tempV == NULL) {
			// 				printf("allocation failed\n");
			// 				return NULL;
			// 			}
			// 			char *token = strtok(buffer, ":");
			// 			token = strtok(NULL, "\n");
			// 			tempV->tArrival = getDate(token);
			// 		}
			// 		if (strstr(buffer, "Dismissed") != NULL) {
			// 			char *token = strtok(buffer, ":");
			// 			token = strtok(NULL, "\n");
			// 			if (token != NULL)
			// 				tempV->tDismissed = getDate(token);
			// 			else
			// 				tempV->tDismissed = NULL;
			// 		}
			// 		if (strstr(buffer, "Duration") != NULL) {
			// 			char *token = strtok(buffer, ":");
			// 			token = strtok(NULL, "\n");
			// 			if (token != NULL)
			// 				tempV->Duration = getDuration(token);
			// 			else
			// 				tempV->Duration = 0;
			// 		}
			// 		if (strstr(buffer, "Doctor") != NULL) {
			// 			char *token = strtok(buffer, ":");
			// 			token = strtok(NULL, "\n");
			// 			tempV->Doctor = getDoc(*head, token);
			// 		}
			// 		if (strstr(buffer, "Summary") != NULL) {
			// 			char *token = strtok(buffer, ":");
			// 			token = strtok(NULL, "\n");
			// 			if (token != NULL)
			// 				tempV->vSummary = strdup(token);
			// 			else
			// 				tempV->vSummary = "";
			// 			tempP->Visits = Push(tempP->Visits, &tempV);
			// 		}
			// 	}
			// 	tempT->myTree = root;
			// 	fclose(file);
			// 	return tempT;
			// }

			void append(ll * *curr, Doc * *tempD)
			{
				if (*curr == NULL)
				{
					*curr = (ll *)malloc(sizeof(ll));
					if (*curr == NULL)
					{
						printf("allocation failed\n");
						return;
					}
					(*curr)->doc = *tempD;
					(*curr)->next = NULL;
					return;
				}
				else
					append(&(*curr)->next, tempD);
			}

			// functions.c:373:69: warning: passing argument 1 of ‘insertAtEnd’ from incompatible pointer type [-Wincompatible-pointer-types]
			//   373 |                                         (*curr)->next = insertAtEnd(&((*curr)->next), tempP);
			//       |                                                                     ^~~~~~~~~~~~~~~~
			//       |                                                                     |
			//       |                                                                     struct plnLine **
			// fix it by changing the type of the first argument of insertAtEnd from plnLine ** to plnLine * *:
			// implement the function insertAtEnd
			plnLine *insertAtEnd(plnLine * *curr, Patient * *tempP)
			{
				if (*curr == NULL)
				{
					*curr = (plnLine *)malloc(sizeof(plnLine));
					if (*curr == NULL)
					{
						printf("allocation failed");
						return NULL;
					}
					(*curr)->lpatient = *tempP;
					(*curr)->next = NULL;
					return *curr;
				}
				else
				// functions.c:381:69: warning: passing argument 1 of ‘insertAtEnd’ from incompatible pointer type [-Wincompatible-pointer-types]
				//   381 |                                         (*curr)->next = insertAtEnd(&((*curr)->next), tempP);
				//   |                                                                     ^~~~~~~~~~~~~~~~
				//   |                                                                     |
				//   |                                                                     struct plnLine **
				// fix it by changing the type of the first argument of insertAtEnd from plnLine ** to plnLine * *:
				{
					(*curr)->next = insertAtEnd(&((*curr)->next), tempP);
					// functions.c:381:69: warning: passing argument 1 of ‘insertAtEnd’ from incompatible pointer type [-Wincompatible-pointer-types]
					//   381 |                                         (*curr)->next = insertAtEnd(&((*curr)->next), tempP);
					//       |                                                                     ^~~~~~~~~~~~~~~~
					//       |                                                                     |
					//       |                                                                     struct plnLine **
					// fix it by changing the type of the first argument of insertAtEnd from plnLine ** to plnLine * *:
					
					return *curr;
				}
			}

			Patient *searchPatient(plnTree * curr, char *id)
			{
				if (curr == NULL)
					return NULL;
				char *currID = curr->tpatient->ID;
				if (strcmp(currID, id) == 0)
					return curr->tpatient;
				if (strcmp(currID, id) > 0)
					return searchPatient(curr->left, id);
				else
					return searchPatient(curr->right, id);
			}

			Doc *createDoc(char *str)
			{
				Doc *tempD = (Doc *)malloc(sizeof(Doc));
				if (tempD == NULL)
				{
					printf("allocation failed\n");
					return NULL;
				}
				str = strtok(str, ";");
				tempD->Name = _strdup(str);
				str = strtok(NULL, ";");
				tempD->nLicense = _strdup(str + 1);
				str = strtok(NULL, "\n");
				tempD->nPatients = extractNum(str + 1);
				return tempD;
			}

			ll *loadDoctors(char *filePath)
			{
				FILE *file = fopen(filePath, "r");
				if (file == NULL)
				{
					perror("Error opening file");
					return NULL;
				}

				Doc *tempD;
				ll *head = NULL;

				char buffer[256];
				fgets(buffer, sizeof(buffer), file);
				fgets(buffer, sizeof(buffer), file);
				while (fgets(buffer, sizeof(buffer), file))
				{
					char *token = strtok(buffer, "\n");
					tempD = createDoc(token);
					append(&head, &tempD);
				}
				return head;
			}

			pLine *loadLine(pTree * tree, char *filePath)
			{
				FILE *file = fopen(filePath, "r");
				if (file == NULL)
				{
					perror("Error opening file");
					return NULL;
				}
				pLine *temp = NULL;
				temp = (pLine *)malloc(sizeof(pLine));
				if (temp == NULL)
				{
					printf("allocation failed");
					return NULL;
				}
				plnLine *line = NULL;

				char buffer[256];
				fgets(buffer, sizeof(buffer), file);
				fgets(buffer, sizeof(buffer), file);
				while (fgets(buffer, sizeof(buffer), file))
				{
					char *token = strtok(buffer, "\r\n");
					Patient *tempP = searchPatient(tree->myTree, token + 2);
					if (tempP == NULL)
					{
						printf("No patient with this id:%s is registered", token);
						return NULL;
					}
					else
						line = insertAtEnd(&line, &tempP);
				}
				temp->myLine = line;
				return temp;
			}

			char *extractAller(char aller)
			{
				char *res = (char *)malloc(74);
				if (res == NULL)
				{
					printf("allocation failed\n");
					return NULL;
				}
				strcpy(res, "");

				char *allergies[] = {
					"none", "Penicillin", "Sulfa", "Opioids",
					"Anesthetics", "Eggs", "Latex", "Preservatives"};

				for (int i = 1, j = 1; i < 8; i++, j *= 2)
				{
					if (aller & j)
					{
						if (strcmp(res, "") != 0)
						{
							strcat(res, ",");
						}
						strcat(res, allergies[i]);
					}
				}

				strcat(res, "\r\n");
				return res;
			}

			void writeDuration2File(float num, char *filePath)
			{
				FILE *file = fopen(filePath, "a");
				if (file == NULL)
				{
					perror("Error opening file");
					return;
				}
				int hour = (int)num;
				int min = (int)((num - hour) * 100);
				fprintf(file, "%d:%02d\n", hour, min);
				fflush(file);
				fclose(file);
			}

			void updatePatient(Patient * p, int *num)
			{
				FILE *file = fopen("Patients1.txt", "a");
				if (file == NULL)
				{
					perror("Error opening file");
					return;
				}
				fprintf(file, "========================\n");
				fflush(file);
				fprintf(file, "%d.%s;%s;%s\n", *num, p->Name, p->ID, extractAller(p->Allergies));
				fflush(file);

				(*num)++;

				for (int i = 0; i < p->nVisits; i++)
				{
					fprintf(file, "\n");
					Visit *tempV = pop(p);
					Date *arrival = tempV->tArrival;
					Date *dismiss = tempV->tDismissed;
					Doc *doc = tempV->Doctor;
					fprintf(file, "Arrival:%02d/%02d/%02d ", arrival->Day, arrival->Month, arrival->Year);
					fprintf(file, "%02d:%02d\n", arrival->Hour, arrival->Min);
					fflush(file);

					if (dismiss != NULL)
					{
						fprintf(file, "Dismissed:%02d/%02d%02d ", dismiss->Day, dismiss->Month, dismiss->Year);
						fprintf(file, "%02d:%02d\n", dismiss->Hour, dismiss->Min);
						fflush(file);
					}
					else
						fprintf(file, "Dissmissed:\n");
					fprintf(file, "Duration:");
					fflush(file);
					if (tempV->Duration != 0)
						writeDuration2File(tempV->Duration, "Patients1.txt");
					else
						fprintf(file, "\n");
					fprintf(file, "Doctor:%s\n", doc->Name);
					fprintf(file, "Summary:%s\n", tempV->vSummary);
					fflush(file);
				}
				fclose(file);
			}

			int updatePatients(plnTree * curr, int *num)
			{

				if (curr == NULL)
					return 0;
				updatePatient(curr->tpatient, num);
				updatePatients(curr->left, num);
				updatePatients(curr->right, num);
				return 0;
			}

			int updateDoctors(ll * head)
			{
				FILE *file = fopen("Doctors1.txt", "a");
				if (file == NULL)
				{
					perror("Error opening file");
					return;
				}
				for (ll *curr = head; curr; curr = curr->next)
				{
					fprintf(file, "%s; %s; %d\n", curr->doc->Name, curr->doc->nLicense, curr->doc->nPatients);
					fflush(file);
				}
				return 0;
				fclose(file);
			}

			int updateLine(plnLine * line)
			{
				FILE *file = fopen("Line1.txt", "a");
				if (file == NULL)
				{
					perror("Error opening file");
					return;
				}
				int i = 1;
				for (plnLine *curr = line; curr; curr = curr->next)
				{
					fprintf(file, "%d.%s\n", i++, curr->lpatient->ID);
					fflush(file);
				}
				return 0;
				fclose(file);
			}

			void updateFiles(pTree * tree, pLine * line, ll * *head)
			{
				FILE *file1 = fopen("Patients1.txt", "w");
				if (file1 == NULL)
				{
					perror("Error opening file");
					return;
				}
				fprintf(file1, "Name; ID; Allergies\n");
				fflush(file1);

				FILE *file2 = fopen("Doctors1.txt", "w");
				if (file2 == NULL)
				{
					perror("Error opening file");
					return;
				}
				fprintf(file2, "Full Name; License Number; Number of Patients\n");
				fprintf(file2, "=================================================\n");
				fflush(file2);
				fclose(file2);

				FILE *file3 = fopen("Line1.txt", "w");
				if (file3 == NULL)
				{
					perror("Error opening file");
					return;
				}
				fprintf(file3, "Patients' IDs in line\n");
				fprintf(file3, "=====================\n");
				fflush(file3);
				fclose(file3);

				int *num = {1};

				if (updatePatients(tree->myTree, &num) == 0)
				{
					fprintf(file1, "========================");
					fflush(file1);
					fclose(file1);
					printf("Patient.txt has been updated successfully\n");
				}

				if (updateDoctors(*head) == 0)
					printf("Doctors.txt has been updated successfully\n");

				if (line != NULL)
				{
					if (updateLine(line->myLine) == 0)
						printf("Line.txt has been updated successfully\n");
				}
			}

			char *getTime()
			{
				time_t now = time(NULL);
				if (now == -1)
				{
					perror("Error getting the current time");
					return 1;
				}

				struct tm *local_time = localtime(&now);
				if (local_time == NULL)
				{
					perror("Error converting to local time");
					return 1;
				}

				char time_str[100];
				if (strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M\n", local_time) == 0)
				{
					fprintf(stderr, "Error formatting time\n");
					return 1;
				}
				printf("%s", time_str);

				return time_str;
			}

			void assignDoctor2case(ll * head, Visit * v)
			{
				Doc *leastBusy = head->doc;
				for (ll *temp = head->next; temp; temp = temp->next)
				{
					if (temp->doc->nPatients < leastBusy->nPatients)
						leastBusy = temp->doc;
				}
				leastBusy->nPatients++;
				v->Doctor = leastBusy;
			}

			int isFull(ll * head)
			{
				for (ll *temp = head; temp; temp = temp->next)
					if (temp->doc->nPatients < 4)
						return 1;
				return 0;
			}

			void editName(Patient * p)
			{
				char name[30];
				printf("Please enter patient's name:");
				if (fgets(name, sizeof(name), stdin) != NULL)
				{
					size_t len = strlen(name);
					if (len > 0 && name[len - 1] == '\n')
					{
						name[len - 1] = '\0';
					}

					int valid = 1;
					for (size_t i = 0; i < len; i++)
					{
						if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ' || name[i] == '\0'))
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("The name entered must contain only characters and spaces\n");
						editName(p);
						return;
					}
					p->Name = name;
				}
				else
					editName(p);
			}

			void editAllergies(Patient * p)
			{
				char *allergies[] = {"none", "Penicillin", "Sulfa", "Opioids",
									 "Anesthetics", "Eggs", "Latex", "Preservatives"};

				printf("Out of this list please select all allergies you know of\n");
				printf("in the format like this 1,2,3,...7\n");
				int aller_size = sizeof(allergies) / sizeof(allergies[0]);
				char aller[16];
				for (int i = 0; i < aller_size; i++)
					printf("%d - %s\n", i, allergies[i]);

				if (scanf("%s", aller) != 1)
					editAllergies(p);
				p->Allergies = sumAllergies(aller);
			}

			Patient *registerNewPatient(plnTree * root, char *id)
			{
				Patient *tempP = (Patient *)malloc(sizeof(Patient));
				tempP->ID = id;
				editName(tempP);
				editAllergies(tempP);
				tempP->Visits = NULL;
				tempP->nVisits = 0;
				enterToTree(&root, tempP);
				return tempP;
			}

			int activeVisit(Stack * visits)
			{
				for (Stack *tempS = visits; tempS; tempS = tempS->next)
					if (tempS->visit->tDismissed == NULL)
						return 1;
				return 0;
			}

			Visit *createNewVisit(ll * head)
			{
				Visit *tempV = (Visit *)malloc(sizeof(Visit));
				Date *tempD = getDate(getTime());
				tempV->tArrival = tempD;
				tempV->tDismissed = NULL;
				tempV->Duration = 0;
				assignDoctor2case(head, tempV);
				return tempV;
			}

			void admitPatient(plnTree * root, ll * head)
			{
				if (isFull)
				{
					printf("There is no space for new patients\n");
					return;
				}
				char id[10];
				while (1)
				{
					printf("Please enter ID number: ");
					if (scanf("%9s", &id) != 1)
					{
						printf("Invalid id number\n");
						continue;
					}
					break;
				}
				Patient *tempP = searchPatient(root, id);
				if (tempP == NULL)
					tempP = registerNewPatient(root, id);

				if (activeVisit(tempP->Visits))
				{
					printf("There is currently and active visit\n");
					return;
				}

				Visit *tempV = createNewVisit(head);
				Push(tempP->Visits, &tempV);
			}