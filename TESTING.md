# Testing

## Environment

- C++ Standard: C++17
- Build System: CMake
- Integrated Commit Tested: [fill in after integration]
- Test Date: [fill in after final testing]

## September 21 Integration Checkpoint

- Integrated Branches / Pull Requests: [fill in actual PR numbers or links]
- Build Result: [PASS / FAIL]
- Basic Integrated Test: [describe what was actually tested]

## Reproducible Tests

| # | Type | Steps / Input | Expected Result | Actual Result | Pass? |
|---|---|---|---|---|---|
| 1 | Normal | Add 3 valid assignments | All 3 assignments receive unique IDs and display correctly |  |  |
| 2 | Normal | Mark a valid assignment ID complete | The assignment is marked as completed |  |  |
| 3 | Normal | Save, exit, and restart the program | Saved assignments reload when the program starts again |  |  |
| 4 | Normal | Create an active HIGH-priority assignment | The assignment appears in the HIGH-priority display |  |  |
| 5 | Boundary | Display assignments when there are zero assignments | A safe no-assignments message is displayed and the program does not crash |  |  |
| 6 | Boundary | Enter daysUntilDue = 0 | The value is accepted |  |  |
| 7 | Boundary | Enter estimatedHours = 0 | The value is accepted |  |  |
| 8 | Boundary | Enter importance = 1 | The value is accepted |  |  |
| 9 | Boundary | Enter importance = 3 | The value is accepted |  |  |
| 10 | Invalid | Enter letters into a numeric field | An error message appears and the program asks for input again without crashing |  |  |
| 11 | Invalid | Enter negative days until due | The value is rejected and the program asks for input again |  |  |
| 12 | Invalid | Enter negative estimated hours | The value is rejected and the program asks for input again |  |  |
| 13 | Invalid | Enter importance = 0 or importance = 4 | The value is rejected and the program asks for input again |  |  |
| 14 | Invalid | Enter a blank course name or assignment title | Blank input is rejected and the program asks for input again |  |  |
| 15 | Invalid | Enter a menu choice outside the valid range | The invalid menu choice is rejected and the program asks again |  |  |
| 16 | No-Data | Start the program when assignments.txt is missing | The program starts with an empty planner and does not crash |  |  |
| 17 | No-Data | Start the program with an empty assignments.txt file | The program starts with an empty planner and does not crash |  |  |
| 18 | Search | Try to complete an assignment ID that does not exist | A not-found message is displayed and the program does not crash |  |  |
| 19 | State | Complete an assignment that currently has HIGH priority | The completed assignment no longer appears in the active HIGH-priority list |  |  |
| 20 | Persistence | Load existing assignment IDs and then add a new assignment | The new assignment receives an ID greater than every loaded ID |  |  |

## Final Result

[After final integrated testing, summarize any problems found, fixes made, and whether all required tests passed.]
