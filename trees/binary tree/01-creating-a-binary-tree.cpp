/*

✅ Problem: Create Binary Tree from Level Order
🔗 Link: https://practice.geeksforgeeks.org/problems/construct-tree-from-level-order/1

🎯 Goal:
- Build a binary tree from a level order array
- `-1` or `"N"` denotes null nodes (no child at that position)

*/

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// --------------------------
// 🌳 Node structure
// --------------------------
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// -------------------------------------------------------------
// 🔧 Utility to build binary tree from space-separated string
// Input: "1 2 3 N N 4 5"
// Output: Root of the Binary Tree
// -------------------------------------------------------------
Node *buildTree(string str)
{
    if (str.empty() || str[0] == 'N')
        return nullptr;

    stringstream ss(str);
    string val;
    ss >> val;

    Node *root = new Node(stoi(val));
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (!(ss >> val))
            break;

        if (val != "N")
        {
            curr->left = new Node(stoi(val));
            q.push(curr->left);
        }

        if (!(ss >> val))
            break;

        if (val != "N")
        {
            curr->right = new Node(stoi(val));
            q.push(curr->right);
        }
    }

    return root;
}

// -------------------------------------------------------------
// 🧪 For verification: Inorder Traversal
// -------------------------------------------------------------
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 🔽 Example Driver Code
int main()
{
    string input = "1 2 3 4 5 N 6";
    Node *root = buildTree(input);

    cout << "Inorder Traversal: ";
    inorder(root); // Output: 4 2 5 1 3 6
    cout << endl;

    return 0;
}
