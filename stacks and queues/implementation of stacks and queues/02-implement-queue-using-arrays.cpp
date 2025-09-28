/* Implementing Queue using Array */

#include <iostream>
#include <climits>

#define MAX_SIZE 5

class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    // 1. Enqueue: Adds an element to the rear of the queue
    void enqueue(int data)
    {
        if (isFull())
        {
            std::cout << "Error: Queue Overflow! Cannot enqueue " << data << ". Queue is full.\n";
            return;
        }

        // Modulo arithmetic for circular movement
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;
        count++;
        std::cout << "Enqueued: " << data << std::endl;
    }

    // 2. Dequeue: Removes and returns the front element
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Error: Queue Underflow! Cannot dequeue from an empty queue.\n";
            return INT_MIN; // Return a safe error value
        }

        int dequeued_data = arr[front];

        // Modulo arithmetic for circular movement
        front = (front + 1) % MAX_SIZE;
        count--;

        return dequeued_data;
    }

    // 3. Peek: Returns the front element
    int peek() const
    {
        if (isEmpty())
        {
            std::cout << "Error: Queue is empty. Cannot peek.\n";
            return INT_MIN;
        }
        return arr[front];
    }

    // 4. Check if the queue is empty
    bool isEmpty() const
    {
        return count == 0;
    }

    // 5. Check if the queue is full
    bool isFull() const
    {
        return count == MAX_SIZE;
    }

    // 6. Get the current size
    int size() const
    {
        return count;
    }

    // 7. Display -Helper function
    void display() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Queue elements (Front to Rear): ";
        int i = front;
        for (int k = 0; k < count; ++k)
        {
            std::cout << arr[i] << (k == count - 1 ? "" : " -> ");
            i = (i + 1) % MAX_SIZE; // Move to the next circular index
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Expected: 10 -> 20 -> 30

    std::cout << "Front element (Peek): " << q.peek() << std::endl; // Expected: 10

    std::cout << "Dequeued element: " << q.dequeue() << std::endl; // Expected: 10
    q.display();                                                   // Expected: 20 -> 30

    q.enqueue(40);
    q.enqueue(50); // Queue is now full (size 4)
    q.enqueue(60);
    q.enqueue(70); // This should cause an Overflow (MAX_SIZE is 5, but we only have 4 elements now)

    q.display();

    // Wrapping around (Circular Queue)
    std::cout << "Dequeued element: " << q.dequeue() << std::endl; // Expected: 20 (front was index 1)
    q.enqueue(60);                                                 // Enqueue 60, it should be placed at index 0 (rear wraps around)

    q.display();

    std::cout << "Current size: " << q.size() << std::endl; // Expected: 4

    return 0;
}