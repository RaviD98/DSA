/*
✅ Problem: Sum of Binary Tree
🔗 Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1

🧪 Sample:
Input:
       1
     /   \
    2     3

Output: 6

🎯 Goal:
- Return the sum of all nodes' values in a binary tree
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(h) — where h is the height of the tree (recursion stack)

    int sumBT(Node *root)
    {
        if (root == nullptr)
            return 0;

        int leftSum = sumBT(root->left);
        int rightSum = sumBT(root->right);

        return root->data + leftSum + rightSum;
    }
};
