#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int x : nums) s.push_back(to_string(x));

        sort(s.begin(), s.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });

        if (s[0] == "0") return "0";

        string res;
        for (auto& str : s) res += str;
        return res;
    }
};

void runLargestNumber() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> v = {10,2};
        cout << sol.largestNumber(v) << "\n";
    }

    {
        vector<int> v = {3,30,34,5,9};
        cout << sol.largestNumber(v) << "\n";
    }

    cout << "\n";
}