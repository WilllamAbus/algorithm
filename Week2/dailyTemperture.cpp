#include <iostream>
#include <vector>
using namespace std;

vector<int> daily(vector<int>& T) {
    int n = T.size();
    vector<int> res(n);
    vector<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[i] > T[st.back()]) {
            int j = st.back(); st.pop_back();
            res[j] = i - j;
        }
        st.push_back(i);
    }
    return res;
}

void run_temp() {
    vector<int> t = {73,74,75,71,69,72,76,73};
    auto r = daily(t);

    for (int x : r) cout << x << " ";
    cout << "\n";
}