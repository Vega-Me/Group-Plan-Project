#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
using namespace std;


class Assignment {
private:
    int id;
    string courseName;
    string title;
    int daysUntilDue;
    double estimatedHours;
    int importance;
    bool completed;

public:
    Assignment();
    Assignment(int id, string courseName, string title,
               int daysUntilDue, double estimatedHours,
               int importance, bool completed = false);

    int getId() const;
    string getCourseName() const;       //all const because they return a member's information without changing
    string getTitle() const;
    int getDaysUntilDue() const;
    double getEstimatedHours() const;
    int getImportance() const;
    bool isCompleted() const;

    void setCompleted(bool status);     //changing the completed member
    string calculatePriority() const;
    string toString() const;
};

#endif