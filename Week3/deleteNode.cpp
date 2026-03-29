#include "utils/list_utils.h"
#include <iostream>
#include <vector>
using namespace std;

// ===== SOLUTION =====
class Solution {
public:
    void deleteNode(ListNode* node) {
        // bài này đảm bảo node không phải tail
        ListNode* nxt = node->next;

        node->val = nxt->val;
        node->next = nxt->next;

        delete nxt;
    }
};

// ===== RUN =====
void runDeleteNode() {
    Solution sol;

    cout << "RESULT:\n";

    {
        ListNode* h = buildList({4,5,1,9});
        sol.deleteNode(h->next);

        printList(h); cout << "\n";
        freeList(h);
    }

    {
        ListNode* h = buildList({4,5,1,9});
        sol.deleteNode(h->next->next);

        printList(h); cout << "\n";
        freeList(h);
    }

    cout << "\n";
}