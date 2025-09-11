Task Scheduler

Problem Statement
-----------------
Design a simple task scheduler that supports the following operations:

1. Add a task with a name (string) and a priority (integer)
   - Smaller numbers = higher priority
   - If two tasks have the same priority, earlier inserted tasks should run first

2. Get the next task (remove and return the name of the task with the highest priority)

If there are no tasks available, return "NO TASKS"

Constraints
-----------
- Task names are non-empty strings of length <= 100
- Priorities are integers in the range [1, 10^6]
- The number of tasks added will not exceed 10^5

Example
-------
Input:
    add("Write report", 2)
    add("Fix bug", 1)
    add("Make coffee", 3)
    next()
    next()
    next()
    next()

Output:
    Fix bug
    Write report
    Make coffee
    NO TASKS

Difficulty
----------
Medium
Time Complexity: O(n log n)
