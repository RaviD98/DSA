/*
✅ Problem: Construct Binary Tree from Inorder and Postorder Traversal
🔗 Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

🧪 Sample Test Case (LeetCode):
Input:
inorder = [9,3,15,20,7],
postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

🎯 Goal:
- Reconstruct the binary tree from its inorder and postorder traversal arrays.
*/

class Solution
{
public:
    unordered_map<int, int> inorderIndex;

    TreeNode *buildTreeHelper(vector<int> &postorder, int postStart, int postEnd,
                              vector<int> &inorder, int inStart, int inEnd)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);

        int inRootIndex = inorderIndex[rootVal];
        int leftSize = inRootIndex - inStart;

        root->left = buildTreeHelper(postorder, postStart, postStart + leftSize - 1,
                                     inorder, inStart, inRootIndex - 1);
        root->right = buildTreeHelper(postorder, postStart + leftSize, postEnd - 1,
                                      inorder, inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            inorderIndex[inorder[i]] = i;

        return buildTreeHelper(postorder, 0, n - 1, inorder, 0, n - 1);
    }
};
