/*
✅ Problem: Bottom View of Binary Tree
🔗 Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

🧪 Sample Test Case (GFG):
Input:
        20
       /  \
     8     22
    / \      \
   5   3     25
      / \
     10 14
Output: 5 10 3 14 25

🎯 Goal:
- Print the bottom view of the binary tree (nodes visible when viewed from below).
- For each horizontal distance, keep the last node encountered at that HD.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<int> bottomView(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        // Map of horizontal distance -> last node's value at that HD
        map<int, int> hdMap;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            // Always update with the latest node at this horizontal distance
            hdMap[hd] = node->data;

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
