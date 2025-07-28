/*
✅ Problem: Morris Traversal (Inorder Traversal without recursion or stack)
🔗 Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

🧪 Sample Test Case:
Input: [1, null, 2, 3]
Output: [1, 3, 2]

🎯 Goal:
- Traverse a binary tree in **inorder** without using recursion or stack.
- Use Morris Traversal technique which modifies tree temporarily and restores it back.
*/

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // No left child, visit node and go right
            result.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of current
            TreeNode *pred = curr->left;
            while (pred->right != nullptr && pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == nullptr)
            {
                // Make thread: connect right of predecessor to current
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // Thread already exists, remove it and visit current
                pred->right = nullptr;
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return result;
}
