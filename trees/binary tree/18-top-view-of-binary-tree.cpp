/*
✅ Problem: Top View of Binary Tree
🔗 Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

🧪 Sample Test Case (GFG):
Input:
        1
      /   \
     2     3
      \
       4
        \
         5
          \
           6
Output: 2 1 3 6

🎯 Goal:
- Print the top view of the binary tree (nodes visible when viewed from above).
- For each horizontal distance from the root, only the first node (from top to bottom) is included.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        // Map to store the first node at each horizontal distance
        map<int, int> hdMap;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            if (hdMap.find(hd) == hdMap.end())
            {
                hdMap[hd] = node->data;
            }

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto &[hd, val] : hdMap)
        {
            result.push_back(val);
        }

        return result;
    }
};
