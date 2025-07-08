/*

✅ Problem: Linked List Cycle II
🔗 Link: https://leetcode.com/problems/linked-list-cycle-ii/

🎯 Goal:
- If a cycle exists in the linked list, return the node where the cycle begins.
- If no cycle, return nullptr.

🧠 Approach: Floyd’s Cycle Detection + Finding Entry Point
1️⃣ Use fast and slow pointers to detect the cycle
2️⃣ Once they meet, move one pointer to head and both one step at a time
3️⃣ Where they meet again is the start of the loop

🔸 Example 1:
Input  : head = [3,2,0,-4], pos = 1
Output : node with value 2

🔸 Example 2:
Input  : head = [1,2], pos = 0
Output : node with value 1

🔸 Example 3:
Input  : head = [1], pos = -1
Output : nullptr

*/

// -----------------------------------------------------------------------------
// 🧠 Floyd’s Algorithm + Entry Point Finder
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // Step 2: Reset one pointer to head
                ListNode *entry = head;
                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry; // Start of the cycle
            }
        }

        return nullptr; // No cycle
    }
};
