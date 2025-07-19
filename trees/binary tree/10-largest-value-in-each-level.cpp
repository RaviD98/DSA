/*
✅ Problem: Find Largest Value in Each Tree Row
🔗 Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

🧪 Sample:
Input:
        1
       / \
      3   2
     / \   \
    5   3   9

Output: [1, 3, 9]

🎯 Goal:
- Return a list of the largest value in each level of a binary tree
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            res.push_back(maxVal);
        }

        return res;
    }
};
