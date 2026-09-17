#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <string>

using namespace std;

void displayMenu();
int getValidatedInt(string prompt, int minimum, int maximum);
double getValidatedDouble(string prompt, double minimum);
string readNonEmptyLine(string prompt);

#endif