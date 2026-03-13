#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for(char c : magazine) {
            freq[c - 'a']++;
        }

        for(char c : ransomNote) {
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};

int main() {

    Solution sol;

    // Example 1
    string ransom1 = "a";
    string magazine1 = "b";
    cout << "Example 1: "
         << (sol.canConstruct(ransom1, magazine1) ? "true" : "false")
         << endl;

    // Example 2
    string ransom2 = "aa";
    string magazine2 = "ab";
    cout << "Example 2: "
         << (sol.canConstruct(ransom2, magazine2) ? "true" : "false")
         << endl;

    // Example 3
    string ransom3 = "aa";
    string magazine3 = "aab";
    cout << "Example 3: "
         << (sol.canConstruct(ransom3, magazine3) ? "true" : "false")
         << endl;

    return 0;
}