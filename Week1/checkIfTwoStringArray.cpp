#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int p = 0, q = 0;

        while (i < word1.size() && j < word2.size()) {

            if (word1[i][p] != word2[j][q])
                return false;

            p++;
            q++;

            if (p == word1[i].size()) {
                i++;
                p = 0;
            }

            if (q == word2[j].size()) {
                j++;
                q = 0;
            }
        }

        return i == word1.size() && j == word2.size();
    }
};

int main() {

    Solution sol;

    // Example 1
    vector<string> word1_1 = {"ab", "c"};
    vector<string> word2_1 = {"a", "bc"};

    cout << "Example 1: ";
    cout << (sol.arrayStringsAreEqual(word1_1, word2_1) ? "true" : "false") << endl;

    // Example 2
    vector<string> word1_2 = {"a", "cb"};
    vector<string> word2_2 = {"ab", "c"};

    cout << "Example 2: ";
    cout << (sol.arrayStringsAreEqual(word1_2, word2_2) ? "true" : "false") << endl;

    // Example 3
    vector<string> word1_3 = {"abc", "d", "defg"};
    vector<string> word2_3 = {"abcddefg"};

    cout << "Example 3: ";
    cout << (sol.arrayStringsAreEqual(word1_3, word2_3) ? "true" : "false") << endl;

    return 0;
}