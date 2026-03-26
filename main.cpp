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

