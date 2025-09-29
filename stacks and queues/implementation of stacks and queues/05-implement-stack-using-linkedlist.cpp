/* Implementing Stack using Linked List */

#include <iostream>
#include <climits> // For INT_MIN

// 1. Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// 2. Stack Class (Uses the Node class to form the list)
class Stack
{
private:
    Node *top; // The head of the list acts as the top of the stack
    int current_size;

public:
    // Constructor
    Stack()
    {
        top = nullptr; // Initialize the stack as empty
        current_size = 0;
    }

    // Destructor (Good practice to clean up memory)
    ~Stack()
    {
        Node *current = top;
        Node *next_node = nullptr;
        while (current != nullptr)
        {
            next_node = current->next;
            delete current; // Free the memory for the current node
            current = next_node;
        }
        top = nullptr; // Ensure top is null after cleanup
    }

    // --- Core Operations ---

    // 1. PUSH (Insert at Head): O(1)
    void push(int data)
    {
        // Create a new node
        Node *new_node = new Node(data);

        // Link the new node to the current top
        new_node->next = top;

        // Update the top pointer
        top = new_node;

        current_size++;
        std::cout << "Pushed: " << data << std::endl;
    }

    // 2. POP: O(1)
    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Error: Stack Underflow! Cannot pop from an empty stack.\n";
            return INT_MIN;
        }

        // 1. Store the node to be deleted and its data
        Node *temp = top;
        int popped_data = temp->data;

        // 2. Move the top pointer to the next node
        top = top->next;

        // 3. Delete the old top node
        delete temp;

        current_size--;
        return popped_data;
    }

    // 3. PEEK: O(1)
    int peek() const
    {
        if (isEmpty())
        {
            std::cout << "Error: Stack is empty. Cannot peek.\n";
            return INT_MIN;
        }
        return top->data;
    }

    // 4. IS EMPTY: O(1)
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // 5. SIZE
    int size() const
    {
        return current_size;
    }
};

int main()
{
    Stack s;

    // Push
    s.push(10);
    s.push(20);
    s.push(30);

    // Peek
    std::cout << "Top element (Peek): " << s.peek() << std::endl; // Expected: 30
    std::cout << "Current size: " << s.size() << std::endl;       // Expected: 3

    // Pop
    std::cout << "Popped element: " << s.pop() << std::endl; // Expected: 30
    std::cout << "Popped element: " << s.pop() << std::endl; // Expected: 20

    // Check new state
    std::cout << "New Top: " << s.peek() << std::endl; // Expected: 10

    // Empty the stack
    std::cout << "Popped element: " << s.pop() << std::endl; // Expected: 10

    // Test Underflow
    std::cout << "Popped element: " << s.pop() << std::endl; // Expected: Underflow Error
    std::cout << "Is Empty: " << s.isEmpty() << std::endl;   // Expected: 1 (true)

    return 0;
}