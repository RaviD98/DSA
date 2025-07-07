/*

✅ Problem: Climbing Stairs
🔗 Link: https://leetcode.com/problems/climbing-stairs/

Problem Statement:
🎯 You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb **1 or 2 steps**.
Return the number of distinct ways to climb to the top using recursion.

🔸 This is equivalent to finding the nth number in the modified Fibonacci series:
ways(n) = ways(n - 1) + ways(n - 2)

🔸 Example 1:
Input  : n = 2
Output : 2
Explanation: 1 step + 1 step OR 2 steps

🔸 Example 2:
Input  : n = 3
Output : 3
Explanation: (1+1+1), (1+2), (2+1)

🔒 Constraints:
1 ≤ n ≤ 45

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach (Fibonacci logic)
// 🕒 Time: O(2^n), 🛢️ Space: O(n) — recursion stack
// 📌 For large n, this is inefficient (memoization/DP is better, but we're only doing recursion here)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
