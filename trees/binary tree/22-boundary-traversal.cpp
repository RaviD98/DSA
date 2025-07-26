/*
✅ Problem: Boundary Traversal of Binary Tree
🔗 Link: https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

🧪 Sample Test Case (GFG Style):
Input:
          20
         /  \
        8   22
       / \    \
      4  12    25
         / \
        10 14
Output: 20 8 4 10 14 25 22

🎯 Goal:
- Print all boundary nodes in anti-clockwise order starting from root.
- Include:
  1. Left boundary (excluding leaves)
  2. All leaf nodes (from left to right)
  3. Right boundary (excluding leaves, bottom-up)
*/

class Solution
{
public:
    bool isLeaf(TreeNode *node)
    {
        return (node->left == nullptr && node->right == nullptr);
    }

    void addLeftBoundary(TreeNode *node, vector<int> &res)
    {
        TreeNode *curr = node->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRightBoundary(TreeNode *node, vector<int> &res)
    {
        TreeNode *curr = node->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->val);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        // Add in reverse order
        for (int i = temp.size() - 1; i >= 0; --i)
            res.push_back(temp[i]);
    }

    void addLeaves(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        if (isLeaf(node))
        {
            res.push_back(node->val);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
