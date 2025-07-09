/*

✅ Problem: Length of Cycle in Linked List
🔗 (Variant of) Linked List Cycle Detection

🎯 Goal:
- If a cycle exists in the linked list, return its length (number of nodes in the loop).
- If no cycle, return 0.

🧠 Approach:
1️⃣ Use Floyd’s Tortoise and Hare to detect the meeting point inside the cycle.
2️⃣ From the meeting point, keep one pointer fixed and move the other around the cycle until they meet again, counting steps.

🔸 Example 1:
Input  : head = [3,2,0,-4], pos = 1
Output : 3
Explanation: Cycle is 2 → 0 → -4 → back to 2, length = 3.

🔸 Example 2:
Input  : head = [1,2], pos = 0
Output : 2
Explanation: Cycle is 1 → 2 → back to 1, length = 2.

🔸 Example 3:
Input  : head = [1], pos = -1
Output : 0
Explanation: No cycle.

*/

// -----------------------------------------------------------------------------
// 🧠 Floyd’s Algorithm + Loop Length Counter
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countCycleLength(ListNode *meeting)
    {
        // Starting from meeting point, loop until we return, counting steps
        int len = 1;
        ListNode *curr = meeting->next;
        while (curr != meeting)
        {
            curr = curr->next;
            ++len;
        }
        return len;
    }

    int loopLength(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // Step 2: Count cycle length
                return countCycleLength(slow);
            }
        }

        // No cycle
        return 0;
    }
};
