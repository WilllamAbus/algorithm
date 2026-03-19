#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string stack;
        stack.reserve(s.size()); // tránh realloc (quan trọng với input lớn)

        for (char c : s) {
            if (!stack.empty() && abs(stack.back() - c) == 32) {
                // conflict → rollback
                stack.pop_back();
            } else {
                // append
                stack.push_back(c);
            }
        }
        return stack;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "leEeetcode";
    string s2 = "abBAcC";
    string s3 = "s";

    cout << "Input: " << s1 << "\nOutput: " << sol.makeGood(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << sol.makeGood(s2) << "\n\n";
    cout << "Input: " << s3 << "\nOutput: " << sol.makeGood(s3) << "\n\n";

    return 0;
}