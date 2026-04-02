/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both are NULL
        if (p == nullptr && q == nullptr) return true;

        // Case 2: one is NULL
        if (p == nullptr || q == nullptr) return false;

        // Case 3: values are different
        if (p->val != q->val) return false;

        // Recursive check for left and right subtree
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};