/*
✅ Problem: Diagonal Traversal of Binary Tree
🔗 Link: https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

🧪 Sample Test Case:
Input:
           8
         /   \
        3     10
       / \      \
      1   6      14
         / \     /
        4   7   13

Output:
8 10 14
3 6 7 13
1 4

🎯 Goal:
- Traverse the binary tree diagonally.
- Nodes with the same diagonal distance from the root appear together.
- Right child stays on the same diagonal, left child moves to the next diagonal.
*/

vector<vector<int>> diagonalTraversal(Node *root)
{
    if (!root)
        return {};

    map<int, vector<int>> diagonalMap; // diagonal -> list of node values
    queue<pair<Node *, int>> q;        // node, diagonal level
    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, d] = q.front();
        q.pop();

        diagonalMap[d].push_back(node->data);

        if (node->left)
            q.push({node->left, d + 1}); // left child → next diagonal
        if (node->right)
            q.push({node->right, d}); // right child → same diagonal
    }

    vector<vector<int>> result;
    for (auto &[d, nodes] : diagonalMap)
    {
        result.push_back(nodes);
    }

    return result;
}
