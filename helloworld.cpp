#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Function declarations
void showMenu();
void handleArithmetic(int choice);
void handleScientific(int choice);

int main() {
    int choice;
    
    cout << "====================================\n";
    cout << "    ADVANCED SCIENTIFIC CALCULATOR   \n";
    cout << "====================================\n";

    do {
        showMenu();
        cout << "\nEnter your choice (0-13): ";
        
        // Handle non-integer input errors
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            handleArithmetic(choice);
        } else if (choice >= 6 && choice <= 13) {
            handleScientific(choice);
        } else if (choice != 0) {
            cout << "Invalid choice! Please select a valid option from the menu.\n";
        }
        
        cout << "\n------------------------------------\n";
    } while (choice != 0);

    cout << "Thank you for using the Advanced Calculator. Goodbye!\n";
    return 0;
}

void showMenu() {
    cout << "\n[Basic Operations]     [Scientific Operations]\n";
    cout << "1. Addition (+)        6. Power (x^y)         10. Sine (sin)\n";
    cout << "2. Subtraction (-)     7. Square Root (v)     11. Cosine (cos)\n";
    cout << "3. Multiplication (*)  8. Natural Log (ln)    12. Tangent (tan)\n";
    cout << "4. Division (/)        9. Base-10 Log (log)   13. Modulo (%)\n";
    cout << "5. Absolute Value (|x|)\n";
    cout << "0. Exit Program\n";
}

void handleArithmetic(int choice) {
    double num1, num2;
    
    if (choice == 5) { // Absolute value only requires one number
        cout << "Enter number: ";
        cin >> num1;
        cout << "Result: |" << num1 << "| = " << abs(num1) << "\n";
        return;
    }

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
            break;
        case 2:
            cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
            break;
        case 3:
            cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error: Division by zero is undefined!\n";
            } else {
                cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
            }
            break;
    }
}

void handleScientific(int choice) {
    double num1, num2;

    if (choice == 6) { // Power (x^y)
        cout << "Enter base (x): ";
        cin >> num1;
        cout << "Enter exponent (y): ";
        cin >> num2;
        cout << "Result: " << num1 << "^" << num2 << " = " << pow(num1, num2) << "\n";
        return;
    }
    
    if (choice == 13) { // Modulo requires integers
        int int1, int2;
        cout << "Enter first integer: ";
        cin >> int1;
        cout << "Enter second integer: ";
        cin >> int2;
        if (int2 == 0) {
            cout << "Error: Modulo by zero is undefined!\n";
        } else {
            cout << "Result: " << int1 << " % " << int2 << " = " << (int1 % int2) << "\n";
        }
        return;
    }

    // Single operand items (sqrt, log, trig)
    cout << "Enter number: ";
    cin >> num1;

    switch (choice) {
        case 7:
            if (num1 < 0) {
                cout << "Error: Cannot calculate the square root of a negative number!\n";
            } else {
                cout << "Result: v" << num1 << " = " << sqrt(num1) << "\n";
            }
            break;
        case 8:
            if (num1 <= 0) {
                cout << "Error: Logarithm is only defined for positive numbers!\n";
            } else {
                cout << "Result: ln(" << num1 << ") = " << log(num1) << "\n";
            }
            break;
        case 9:
            if (num1 <= 0) {
                cout << "Error: Logarithm is only defined for positive numbers!\n";
            } else {
                cout << "Result: log10(" << num1 << ") = " << log10(num1) << "\n";
            }
            break;
        case 10:
            // Convert degrees to radians if necessary; defaults to radians here
            cout << "Result: sin(" << num1 << " rad) = " << sin(num1) << "\n";
            break;
        case 11:
            cout << "Result: cos(" << num1 << " rad) = " << cos(num1) << "\n";
            break;
        case 12:
            cout << "Result: tan(" << num1 << " rad) = " << tan(num1) << "\n";
            break;
    }
}

