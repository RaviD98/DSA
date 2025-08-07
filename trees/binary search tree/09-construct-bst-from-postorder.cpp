// Problem: Construct BST from Postorder Traversal

// -------------------------
// ✅ Approach: BST Bound Method (Efficient)
// Time: O(n), Space: O(n) for recursion stack
// -------------------------

class Solution
{
public:
    TreeNode *constructBSTFromPostorder(vector<int> &postorder)
    {
        int index = postorder.size() - 1;
        return build(postorder, index, INT_MIN);
    }

private:
    TreeNode *build(vector<int> &postorder, int &index, int lowerBound)
    {
        if (index < 0 || postorder[index] < lowerBound)
            return nullptr;

        int val = postorder[index--];
        TreeNode *root = new TreeNode(val);

        // Build right subtree first because postorder is LRN (left-right-root),
        // and we're iterating from end, so it's root-right-left
        root->right = build(postorder, index, val);
        root->left = build(postorder, index, lowerBound);

        return root;
    }
};
