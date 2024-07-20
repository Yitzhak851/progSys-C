#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

int menu()
{
    char *options[] = {
        "1 - Admit patient",
        "2 - Check for patient's allergies",
        "3 - Display all patients",
        "4 - Display all patient's admissions",
        "5 - Display all patients in line",
        "6 - Advance patient in line",
        "7 - Display list of doctors",
        "8 - Display all patients assigned to a doctor",
        "9 - Discharge patient",
        "10 - Remove visit",
        "11 - Remove patient",
        "12 - Close the hospital",
        "0 - Exit Program"};

    printf("Please choose an option:\n");
    int option_size = sizeof(options) / sizeof(options[0]);
    for (int i = 0; i < option_size; i++)
        printf("%s\n", options[i]);

    int choice;
    printf("User's choice: ");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return -1;
    }

    if (choice < 0 || choice > 12)
    {
        printf("Invalid choice. Please choose a number between 0 and %d.\n", option_size - 1);
        return -1;
    }

    return choice;
}

int main()
{
    // Load data from files
    ll *docList = loadDoctors("Doctors.txt");
    pTree *tree = loadPatients(&docList, "Patients.txt");
    pLine *line = loadLine(tree, "Line.txt");
    // Main loop
    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case 0:
            printf("System shuting down\n");
            updateFiles(tree, line, &docList);
            return 0;
        case 3:
            break;
        }
    }
}
