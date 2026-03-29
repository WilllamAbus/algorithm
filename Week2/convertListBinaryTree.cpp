#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

ListNode* build(vector<int>& a) {
    ListNode* h = new ListNode(a[0]);
    ListNode* cur = h;
    size_t n = a.size();
    for (size_t i = 1; i < n; ++i) {
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    return h;
}

void inorder(TreeNode* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

TreeNode* solve(ListNode* h) {
    if (!h) return nullptr;
    if (!h->next) return new TreeNode(h->val);

    ListNode *slow=h, *fast=h, *prev=nullptr;
    while (fast && fast->next) {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if (prev) prev->next=nullptr;

    TreeNode* root = new TreeNode(slow->val);
    root->left = solve(h);
    root->right = solve(slow->next);

    return root;
}

void runBst() {
    vector<int> a = {-10,-3,0,5,9};
    ListNode* h = build(a);
    TreeNode* r = solve(h);

    inorder(r);
    cout << "\n";
}