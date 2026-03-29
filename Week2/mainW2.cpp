#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

// forward declare
void runAsteroid();
void runCircularQueue();
void runBst();
void runTemp();
void runRpn();
void runQueue();
void runStack();
void runMakeGood();
void runRemoveElements();
void runRemoveDuplicates();

int main(int argc, char* argv[]) {

    unordered_map<string, function<void()>> reg = {
        {"asteroid", runAsteroid},
        {"queue", runCircularQueue},
        {"bst", runBst},
        {"temp", runTemp},
        {"rpn", runRpn},
        {"queueUsingStack", runQueue},
        {"stackUsingQueue", runStack},
        {"makeGood", runMakeGood},
        {"move elements", runRemoveElements},
        {"move duplicate", runRemoveDuplicates},
    };

    if (argc < 2) {
        cout << "Usage: ./mainW2 <algo|all>\n";
        for (auto& [k,_]:reg) cout << " - " << k << "\n";
        return 1;
    }

    string cmd = argv[1];

    if (cmd == "all") {
        for (auto& [k,f]:reg) {
            cout << "==== " << k << " ====\n";
            f();
        }
        return 0;
    }

    auto it = reg.find(cmd);
    if (it != reg.end()) it->second();
    else cout << "Unknown\n";
}