#include "utils/list_utils.h"
#include <iostream>
#include <vector>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_dummy(0);
        ListNode greater_dummy(0);

        ListNode* less = &less_dummy;
        ListNode* greater = &greater_dummy;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // tránh cycle
        greater->next = nullptr;

        // nối 2 list
        less->next = greater_dummy.next;

        return less_dummy.next;
    }
};

// ===== RUN =====
void runPartition() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> input = {1,4,3,2,5,2};
        int x = 3;

        ListNode* head = buildList(input);
        ListNode* result = sol.partition(head, x);

        cout << "Output 1: ";
        printList(result);

        freeList(result);
    }

    {
        vector<int> input = {2,1};
        int x = 2;

        ListNode* head = buildList(input);
        ListNode* result = sol.partition(head, x);

        cout << "Output 2: ";
        printList(result);

        freeList(result);
    }
}