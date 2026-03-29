#include "utils/vector_utils.h"
#include <iostream>
#include <vector>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int l = 0, r = n - 1, k = n - 1;

        while (l <= r) {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];

            if (left > right) {
                res[k--] = left;
                l++;
            } else {
                res[k--] = right;
                r--;
            }
        }
        return res;
    }
};

// ===== RUN =====
void runSortedSquares() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> nums = {-4,-1,0,3,10};
        vector<int> res = sol.sortedSquares(nums);

        cout << "Output 1: ";
        printVector(res);
    }

    {
        vector<int> nums = {-7,-3,2,3,11};
        vector<int> res = sol.sortedSquares(nums);

        cout << "Output 2: ";
        printVector(res);
    }
}