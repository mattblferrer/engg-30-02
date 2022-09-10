#include <iostream>
using namespace std;

int main() {
    string candidates[5];

    // get input names of finalists
    cout << "Input names of Finalists \n";
    for (int i = 0; i < 5; i++) {
        char candidate[50];

        cin.getline(candidate, 50);
        candidates[i] = candidate;
    }

    // display names of the finalists
    cout << "\nList of finalists: " << "\n";

    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ": " << candidates[i] << "\n";
    }
    
    // ask for winning candidate number
    int candidate_number;

    cout << "Input Winning Candidate Number: ";
    cin >> candidate_number; 
    cout << "The winner is " << candidates[candidate_number - 1];

    return 0;
}
