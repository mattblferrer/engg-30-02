#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    int student_number;
    string degree_program;
    int units;
    string name_guardian;
    string home_address;

    // Enter name
    cout << "Enter name: " << endl;
    getline(cin, name);

    // Enter age
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid age, please re-enter. " << endl;
            cin >> age;
        }
        else {
            cout << "Enter age: " << endl;
            cin >> age;
        }

        while (age < 0 || age > 100) {
            cout << "Invalid age, please re-enter. " << endl;
            cin >> age;
        }

    } while(cin.fail());

    // Enter student number
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid student number, please re-enter. " << endl;
            cin >> student_number;
        }
        else {
            cout << "Enter student number: " << endl;
            cin >> student_number;
        }

        while (student_number < 100000 || student_number > 999999) {
            cout << "Invalid student number, please re-enter. " << endl;
            cin >> student_number;
        }

    } while(cin.fail());

    // Enter degree program
    if (cin.peek() == '\n') cin.ignore();
    cout << "Enter degree program: " << endl;
    getline(cin, degree_program);

    // Enter number of units
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid number of units, please re-enter. " << endl;
            cin >> units;
        }
        else {
            cout << "Enter number of units: " << endl;
            cin >> units;
        }

        while (units < 0 || units > 30) {
            cout << "Invalid number of units, please re-enter. " << endl;
            cin >> units;
        }

    } while(cin.fail());

    // Enter name of guardian
    if (cin.peek() == '\n') cin.ignore();
    cout << "Enter name of guardian: " << endl;
    getline(cin, name_guardian);

    // Enter home address
    cout << "Enter home address: " << endl;
    getline(cin, home_address);

    // print input
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Student Number: " << student_number << endl;
    cout << "Degree Program: " << degree_program << endl;
    cout << "Number of Units Enrolled: " << units << endl;
    cout << "Name of Guardian: " << name_guardian << endl;
    cout << "Home Address: " << home_address << endl;

    return 0;
}
