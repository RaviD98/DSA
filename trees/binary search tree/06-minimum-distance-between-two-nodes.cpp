// Problem: Minimum Distance Between BST Nodes
// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// -------------------------
// ✅ Approach: Inorder Traversal (Sorted Property of BST)
// Time: O(n), Space: O(h) → h = height of BST (recursion stack)
// -------------------------

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int minDiff = INT_MAX;
        TreeNode *prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorder(TreeNode *root, TreeNode *&prev, int &minDiff)
    {
        if (!root)
            return;

        inorder(root->left, prev, minDiff);

        if (prev)
            minDiff = min(minDiff, root->val - prev->val);

        prev = root;

        inorder(root->right, prev, minDiff);
    }
};
