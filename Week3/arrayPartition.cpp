#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

void runArrayPairSum() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> v = {1,4,3,2};
        cout << sol.arrayPairSum(v) << "\n";
    }

    {
        vector<int> v = {6,2,6,5,1,2};
        cout << sol.arrayPairSum(v) << "\n";
    }

    cout << "\n";
}