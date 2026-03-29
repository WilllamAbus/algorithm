#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

void runKids() {
    vector<int> candies = {2,3,5,1,3};
    int extra = 3;

    auto res = kidsWithCandies(candies, extra);

    for (bool b : res)
        cout << (b ? "true " : "false ");
    cout << endl;
}