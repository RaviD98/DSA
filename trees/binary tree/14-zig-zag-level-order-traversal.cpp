/*
✅ Problem: Binary Tree Zigzag Level Order Traversal
🔗 Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

🧪 Sample Test Case (Leetcode):
Input:
       1
      / \
     2   3
    / \   \
   4   5   6

Output: [[1], [3,2], [4,5,6]]

🎯 Goal:
- Traverse the binary tree level by level.
- Alternate the direction of traversal at each level (left to right, then right to left, and so on).
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // Place the node's value at the correct index based on direction
                int index = leftToRight ? i : (size - i - 1);
                level[index] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight; // toggle direction
        }

        return result;
    }
};
