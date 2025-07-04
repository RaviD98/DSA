/*

✅ Topic: Linked List Creation and Insertion Operations

🎯 Operations Implemented:
- Insert at Head
- Insert at Tail
- Insert at a Given Position
- Insert After a Given Value X
- Insert Before a Given Value X

🔒 Assumes: 1-based positions, unique values for insert-after/before

*/

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// 🧱 Node Structure: Each node has a data value and a pointer to the next node
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
// 📌 Insert at Head: New node becomes the new head of the list
// -----------------------------------------------------------------------------

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val); // Create a new node
    newNode->next = head;          // Point it to the current head
    head = newNode;                // Update head to this new node
}

// -----------------------------------------------------------------------------
// 📌 Insert at Tail: New node is added at the end of the list
// -----------------------------------------------------------------------------

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        // If the list is empty, the new node is the head
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next; // Traverse to the last node
    }

    temp->next = newNode; // Append the new node
}

// -----------------------------------------------------------------------------
// 📌 Insert at Given Position (1-based index)
// -----------------------------------------------------------------------------

void insertAtPosition(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);

    if (pos <= 1 || head == nullptr)
    {
        // If position is 1 or list is empty, insert at head
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    // Traverse to the (pos - 1)th node
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    // If position is beyond the current length, do nothing
    if (temp == nullptr)
        return;

    newNode->next = temp->next; // Link new node to next node
    temp->next = newNode;       // Link previous node to new node
}

// -----------------------------------------------------------------------------
// 📌 Insert After Given Value X: Inserts a node after first occurrence of x
// -----------------------------------------------------------------------------

void insertAfterValue(Node *&head, int x, int val)
{
    Node *temp = head;

    // Search for the value x
    while (temp != nullptr && temp->data != x)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
        return; // x not found in the list

    Node *newNode = new Node(val);
    newNode->next = temp->next; // Connect new node to next node
    temp->next = newNode;       // Connect x's node to new node
}

// -----------------------------------------------------------------------------
// 📌 Insert Before Given Value X: Inserts a node before first occurrence of x
// -----------------------------------------------------------------------------

void insertBeforeValue(Node *&head, int x, int val)
{
    if (head == nullptr)
        return;

    // Special case: x is at the head
    if (head->data == x)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    // Traverse until just before the node with value x
    while (temp->next != nullptr && temp->next->data != x)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
        return; // x not found

    Node *newNode = new Node(val);
    newNode->next = temp->next; // Point to x node
    temp->next = newNode;       // Insert before x
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
