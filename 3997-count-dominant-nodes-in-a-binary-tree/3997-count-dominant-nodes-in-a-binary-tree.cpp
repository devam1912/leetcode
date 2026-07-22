/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int cnt(TreeNode* root) {
        if (root == nullptr)
            return INT_MIN;

        int left = cnt(root->left);
        int right = cnt(root->right);

        if (root->val >= max(left, right)) {
            ans++;
        }

        return max(root->val, max(left, right));
    }

    int countDominantNodes(TreeNode* root) {
        ans = 0;
        cnt(root);
        return ans;
    }
};