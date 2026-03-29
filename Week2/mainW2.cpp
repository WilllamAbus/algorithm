#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

// forward declare
void run_asteroid();
void run_queue();
void run_bst();
void run_temp();
void run_rpn();
void runQueue();
void runStack();
void runMakeGood();
void runRemoveElements();
void runRemoveDuplicates();

int main(int argc, char* argv[]) {

    unordered_map<string, function<void()>> reg = {
        {"asteroid", run_asteroid},
        {"queue", run_queue},
        {"bst", run_bst},
        {"temp", run_temp},
        {"rpn", run_rpn},
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