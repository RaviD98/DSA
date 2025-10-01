/*
✅ Problem: Min Stack
🔗 Link: https://leetcode.com/problems/min-stack/

🎯 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.


Constraints:
-2^31 ≤ val ≤ 2^31 - 1
Methods pop, top, and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Two Stacks (Main Stack + Min Stack)
// - Use one stack for values, another to track minimums.
// - On push: add value to main, push min(val, minStack.top()) to min stack.
// - On pop: pop from both stacks.
// - Top → main.top(), Min → minStack.top().
// 🕒 Time: O(1) for all ops, 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class MinStack
{
private:
    stack<int> st, minSt;

public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Single Stack with Pair (val, currentMin)
// - Store both value and min-so-far in one stack.
// - This reduces number of stacks but memory per node increases.
// 🕒 Time: O(1) for all ops, 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class MinStack2
{
private:
    stack<pair<int, int>> st; // {value, minSoFar}

public:
    MinStack2() {}

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: Optimized (Encoding Min Value)
// - Use a single stack and encode values to save space.
// - Keep track of current min in a variable.
// - If newVal < minVal → push encoded value (2*newVal - minVal), update minVal.
// - On pop, if popped < minVal → it was encoded, recover old min.
// 🕒 Time: O(1) for all ops, 🛢️ Space: O(1) extra (besides stack)
// -----------------------------------------------------------------------------

class MinStack3
{
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack3()
    {
        minVal = LLONG_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                st.push(2LL * val - minVal); // encode
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long top = st.top();
        st.pop();

        if (top < minVal)
        {
            // encoded value, restore old min
            minVal = 2LL * minVal - top;
        }
    }

    int top()
    {
        long long top = st.top();
        if (top < minVal)
        {
            return (int)minVal; // actual value is current min
        }
        return (int)top;
    }

    int getMin()
    {
        return (int)minVal;
    }
};
