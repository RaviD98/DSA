/*

✅ Topic: Search an Element in Linked List
🔍 Implemented both Iterative and Recursive search methods

🎯 Goal:
- Return true if value exists in the linked list
- Return false otherwise

*/

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// 🧱 Node Structure
// -----------------------------------------------------------------------------

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// -----------------------------------------------------------------------------
// 🔁 Iterative Search
// -----------------------------------------------------------------------------

bool searchIterative(Node *head, int key)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }

    return false;
}

// -----------------------------------------------------------------------------
// 🔁 Recursive Search
// -----------------------------------------------------------------------------

bool searchRecursive(Node *head, int key)
{
    if (head == nullptr)
        return false;

    if (head->data == key)
        return true;

    return searchRecursive(head->next, key);
}

// -----------------------------------------------------------------------------
// 🧪 Utility: Print Linked List
// -----------------------------------------------------------------------------

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
