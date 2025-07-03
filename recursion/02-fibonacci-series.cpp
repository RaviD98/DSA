/*

✅ Problem: Fibonacci Number
🔗 Link: https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

Problem Statement:
🎯 Given a number `n`, return the `n`th Fibonacci number using recursion.

🔸 Fibonacci Series:
f(0) = 0
f(1) = 1
f(n) = f(n - 1) + f(n - 2) for n > 1

🔸 Example:
Input  : n = 5
Output : 5
Explanation: 0 1 1 2 3 5 → 5th Fibonacci number is 5

🔒 Constraints:
0 ≤ n ≤ 30

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach
// 🕒 Time: O(2^n), 🛢️ Space: O(n) — recursion stack
// 📌 Direct recursive implementation without memoization
// -----------------------------------------------------------------------------

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};
