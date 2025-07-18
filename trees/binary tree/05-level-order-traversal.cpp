/*

✅ Problem: Binary Tree Level Order Traversal
🔗 Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

🎯 Goal:
- Traverse the binary tree level by level (top to bottom, left to right)
- Return a vector of vectors where each vector is a level

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// --------------------------
// 🌳 Tree Node definition
// --------------------------
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---------------------------------------------------------------------
// 🔁 Iterative Level Order Traversal using Queue (BFS)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// ---------------------------------------------------------------------
vector<vector<int>> levelOrderIterative(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

// ---------------------------------------------------------------------
// 🧠 Recursive Level Order Traversal using DFS + level tracking
// 🕒 Time: O(n), 🛢️ Space: O(n) for recursion stack
// ---------------------------------------------------------------------
void dfs(TreeNode *node, int level, vector<vector<int>> &result)
{
    if (!node)
        return;

    if (result.size() == level)
    {
        result.push_back({});
    }

    result[level].push_back(node->val);

    dfs(node->left, level + 1, result);
    dfs(node->right, level + 1, result);
}

vector<vector<int>> levelOrderRecursive(TreeNode *root)
{
    vector<vector<int>> result;
    dfs(root, 0, result);
    return result;
}

// 🔽 Example Driver Code
int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    auto rec = levelOrderRecursive(root);
    auto itr = levelOrderIterative(root);

    cout << "Recursive Level Order:\n";
    for (auto &level : rec)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    cout << "\nIterative Level Order:\n";
    for (auto &level : itr)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
