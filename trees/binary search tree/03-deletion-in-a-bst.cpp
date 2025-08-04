// Problem: Delete Node in a BST
// Link: https://leetcode.com/problems/delete-node-in-a-bst/

// -------------------------
// ✅ Approach: Recursive Deletion
// Time: O(h), Space: O(h) for recursion stack (h = height of BST)
// -------------------------

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Node with one child or no child
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            // Node with two children:
            // Get the inorder successor (smallest in the right subtree)
            TreeNode *successor = minValueNode(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }

private:
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
};
