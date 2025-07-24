/*
✅ Problem: Construct Binary Tree from Preorder and Inorder Traversal
🔗 Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

🧪 Sample Test Case (LeetCode):
Input:
preorder = [3,9,20,15,7],
inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

🎯 Goal:
- Reconstruct the binary tree from its preorder and inorder traversal arrays.
*/

class Solution
{
public:
    unordered_map<int, int> inorderIndex;

    TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                              vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        int inRootIndex = inorderIndex[rootVal];
        int leftSubtreeSize = inRootIndex - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                     inorder, inStart, inRootIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                      inorder, inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
            inorderIndex[inorder[i]] = i;

        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
