#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;

        for (int c : candies)
            maxCandies = max(maxCandies, c);

        vector<bool> result;
        result.reserve(candies.size());

        for (int c : candies) {
            result.push_back(c + extraCandies >= maxCandies);
        }

        return result;
    }
};

void printResult(const vector<bool>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << (v[i] ? "true" : "false");
        if (i != v.size() - 1)
            cout << ",";
    }
    cout << "]\n";
}

int main() {

    Solution sol;

    // Example 1
    vector<int> candies1 = {2,3,5,1,3};
    int extra1 = 3;

    cout << "Example 1: ";
    printResult(sol.kidsWithCandies(candies1, extra1));

    // Example 2
    vector<int> candies2 = {4,2,1,1,2};
    int extra2 = 1;

    cout << "Example 2: ";
    printResult(sol.kidsWithCandies(candies2, extra2));

    // Example 3
    vector<int> candies3 = {12,1,12};
    int extra3 = 10;

    cout << "Example 3: ";
    printResult(sol.kidsWithCandies(candies3, extra3));

    return 0;
}