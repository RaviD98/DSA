/*

✅ Problem: Segregate Even and Odd Nodes in a Linked List
🔗 Link: https://www.geeksforgeeks.org/problems/linked-list-of-0s-1s-and-2s/1 (similar)

🎯 Goal:
- Rearrange nodes in such a way that all **even nodes appear before odd nodes**.
- Maintain **relative order** of even and odd nodes.

🔸 Example:
Input  : 17 -> 15 -> 8 -> 12 -> 10 -> 5 -> 4 -> NULL
Output : 8 -> 12 -> 10 -> 4 -> 17 -> 15 -> 5 -> NULL

*/

// -----------------------------------------------------------------------------
// ✅ Efficient Approach: Two dummy lists for even and odd nodes
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *segregateEvenOdd(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *evenDummy = new ListNode(-1); // dummy for even list
        ListNode *oddDummy = new ListNode(-1);  // dummy for odd list

        ListNode *evenTail = evenDummy;
        ListNode *oddTail = oddDummy;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (curr->data % 2 == 0)
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
            curr = curr->next;
        }

        // Combine even and odd lists
        evenTail->next = oddDummy->next;
        oddTail->next = nullptr;

        head = evenDummy->next;

        // Clean up dummy nodes
        delete evenDummy;
        delete oddDummy;

        return head;
    }
};
