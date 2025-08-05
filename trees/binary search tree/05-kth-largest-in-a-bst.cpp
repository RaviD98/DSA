// Problem: Kth Largest Element in BST
// Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// -------------------------
// ✅ Approach: Reverse Inorder Traversal (Right → Root → Left)
// Time: O(h + k), Space: O(h) where h = height of BST
// -------------------------

class Solution
{
public:
    int kthLargest(Node *root, int K)
    {
        int count = 0, result = -1;
        reverseInorder(root, K, count, result);
        return result;
    }

private:
    void reverseInorder(Node *root, int K, int &count, int &result)
    {
        if (!root || count >= K)
            return;

        reverseInorder(root->right, K, count, result);

        count++;
        if (count == K)
        {
            result = root->data;
            return;
        }

        reverseInorder(root->left, K, count, result);
    }
};
