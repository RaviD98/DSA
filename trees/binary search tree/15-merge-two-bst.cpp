// Problem: Merge Two BSTs
// Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

// -------------------------
// ✅ Approach:
// 1. Perform inorder traversal on both BSTs to get two sorted arrays.
// 2. Merge the two sorted arrays into one.
// 3. Return the merged sorted array.
// Time: O(n1 + n2), Space: O(n1 + n2)
// -------------------------

class Solution
{
public:
    void inorder(Node *root, vector<int> &arr)
    {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> mergeSortedArrays(vector<int> &a, vector<int> &b)
    {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
                merged.push_back(a[i++]);
            else
                merged.push_back(b[j++]);
        }
        while (i < a.size())
            merged.push_back(a[i++]);
        while (j < b.size())
            merged.push_back(b[j++]);
        return merged;
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> arr1, arr2;

        // Step 1: Get sorted elements from both BSTs
        inorder(root1, arr1);
        inorder(root2, arr2);

        // Step 2: Merge the two sorted arrays
        return mergeSortedArrays(arr1, arr2);
    }
};
