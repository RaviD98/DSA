// Problem: Common Nodes in Two BSTs
// Link: https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

// -------------------------
// ✅ Approach: Inorder Traversal + Two Pointer Merge
// Time: O(n + m), Space: O(h1 + h2) for stacks
// -------------------------

class Solution
{
public:
    vector<int> findCommon(TreeNode *root1, TreeNode *root2)
    {
        vector<int> result;
        stack<TreeNode *> s1, s2;

        while (true)
        {
            // Push all left nodes of root1
            while (root1)
            {
                s1.push(root1);
                root1 = root1->left;
            }

            // Push all left nodes of root2
            while (root2)
            {
                s2.push(root2);
                root2 = root2->left;
            }

            if (s1.empty() || s2.empty())
                break;

            TreeNode *top1 = s1.top();
            TreeNode *top2 = s2.top();

            if (top1->val == top2->val)
            {
                result.push_back(top1->val);
                s1.pop();
                s2.pop();
                root1 = top1->right;
                root2 = top2->right;
            }
            else if (top1->val < top2->val)
            {
                s1.pop();
                root1 = top1->right;
            }
            else
            {
                s2.pop();
                root2 = top2->right;
            }
        }

        return result;
    }
};
