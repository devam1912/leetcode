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
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (root == nullptr)
            return;

        // choose current node
        sum += root->val;
        path.push_back(root->val);

        // check only at leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                ans.push_back(path);
            }

            // backtrack
            path.pop_back();
            return;
        }

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);

        // remove current node before going back to parent
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};