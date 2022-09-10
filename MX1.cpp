#include <iostream>
using namespace std;

int main() {
    int r = 5;
    double pi = 3.14;

    double circumference = 2*pi*r; // calculate circumference
    double area = pi*r*r; // calculate area

    cout << "The radius of " << r << " m will have a circumference of "
        << circumference << " m and an area of " << area << " m^2";

    return 0;
}
