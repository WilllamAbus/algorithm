#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

        // critical: tránh cycle
        greater->next = nullptr;

        // nối 2 list
        less->next = greater_dummy.next;

        return less_dummy.next;
    }
};

// ===== HELPER =====

// build linked list từ vector
ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// in list theo format LeetCode
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

// free memory (production mindset)
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// ===== MAIN =====
int main() {
    Solution sol;

    // ===== Example 1 =====
    vector<int> input1 = {1,4,3,2,5,2};
    int x1 = 3;

    ListNode* head1 = buildList(input1);
    ListNode* result1 = sol.partition(head1, x1);

    cout << "Output 1: ";
    printList(result1);  // expected: [1,2,2,4,3,5]

    freeList(result1);

    // ===== Example 2 =====
    vector<int> input2 = {2,1};
    int x2 = 2;

    ListNode* head2 = buildList(input2);
    ListNode* result2 = sol.partition(head2, x2);

    cout << "Output 2: ";
    printList(result2);  // expected: [1,2]

    freeList(result2);

    return 0;
}