/*

✅ Problem: Binary Tree Preorder Traversal
🔗 Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

🎯 Goal:
- Return the preorder traversal of a binary tree's nodes' values.
- Preorder = [root, left, right]

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
// 🧠 Recursive Preorder Traversal
// 🕒 Time: O(n), 🛢️ Space: O(n) recursion stack
// -------------------------------------------------------------
void preorderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    result.push_back(root->val);            // Visit root
    preorderRecursive(root->left, result);  // Visit left
    preorderRecursive(root->right, result); // Visit right
}

vector<int> preorderTraversalRecursive(TreeNode *root)
{
    vector<int> result;
    preorderRecursive(root, result);
    return result;
}

// -------------------------------------------------------------
// 🔁 Iterative Preorder Traversal using Stack
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -------------------------------------------------------------
vector<int> preorderTraversalIterative(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);

        // Push right first so that left is processed first
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }

    return result;
}

// 🔽 Example Driver Code
int main()
{

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> rec = preorderTraversalRecursive(root);
    vector<int> itr = preorderTraversalIterative(root);

    cout << "Recursive Preorder: ";
    for (int val : rec)
        cout << val << " ";
    cout << endl;

    cout << "Iterative Preorder: ";
    for (int val : itr)
        cout << val << " ";
    cout << endl;

    return 0;
}
