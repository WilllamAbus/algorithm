#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (size_t i = 0; i + 1 < q.size(); ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

void runStack() {
    MyStack s;
    vector<string> out;

    out.push_back("null");
    s.push(1); out.push_back("null");
    s.push(2); out.push_back("null");
    out.push_back(to_string(s.top()));
    out.push_back(to_string(s.pop()));
    out.push_back(s.empty() ? "true" : "false");

    cout << "[ALGO] stack_queue\nRESULT: [";
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i];
        if (i + 1 < out.size()) cout << ", ";
    }
    cout << "]\n\n";
}