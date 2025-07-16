/*

✅ Problem: Add Two Numbers II
🔗 Link: https://leetcode.com/problems/add-two-numbers-ii/

🎯 Goal:
- Add two numbers represented by linked lists where each node contains a single digit.
- The digits are stored in **forward order** (most significant digit first).
- Return the sum as a linked list in the same order.

🔸 Example:
Input  : l1 = [7,2,4,3], l2 = [5,6,4]
Output : [7,8,0,7]
Explanation: 7243 + 564 = 7807

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Use Stacks to Simulate Reverse Order
// 🕒 Time: O(max(m, n)), 🛢️ Space: O(m + n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        // Push digits of both numbers onto stacks
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = nullptr;
        int carry = 0;

        // Pop from stacks and add digits
        while (!s1.empty() || !s2.empty() || carry)
        {
            int val1 = (!s1.empty()) ? s1.top() : 0;
            int val2 = (!s2.empty()) ? s2.top() : 0;

            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            // Create new node and attach to front
            ListNode *newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
