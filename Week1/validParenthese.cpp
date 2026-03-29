#include <iostream>
#include <string>
using namespace std;

bool isValid(string s) {
    char st[10000];
    int top = -1;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st[++top] = c;
        } else {
            if (top < 0) return false;

            char t = st[top--];

            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
        }
    }

    return top == -1;
}

void runValid() {
    cout << (isValid("()") ? "true" : "false") << endl;
    cout << (isValid("(]") ? "true" : "false") << endl;
}