/*
✅ Problem: Count Leaf and Non-Leaf Nodes in a Binary Tree
🔗 Link: https://www.geeksforgeeks.org/write-a-c-program-to-count-leaf-nodes-in-a-binary-tree/

🎯 Goal:
- Count how many leaf nodes (no children) are present.
- Count how many non-leaf (internal) nodes exist.

🕒 Time: O(n)
🛢️ Space: O(h) recursion stack in worst case

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function
void countNodes(Node *root, int &leafCount, int &nonLeafCount)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        leafCount++;
    else
        nonLeafCount++;

    countNodes(root->left, leafCount, nonLeafCount);
    countNodes(root->right, leafCount, nonLeafCount);
}

// Driver
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int leaf = 0, nonLeaf = 0;
    countNodes(root, leaf, nonLeaf);

    cout << "Leaf Nodes: " << leaf << endl;
    cout << "Non-Leaf Nodes: " << nonLeaf << endl;

    return 0;
}
