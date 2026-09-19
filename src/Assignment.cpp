#include "Assignment.h"

//Defualt Constructor
Assignment::Assignment() 
    : id(0),
      courseName("Unknown"),
      title("Unknown"),
      daysUntilDue(0),
      estimatedHours(0.0),
      importance(1),
      completed(false)
{
}

//Parameterized Constructor
Assignment::Assignment(int id, string courseName, string title, int daysUntilDue, 
                        double estimatedHours, int importance, bool completed) 
    : id(id),
      courseName(courseName),
      title(title),
      daysUntilDue(daysUntilDue),
      estimatedHours(estimatedHours),
      importance(importance),
      completed(completed)
{
}

//==============================================
//                  GETTERS

int Assignment::getId() const {
    return id;
}

string Assignment::getCourseName() const {
    return courseName;
}

string Assignment::getTitle() const {
    return title;
}

int Assignment::getDaysUntilDue() const {
    return daysUntilDue;
}

int Assignment::getImportance() const {
    return importance;
}

bool Assignment::isCompleted() const {
    return completed;
}

double Assignment::getEstimatedHours() const {
    return estimatedHours;
}

//==============================================

void Assignment::setCompleted(bool status) {
    completed = status;
}

string Assignment::calculatePriority() const{
    int StartScore = importance;

    if (daysUntilDue <= 1) {
        StartScore += 3;
    }
    else if (daysUntilDue <= 3) {
        StartScore += 2;
    }
    else if (daysUntilDue <= 7) {
        StartScore += 1;
    }
    if (estimatedHours >= 5.0) {
        StartScore += 1;
    }

    if (StartScore >= 5) {
        return "HIGH";
    } 
    else if (StartScore >= 3) {
        return "MEDIUM";
    }
    else {
        return "LOW";
    }

}

string Assignment::toString() const {
    string status;
    if (completed) {
        status = "True";
    } 
    else {
        status = "Active";
    }
    return "ID: " + to_string(id) +  " | Course: " + courseName + " | Title: " + title + 
        " | Days Until Due: " + to_string(daysUntilDue) + " | Estimated Hours: " + to_string(estimatedHours) +
        " | Importance: " + to_string(importance) + " | Priority: " + calculatePriority() + " | Status: " + status;

}