#Study Load & Assignment Priority Planner

#Purpose

A console-based C++17 program that helps a college student track assignments and decide what to work on first.

#Features

- Add an assignment with validated input.
- Display all assignments.
- Display active HIGH-priority assignments.
- Mark an assignment complete by numeric ID.
- Save assignments to a local text file.
- Reload saved assignments when the program starts.
- Handle empty, missing-file, boundary, and invalid-input cases safely.

#Project Structure

- include/Assignment.h / src/Assignment.cpp: one assignment and its behavior.
- include/StudyPlanner.h / src/StudyPlanner.cpp: vector of assignments and planner operations.
- include/input_utils.h / src/input_utils.cpp: reusable validated input helpers.
- src/main.cpp: program menu and coordination.
- data/assignments.txt: saved assignment data.

#Priority Rule

Priority uses importance, days until due, and estimated hours.

1. Start score at the importance value from 1 to 3.
2. Add 3 if due in 0-1 days, 2 if due in 2-3 days, or 1 if due in 4-7 days.
3. Add 1 if estimated work is at least 5 hours.
4. Score 5 or greater = HIGH, score 3-4 = MEDIUM, and score 1-2 = LOW.

Completed assignments are excluded from the active HIGH-priority view.

#Requirements

- C++17 compiler
- CMake 3.16 or newer

#Build and Run

From the project root, use the following commands:

cmake -S . -B build

cmake --build build

./build/StudyPlanner

On Windows with a multi-config generator, the executable may be located at:

build/Debug/StudyPlanner.exe

#Input Rules

- Course name: required, non-empty text.
- Assignment title: required, non-empty text.
- Days until due: integer greater than or equal to 0.
- Estimated hours: number greater than or equal to 0.
- Importance: integer from 1 through 3.
- Menu choices are validated and out-of-range values are rejected.

#Data File

Saved records are stored in data/assignments.txt as tab-separated fields.

The field order is:

id, course, title, days, hours, importance, completed

A missing or empty file starts the planner with no assignments.

#Known Limitations

- The program is console-based and does not include a graphical interface.
- Priority is based on a simple rule rather than a calendar or scheduling optimizer.
- Literal tab characters inside course names or titles are not supported by the save format.
- The executable should be run from the project root so the data/assignments.txt path works correctly.

#Team

- Marcos Gilbert
- Zhang Yunja
