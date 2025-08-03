// Problem : Create Binary Tree from Level Order
// Link : https://leetcode.com/problems/insert-into-a-binary-search-tree

/*
Example:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
*/

#include <iostream>
                  using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:


    // Recursive Code
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }

    // Iterative Code
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (!root)
            return newNode;

        TreeNode *curr = root;

        while (true)
        {
            if (val < curr->val)
            {
                if (!curr->left)
                {
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }
            else
            {
                if (!curr->right)
                {
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};

// Optional: Helper code to test insert logic (not part of core solution)
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    TreeNode *updatedRoot = sol.insertIntoBST(root, val);

    inorder(updatedRoot); // Output should be: 1 2 3 4 5 7
    return 0;
}
