#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

void runArrayPairSum();
void runContainsDuplicate();
void runDeleteNode();
void runLargestNumber();
void runMissingNumber();
void runPartition();
void runRemoveNth();
void runSortColors();
void runSortedSquares();
void runThirdMax();


int main(int argc, char* argv[]) {

    unordered_map<string, function<void()>> reg = {
        {"pair sum", runArrayPairSum},
        {"contains duplicate", runContainsDuplicate},
        {"delete note", runDeleteNode},
        {"largest number", runLargestNumber},
        {"missing number", runMissingNumber},
        {"partition", runPartition},
        {"remove Nth", runRemoveNth},
        {"sort colors", runSortColors},
        {"sort squares", runSortedSquares},
        {"third max", runThirdMax},
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