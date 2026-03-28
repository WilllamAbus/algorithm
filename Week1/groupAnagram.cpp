#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

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

void run_group_anagram() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto res = groupAnagrams(strs);

    for (auto& group : res) {
        cout << "[ ";
        for (auto& s : group) cout << s << " ";
        cout << "]\n";
    }
}