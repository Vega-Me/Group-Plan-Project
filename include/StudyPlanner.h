#ifndef STUDYPLANNER_H
#define STUDYPLANNER_H

#include <string>
#include <vector>
#include "Assignment.h"

using namespace std;

class StudyPlanner {
private:
    vector<Assignment> assignments;
    int nextId;

public:
    StudyPlanner();

    void addAssignment(string courseName, string title,
                       int daysUntilDue, double estimatedHours,
                       int importance);

    void displayAll() const;
    void displayPriorityTasks() const;
    int findById(int id) const;
    bool markCompleted(int id);
    bool loadFromFile(string filename);
    bool saveToFile(string filename) const;
    int getCount() const;
};

#endif