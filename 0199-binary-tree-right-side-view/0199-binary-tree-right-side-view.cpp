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

    vector<int> ans;

    void dfs(TreeNode* node, int level)
    {
        if(node == NULL)
            return;

        // First node reached at this level is the rightmost node
        if(level == ans.size())
            ans.push_back(node->val);

        // Visit right subtree first
        dfs(node->right, level + 1);

        // Then visit left subtree
        dfs(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {

        dfs(root, 0);

        return ans;
    }
};