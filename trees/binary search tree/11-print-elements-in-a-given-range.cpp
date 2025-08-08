// Problem: Print BST Elements in Given Range
// Link: https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

// -------------------------
// ✅ Approach: Inorder Traversal with Range Checks
// Time: O(n), Space: O(h) recursion stack
// -------------------------

class Solution
{
public:
    void inorder(TreeNode *root, int low, int high, vector<int> &res)
    {
        if (!root)
            return;

        // Traverse left subtree only if it might have valid values
        if (root->val > low)
            inorder(root->left, low, high, res);

        // Include current node if it's within range
        if (root->val >= low && root->val <= high)
            res.push_back(root->val);

        // Traverse right subtree only if it might have valid values
        if (root->val < high)
            inorder(root->right, low, high, res);
    }

    vector<int> printNearNodes(TreeNode *root, int low, int high)
    {
        vector<int> res;
        inorder(root, low, high, res);
        return res;
    }
};
