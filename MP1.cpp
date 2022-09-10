#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

// algorithm for bubble sorting integers
void bubble_sort(int list[], int recordNumbers[]) {
    int i, j;  // indices of array elements to be checked

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (list[j] > list[j+1]) {
                swap(list[j], list[j+1]);
                swap(recordNumbers[j], recordNumbers[j+1]);
            }
        }
    }
}

// algorithm for bubble sorting surnames
void bubble_sort(char surnames[][20], int recordNumbers[]) {
    int i, j;  // indices of array elements to be checked
    char temp[20];

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (strcmp(surnames[j], surnames[j+1]) > 0) {
                // swap the two elements
                strcpy(temp, surnames[j]);
                strcpy(surnames[j], surnames[j+1]);
                strcpy(surnames[j+1], temp);
                swap(recordNumbers[j], recordNumbers[j+1]);
            }
        }
    }
}

int main() {
    // arrays for storing database
    int recordNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int studentNumbers[10];
    char surnames[10][20];
    char givenNames[10][20];
    char middleInitials[10];
    int finalGrades[10];

    // printing input interface
    cout << "Physics Class Final Grade Database" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "\nRecord " << (i+1) << " of 10" << endl;

        // take input from user
        cout << "Enter Student No. ";
        cin >> studentNumbers[i];
        cout << "Enter Surname: ";
        cin >> surnames[i];
        cout << "Enter Given Name: ";
        cin >> givenNames[i];
        cout << "Enter Middle Initial: ";
        cin >> middleInitials[i];
        cout << "Enter Physics Final Grade: ";
        cin >> finalGrades[i];
    }

    // choice interface
    int choice;

    cout << "\nDo you wish to display records sorted according to: ";
    cout << "\n[1] Record No. ";
    cout << "\n[2] Surname";
    cout << "\n[3] Physics Final Grade";
    cout << "\nEnter choice: ";
    cin >> choice;

    // order interface
    int order;

    cout << "\nDo you wish to display records sorted in: ";
    cout << "\n[1] Ascending Order";
    cout << "\n[2] Descending Order";
    cout << "\nEnter choice: ";
    cin >> order;

    // print table header
    cout << left << setfill(' ') << setw(6) << "REC#";
    cout << left << setfill(' ') << setw(6) << "STUD#";
    cout << left << setfill(' ') << setw(21) << "SURNAME";
    cout << left << setfill(' ') << setw(21) << "GIVEN NAME";
    cout << left << setfill(' ') << setw(6) << "M.I.";
    cout << left << setfill(' ') << setw(6) << "GRADE" << endl;

    // sort according to choice
    if (choice == 1) {  // sort by record number
        // print table
        if (order == 1) {  // ascending order
            for (int i = 0; i < 10; i++) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[rec];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[rec] << endl;
            }
        }
        else if (order == 2) {  // descending order
            for (int i = 9; i > -1; i--) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[rec];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[rec] << endl;
            }
        }
    }

    else if (choice == 2) {  // sort by surname
        bubble_sort(surnames, recordNumbers);

        // print table
        if (order == 1) {  // ascending order
            for (int i = 0; i < 10; i++) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[i];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[rec] << endl;
            }
        }
        else if (order == 2) {  // descending order
            for (int i = 9; i > -1; i--) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[i];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[rec] << endl;
            }
        }
    }
    
    else if (choice == 3) {  // sort by final grade
        bubble_sort(finalGrades, recordNumbers);

        // print table
        if (order == 1) {  // ascending order
            for (int i = 0; i < 10; i++) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[rec];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[i] << endl;
            }
        }
        else if (order == 2) {  // descending order
            for (int i = 9; i > -1; i--) {
                int rec = recordNumbers[i] - 1;
                cout << left << setfill(' ') << setw(6) << (rec+1);
                cout << left << setfill(' ') << setw(6) << studentNumbers[rec];
                cout << left << setfill(' ') << setw(21) << surnames[rec];
                cout << left << setfill(' ') << setw(21) << givenNames[rec];
                cout << left << setfill(' ') << setw(6) << middleInitials[rec];
                cout << left << setfill(' ') << setw(6) << finalGrades[i] << endl;
            }
        }
    }

    return 0;
}
