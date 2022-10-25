#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class Question {
    private:
        // generates an int with the desired number of digits (difficulty)
        int generateInt(int difficulty) {
            int limit = pow(10, difficulty);
            int random = (rand() % limit);

            return random;
        }

        // chooses operation number from set 
        int chooseOperation(int numbers) {
            int random;

            if (numbers == 1) {  // one number question
                random = (rand() % 3);
            }
            else { // two number question
                random = (rand() % 5);
            }

            return random;
        }

    public:
        int difficulty;
        string operations1[3] = {"sin", "cos", "tan"};
        string operations2[5] = {"+", "-", "*", "/", "^"};
        string questionString = "";
        int correctAnswer;

        // determine the numbers to be used in the question
        string generateQuestion(int difficulty, bool extraFunctions) {
            if (not extraFunctions) {
                return generateTwoNumQuestion(difficulty);
            }

            int random = (rand() % 5);  // weighted 20% trig, 80% other
            if (random == 0) {  // one number question
                return generateOneNumQuestion(difficulty);
            }
            else {  // two number question
                return generateTwoNumQuestion(difficulty);
            }
        }

        // generates and returns a one number question in string form
        string generateOneNumQuestion(int difficulty) {
            int operation = chooseOperation(1);

            // choose numbers from preselected list of angles
            string angles[5] = {"0","pi/2","pi","3pi/2","2pi"};
            double angleEquivalents[5] = {0, M_PI/2, M_PI, 3*M_PI/2, 2*M_PI};

            // get correct answer
            int random;
            if (operation == 2) {  // tan
                
                do {
                    random = (rand() % 5);
                    correctAnswer = tan(angleEquivalents[random]);
                } while (random == 1 || random == 3);  // tan undefined at these angles
            }
            else {
                random = (rand() % 5);
                if (operation == 0) {  // sin
                    correctAnswer = sin(angleEquivalents[random]);
                }
                else if (operation == 1) { // cos
                    correctAnswer = cos(angleEquivalents[random]);
                }
            }

            // build question string
            questionString.append(operations1[operation]);
            questionString.append(" ");
            questionString.append(angles[random]);

            return questionString;
        }

        // generates and returns a two number question in string form
        string generateTwoNumQuestion(int difficulty) {
            // generate random int 1 and operation
            int operation = chooseOperation(2);
            int num1 = generateInt(difficulty);
            int num2;
        
            // generate random int 2
            if (operation == 2) {
                if (difficulty == 5) {
                    num2 = generateInt(4);  // limit num 2 to prevent overflows
                }
                else {
                    num2 = generateInt(difficulty);
                }
            }
            if (operation == 3) {
                // generate second integer that is not 0
                num2 = 0;
                do {
                    num2 = generateInt(difficulty);
                } while (num2 == 0);
            } 
            else if (operation == 4) {
                // get exponent limit to make sure int does not overflow
                double maxLog = log(INT_MAX);
                double baseLog = log(num1);
                int limit = floor(maxLog / baseLog);

                num2 = (rand() % limit);
            } 
            else {
                num2 = generateInt(difficulty);
            }

            // get correct answer
            if (operation == 0) {
                correctAnswer = num1 + num2;
            } 
            else if (operation == 1) {
                correctAnswer = num1 - num2;
            }
            else if (operation == 2) {
                correctAnswer = num1 * num2;
            } 
            else if (operation == 3) {
                correctAnswer = num1 / num2;
            }
            else if (operation == 4) {
                correctAnswer = pow(num1, num2);
            }

            // build question string
            questionString.append(to_string(num1));
            questionString.append(" ");
            questionString.append(operations2[operation]);
            questionString.append(" ");
            questionString.append(to_string(num2));
            return questionString;
        }

        // takes the question as input and returns True if answer given is correct
        bool checkAnswer(int answer) {
            if (answer == correctAnswer) {
                return true;
            }
            return false;
        }
};

class InputValidation {
    public:
        // gets an integer input
        int getAnswer() {
            int input;

            // check integer input
            do {
                // if user entered invalid type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please re-enter. ";
                    cin >> input;
                }
                else {
                    cout << "Enter answer: ";
                    cin >> input;
                }

            } while (cin.fail());

