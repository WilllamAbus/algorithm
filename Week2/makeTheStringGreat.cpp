#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string st;
        st.reserve(s.size());

        for (char c : s) {
            if (!st.empty() && abs(st.back() - c) == 32)
                st.pop_back();
            else
                st.push_back(c);
        }
        return st;
    }
};

void runMakeGood() {
    Solution sol;

    cout << "[ALGO] make_good\n";
    cout << "RESULT:\n";
    cout << sol.makeGood("leEeetcode") << "\n";
    cout << sol.makeGood("abBAcC") << "\n";
    cout << sol.makeGood("s") << "\n\n";
}