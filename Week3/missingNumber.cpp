#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expect = 1LL * n * (n + 1) / 2;

        long long sum = 0;
        for (int x : nums) sum += x;

        return (int)(expect - sum);
    }
};

void runMissingNumber() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> v = {3,0,1};
        cout << sol.missingNumber(v) << "\n";
    }

    {
        vector<int> v = {0,1};
        cout << sol.missingNumber(v) << "\n";
    }

    {
        vector<int> v = {9,6,4,2,3,5,7,0,1};
        cout << sol.missingNumber(v) << "\n";
    }

    cout << "\n";
}