
#include "StudyPlanner.h"
#include "Assignment.h"
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

void StudyPlanner::displayAll() const {}

void StudyPlanner::displayPriorityTasks() const {}

int StudyPlanner::findById(int) const { return -1; }

bool StudyPlanner::markCompleted(int) { return false; }

bool StudyPlanner::loadFromFile(string) { return false; }

bool StudyPlanner::saveToFile(string) const { return true; }

int StudyPlanner::getCount() const { return 0; }

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