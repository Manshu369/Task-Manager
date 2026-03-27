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

// Add tasks
void addTask(vector<Task>& tasks) {
    int n;
    cout << "\n📝 How many tasks do you want to add: ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        Task t;
        t.id = tasks.empty() ? 1 : tasks.back().id + 1;

        cout << "\n👉 Enter title for Task " << (i + 1) << ": ";
        getline(cin, t.title);

        string p;
        cout << "🎯 Priority (High / Medium / Low): ";
        getline(cin, p);

        t.priority = getPriority(p);
        t.completed = false;

        tasks.push_back(t);
        cout << "✅ Task added.\n";
    }
}

// View tasks
void viewTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n⚠️ No tasks available.\n";
        return;
    }

    cout << "\n📋 Your Tasks:\n";

    for (auto &t : tasks) {
        cout << "\n----------------------\n";
        cout << "🆔 ID: " << t.id << endl;
        cout << "📌 Title: " << t.title << endl;
        cout << "🎯 Priority: " << t.priority << endl;
        cout << "📊 Status: " << (t.completed ? "Completed ✅" : "Pending ⏳") << endl;
    }
}

// Mark complete
void markComplete(vector<Task>& tasks) {
    int id;
    cout << "\n✔️ Enter task ID to mark complete: ";
    cin >> id;

    for (auto &t : tasks) {
        if (t.id == id) {
            t.completed = true;
            cout << "🎉 Task completed!\n";
            return;
        }
    }

    cout << "❌ Task not found.\n";
}

// Filter tasks
void filterTasks(vector<Task>& tasks) {
    int choice;
    cout << "\n🔍 Filter Options:\n";
    cout << "1. Completed ✅\n2. Pending ⏳\nChoose: ";
    cin >> choice;

    bool found = false;

    for (auto &t : tasks) {
        if ((choice == 1 && t.completed) || (choice == 2 && !t.completed)) {
            cout << "\n----------------------\n";
            cout << "🆔 ID: " << t.id << endl;
            cout << "📌 Title: " << t.title << endl;
            cout << "🎯 Priority: " << t.priority << endl;
            cout << "📊 Status: " << (t.completed ? "Completed ✅" : "Pending ⏳") << endl;
            found = true;
        }
    }

    if (!found) cout << "\n⚠️ No matching tasks.\n";
}

// Main
int main() {
    vector<Task> tasks = loadTasks();
    int choice;

    while (true) {
        cout << "\n============================\n";
        cout << "   🚀 TASK MANAGER 🚀\n";
        cout << "============================\n";
        cout << "1. ➕ Add Tasks\n";
        cout << "2. 📋 View Tasks\n";
        cout << "3. ✔️ Mark Complete\n";
        cout << "4. 🔍 Filter Tasks\n";
        cout << "5. 💾 Exit\n";
        cout << "============================\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markComplete(tasks); break;
            case 4: filterTasks(tasks); break;
            case 5:
                saveTasks(tasks);
                cout << "\n💾 Tasks saved. Exiting...\n";
                return 0;
            default:
                cout << "\n⚠️ Invalid choice.\n";
        }
    }
}
