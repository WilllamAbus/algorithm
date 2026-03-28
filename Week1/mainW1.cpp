#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

// forward declarations
void run_check_strings();
void run_find_diff();
void run_group_anagram();
void run_kids();
void run_longest();
void run_avg();
void run_merge();

void run_ransom();
void run_circle();
void run_valid();

int main(int argc, char* argv[]) {

    unordered_map<string, function<void()>> registry = {
        {"check", run_check_strings},
        {"diff", run_find_diff},
        {"anagram", run_group_anagram},
        {"kids", run_kids},
        {"longest", run_longest},
        {"avg", run_avg},
        {"merge", run_merge},

        {"ransom", run_ransom},
        {"circle", run_circle},
        {"valid", run_valid}
    };

    if (argc < 2) {
        cout << "Usage: ./mainW1 <algo>\n";
        cout << "Available:\n";
        for (auto& [k, _] : registry)
            cout << "  - " << k << "\n";
        return 1;
    }

    string cmd = argv[1];

    auto it = registry.find(cmd);
    if (it != registry.end()) {
        it->second();
    } else {
        cout << "Unknown: " << cmd << "\n";
    }

    return 0;
}