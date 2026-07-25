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
    TreeNode* prev = nullptr;
    bool ans = true;

    void inorder(TreeNode* root)
    {
        if (root == nullptr)
            return;

        // Traverse left subtree
        inorder(root->left);

        // Process current node
        if (prev == nullptr)
        {
            prev = root;
        }
        else
        {
            if (root->val <= prev->val)
                ans = false;

            prev = root;
        }

        // Traverse right subtree
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root)
    {
        inorder(root);
        return ans;
    }
};