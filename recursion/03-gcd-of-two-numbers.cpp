/*

✅ Problem: GCD of Two Numbers
🔗 Link: https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

Problem Statement:
🎯 Given two integers a and b, find their greatest common divisor (GCD) using recursion.

🔸 GCD (also called HCF):
GCD(a, b) = GCD(b, a % b)
Base Case: GCD(a, 0) = a

🔸 Example 1:
Input  : a = 10, b = 15
Output : 5

🔸 Example 2:
Input  : a = 14, b = 28
Output : 14

🔒 Constraints:
1 ≤ a, b ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach (Euclidean Algorithm)
// 🕒 Time: O(log(min(a, b))), 🛢️ Space: O(log(min(a, b)))
// 📌 Use modulo to reduce the problem in each recursive call
// -----------------------------------------------------------------------------

class Solution
{
public:
    int gcd(int a, int b)
    {
        // base case
        if (b == 0)
            return a;

        // recursive case
        return gcd(b, a % b);
    }
};
