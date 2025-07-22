/*
✅ Problem: Right View of Binary Tree
🔗 Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

🧪 Sample Test Case (GFG):
Input:
        1
      /   \
     2     3
      \     \
       5     4
Output: 1 3 4

🎯 Goal:
- Print the nodes visible from the right side of the binary tree.
- Only the last node of each level is visible from the right.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<int> rightView(Node *root)
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

                // Store the last node of each level
                if (i == levelSize - 1)
                {
                    result.push_back(node->data);
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return result;
    }
};
