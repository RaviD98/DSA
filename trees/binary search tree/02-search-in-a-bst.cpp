// Problem: Search in a Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

// -------------------------
// ✅ Approach 1: Recursive Search
// Time: O(h), Space: O(h) for recursion stack (h = height of BST)
// -------------------------

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

// -------------------------
// ✅ Approach 2: Iterative Search
// Time: O(h), Space: O(1)
// -------------------------

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != nullptr && root->val != val)
        {
            root = (val < root->val) ? root->left : root->right;
        }
        return root;
    }
};
