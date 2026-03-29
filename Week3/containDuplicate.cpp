#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x)) return true;
            s.insert(x);
        }
        return false;
    }
};

void runContainsDuplicate() {
    Solution sol;

    cout << "RESULT:\n";

    vector<vector<int>> tests = {
        {1,2,3,1},
        {1,2,3,4},
        {1,1,1,3,3,4,3,2,4,2}
    };

    for (auto& v : tests) {
        cout << (sol.containsDuplicate(v) ? "true" : "false") << "\n";
    }

    cout << "\n";
}