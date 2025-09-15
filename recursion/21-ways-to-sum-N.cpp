/*

✅ Problem: Ways to Sum to N
🔗 Link: https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n/0

🎯 Given a set of m distinct positive integers (arr[]) and a value N,
count the total number of ways we can form N by adding the array elements.
Repetitions and different arrangements are allowed.

⚠️ Since the answer can be large, return it modulo (1e9 + 7).

🔸 Example 1:
Input: m = 3, N = 7, arr = {1, 5, 6}
Output: 6
Explanation:
The different ways are:
1+1+1+1+1+1+1
1+1+5
1+5+1
5+1+1
1+6
6+1

🔸 Example 2:
Input: m = 2, N = 5, arr = {2, 3}
Output: 2
Explanation:
The ways are: 2+3, 3+2

🔒 Constraints:
1 ≤ m ≤ 100
1 ≤ arr[i] ≤ 1000
1 ≤ N ≤ 10^4

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Recursion (Exponential, not efficient for large N)
// 🕒 Time: O(m^N), 🛢️ Space: O(N)
// -----------------------------------------------------------------------------

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int solveRec(int arr[], int m, int N)
    {
        if (N == 0)
            return 1; // Found a valid way
        if (N < 0)
            return 0; // Overshoot

        int ways = 0;
        for (int i = 0; i < m; i++)
        {
            ways = (ways + solveRec(arr, m, N - arr[i])) % MOD;
        }
        return ways;
    }

    int countWays(int arr[], int m, int N)
    {
        return solveRec(arr, m, N);
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Dynamic Programming (Efficient)
// 🕒 Time: O(m * N), 🛢️ Space: O(N)
// -----------------------------------------------------------------------------

// to be added