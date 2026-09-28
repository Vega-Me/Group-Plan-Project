must include dated contributions, commit hashes/links, review/testing work, blockers, the integration checkpoint, and a signed statement from each member.

https://github.com/Vega-Me/Group-Plan-Project

# Collaboration and Contribution Evidence

## Roles

- Marcos Gilbert: Coordinator/Design + Repository/Integration Lead
- Zhang Yunjia: Testing/Documentation Lead
- Shared: both members write code, review, test the integrated program, and understand the full submission.

## Contribution Log

| Date | Member | Task | Commit / PR | Review or Test Evidence | Blocker / Resolution |
|------|--------|------|-------------|-------------------------|----------------------|
| September 17–18, 2026 | Marcos Gilbert | Implemented Assignment constructors, getters, completion setter, priority calculation, and display formatting. | e21b8a9, d4457dc | Built the implementation with CMake. | Resolved a linker error by adding the missing getEstimatedHours() definition. |
| September 18, 2026 | Marcos Gilbert | Implemented StudyPlanner add, display, find-by-ID, completion, priority filtering, count, save, and load functions. | d4457dc | Checked function definitions against the shared interfaces and built with CMake. | Matched class declarations and definitions to resolve integration issues. |
| September 18, 2026 | Marcos Gilbert | Added initial collaboration documentation and AI-use disclosure. | fd34720 | Recorded AI assistance and implementation verification. | Final team contribution and disclosure details remained to be completed. |
| September 26, 2026 | Zhang Yunjia | Implemented input-validation helpers and the main menu, including add, display, priority filtering, completion, and exit/save flows. | 3f355a2, 2faa214; PR #1 | Reported a successful build with the shared planner stubs in PR #1. | Full behavior testing required Marcos’s planner implementation to be integrated. |
| September 26, 2026 | Zhang Yunjia | Updated README.md and created the 20-case testing plan. | 6cda0b6, 7de7378; PR #1 | Documented build/run instructions and expected normal, boundary, invalid-input, and persistence results. | Actual test results were deferred until integration. |
| September 26–27, 2026 | Marcos Gilbert | Reviewed Zhang’s code, merged PR #1, brought main into the model-planner branch, and corrected planner loop and priority behavior. | 900b5be, 4a89370, 8ecf21c | Built and tested the combined implementation with CMake, as recorded in PR #2. | Corrected planner behavior found during integration. |
| September 27, 2026 | Marcos Gilbert | Submitted the completed Assignment and StudyPlanner implementation for integration into main. | PR #2; merge commit b7aabc9 | PR #2 documented the implementation and build/testing work. | The completed planner was integrated into main on September 27. |
| September 27, 2026 | Zhang Yunjia | Recorded final integrated testing results for all 20 planned cases. | dddadfd, bd5a137; PR #3 | TESTING.md identifies b7aabc9 as the tested commit and records actual results for all 20 cases. | All 20 listed tests were reported as passing. Additional validation limitations identified during AI review remain unresolved. |