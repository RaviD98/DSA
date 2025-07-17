/*

✅ Problem: Flatten a Multilevel Doubly Linked List
🔗 Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

🎯 Goal:
- Given a doubly linked list where nodes may have a `child` pointer to another list,
  flatten it into a single-level doubly linked list.

🧠 Idea:
- Use DFS (recursive or stack) to go depth-first into child lists.
- Reconnect pointers as you go to maintain doubly linked list structure.

*/

class Solution
{
public:
    // 🕒 Time: O(n), 🛢️ Space: O(n) due to recursion stack
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;

        dfs(head);
        return head;
    }

private:
    // Helper to recursively flatten and return tail node
    Node *dfs(Node *node)
    {
        Node *curr = node;
        Node *last = nullptr;

        while (curr)
        {
            Node *nextNode = curr->next;

            // If child exists, recurse into it
            if (curr->child)
            {
                Node *childHead = curr->child;
                Node *childTail = dfs(childHead);

                // Connect curr -> childHead
                curr->next = childHead;
                childHead->prev = curr;

                // If nextNode exists, connect child's tail to it
                if (nextNode)
                {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                // Nullify child pointer
                curr->child = nullptr;
                last = childTail;
                curr = nextNode;
            }
            else
            {
                last = curr;
                curr = curr->next;
            }
        }

        return last;
    }
};
