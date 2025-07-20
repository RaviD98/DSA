/*
✅ Problem: Mirror of a Binary Tree
🔗 Link: https://www.geeksforgeeks.org/problems/mirror-tree/1

🧪 Sample:
Input:
     1
   /   \
  2     3
Output:
     1
   /   \
  3     2

🎯 Goal:
- Convert the given binary tree to its mirror.
- For each node, swap the left and right subtrees.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(h) (due to recursion stack)

    void mirror(Node *root)
    {
        if (!root)
            return;

        // Swap the left and right children
        swap(root->left, root->right);

        // Recurse on left and right subtrees
        mirror(root->left);
        mirror(root->right);
    }
};
