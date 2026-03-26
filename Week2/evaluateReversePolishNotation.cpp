#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens, bool debug = false) {
        stack<int> st;

        for (const string& t : tokens) {
            if (t.size() == 1 && isOperator(t[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int res = apply(a, b, t[0]);
                st.push(res);

                if (debug) {
                    cout << "OP: " << a << " " << t << " " << b
                         << " = " << res << " | stack size=" << st.size() << "\n";
                }

            } else {
                int val = stoi(t);
                st.push(val);

                if (debug) {
                    cout << "PUSH: " << val
                         << " | stack size=" << st.size() << "\n";
                }
            }
        }

        return st.top();
    }

private:
    inline bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    inline int apply(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b; // truncate toward 0
        }
        return 0;
    }
};

void runTest(vector<string> tokens, int expected, int id) {
    Solution sol;

    cout << "\n===== Example " << id << " =====\n";
    cout << "Tokens: ";
    for (auto& t : tokens) cout << t << " ";
    cout << "\n\n--- Execution Trace ---\n";

    int result = sol.evalRPN(tokens, true);

    cout << "\n--- Result ---\n";
    cout << "Output  : " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "PASS\n" : "FAIL\n");
}

int main() {
    vector<string> ex1 = {"2","1","+","3","*"};
    vector<string> ex2 = {"4","13","5","/","+"};
    vector<string> ex3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    runTest(ex1, 9, 1);
    runTest(ex2, 6, 2);
    runTest(ex3, 22, 3);

    return 0;
}