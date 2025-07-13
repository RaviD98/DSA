/*

✅ Problem: Plus One Linked List
🔗 Link: https://leetcode.com/problems/plus-one-linked-list/

🎯 Goal:
- Given a non-negative integer represented as a linked list of digits (most significant digit first), add 1 to the number and return the head of the updated list.

🔸 Example:
Input  : 1 → 2 → 3
Output : 1 → 2 → 4

Input  : 9 → 9 → 9
Output : 1 → 0 → 0 → 0

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Reverse the List → Add 1 → Reverse Again
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode *plusOne(ListNode *head)
    {
        head = reverseList(head); // Step 1: Reverse the list

        ListNode *curr = head;
        int carry = 1;

        while (curr != nullptr && carry)
        {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if (carry && curr->next == nullptr)
            {
                curr->next = new ListNode(0); // Create new node if needed
            }
            curr = curr->next;
        }

        return reverseList(head); // Step 3: Reverse back
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Recursive Approach (Handles carry from end to front)
// 🕒 Time: O(n), 🛢️ Space: O(n) due to recursion
// -----------------------------------------------------------------------------

class Solution
{
public:
    int addOneRecursive(ListNode *node)
    {
        if (node == nullptr)
            return 1;

        int carry = addOneRecursive(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }

    ListNode *plusOne(ListNode *head)
    {
        int carry = addOneRecursive(head);

        // If there's a leftover carry, create a new head
        if (carry)
        {
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};
