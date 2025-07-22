/*
✅ Problem: Left View of Binary Tree
🔗 Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

🧪 Sample Test Case (GFG):
Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
Output: 1 2 4

🎯 Goal:
- Print the nodes visible from the left view of the binary tree.
- Only one node per level (the first one seen from the left).
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<int> leftView(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i)
            {
                Node *node = q.front();
                q.pop();

                // Add the first node of each level
                if (i == 0)
                    result.push_back(node->data);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return result;
    }
};
