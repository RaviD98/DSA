/*

✅ Problem: Rotate List
🔗 Link: https://leetcode.com/problems/rotate-list/

🎯 Goal:
- Given the head of a linked list, rotate the list to the right by `k` places.

🔸 Example:
Input  : head = [1,2,3,4,5], k = 2
Output : [4,5,1,2,3]

🧠 Idea:
- Find the length of the list.
- Make it circular temporarily.
- Break the circle at the correct new head position.

*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(1)
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Count the length
        int length = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }

        // Step 2: Connect tail to head to form a circular list
        tail->next = head;

        // Step 3: Find the new head (length - k % length) steps ahead
        k = k % length;
        int stepsToNewHead = length - k;

        ListNode *newTail = tail;
        while (stepsToNewHead--)
        {
            newTail = newTail->next;
        }

        // Step 4: Break the cycle and return new head
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
