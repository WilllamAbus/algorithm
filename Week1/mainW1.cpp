#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

// forward declarations
void runCheckStrings();
void runFindDiff();
void runGroupAnagram();
void runKids();
void runLongest();
void runAvg();
void runMerge();

void runRansom();
void runCircle();
void runValid();

int main(int argc, char* argv[]) {

    unordered_map<string, function<void()>> registry = {
        {"check", runCheckStrings},
        {"diff", runFindDiff},
        {"anagram", runGroupAnagram},
        {"kids", runKids},
        {"longest", runLongest},
        {"avg", runAvg},
        {"merge", runMerge},

        {"ransom", runRansom},
        {"circle", runCircle},
        {"valid", runValid}
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