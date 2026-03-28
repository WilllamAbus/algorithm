#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(vector<int>& nums1, int m,
                      vector<int>& nums2, int n) {

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    while (j >= 0)
        nums1[k--] = nums2[j--];
}


void run_merge() {
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};

    mergeSortedArray(a, 3, b, 3);

    for (int x : a) cout << x << " ";
    cout << endl;
}