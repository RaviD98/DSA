/*

✅ Problem: Binary Tree Inorder Traversal
🔗 Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

🎯 Goal:
- Return the inorder traversal of a binary tree's nodes' values.
- Inorder = [left, root, right]

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
// 🧠 Recursive Inorder Traversal
// 🕒 Time: O(n), 🛢️ Space: O(n) recursion stack
// -------------------------------------------------------------
void inorderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    inorderRecursive(root->left, result);  // Visit left
    result.push_back(root->val);           // Visit root
    inorderRecursive(root->right, result); // Visit right
}

vector<int> inorderTraversalRecursive(TreeNode *root)
{
    vector<int> result;
    inorderRecursive(root, result);
    return result;
}

// -------------------------------------------------------------
// 🔁 Iterative Inorder Traversal using Stack
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -------------------------------------------------------------
vector<int> inorderTraversalIterative(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }

    return result;
}

// 🔽 Example Driver Code
int main()
{

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> rec = inorderTraversalRecursive(root);
    vector<int> itr = inorderTraversalIterative(root);

    cout << "Recursive Inorder: ";
    for (int val : rec)
        cout << val << " ";
    cout << endl;

    cout << "Iterative Inorder: ";
    for (int val : itr)
        cout << val << " ";
    cout << endl;

    return 0;
}
