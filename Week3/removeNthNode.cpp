#include "utils/list_utils.h"
#include <iostream>
#include <vector>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // move fast trước n bước
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // giữ khoảng cách n
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // xóa node
        ListNode* target = slow->next;
        slow->next = target->next;

        delete target;
        return dummy.next;
    }
};

// ===== RUN =====
void runRemoveNth() {
    Solution sol;

    cout << "RESULT:\n";

    {
        vector<int> v = {1,2,3,4,5};
        int n = 2;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Output 1: ";
        printList(head);

        freeList(head);
    }

    {
        vector<int> v = {1};
        int n = 1;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Output 2: ";
        printList(head);

        freeList(head);
    }

    {
        vector<int> v = {1,2};
        int n = 1;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Output 3: ";
        printList(head);

        freeList(head);
    }
}