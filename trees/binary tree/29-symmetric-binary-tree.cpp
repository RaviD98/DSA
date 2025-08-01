/*
✅ Problem: Symmetric Tree
🔗 Link: https://leetcode.com/problems/symmetric-tree/

🧪 Sample Test Case:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

🎯 Goal:
- Check whether a binary tree is **mirror symmetric** around its center.
- In other words, the left and right subtrees should be mirror images of each other.

🔍 Approach:
- Use **recursive DFS** to compare left and right subtrees.
- For symmetry:
   → Left subtree of left node should be mirror of right subtree of right node.
   → Right subtree of left node should be mirror of left subtree of right node.
- If all mirrored nodes match in value and structure, the tree is symmetric.

🕒 Time Complexity: O(N), where N = number of nodes
🛢️ Space Complexity: O(H), where H = height of the tree (recursion stack)
*/

class Solution
{
public:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true; // both null
        if (!left || !right)
            return false; // only one null
        if (left->val != right->val)
            return false;

        // Check mirrored children
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};
