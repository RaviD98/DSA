/*
✅ Problem: Binary Tree Maximum Path Sum
🔗 Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

🧪 Sample Test Case:
Input:
        -10
        /  \
       9   20
           / \
         15   7
Output: 42

🎯 Goal:
- Find the path in the tree which gives the maximum sum.
- A path is any sequence of nodes from some starting node to any node in the tree following parent-child connections.
- The path **must contain at least one node** and does **not need to go through the root**.

🔍 Approach:
1. Use **postorder traversal** to calculate maximum gain from left and right child.
2. At each node, calculate the **max path sum including that node as the root**.
3. Keep updating a global `maxSum`.
4. For parent recursion, return only the **maximum single path sum** (not both left and right), as path cannot fork upwards.

⏱ Time Complexity: O(N), where N is the number of nodes.
*/

class Solution
{
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        // Get max gain from left and right (ignore negatives)
        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // Calculate path sum with root as highest node (can fork here)
        int localSum = root->val + leftGain + rightGain;

        // Update global maxSum
        maxSum = max(maxSum, localSum);

        // Return max path sum going upwards (single direction only)
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxSum;
    }
};
