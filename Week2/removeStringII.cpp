#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        st.reserve(s.size());

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                if (++st.back().second == k)
                    st.pop_back();
            } else {
                st.emplace_back(c,1);
            }
        }

        string res;
        res.reserve(s.size());

        for (auto &p : st)
            res.append(p.second, p.first);

        return res;
    }
};

void runRemoveDuplicates() {
    Solution sol;

    cout << "[ALGO] remove_duplicates\nRESULT:\n";
    cout << sol.removeDuplicates("abcd",2) << "\n";
    cout << sol.removeDuplicates("deeedbbcccbdaa",3) << "\n";
    cout << sol.removeDuplicates("pbbcggttciiippooaais",2) << "\n\n";
}