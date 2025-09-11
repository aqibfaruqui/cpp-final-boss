#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct Task {
    std::string message;
    int priority;

    Task(std::string m, int p) :
        message(m), priority(p) {}
};

class TaskScheduler {
private:
    // Comparator to order Task objects by priority (ascending)
    static inline auto cmp = [](const Task lhs, const Task rhs) {
        return (lhs.priority > rhs.priority);
    };

    std::priority_queue<Task, std::vector<Task>, decltype(cmp)> tasks{cmp};

public:
    // Add a new task with given name and priority
    void add(const std::string& task, int priority) {
        Task t(task, priority);
        tasks.push(t);
    }

    // Return and remove the highest priority task
    std::string next() {
        if (tasks.empty())
            return "NO TASKS";
        
        Task t = tasks.top();
        tasks.pop();
        return t.message;
    }
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
