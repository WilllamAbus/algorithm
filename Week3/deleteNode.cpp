#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;

        node->val = next->val; //coppy data
        node->next = next->next; // bypass

        delete next; // tránh memory leak
    }
};

// build list từ vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;

    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// in list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // ===== Example 1 =====
    // Input: [4,5,1,9], node = 5
    ListNode* head1 = buildList({4,5,1,9});

    // lấy node = 5
    ListNode* node1 = head1->next;

    sol.deleteNode(node1);

    cout << "Output Example 1: ";
    printList(head1);  // expected: [4,1,9]


    // ===== Example 2 =====
    // Input: [4,5,1,9], node = 1
    ListNode* head2 = buildList({4,5,1,9});

    // lấy node = 1
    ListNode* node2 = head2->next->next;

    sol.deleteNode(node2);

    cout << "Output Example 2: ";
    printList(head2);  // expected: [4,5,9]

    return 0;
}