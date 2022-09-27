#include <iostream>
#include <math.h>
using namespace std;

double pi = M_PI;  // define pi

// circumference function
double circumference(double r) {
    return 2*pi*r;
}

// area function
double area(double r) {
    return pi*r*r; 
}

// volume function
double volume(double r) {
    return (4/3.0)*pi*r*r*r; 
}

// function to get radius
double get_radius() {
    double r;

    // check radius input
    do {
        // if user entered invalid type
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please re-enter" << endl;
            cin >> r;
        }
        else {
            cout << "Enter radius in m: ";
            cin >> r;
        }

        // check input if negative
        while (r < 0) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Radius cannot be negative." << endl;
            cin >> r;
        }
    } while (cin.fail());

    return r;
}

// function to get the user's choice
int get_choice() {
    int choice;

    // check choice input
    do {
        // if user entered invalid type
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid choice. Please re-enter" << endl;
            cin >> choice;
        }
        else {
            cout << "Enter 1 for circumference, 2 for area, 3 for volume. ";    
            cin >> choice; // input of choice
        }

        // check input if in range
        while (choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Choice not in range. Please re-enter" << endl;
            cin >> choice;
        }
    } while (cin.fail());

    return choice;
}

int main() {
    double r;
    int choice;
    r = get_radius();
    choice = get_choice();

    if (choice == 1) {  // calculate circumference
        cout << "The circumference is " << circumference(r) << " m";
    }
    else if (choice == 2) {  // calculate area
        cout << "The area is " << area(r) << " m^2";
    }
    else if (choice == 3) {  // calculate volume
        cout << "The volume is " << volume(r) << " m^3";
    }
    else {
        cout << "Invalid input. Please re-enter";
    }
    return 0;
}
