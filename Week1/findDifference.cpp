#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for (char c : s) {
            result ^= c;
        }

        for (char c : t) {
            result ^= c;
        }

        return result;
    }
};

int main() {

    Solution sol;

    // Example 1
    string s1 = "abcd";
    string t1 = "abcde";

    cout << "Example 1: ";
    cout << sol.findTheDifference(s1, t1) << endl;

    // Example 2
    string s2 = "";
    string t2 = "y";

    cout << "Example 2: ";
    cout << sol.findTheDifference(s2, t2) << endl;

    return 0;
}