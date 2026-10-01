# Study Load & Assignment Priority Planner

## Purpose

A console-based C++17 program that helps a college student track assignments and decide what to work on first.

## Features

- Add an assignment with validated input.
- Display all assignments.
- Display active HIGH-priority assignments.
- Mark an assignment complete by numeric ID.
- Save assignments to a local text file.
- Reload saved assignments when the program starts.
- Safely handle missing, empty, or malformed saved data without crashing.

## Project Structure

- include/Assignment.h and src/Assignment.cpp: represent one assignment and its behavior.
- include/StudyPlanner.h and src/StudyPlanner.cpp: manage the collection of assignments and planner operations.
- include/input_utils.h and src/input_utils.cpp: contain reusable input-validation functions.
- src/main.cpp: controls the main menu and program flow.
- data/assignments.txt: stores saved assignment data.

## Priority Rule

Priority is based on assignment importance, days until the due date, and estimated work hours.

1. Start the score at the importance value from 1 to 3.
2. Add 3 if the assignment is due in 0 to 1 days.
3. Add 2 if the assignment is due in 2 to 3 days.
4. Add 1 if the assignment is due in 4 to 7 days.
5. Add 1 if the estimated work time is at least 5 hours.
6. A score of 5 or greater is HIGH.
7. A score of 3 to 4 is MEDIUM.
8. A score of 1 to 2 is LOW.

Completed assignments are excluded from the active HIGH-priority view.

## Requirements

- C++17 compiler
- CMake 3.16 or newer

## Build and Run

From the project root, run these commands:

cmake -S . -B build

cmake --build build

./build/StudyPlanner

On Windows with a multi-config generator, the executable may be located at:

build/Debug/StudyPlanner.exe

## Input Rules

- Course name must be non-empty text.
- Assignment title must be non-empty text.
- Days until due must be an integer greater than or equal to 0.
- Estimated hours must be a number greater than or equal to 0.
- Importance must be an integer from 1 through 3.
- Menu choices must be within the valid range.

## Data File
Saved records are stored in `data/assignments.txt` as tab-separated fields:

`id, course, title, days, hours, importance, completed`

A missing or empty file starts the planner with no assignments.

When loading saved data, malformed records produce a warning and are skipped while valid records continue loading. A saved record is skipped if required fields are missing or blank, a numeric field cannot be fully converted, or a saved value is outside its allowed range.

## Known Limitations

- The program uses a console interface only.
- The priority system is based on a simple scoring rule and is not a calendar or scheduling optimizer.
- Literal tab characters inside course names or assignment titles are not supported by the save-file format.
- The program should be run from the project root so the data/assignments.txt path works correctly.

## Team

- Marcos Gilbert
- Zhang Yunjia
