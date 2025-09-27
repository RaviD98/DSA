/* Implementing Stack using Array */


#include <iostream>
#include <climits>
using namespace std;

class stack
{
    int capacity;
    int *arr;
    int top;

public:
    // Constructor
    stack(int c)
    {
        this->capacity = c;
        this->top = -1;
        arr = new int[c];
    }

    // Destructor to free dynamically allocated memory
    ~stack()
    {
        delete[] arr;
    }

    // PUSH: Add element to the top
    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        this->top++;
        this->arr[this->top] = data;
    }

    // POP: Remove and return the top element
    int pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT_MIN; // Return error value
        }

        // **FIX: Store data before decrementing top and return it.**
        int popped_data = this->arr[this->top];
        this->top--;
        return popped_data;
    }

    // GETTOP (PEEK): Return the top element without removing it
    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT_MIN; // Return error value
        }
        return this->arr[this->top];
    }

    // IS EMPTY
    bool isEmpty()
    {
        return this->top == -1;
    }

    // IS FULL
    bool isFull()
    {
        return this->top == this->capacity - 1;
    }

    // SIZE
    int size()
    {
        return this->top + 1;
    }
};

int main()
{
    stack st(5);

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(6); // Overflow expected here

    cout << "Top: " << st.getTop() << "\n"; // Expected: 1
    cout << "Size: " << st.size() << "\n";  // Expected: 5

    cout << "Popping: " << st.pop() << "\n"; // Expected: 1
    cout << "Popping: " << st.pop() << "\n"; // Expected: 2
    cout << "Popping: " << st.pop() << "\n"; // Expected: 3

    cout << "Top: " << st.getTop() << "\n"; // Expected: 4
    cout << "Size: " << st.size() << "\n";  // Expected: 2

    st.push(6);
    cout << "Popping: " << st.pop() << "\n"; // Expected: 6
    cout << "Popping: " << st.pop() << "\n"; // Expected: 4
    cout << "Popping: " << st.pop() << "\n"; // Expected: 5

    cout << "Top: " << st.getTop() << "\n";       // Underflow expected here
    cout << "Size: " << st.size() << "\n";        // Expected: 0
    cout << "Is Full: " << st.isFull() << "\n";   // Expected: 0 (false)
    cout << "Is Empty: " << st.isEmpty() << "\n"; // Expected: 1 (true)

    return 0;
}