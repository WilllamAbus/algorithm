#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ================= SOLUTION =================
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // tạo gap n
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // chạy cùng nhau
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // delete node
        ListNode* target = slow->next;
        slow->next = target->next;

        delete target;

        return dummy.next;
    }
};

// ================= HELPER =================

// build linked list từ vector
ListNode* buildList(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return dummy.next;
}

// in linked list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

// free memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// ================= MAIN =================

int main() {
    Solution sol;

    // ===== Example 1 =====
    {
        vector<int> v = {1,2,3,4,5};
        int n = 2;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Example 1 Output: ";
        printList(head); // [1,2,3,5]

        freeList(head);
    }

    // ===== Example 2 =====
    {
        vector<int> v = {1};
        int n = 1;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Example 2 Output: ";
        printList(head); // []

        freeList(head);
    }

    // ===== Example 3 =====
    {
        vector<int> v = {1,2};
        int n = 1;

        ListNode* head = buildList(v);
        head = sol.removeNthFromEnd(head, n);

        cout << "Example 3 Output: ";
        printList(head); // [1]

        freeList(head);
    }

    return 0;
}