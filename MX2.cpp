#include <iostream>
using namespace std;

int main() {
    int r;
    int choice;
    double pi = 3.14;

    cout << "Enter radius in m: ";
    cin >> r;
    cout << "Enter 1 for circumference, 2 for area, 3 for volume. ";    
    cin >> choice; // input of choice
    
    if (choice == 1) {
        double circumference = 2*pi*r; // calculate circumference
        cout << "The circumference is " << circumference << " m";
    }
    else if (choice == 2) {
        double area = pi*r*r; // calculate area
        cout << "The area is " << area << " m^2";
    }
    else if (choice == 3) {
        double volume = (4/3.0)*pi*r*r*r; // calculate area
        cout << "The volume is " << volume << " m^3";
    }
    else {
        cout << "Invalid input.";
    }
    return 0;
}
