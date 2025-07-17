/*

✅ Problem: Copy List with Random Pointer
🔗 Link: https://leetcode.com/problems/copy-list-with-random-pointer/

🎯 Goal:
- Clone a linked list where each node has:
  - `next` pointer (like normal)
  - `random` pointer (can point to any node or be NULL)

🧠 Idea:
- Use a 3-pass O(n) time & O(1) space method.
- Interleave original and copied nodes to avoid extra space.

*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(1)
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // 1️⃣ Step 1: Clone nodes and insert right after original
        Node *curr = head;
        while (curr)
        {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2️⃣ Step 2: Set random pointers for the cloned nodes
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3️⃣ Step 3: Separate the cloned list from the original
        Node *dummy = new Node(0);
        Node *copyCurr = dummy;
        curr = head;
        while (curr)
        {
            Node *copy = curr->next;
            curr->next = copy->next;

            copyCurr->next = copy;
            copyCurr = copy;
            curr = curr->next;
        }

        return dummy->next;
    }
};
