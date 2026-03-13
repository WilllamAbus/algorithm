#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int last[128];

        for (int i = 0; i < 128; i++)
            last[i] = -1;

        int max_len = 0;
        int L = 0;

        for (int R = 0; R < s.size(); R++) {

            char c = s[R];

            if (last[c] >= L) {
                L = last[c] + 1;
            }

            last[c] = R;

            int len = R - L + 1;

            if (len > max_len)
                max_len = len;
        }

        return max_len;
    }
};

int main() {

    Solution sol;

    // Example 1
    string s1 = "abcabcbb";
    cout << "Example 1: " << sol.lengthOfLongestSubstring(s1) << endl;

    // Example 2
    string s2 = "bbbbb";
    cout << "Example 2: " << sol.lengthOfLongestSubstring(s2) << endl;

    // Example 3
    string s3 = "pwwkew";
    cout << "Example 3: " << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}