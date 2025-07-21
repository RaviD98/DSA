/*
✅ Problem: Cousins in Binary Tree
🔗 Link: https://leetcode.com/problems/cousins-in-binary-tree/

🧪 Sample Test Case (Leetcode):
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

🎯 Goal:
- Return true if two nodes (with values x and y) are cousins.
- Cousins: nodes that are at the same level but have different parents.
*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n)
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;

        queue<pair<TreeNode *, TreeNode *>> q; // node, parent
        q.push({root, nullptr});

        while (!q.empty())
        {
            int size = q.size();
            TreeNode *xParent = nullptr;
            TreeNode *yParent = nullptr;

            for (int i = 0; i < size; ++i)
            {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x)
                    xParent = parent;
                if (node->val == y)
                    yParent = parent;

                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});
            }

            // After traversing one level, check if both found
            if (xParent && yParent)
                return xParent != yParent;

            if ((xParent && !yParent) || (!xParent && yParent))
                return false;
        }

        return false;
    }
};
