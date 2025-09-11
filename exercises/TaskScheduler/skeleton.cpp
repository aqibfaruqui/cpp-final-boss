#include <iostream>
#include <string>

class TaskScheduler {
private:

public:
    // Add a new task with given name and priority
    void add(const std::string& task, int priority);

    // Return and remove the highest priority task
    std::string next();
};

int main() {
    TaskScheduler scheduler;

    scheduler.add("Write report", 2);
    scheduler.add("Fix bug", 1);
    scheduler.add("Make coffee", 3);

    std::cout << scheduler.next() << std::endl;  // Expected: Fix bug
    std::cout << scheduler.next() << std::endl;  // Expected: Write report
    std::cout << scheduler.next() << std::endl;  // Expected: Make coffee
    std::cout << scheduler.next() << std::endl;  // Expected: NO TASKS
    return 0;
}
