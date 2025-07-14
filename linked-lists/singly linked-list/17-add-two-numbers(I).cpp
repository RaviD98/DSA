/*

✅ Problem: Add Two Numbers
🔗 Link: https://leetcode.com/problems/add-two-numbers/

🎯 Goal:
- You are given two non-empty linked lists representing two non-negative integers.
- Digits are stored in reverse order, and each node contains a single digit.
- Add the two numbers and return the sum as a linked list.

🔸 Example:
Input  : l1 = [2,4,3], l2 = [5,6,4]
Output : [7,0,8]
Explanation: 342 + 465 = 807

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Iterative Digit-by-Digit Addition (Carry Handling)
// 🕒 Time: O(max(m, n)), 🛢️ Space: O(max(m, n)) for result list
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to simplify code
        ListNode *curr = dummy;

        int carry = 0;

        // Traverse both lists until end
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        return dummy->next; // Skip dummy node and return real head
    }
};
