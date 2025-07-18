/*
✅ Problem: Height of Binary Tree
🔗 GFG: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

🎯 Goal:
- Return the maximum depth (or height) of a binary tree
- Height = Number of nodes on the longest path from root to a leaf
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
// 🕒 Time: O(n), 🛢️ Space: O(h) for recursion stack (h = height)
// ------------------------------------------------------------------
int height(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// 🔽 Example Driver Code
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Height of Binary Tree: " << height(root) << endl; // Output: 3

    return 0;
}
