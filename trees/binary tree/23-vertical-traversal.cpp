/*
✅ Problem: Vertical Order Traversal of a Binary Tree
🔗 Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

🧪 Sample Test Case (LeetCode Style):
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

🎯 Goal:
- Return vertical order traversal from leftmost to rightmost verticals.
- Within the same vertical:
  - Nodes should appear top-to-bottom.
  - If multiple nodes share the same row and column, order them by value.
*/

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // map<x-coordinate, map<y-coordinate, multiset of node values>>
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode *, int, int>> q; // node, x, y
        q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [node, x, y] = q.front();
            q.pop();
            nodes[x][y].insert(node->val);
            if (node->left)
                q.push({node->left, x - 1, y + 1});
            if (node->right)
                q.push({node->right, x + 1, y + 1});
        }

        vector<vector<int>> result;
        for (auto &[x, yMap] : nodes)
        {
            vector<int> col;
            for (auto &[y, vals] : yMap)
            {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
