/*

✅ Problem: Josephus Problem
🔗 Link: https://practice.geeksforgeeks.org/problems/josephus-problem/1

🎯 The Josephus problem is a famous theoretical puzzle:
N people are standing in a circle. Every k-th person is eliminated until only one remains.
We need to find the position of the last remaining person.

⚡ Positions are considered in a **1-based index**.

🔸 Example 1:
Input : N = 3, k = 2
Output: 3
Explanation: Start at position 1.
- Person at 2 is killed.
- Then person at 1 is killed.
- Person at 3 survives.

🔸 Example 2:
Input : N = 5, k = 3
Output: 4
Explanation:
- Kill 3rd person → left {1,2,4,5}
- Kill 1st person → left {2,4,5}
- Kill 5th person → left {2,4}
- Kill 2nd person → left {4}
Survivor is at position 4.

🔒 Constraints:
1 ≤ N, K ≤ 10^5

*/

// -----------------------------------------------------------------------------
// 🛠️ Simulation using vector<bool>
// 🕒 Time: O(N * K) worst case (since we skip eliminated people),
// 🛢️ Space: O(N) for tracking alive people
// -----------------------------------------------------------------------------

class SolutionSimulation
{
public:
    int josephus(int n, int k)
    {
        vector<bool> person(n, true); // true = alive
        int index = 0;                // starting from person 0
        int person_left = n;

        while (person_left > 1)
        {
            int steps = 0;
            while (steps < k)
            {
                if (person[index])
                { // alive
                    steps++;
                }
                if (steps == k)
                    break;
                index = (index + 1) % n; // move circularly
            }
            // kill this person
            person[index] = false;
            person_left--;

            // move to next alive person
            do
            {
                index = (index + 1) % n;
            } while (!person[index]);
        }

        // Find the survivor
        for (int i = 0; i < n; i++)
        {
            if (person[i])
                return i + 1; // convert to 1-based
        }
        return -1; // should never reach
    }
};

// -----------------------------------------------------------------------------
// 🔁 Recursive Solution (Classic Josephus Formula)
// 🕒 Time: O(N), 🛢️ Space: O(N) recursion stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    int josephus(int n, int k)
    {
        if (n == 1)
            return 1;
        // recurrence: f(n, k) = (f(n-1, k) + k - 1) % n + 1
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};

// -----------------------------------------------------------------------------
// 🔁 Iterative Solution (Efficient, avoids recursion stack)
// 🕒 Time: O(N), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class SolutionIterative
{
public:
    int josephus(int n, int k)
    {
        int survivor = 0; // in 0-based indexing
        for (int i = 2; i <= n; i++)
        {
            survivor = (survivor + k) % i;
        }
        return survivor + 1; // convert to 1-based
    }
};
