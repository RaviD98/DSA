/*

✅ Problem: Binary Tree Postorder Traversal
🔗 Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

🎯 Goal:
- Return the postorder traversal of a binary tree's nodes' values.
- Postorder = [left, right, root]

*/

#include <iostream>
#include <vector>
#include <stack>
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

// -------------------------------------------------------------
// 🧠 Recursive Postorder Traversal
// 🕒 Time: O(n), 🛢️ Space: O(n) recursion stack
// -------------------------------------------------------------
void postorderRecursive(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    postorderRecursive(root->left, result);  // Visit left
    postorderRecursive(root->right, result); // Visit right
    result.push_back(root->val);             // Visit root
}

vector<int> postorderTraversalRecursive(TreeNode *root)
{
    vector<int> result;
    postorderRecursive(root, result);
    return result;
}

// -------------------------------------------------------------
// 🔁 Iterative Postorder Traversal using 2 stacks
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -------------------------------------------------------------
vector<int> postorderTraversalIterative(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    stack<TreeNode *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        result.push_back(s2.top()->val);
        s2.pop();
    }

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

    vector<int> rec = postorderTraversalRecursive(root);
    vector<int> itr = postorderTraversalIterative(root);

    cout << "Recursive Postorder: ";
    for (int val : rec)
        cout << val << " ";
    cout << endl;

    cout << "Iterative Postorder: ";
    for (int val : itr)
        cout << val << " ";
    cout << endl;

    return 0;
}
