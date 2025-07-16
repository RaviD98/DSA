/*

✅ Problem: Reverse Nodes in k-Group
🔗 Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

🎯 Goal:
- Reverse the nodes of a linked list k at a time.
- Return the modified list.
- If the number of nodes is not a multiple of k, leave the remaining nodes as is.

🔸 Example:
Input  : head = [1,2,3,4,5], k = 2
Output : [2,1,4,3,5]

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Reverse K Nodes Recursively
// 🕒 Time: O(n), 🛢️ Space: O(n/k) for recursion stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Step 1: Check if there are at least k nodes to reverse
        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }

        // If fewer than k nodes, return head (no reversal)
        if (count < k)
            return head;

        // Step 2: Reverse first k nodes
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        int reversed = 0;

        while (curr != nullptr && reversed < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            reversed++;
        }

        // Step 3: Recursively reverse the next group
        if (next != nullptr)
        {
            head->next = reverseKGroup(next, k);
        }

        // 'prev' is the new head after reversal
        return prev;
    }
};
