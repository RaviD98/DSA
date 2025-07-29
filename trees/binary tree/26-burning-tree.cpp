/*
✅ Problem: Burning Tree
🔗 Link: https://www.geeksforgeeks.org/problems/burning-tree/1

🧪 Sample Test Case:
Input:
            1
          /   \
         2     3
        / \     \
       4   5     6
Burning Node: 5
Output: 4

🎯 Goal:
- Given a binary tree and a target node, find the time (in seconds) it takes to burn the entire tree if the fire starts from the target node.
- Fire spreads to adjacent nodes (left child, right child, and parent) in 1 second.

🔍 Approach:
1. Use BFS (level-order traversal) to simulate fire spread.
2. Use a map to store parent references of each node.
3. Use a queue to track burning nodes per level.
*/

class Solution
{
public:
    // Step 1: Create parent mapping and locate the target node
    TreeNode *markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int target, TreeNode *&targetNode)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == target)
                targetNode = curr;

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }

    // Step 2: BFS from target node to simulate fire
    int burnTree(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();

                // Check left
                if (curr->left && !visited[curr->left])
                {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // Check right
                if (curr->right && !visited[curr->right])
                {
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // Check parent
                if (parent[curr] && !visited[parent[curr]])
                {
                    flag = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (flag)
                time++;
        }
        return time;
    }

    int minTime(TreeNode *root, int target)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode *targetNode = nullptr;

        // Step 1: Get parent mapping + target node
        markParents(root, parent, target, targetNode);

        // Step 2: Simulate fire and get time
        return burnTree(targetNode, parent);
    }
};
