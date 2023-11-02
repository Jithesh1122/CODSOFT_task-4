#include <iostream>
#include <string>
#include <vector>

#define MAX_TASKS 100

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void addTask(const std::string &description) {
    if (tasks.size() < MAX_TASKS) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false; // Initialize as incomplete
        tasks.push_back(newTask);
        std::cout << "Task added successfully!" << std::endl;
    } else {
        std::cout << "Task list is full. Unable to add more tasks." << std::endl;
    }
}

void viewTasks() {
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
    }
}

void markTaskAsCompleted(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
        if (tasks[taskIndex].completed) {
            std::cout << "Task is already completed!" << std::endl;
        } else {
            tasks[taskIndex].completed = true;
            std::cout << "Task marked as completed!" << std::endl;
        }
    } else {
        std::cout << "Invalid task index. Please enter a valid task index." << std::endl;
    }
}

void removeTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index. Please enter a valid task index." << std::endl;
    }
}

int main() {
    int choice;
    std::string description;
    int taskIndex;

    while (true) {
        std::cout << "\nTodo List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                viewTasks();
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                markTaskAsCompleted(taskIndex - 1);
                break;
            case 4:
                viewTasks();
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex;
                removeTask(taskIndex - 1);
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
