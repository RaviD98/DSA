/*

✅ Problem: Delete the Middle Node of a Linked List
🔗 Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

🎯 Goal:
- Delete the middle node from a singly linked list
- If the list has only one node, return nullptr

🧠 Approach:
- Use slow and fast pointers to locate the middle node
- Track the previous node of `slow` using `prev`
- Delete the node at `slow` (i.e., the middle one)

🕒 Time Complexity: O(n)
🛢️ Space Complexity: O(1)

🔸 Example 1:
Input  : [1, 3, 4, 7, 1, 2, 6]
Output : [1, 3, 4, 1, 2, 6]
         (deleted node with value 7)

🔸 Example 2:
Input  : [1, 2, 3, 4]
Output : [1, 2, 4]
         (deleted node with value 3)

🔸 Example 3:
Input  : [1]
Output : []

*/

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // 🧤 Edge case: only one node
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        // Move slow by 1 and fast by 2
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