            return input;
        }

        // gets the difficulty as input from the user
        int getDifficulty() {
            int difficulty;

            // check difficulty input if int
            do {
                // if user entered invalid type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid difficulty. Please re-enter. ";
                    cin >> difficulty;
                }
                else {
                    cout << "Enter difficulty: ";
                    cin >> difficulty;
                }
                while (difficulty > 5 || difficulty < 1) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Difficulty can only be from 1 to 5. Please re-enter. ";
                    cin >> difficulty;
                }

            } while (cin.fail());

            return difficulty;
        }

        // gets the number of questions as input from the user
        int getQuestions() {
            int questionsNum;

            // check difficulty input if int
            do {
                // if user entered invalid type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid number of questions. Please re-enter. ";
                    cin >> questionsNum;
                }
                else {
                    cout << "Enter number of questions: ";
                    cin >> questionsNum;
                }
                while (questionsNum < 1) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Number of questions cannot be negative. Please re-enter. ";
                    cin >> questionsNum;
                }

            } while (cin.fail());

            return questionsNum;
        }

        // prompts the user if they want to repeat the program
        bool getRepeat() {
            int repeat;

            // check difficulty input if int
            do {
                // if user entered invalid type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please re-enter. ";
                    cin >> repeat;
                }
                else {
                    cout << "Do you want to repeat the quiz? Type: " << endl;
                    cout << "0: No" << endl;
                    cout << "1: Yes" << endl;
                    cin >> repeat;
                }
                while (repeat > 1 || repeat < 0) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Please re-enter either 0 or 1. ";
                    cin >> repeat;
                }

            } while (cin.fail());

            if (repeat == 1) {
                return true;
            }
            return false;
        }

        // prompts the user if they want to include extra functions
        bool getExtraFunctions() {
            int extraFunctions;

            // check difficulty input if int
            do {
                // if user entered invalid type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please re-enter. ";
                    cin >> extraFunctions;
                }
                else {
                    cout << "Do you want to include extra functions: ";
                    cout << "(ex. sin, cos, tan) " << endl;
                    cout << "0: No" << endl;
                    cout << "1: Yes" << endl;
                    cin >> extraFunctions;
                }
                while (extraFunctions > 1 || extraFunctions < 0) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Please re-enter either 0 or 1. ";
                    cin >> extraFunctions;
                }

            } while (cin.fail());

            if (extraFunctions == 1) {
                return true;
            }
            return false;
        }
};

class Interface {
    public:
        // prints the guide at the start of the program
        void printGuide() {
            cout << "This is a program that aims to improve ";
            cout << "people's math skills." << endl;
            cout << "This quiz has 5 difficulty levels:" << endl;
            cout << "1. 1 digit" << endl;
            cout << "2. 2 digits" << endl;
            cout << "3. 3 digits" << endl;
            cout << "4. 4 digits" << endl;
            cout << "5. 5 digits" << endl;
        }

        // prints instructions before user starts answering
        void printAnswerInstructions() {
            cout << "Enter integers only. If answer is a decimal, ";
            cout << "enter answer rounded down." << endl;
        }

        // prints points
        void printPoints(int points) {
            cout << "Number of points: " << points << endl;
        }

        // prints thank you message at the end of the program
        void printThankYou() {
            cout << "Thank you for using this program!" << endl;
            cout << "Submitted as Machine Problem 2 by Matt Ferrer" << endl;
        }
};

int main() {
    Interface interface; 
    InputValidation validation;
    interface.printGuide();
    bool repeat = true;

    do {
        srand(time(0));  // set seed for random number generator

        int difficulty = validation.getDifficulty();
        int questionsNum = validation.getQuestions();
        int extraFunctions = validation.getExtraFunctions();
        interface.printAnswerInstructions();
        
        // quiz phase
        int points = 0;

        for (int i = 0; i < questionsNum; i++) {
            Question question;
            cout << question.generateQuestion(difficulty, extraFunctions) << endl;
            int answer = validation.getAnswer();
            bool isCorrect = question.checkAnswer(answer);
            
            if (isCorrect) {
                cout << "Answer " << answer << " is correct! " << endl;
                points++;
            } 
            else {
                cout << "Answer " << answer << " is incorrect. ";
                cout << "Correct answer is " << question.correctAnswer << endl;
            }
        }

        interface.printPoints(points);  // print number of points
        repeat = validation.getRepeat();
    } while (repeat);

    interface.printThankYou();
    return 0;
}
