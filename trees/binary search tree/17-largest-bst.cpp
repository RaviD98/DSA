// Problem: Largest BST Subtree
// Link: https://leetcode.com/problems/largest-bst-subtree/

// -------------------------
// ✅ Approach:
// - Use postorder traversal to gather info from subtrees.
// - For each node, track: min, max, size, and BST validity.
// - If subtree is BST → update max size.
// Time: O(n), Space: O(h) recursion stack
// -------------------------

class Solution
{
public:
    struct Info
    {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    int maxSize = 0;

    Info solve(TreeNode *root)
    {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal)
        {
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);
            maxSize = max(maxSize, curr.size);
        }
        else
        {
            curr.isBST = false;
            curr.size = max(left.size, right.size);
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }

    int largestBSTSubtree(TreeNode *root)
    {
        solve(root);
        return maxSize;
    }
};
