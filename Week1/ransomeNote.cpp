#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int freq[26] = {0};

    for (char c : magazine)
        freq[c - 'a']++;

    for (char c : ransomNote) {
        if (--freq[c - 'a'] < 0)
            return false;
    }

    return true;
}

void runRansom() {
    cout << (canConstruct("a", "b") ? "true" : "false") << endl;
    cout << (canConstruct("aa", "ab") ? "true" : "false") << endl;
    cout << (canConstruct("aa", "aab") ? "true" : "false") << endl;
}