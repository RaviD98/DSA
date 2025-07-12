/*

✅ Problem: Sort a Linked List of 0s, 1s and 2s
🔗 Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

🎯 Goal:
- Sort a linked list consisting only of 0s, 1s, and 2s.
- You are not allowed to use array or extra space for sorting.

🔸 Example:
Input  : 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> NULL
Output : 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Count & Overwrite
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    Node *sortList(Node *head)
    {
        int count[3] = {0, 0, 0};

        Node *curr = head;

        // Count occurrences of 0s, 1s, and 2s
        while (curr != nullptr)
        {
            count[curr->data]++;
            curr = curr->next;
        }

        curr = head;
        int i = 0;

        // Overwrite data with sorted values
        while (curr != nullptr)
        {
            if (count[i] == 0)
            {
                i++;
            }
            else
            {
                curr->data = i;
                count[i]--;
                curr = curr->next;
            }
        }

        return head;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Dutch National Flag (Create 3 separate lists)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    Node *sortList(Node *head)
    {
        // Dummy nodes for 0s, 1s and 2s list
        Node *zeroD = new Node(0), *oneD = new Node(0), *twoD = new Node(0);
        Node *zero = zeroD, *one = oneD, *two = twoD;

        Node *curr = head;

        // Distribute nodes into 0s, 1s and 2s lists
        while (curr != nullptr)
        {
            if (curr->data == 0)
            {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1)
            {
                one->next = curr;
                one = one->next;
            }
            else
            {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect all three lists
        zero->next = (oneD->next != nullptr) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        Node *sortedHead = zeroD->next;

        // Clean up dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return sortedHead;
    }
};
