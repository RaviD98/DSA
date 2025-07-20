/*
✅ Problem: Same Tree
🔗 Link: https://leetcode.com/problems/same-tree/

🧪 Sample:
Input:
Tree 1:    1         Tree 2:    1
          / \                  / \
         2   3                2   3

Output: true

🎯 Goal:
- Return true if both binary trees are structurally identical and nodes have the same values
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true; // Both null
        if (!p || !q || p->val != q->val)
            return false; // Mismatch

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
