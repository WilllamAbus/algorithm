#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        st.reserve(s.size());

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back(); // rollback
                }
            } else {
                st.emplace_back(c, 1);
            }
        }

        string result;
        result.reserve(s.size());

        for (auto &[ch, cnt] : st) {
            result.append(cnt, ch);
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    {
        string s = "abcd";
        int k = 2;
        cout << sol.removeDuplicates(s, k) << "\n"; // abcd
    }

    // Example 2
    {
        string s = "deeedbbcccbdaa";
        int k = 3;
        cout << sol.removeDuplicates(s, k) << "\n"; // aa
    }

    // Example 3
    {
        string s = "pbbcggttciiippooaais";
        int k = 2;
        cout << sol.removeDuplicates(s, k) << "\n"; // ps
    }

    return 0;
}