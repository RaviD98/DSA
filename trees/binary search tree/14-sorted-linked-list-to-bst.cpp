// Problem: Convert Sorted List to Binary Search Tree
// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

// -------------------------
// ✅ Approach: Slow/Fast Pointer + Recursion
// Time: O(n log n), Space: O(log n) recursion stack
// -------------------------

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);

        // Find middle node
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half
        if (prev)
            prev->next = nullptr;

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head == slow ? nullptr : head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
