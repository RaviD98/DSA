/*

✅ Topic: Linked List Deletion Operations

🎯 Operations Implemented:
- Delete at Head
- Delete at Tail
- Delete at a Specific Position
- Delete Node by Value X
- Delete Middle Node

🔒 Assumes: 1-based positions

*/

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// 🧱 Node Structure: Each node contains data and a pointer to the next node
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
// ❌ Delete at Head: Removes the first node in the list
// -----------------------------------------------------------------------------

void deleteAtHead(Node *&head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;
    delete temp;
}

// -----------------------------------------------------------------------------
// ❌ Delete at Tail: Removes the last node in the list
// -----------------------------------------------------------------------------

void deleteAtTail(Node *&head)
{
    if (head == nullptr)
        return;

    // Only one node present
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;

    // Traverse to second last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;    // Delete last node
    temp->next = nullptr; // Set second last's next to null
}

// -----------------------------------------------------------------------------
// ❌ Delete at Specific Position (1-based index)
// -----------------------------------------------------------------------------

void deleteAtPosition(Node *&head, int pos)
{
    if (head == nullptr || pos <= 0)
        return;

    // If position is 1 → delete head
    if (pos == 1)
    {
        Node *toDelete = head;
        head = head->next; // Move head to next node
        delete toDelete;   // Delete the old head
        return;
    }

    Node *temp = head;

    // Move temp to (pos - 1)th node
    for (int i = 1; i < pos - 1 && temp->next != nullptr; ++i)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
        return; // Invalid position

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// -----------------------------------------------------------------------------
// ❌ Delete Node by Value X (first occurrence only)
// -----------------------------------------------------------------------------

void deleteByValue(Node *&head, int x)
{
    if (head == nullptr)
        return;

    // Special case: if head contains value x
    if (head->data == x)
    {
        Node *toDelete = head;
        head = head->next; // Move head to next node
        delete toDelete;   // Delete the old head
        return;
    }

    Node *temp = head;

    // Traverse to node just before the one containing x
    while (temp->next != nullptr && temp->next->data != x)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
        return; // x not found

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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
