/*
✅ Problem: Size of Binary Tree
🔗 GFG: https://www.geeksforgeeks.org/problems/size-of-binary-tree/1

🎯 Goal:
- Return the total number of nodes in a binary tree
*/

#include <iostream>
using namespace std;

// 🌳 Tree Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ------------------------------------------------------------------
// 🧠 Recursive Approach
// 🕒 Time: O(n), 🛢️ Space: O(h) where h = height of tree
// ------------------------------------------------------------------
int size(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftSize = size(root->left);
    int rightSize = size(root->right);

    return 1 + leftSize + rightSize;
}

// 🔽 Example Driver Code
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Size of Binary Tree: " << size(root) << endl; // Output: 4

    return 0;
}
