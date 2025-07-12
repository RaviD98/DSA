/*

✅ Problem: Intersection of Two Linked Lists
🔗 Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

🎯 Goal:
- Find the node at which the two singly linked lists intersect.
- If no intersection, return nullptr.

🔸 Example:
List A: 1 → 2
                  ↘
                    8 → 4 → 5
                  ↗
List B:     3 → 7

Output: Reference to node with value 8

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Brute Force (Nested loops)
// 🕒 Time: O(m*n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        for (ListNode *a = headA; a != nullptr; a = a->next)
        {
            for (ListNode *b = headB; b != nullptr; b = b->next)
            {
                if (a == b)
                    return a;
            }
        }
        return nullptr;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Hashing
// 🕒 Time: O(m + n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

#include <unordered_set>

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> visited;

        while (headA != nullptr)
        {
            visited.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr)
        {
            if (visited.count(headB))
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: Length Difference Method
// 🕒 Time: O(m + n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Align both lists
        while (lenA > lenB)
        {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA)
        {
            headB = headB->next;
            lenB--;
        }

        // Traverse together to find intersection
        while (headA != nullptr && headB != nullptr)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 4: Two Pointer Technique
// 🕒 Time: O(m + n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        // At most 2 passes: a and b will align at the intersection or both will be nullptr
        while (a != b)
        {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }

        return a;
    }
};
