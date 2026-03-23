#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};

/// Build linked list từ vector
ListNode* buildList(const vector<int>& arr) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int x : arr) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

/// In linked list theo format [1,2,3]
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

/// Free memory (quan trọng nếu scale lớn)
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    // ===== Example 1 =====
    {
        vector<int> input = {1,2,6,3,4,5,6};
        int val = 6;

        ListNode* head = buildList(input);
        ListNode* result = sol.removeElements(head, val);

        cout << "Example 1 Output: ";
        printList(result);  // [1,2,3,4,5]

        freeList(result);
    }

    // ===== Example 2 =====
    {
        vector<int> input = {};  // empty list
        int val = 1;

        ListNode* head = buildList(input);
        ListNode* result = sol.removeElements(head, val);

        cout << "Example 2 Output: ";
        printList(result);  // []

        freeList(result);
    }

    // ===== Example 3 =====
    {
        vector<int> input = {7,7,7,7};
        int val = 7;

        ListNode* head = buildList(input);
        ListNode* result = sol.removeElements(head, val);

        cout << "Example 3 Output: ";
        printList(result);  // []

        freeList(result);
    }

    return 0;
}