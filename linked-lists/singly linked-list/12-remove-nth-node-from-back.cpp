/*

✅ Problem: Remove N-th Node From End of List
🔗 Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

🎯 Goal:
- Given the head of a linked list, remove the n-th node from the end and return the new head.

🔸 Example:
Input  : head = [1, 2, 3, 4, 5], n = 2
Output : [1, 2, 3, 5]

*/

// -----------------------------------------------------------------------------
// ✅ Optimal Approach: Two Pointer (Fast and Slow) with dummy node
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node before head to handle edge cases
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Move fast ahead by n+1 steps to maintain the gap
        for (int i = 0; i <= n; ++i)
        {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Slow is now at the node before the one to delete
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        // Get the real head
        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
