#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char st[10000];
        int top = -1;

        for (char c : s) {

            if (c == '(' || c == '[' || c == '{') {
                st[++top] = c;
            } else {

                if (top < 0)
                    return false;

                char t = st[top--];

                if (c == ')' && t != '(')
                    return false;
                if (c == ']' && t != '[')
                    return false;
                if (c == '}' && t != '{')
                    return false;
            }
        }

        return top == -1;
    }
};

int main() {

    Solution sol;
    string s;

    while (cin >> s) {
        cout << (sol.isValid(s) ? "true" : "false") << endl;
    }

    return 0;
}