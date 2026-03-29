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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};

ListNode* build(const vector<int>& a) {
    ListNode dummy(0);
    ListNode* t = &dummy;
    for (int x : a) {
        t->next = new ListNode(x);
        t = t->next;
    }
    return dummy.next;
}

void print(ListNode* h) {
    cout << "[";
    while (h) {
        cout << h->val;
        if (h->next) cout << ",";
        h = h->next;
    }
    cout << "]";
}

void freeList(ListNode* h) {
    while (h) {
        auto t = h;
        h = h->next;
        delete t;
    }
}

void runRemoveElements() {
    Solution sol;

    cout << "[ALGO] remove_elements\nRESULT:\n";

    {
        auto h = build({1,2,6,3,4,5,6});
        auto r = sol.removeElements(h, 6);
        print(r); cout << "\n";
        freeList(r);
    }

    {
        auto h = build({});
        auto r = sol.removeElements(h, 1);
        print(r); cout << "\n";
        freeList(r);
    }

    {
        auto h = build({7,7,7});
        auto r = sol.removeElements(h, 7);
        print(r); cout << "\n";
        freeList(r);
    }

    cout << "\n";
}