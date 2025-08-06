// Problem: Sum of k smallest elements in BST
// Link: https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst/1

// -------------------------
// ✅ Approach: Inorder Traversal (Gives elements in sorted order)
// Time: O(k), Space: O(h) → h = height of tree
// -------------------------

class Solution
{
public:
    int sum = 0, count = 0;

    int sumK(Node *root, int k)
    {
        inorder(root, k);
        return sum;
    }

private:
    void inorder(Node *root, int k)
    {
        if (!root || count >= k)
            return;

        inorder(root->left, k);

        if (count < k)
        {
            sum += root->data;
            count++;
        }

        inorder(root->right, k);
    }
};
