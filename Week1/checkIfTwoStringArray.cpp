#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    size_t i = 0, j = 0;
    size_t p = 0, q = 0;

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

void runCheckStrings() {
    vector<string> w1 = {"ab", "c"};
    vector<string> w2 = {"a", "bc"};

    cout << (arrayStringsAreEqual(w1, w2) ? "true" : "false") << endl;
}