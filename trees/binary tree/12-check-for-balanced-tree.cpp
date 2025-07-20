/*
✅ Problem: Balanced Binary Tree
🔗 Link: https://leetcode.com/problems/balanced-binary-tree/

🧪 Sample:
Input: root = [3,9,20,null,null,15,7]
Output: true

🎯 Goal:
- A binary tree is height-balanced if, for every node,
  the height difference between left and right subtree is at most 1.
- Return true if the tree is height-balanced.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)

    // Helper returns height if balanced, else -1
    int checkHeight(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = checkHeight(root->left);
        if (left == -1)
            return -1;

        int right = checkHeight(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        return checkHeight(root) != -1;
    }
};
