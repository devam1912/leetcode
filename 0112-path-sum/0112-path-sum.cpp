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

    bool dfs(TreeNode* root, int sum, int target)
    {
        if(root == NULL)
            return false;

        // Add current node value
        sum += root->val;

        // If it is a leaf node
        if(root->left == NULL && root->right == NULL)
        {
            return sum == target;
        }

        // Check left or right subtree
        return dfs(root->left, sum, target) ||
               dfs(root->right, sum, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        return dfs(root, 0, targetSum);
    }
};