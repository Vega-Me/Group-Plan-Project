
#include "StudyPlanner.h"
using namespace std;

StudyPlanner::StudyPlanner() : nextId(1) {}

void StudyPlanner::addAssignment(string, string, int, double, int) {}

void StudyPlanner::displayAll() const {}

void StudyPlanner::displayPriorityTasks() const {}

int StudyPlanner::findById(int) const { return -1; }

bool StudyPlanner::markCompleted(int) { return false; }

bool StudyPlanner::loadFromFile(string) { return false; }

bool StudyPlanner::saveToFile(string) const { return true; }

int StudyPlanner::getCount() const { return 0; }