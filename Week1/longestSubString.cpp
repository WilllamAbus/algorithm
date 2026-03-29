#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int last[128];
    for (int i = 0; i < 128; i++) last[i] = -1;

    int max_len = 0;
    int L = 0;

    for (int R = 0; R < (int)s.size(); R++) {

    unsigned char c = s[R];

        if (last[c] >= L)
            L = last[c] + 1;

        last[c] = R;

        int len = R - L + 1;
        if (len > max_len) max_len = len;
    }

    return max_len;
}

void runLongest() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
}