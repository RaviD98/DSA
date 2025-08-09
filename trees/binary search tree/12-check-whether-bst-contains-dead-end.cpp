// Problem: Check whether BST contains Dead End
// Link: https://www.geeksforgeeks.org/problems/dead-end/1

// -------------------------
// ✅ Approach: Use HashSets to Track All Nodes and Leaf Nodes
// Time: O(n), Space: O(n)
// -------------------------

class Solution
{
public:
    void storeNodes(TreeNode *root, unordered_set<int> &all, unordered_set<int> &leaf)
    {
        if (!root)
            return;

        all.insert(root->val);

        // Check for leaf node
        if (!root->left && !root->right)
        {
            leaf.insert(root->val);
        }

        storeNodes(root->left, all, leaf);
        storeNodes(root->right, all, leaf);
    }

    bool isDeadEnd(TreeNode *root)
    {
        if (!root)
            return false;

        unordered_set<int> all_nodes;
        unordered_set<int> leaf_nodes;

        all_nodes.insert(0); // Include 0 to handle special case for 1

        storeNodes(root, all_nodes, leaf_nodes);

        for (int leaf : leaf_nodes)
        {
            if (all_nodes.count(leaf - 1) && all_nodes.count(leaf + 1))
            {
                return true;
            }
        }

        return false;
    }
};
