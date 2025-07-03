/*

✅ Problem: Factorial of a Number
🔗 Link: https://www.geeksforgeeks.org/problems/factorial2731/1

Problem Statement:
🎯 Given a positive integer `n`, return its factorial using recursion.

🔸 Factorial Formula:
n! = n × (n - 1) × (n - 2) × ... × 1
Base Case: 0! = 1

🔸 Example:
Input  : n = 5
Output : 120
Explanation: 5! = 5 × 4 × 3 × 2 × 1 = 120

🔒 Constraints:
0 ≤ n ≤ 18

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach
// 🕒 Time: O(n), 🛢️ Space: O(n) — recursion stack
// 📌 Each function call reduces n by 1 until it hits the base case (n == 0 or 1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    long long factorial(int n)
    {
        // base case
        if (n == 0 || n == 1)
            return 1;

        // recursive case
        return n * factorial(n - 1);
    }
};
