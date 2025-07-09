/*

✅ Problem: Palindrome Linked List
🔗 Link: https://leetcode.com/problems/palindrome-linked-list/

🎯 Goal:
- Return true if the linked list is a palindrome (same forward and backward)

🧠 Approach:
1️⃣ Find the middle of the linked list
2️⃣ Reverse the second half
3️⃣ Compare both halves
4️⃣ (Optional) Restore the list back to original

🔸 Example 1:
Input  : head = [1, 2, 2, 1]
Output : true

🔸 Example 2:
Input  : head = [1, 2]
Output : false

*/

// -----------------------------------------------------------------------------
// 🧠 Efficient Approach using fast and slow pointers
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

    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find the middle
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode *secondHalfStart = reverseList(slow->next);

        // Step 3: Compare both halves
        ListNode *firstHalf = head;
        ListNode *secondHalf = secondHalfStart;
        while (secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
