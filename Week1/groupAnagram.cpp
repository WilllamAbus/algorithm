#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> table;

        for (string s : strs) {

            string key = s;

            sort(key.begin(), key.end());

            table[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& p : table) {
            result.push_back(move(p.second));
        }

        return result;
    }
};

void printGroups(const vector<vector<string>>& groups) {

    cout << "[";

    for (size_t i = 0; i < groups.size(); i++) {

        cout << "[";

        for (size_t j = 0; j < groups[i].size(); j++) {

            cout << "\"" << groups[i][j] << "\"";

            if (j != groups[i].size() - 1)
                cout << ",";
        }

        cout << "]";

        if (i != groups.size() - 1)
            cout << ",";
    }

    cout << "]\n";
}

int main() {

    Solution sol;

    // Example 1
    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};

    cout << "Example 1:\n";
    printGroups(sol.groupAnagrams(strs1));

    // Example 2
    vector<string> strs2 = {""};

    cout << "Example 2:\n";
    printGroups(sol.groupAnagrams(strs2));

    // Example 3
    vector<string> strs3 = {"a"};

    cout << "Example 3:\n";
    printGroups(sol.groupAnagrams(strs3));

    return 0;
}