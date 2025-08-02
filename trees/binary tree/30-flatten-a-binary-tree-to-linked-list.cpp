/*
✅ Problem: Flatten Binary Tree to Linked List
🔗 Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

🧪 Sample Test Case:
Input:
        1
       / \
      2   5
     / \   \
    3   4   6
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

🎯 Goal:
- Flatten the binary tree to a "linked list" **in-place**.
- The "linked list" should use the right pointers.
- Order must follow **preorder traversal** (root-left-right).

🔍 Approach:
- Use **reverse postorder traversal** (right → left → root).
- Keep a pointer `prev` which points to the previously processed node.
- At each node:
    1. Recursively flatten right and left subtrees.
    2. Set current node’s right to `prev` and left to `nullptr`.
    3. Update `prev` to current node.

🛠️ Why reverse postorder?
- Since we build the list from the back (end to front), we need to process the right subtree before the left.

🕒 Time Complexity: O(N)
🛢️ Space Complexity: O(H), due to recursion stack
*/

class Solution
{
private:
    TreeNode *prev = nullptr;

    void flattenTree(TreeNode *root)
    {
        if (!root)
            return;

        flattenTree(root->right);
        flattenTree(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

public:
    void flatten(TreeNode *root)
    {
        flattenTree(root);
    }
};
