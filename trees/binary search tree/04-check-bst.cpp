// Problem: Validate Binary Search Tree
// Link: https://leetcode.com/problems/validate-binary-search-tree/

// -------------------------
// ✅ Approach: Recursive with Min-Max Range
// Time: O(n), Space: O(h) where h = height of tree
// -------------------------

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode *node, long minVal, long maxVal)
    {
        if (!node)
            return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};
