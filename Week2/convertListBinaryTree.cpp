#include <iostream>
#include <vector>

using namespace std;

/*========================
  Definition Linked List
=========================*/
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/*========================
  Definition Tree Node
=========================*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*========================
        Solution
=========================*/
class Solution {
public:

    ListNode* findMid(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = nullptr;

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        if (!head) return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* mid = findMid(head);

        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};

/*========================
   Helper: build list
=========================*/
ListNode* buildList(vector<int> nums) {

    if(nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

/*========================
   Print BST (inorder)
=========================*/
void inorder(TreeNode* root) {

    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/*========================
          main
=========================*/
int main() {

    vector<int> nums = {-10,-3,0,5,9};

    ListNode* head = buildList(nums);

    Solution sol;

    TreeNode* root = sol.sortedListToBST(head);

    cout << "Inorder traversal of BST:" << endl;
    inorder(root);

    cout << endl;

    return 0;
}