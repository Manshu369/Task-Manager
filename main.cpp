#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Task {
    int id;
    string title;
    string priority;
    bool completed;
};

const string FILE_NAME = "tasks.txt";

// Normalize priority input
string getPriority(string input) {
    for (char &c : input) c = tolower(c);

    if (input == "h" || input == "high") return "High";
    if (input == "m" || input == "medium") return "Medium";
    if (input == "l" || input == "low") return "Low";

    return "Low";
}
// Load tasks
vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file(FILE_NAME);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Task t;

        ss >> t.id;
        ss.ignore();

        getline(ss, t.title, '|');
        getline(ss, t.priority, '|');
        ss >> t.completed;

        tasks.push_back(t);
    }

    return tasks;
}

// Save tasks
void saveTasks(vector<Task>& tasks) {
    ofstream file(FILE_NAME);

    for (auto &t : tasks) {
        file << t.id << " "
             << t.title << "|"
             << t.priority << "|"
             << t.completed << endl;
    }
}

