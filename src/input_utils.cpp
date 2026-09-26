// Zhang implements the input helper functions on feature/ui-validation.
#include "input_utils.h"

#include <iostream>
#include <limits>

using namespace std;


void displayMenu() {

    cout << "\n========================================\n";
    cout << " Study Load & Assignment Priority Planner\n";
    cout << "========================================\n";
    cout << "1. Add assignment\n";
    cout << "2. Display all assignments\n";
    cout << "3. Display high-priority active tasks\n";
    cout << "4. Mark assignment complete\n";
    cout << "5. Exit\n";
    cout << "========================================\n";
}



int getValidatedInt(string prompt,
                    int minimum,
                    int maximum) {

    int value;

    while (true) {

        cout << prompt;
        cin >> value;

        if (cin.fail()) {

            cout << "Invalid input. Please enter a number.\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else if (value < minimum || value > maximum) {

            cout << "Please enter a value between "
                 << minimum
                 << " and "
                 << maximum
                 << ".\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return value;
        }
    }
}


double getValidatedDouble(string prompt,
                          double minimum) {

    double value;

    while (true) {

        cout << prompt;
        cin >> value;

        if (cin.fail()) {

            cout << "Invalid input. Please enter a number.\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else if (value < minimum) {

            cout << "Please enter a value of at least "
                 << minimum
                 << ".\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return value;
        }
    }
}



string readNonEmptyLine(string prompt) {

    string text;

    while (true) {

        cout << prompt;

        getline(cin, text);

        if (!text.empty()) {

            return text;
        }

        cout << "Input cannot be blank. Please try again.\n";
    }
}
