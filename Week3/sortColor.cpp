#include "utils/vector_utils.h"
#include <iostream>
#include <vector>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};

// ===== RUN =====
void runSortColors() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> nums = {2,0,2,1,1,0};
        sol.sortColors(nums);

        cout << "Output 1: ";
        printVector(nums);
    }

    {
        vector<int> nums = {2,0,1};
        sol.sortColors(nums);

        cout << "Output 2: ";
        printVector(nums);
    }
}