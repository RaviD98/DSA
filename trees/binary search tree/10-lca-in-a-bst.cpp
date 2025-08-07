// Problem: Lowest Common Ancestor of a BST
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// -------------------------
// ✅ Approach: BST Property Based Traversal
// Time: O(h), Space: O(1) if iterative / O(h) recursion stack
// -------------------------

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};
