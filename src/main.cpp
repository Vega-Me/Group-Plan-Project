#include <iostream>
#include <limits>

#include "StudyPlanner.h"
#include "input_utils.h"

using namespace std;


int main() {

    StudyPlanner planner;

    // Try loading previously saved assignments.
    planner.loadFromFile("data/assignments.txt");

    bool running = true;

    while (running) {

        displayMenu();

        int choice = getValidatedInt(
            "Enter your choice: ",
            1,
            5
        );


        switch (choice) {


        // ----------------------------------------------------
        // Add assignment
        // ----------------------------------------------------
        case 1:
        {
            string courseName =
                readNonEmptyLine(
                    "Enter course name: "
                );

            string title =
                readNonEmptyLine(
                    "Enter assignment title: "
                );

            int daysUntilDue =
                getValidatedInt(
                    "Enter days until due: ",
                    0,
                    numeric_limits<int>::max()
                );

            double estimatedHours =
                getValidatedDouble(
                    "Enter estimated hours: ",
                    0.0
                );

            int importance =
                getValidatedInt(
                    "Enter importance (1-3): ",
                    1,
                    3
                );


            planner.addAssignment(
                courseName,
                title,
                daysUntilDue,
                estimatedHours,
                importance
            );


            cout << "Assignment added successfully.\n";

            break;
        }


        // ----------------------------------------------------
        // Display all assignments
        // ----------------------------------------------------
        case 2:

            planner.displayAll();

            break;


        // ----------------------------------------------------
        // Display HIGH-priority active assignments
        // ----------------------------------------------------
        case 3:

            planner.displayPriorityTasks();

            break;


        // ----------------------------------------------------
        // Mark assignment complete
        // ----------------------------------------------------
        case 4:
        {
            int id =
                getValidatedInt(
                    "Enter assignment ID: ",
                    1,
                    numeric_limits<int>::max()
                );


            if (planner.markCompleted(id)) {

                cout << "Assignment marked complete.\n";
            }

            else {

                cout << "Assignment ID not found.\n";
            }


            break;
        }


        // ----------------------------------------------------
        // Exit
        // ----------------------------------------------------
        case 5:

            running = false;

            break;
        }
    }


    // Save before leaving the program.
    if (!planner.saveToFile("data/assignments.txt")) {

        cout << "Warning: assignments could not be saved.\n";
    }

    else {

        cout << "Assignments saved successfully.\n";
    }


    cout << "Goodbye!\n";

    return 0;
}
