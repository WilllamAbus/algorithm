#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int eval(vector<string>& tokens) {
    stack<int> st;

    for (auto& t : tokens) {
        if (t.size()==1 && string("+-*/").find(t)!=string::npos) {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();

            if (t=="+") st.push(a+b);
            else if (t=="-") st.push(a-b);
            else if (t=="*") st.push(a*b);
            else st.push(a/b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}

void run_rpn() {
    vector<string> t = {"2","1","+","3","*"};
    cout << eval(t) << "\n";
}