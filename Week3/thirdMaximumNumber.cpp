#include "utils/vector_utils.h"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;

        for (int x : nums) {
            if (x == max1 || x == max2 || x == max3) continue;

            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
        }

        return (max3 == LONG_MIN) ? max1 : max3;
    }
};

// ===== RUN =====
void runThirdMax() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> nums = {3,2,1};
        cout << "Output 1: " << sol.thirdMax(nums) << "\n";
    }

    {
        vector<int> nums = {1,2};
        cout << "Output 2: " << sol.thirdMax(nums) << "\n";
    }

    {
        vector<int> nums = {2,2,3,1};
        cout << "Output 3: " << sol.thirdMax(nums) << "\n";
    }
}