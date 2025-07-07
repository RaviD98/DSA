/*

✅ Problem: Reverse Linked List
🔗 Link: https://leetcode.com/problems/reverse-linked-list/

🎯 Goal:
- Reverse the entire singly linked list and return the new head

🧠 Approaches:
1️⃣ Iterative: Reverse pointers step-by-step using three pointers
2️⃣ Recursive: Use recursion to reverse from the end

🔸 Example 1:
Input  : [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]

🔸 Example 2:
Input  : [1, 2]
Output : [2, 1]

🔸 Example 3:
Input  : []
Output : []

*/

// -----------------------------------------------------------------------------
// 🔁 Iterative Approach
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next; // Save next node
            curr->next = prev;               // Reverse pointer
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }

        return prev; // New head of reversed list
    }
};

// -----------------------------------------------------------------------------
// 🌀 Recursive Approach (Optional)
// 🕒 Time: O(n), 🛢️ Space: O(n) (due to recursion call stack)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Recursively reverse rest of the list
        ListNode *newHead = reverseList(head->next);

        // Fix the links
        head->next->next = head; // Reverse pointer
        head->next = nullptr;    // Detach original forward link

        return newHead;
    }
};
