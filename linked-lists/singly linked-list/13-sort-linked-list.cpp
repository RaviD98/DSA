/*

✅ Problem: Sort List (Merge Sort on Linked List)
🔗 Link: https://leetcode.com/problems/sort-list/

🎯 Goal:
- Sort a singly linked list in ascending order using O(n log n) time and constant space complexity (not including recursion stack).

🔸 Example:
Input  : head = [4, 2, 1, 3]
Output : [1, 2, 3, 4]

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Merge Sort (Divide and Conquer)
// 🕒 Time: O(n log n), 🛢️ Space: O(log n) due to recursion
// -----------------------------------------------------------------------------

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Step 1: Split list into two halves
        ListNode *mid = getMiddle(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;

        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge the two sorted halves
        return merge(left, right);
    }

private:
    // 🧩 Helper to find middle node (slow-fast pointer)
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // 🧩 Merge two sorted lists
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
