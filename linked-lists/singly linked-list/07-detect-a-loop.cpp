/*

✅ Problem: Linked List Cycle
🔗 Link: https://leetcode.com/problems/linked-list-cycle/

🎯 Goal:
- Determine if a linked list has a cycle in it (i.e., loop)

🧠 Approach:
- Use Floyd’s Cycle Detection Algorithm (also known as Tortoise and Hare)
- Move slow pointer one step, fast pointer two steps
- If they meet → cycle exists

🔸 Example 1:
Input  : head = [3,2,0,-4], with a cycle at position 1 (node with value 2)
Output : true

🔸 Example 2:
Input  : head = [1,2], with a cycle at position 0 (node with value 1)
Output : true

🔸 Example 3:
Input  : head = [1], with no cycle
Output : false

*/

// -----------------------------------------------------------------------------
// 🧠 Floyd's Cycle Detection (Tortoise and Hare)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps

            if (slow == fast)
                return true; // They meet → cycle detected
        }

        return false; // Reached end → no cycle
    }
};
