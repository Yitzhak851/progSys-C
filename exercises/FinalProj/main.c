#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

#define _CRT_SECURE_NO_WARNINGS


/**
 * @brief Displays a menu and prompts the user to choose an option.
 *
 * The menu includes options for admitting a patient, checking allergies, displaying patients, and more.
 *
 * @return The chosen option as an integer, or -1 if the input is invalid.
 */
int menu() {
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
    for (int i = 0; i < option_size; i++){
        printf("%s\n", options[i]);
    }

    int choice;
    printf("User's choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'){
            ; // Clear input buffer
        }
        return -1;
    }
    if (choice < 0 || choice > 12) {
        printf("Invalid choice. Please choose a number between 0 and %d.\n", option_size - 1);
        return -1;
    }
    printf("\n");
    return choice;
}

/**
 * @brief The main function that controls the hospital management system.
 *
 * Loads doctors, patients, and line information from files and provides a menu for user interaction.
 *
 * @return Exit status of the program.
 */
int main() {
    // Load doctors, patients, and line from respective files
    ll *docList = loadDoctors("Doctors.txt");
    pTree *tree = loadPatients(&docList, "Patients.txt");
    pLine *line = loadLine(tree, "Line.txt");
    if (docList == NULL || tree == NULL || line == NULL) {
        fprintf(stderr, "Error loading initial data.\n");
        return 1;
    }
    while (1) {
        int choice = menu();
        if (choice == -1){
            continue;
        }
        switch (choice) {
        case 0:
            printf("System shutting down\n");
            updateFiles(tree, line, &docList); // Save data to files before exiting
            freeAll(docList, tree, line);      // Free all allocated memory
            return 0;
        case 1:
            line->myLine = admitPatient(tree->myTree, docList, line->myLine); // Admit a new patient
            break;
        case 2:
            checkForAllergies(line->myLine); // Check for allergies in the patient line
            break;
        case 3:
            displayAllPatients(tree->myTree); // Display all patients in the tree
            printf("\n");
            break;
        case 4:
            displayPatientAdmissions(tree->myTree); // Display all patient admissions
            break;
        case 5:
            displayPatientsInLine(line->myLine, 1); // Display all patients in line
            printf("\n");
            break;
        case 6:
            line->myLine = advancePatientInLine(line->myLine); // Advance a patient in the line
            printf("\n");
            break;
        case 7:
            displayDoctors(docList); // Display all doctors
            printf("\n");
            break;
        case 8:
            displayPatientsToDoctor(line->myLine, docList); // Display all patients assigned to a doctor
            break;
        case 9:
            line->myLine = dischargePatient(line->myLine); // Discharge a patient
            break;
        case 10:
            removeVisit(tree->myTree); // Remove a visit from a patient
            break;
        case 11:
            removePatient(tree, line); // Remove a patient from the system
            break;
        case 12:
            updateFiles(tree, line, &docList); // Save data to files
            freeAll(docList, tree, line);      // Free all allocated memory
            printf("Goodbye :)!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } // end while
}
