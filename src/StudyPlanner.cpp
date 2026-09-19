
#include "StudyPlanner.h"
#include "Assignment.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

StudyPlanner::StudyPlanner() 
    : nextId(1) 
    {
    }

void StudyPlanner::addAssignment(string courseName, string title, int daysUntilDue, double estimatedHours, int importance) {
    Assignment newassignment(nextId, courseName, title, daysUntilDue, estimatedHours, importance);      //needs to include nextId because of original assignment.h object variables
    assignments.push_back(newassignment);                                                               //add to existing vector
    nextId++;                                                                                           //increment for next assignment
}

void StudyPlanner::displayAll() const {
    if (assignments.empty()) {
        cout << "No assignments found" << endl; 
        return;
    }
    for (int i = 0; static_cast<int>(assignments.size()); i++) {
        cout << assignments[i].toString() << endl;
    }
    return;
}

void StudyPlanner::displayPriorityTasks() const {       //get priority string and get completed
    bool found = false;
    for (size_t i = 0; i < assignments.size(); i++) {
        if (assignments[i].calculatePriority() == "HIGH" && assignments[i].isCompleted() == false) {
            assignments[i].toString();
            found = true;
            cout << assignments[i].toString() << endl;
        }
    }
    if (!found) {
        cout << "Could not find any high priority tasks!" << endl;
    }
}

int StudyPlanner::findById(int id) const { 
    for (size_t i = 0; i < assignments.size(); i++) {
        if (assignments[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

bool StudyPlanner::markCompleted(int id) { 
    int temp = findById(id);
    if (temp == -1) {
        return false;
    }
    assignments[temp].setCompleted(true);
    return true;
}


//=======================================       the big one
bool StudyPlanner::loadFromFile(string filename) { 

    ifstream inputfile(filename);      //create a object called inputfile() using ifstream class and pass filename within it

    if (!inputfile) {
        return false;
    }

    assignments.clear();         //clear the vector assignments to paste new data

    string line;                //temporary for getline
    int largestId = 0;          //temporary for largestId

    while (getline(inputfile, line)) {          //keeps doing getline from inputfile and storing it into line, savetoFile has \n to make this possible

        if (line.empty()) {                     //filter out no lines before doing the rest of the function
            continue;                           //skip the iteration of this line and try to read the next line
        }
        stringstream ss(line);              //NEW CONCEPT THANKS TO AI: stringstream turns a string of text into a mini stream. Lets us pull info out of line and ignore whitespace with >> like cin.

        string idText;          //creating temporary variables for every piece of line info, breaking line into variable pieces basically
        string courseName;           //dont need to be turned to other variable
        string title;           //dont need to be turned to other variable
        string daysText;
        string hoursText;
        string importanceText;
        string completedText;

        getline(ss, idText, '\t');      //Taking every piece of the mini stream ss variable, and now we are extracting every line ignoring whitespace and only extracting to the new column '\n'
        getline(ss, courseName, '\t');  //doing getline -> taking info from ss -> putting into variable name -> stopping once we hit the next column
        getline(ss, title, '\t');
        getline(ss, daysText, '\t');
        getline(ss, hoursText, '\t');
        getline(ss, importanceText, '\t');
        getline(ss, completedText, '\t');

        int id = stoi(idText);      //NEW CONCEPT >>> string to integer, s-to-i. Turns our existing string variables from lines and we can start turning them into usable variables
        int daysUntilDue = stoi(daysText);
        double estimatedHours = stod(hoursText); //String to double, s-to-d. These are intuitive to understand, when we want to turn a string to a different type we do s-to-(type we want)
        int importance = stoi(importanceText);
        bool completed = stoi(completedText); //we turn it into a integer and then every non 0 integer c++ will read as true.

        Assignment loadedAssignment(            //creating temporary loop object assignment and then inputting all our variables from ss
            id, courseName, title, daysUntilDue, estimatedHours, importance, completed
        );

        assignments.push_back(loadedAssignment);
        
        if (id > largestId) {
            largestId = id;
        }
    }
    nextId = largestId + 1; //next id for the studyplanner class is going to have a id larger than the last one that was loaded
                            //we aren't changing any of the existing ids, just observing them and then incrementing the next one.
    return true;
}

//Reference:
// Assignment::Assignment(int id, string courseName, string title, int daysUntilDue, 
//                         double estimatedHours, int importance, bool completed) 

// want:
    // int id;                  done
    // string courseName;       done
    // string title;            done
    // int daysUntilDue;        done
    // double estimatedHours;   done
    // int importance;          done
    // bool completed;          done

//=======================================

bool StudyPlanner::saveToFile(string filename) const { 
    ofstream outputFile(filename);
    if (!outputFile) {
        return false;
    }
    for (size_t i = 0; i < assignments.size(); i++) {
        outputFile << assignments[i].getId() << '\t' << assignments[i].getCourseName() << '\t' << assignments[i].getTitle() << '\t'
        << assignments[i].getDaysUntilDue() << '\t' << assignments[i].getEstimatedHours() << '\t' 
        << assignments[i].getImportance() << '\t' << assignments[i].isCompleted() << '\n';
    }
    return true;
}

int StudyPlanner::getCount() const { 
    return static_cast<int>(assignments.size());
}

// class StudyPlanner {
// private:
//     vector<Assignment> assignments;
//     int nextId;

// public:
//     StudyPlanner();

//     void addAssignment(string courseName, string title,
//                        int daysUntilDue, double estimatedHours,
//                        int importance);

//     void displayAll() const;
//     void displayPriorityTasks() const;
//     int findById(int id) const;
//     bool markCompleted(int id);
//     bool loadFromFile(string filename);
//     bool saveToFile(string filename) const;
//     int getCount() const;