/*

✅ Problem: Middle of the Linked List
🔗 Link: https://leetcode.com/problems/middle-of-the-linked-list/

🎯 Goal:
- Return the middle node of a singly linked list
- If there are two middle nodes, return the second one

🧠 Approach:
- Use two pointers: slow and fast
- Move slow by 1 node, fast by 2 nodes
- When fast reaches the end, slow will be at the middle

🕒 Time Complexity: O(n)
🛢️ Space Complexity: O(1)

🔸 Example 1:
Input  : [1, 2, 3, 4, 5]
Output : Node with value 3

🔸 Example 2:
Input  : [1, 2, 3, 4, 5, 6]
Output : Node with value 4

*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow by 1 step and fast by 2 steps
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow is now pointing to the middle node
        return slow;
    }
};
