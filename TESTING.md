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
| 1 | Normal | Add 3 valid assignments | All 3 assignments receive unique IDs and display correctly | Three valid assignments were added with unique IDs and all three displayed correctly. | PASS |
| 2 | Normal | Mark a valid assignment ID complete | The assignment is marked as completed | The selected valid assignment ID was successfully marked as completed. | PASS |
| 3 | Normal | Save, exit, and restart the program | Saved assignments reload when the program starts again | Saved assignments reloaded successfully after restarting the program. | PASS |
| 4 | Normal | Create an active HIGH-priority assignment | The assignment appears in the HIGH-priority display | The active HIGH-priority assignment appeared in the priority display. | PASS |
| 5 | Boundary | Display assignments when there are zero assignments | A safe no-assignments message is displayed and the program does not crash | The program displayed a no-assignments message and continued without crashing. | PASS |
| 6 | Boundary | Enter daysUntilDue = 0 | The value is accepted | daysUntilDue = 0 was accepted successfully. | PASS |
| 7 | Boundary | Enter estimatedHours = 0 | The value is accepted | estimatedHours = 0 was accepted successfully. | PASS |
| 8 | Boundary | Enter importance = 1 | The value is accepted | importance = 1 was accepted successfully. | PASS |
| 9 | Boundary | Enter importance = 3 | The value is accepted | importance = 3 was accepted successfully. | PASS |
| 10 | Invalid | Enter letters into a numeric field | An error message appears and the program asks for input again without crashing | Letter input was rejected with an error message and the program re-prompted without crashing. | PASS |
| 11 | Invalid | Enter negative days until due | The value is rejected and the program asks for input again | Negative days were rejected and the program requested the value again. | PASS |
| 12 | Invalid | Enter negative estimated hours | The value is rejected and the program asks for input again | Negative estimated hours were rejected and the program re-prompted. | PASS |
| 13 | Invalid | Enter importance = 0 or importance = 4 | The value is rejected and the program asks for input again | Importance values 0 and 4 were both rejected and the program re-prompted. | PASS |
| 14 | Invalid | Enter a blank course name or assignment title | Blank input is rejected and the program asks for input again | Blank required text was rejected and the program requested input again. | PASS |
| 15 | Invalid | Enter a menu choice outside the valid range | The invalid menu choice is rejected and the program asks again | An out-of-range menu choice was rejected and the menu choice was requested again. | PASS |
| 16 | No-Data | Start the program when assignments.txt is missing | The program starts with an empty planner and does not crash | The program started with an empty planner when assignments.txt was missing and did not crash. | PASS |
| 17 | No-Data | Start the program with an empty assignments.txt file | The program starts with an empty planner and does not crash | The program started successfully with an empty assignments.txt file and did not crash. | PASS |
| 18 | Search | Try to complete an assignment ID that does not exist | A not-found message is displayed and the program does not crash | A not-found message was displayed for a nonexistent ID and the program continued normally. | PASS |
| 19 | State | Complete an assignment that currently has HIGH priority | The completed assignment no longer appears in the active HIGH-priority list | After the HIGH-priority assignment was completed, it no longer appeared in the active HIGH-priority list. | PASS |
| 20 | Persistence | Load existing assignment IDs and then add a new assignment | The new assignment receives an ID greater than every loaded ID | After loading existing assignments, the newly added assignment received an ID greater than the largest loaded ID. | PASS |

## Final Result

[All 20 required tests passed. Normal, boundary, invalid-input, no-data, search, state, and persistence behaviors were verified successfully. No unresolved defects remained after final integrated testing.]
