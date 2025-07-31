/*
✅ Problem: Diameter of Binary Tree
🔗 Link: https://leetcode.com/problems/diameter-of-binary-tree/

🧪 Sample Test Case:
Input:
        1
       / \
      2   3
     / \
    4   5
Output: 3

🎯 Goal:
- The **diameter** is the length (in edges) of the longest path between any two nodes in the tree.
- This path **does not necessarily** have to pass through the root.

🔍 Approach:
- Use **postorder DFS traversal** to compute the height of left and right subtrees.
- At each node, compute `leftHeight + rightHeight` as the local diameter passing through it.
- Track and update the global maximum diameter.
- Final answer is stored in a global variable.

🛠️ Notes:
- Diameter is measured in **number of edges**, so we don’t count the current node itself in the return value of height.

🕒 Time Complexity: O(N), where N = number of nodes
🛢️ Space Complexity: O(H), where H = height of tree (recursion stack)
*/

class Solution
{
public:
    int maxDiameter = 0;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        // Diameter at this node = edges in left + right subtrees
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Height of subtree rooted at current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxDiameter;
    }
};
