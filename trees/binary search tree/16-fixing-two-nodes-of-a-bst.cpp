// Problem: Recover Binary Search Tree
// Link: https://leetcode.com/problems/recover-binary-search-tree/

// -------------------------
// ✅ Approach:
// - Use inorder traversal to detect two swapped nodes.
// - Maintain three pointers: first, middle, last (and prev for tracking order).
// - If only two nodes are swapped next to each other → swap first & middle.
// - If far apart → swap first & last.
// Time: O(n), Space: O(h) recursion stack
// -------------------------

class Solution
{
public:
    TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        // Detect anomaly
        if (prev && root->val < prev->val)
        {
            if (!first)
            { // first anomaly
                first = prev;
                middle = root;
            }
            else
            { // second anomaly
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
