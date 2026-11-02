/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution
{
    TreeNode prev = null;
    TreeNode first = null;
    TreeNode second = null;

    public void RecoverTree(TreeNode root)
    {
        Inorder(root);

        // Swap the values of the two wrong nodes
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    private void Inorder(TreeNode root)
    {
        if (root == null)
            return;

        Inorder(root.left);

        // In a BST inorder traversal should be increasing.
        // If prev > root, we found a violation.
        if (prev != null && prev.val > root.val)
        {
            if (first == null)
            {
                // First violation
                first = prev;
                second = root;
            }
            else
            {
                // Second violation
                second = root;
            }
        }

        prev = root;

        Inorder(root.right);
    }
}