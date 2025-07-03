/*

✅ Problem: Implement Power Function
🔗 Link: https://leetcode.com/problems/powx-n/ (Leetcode 50)

🎯 Implement the function pow(x, n), which calculates x raised to the power n (i.e., xⁿ) using recursion.

🔸 Example 1:
Input  : x = 2.00000, n = 10
Output : 1024.00000

🔸 Example 2:
Input  : x = 2.00000, n = -2
Output : 0.25000
Explanation: 2⁻² = 1 / (2²) = 1/4 = 0.25

🔒 Constraints:
-100.0 < x < 100.0
-2³¹ ≤ n ≤ 2³¹ - 1
n is an integer

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach — Binary Exponentiation
// 🕒 Time: O(log n), 🛢️ Space: O(log n)
// 📌 Use recursion to divide the power and reduce calls using (n/2) logic
// -----------------------------------------------------------------------------

    class Solution
    {
    public:
        double myPow(double x, int n)
        {
            // Convert n to long to safely handle -2^31
            long long N = n;

            if (N < 0)
            {
                x = 1 / x;
                N = -N;
            }

            return power(x, N);
        }

        double power(double x, long long n)
        {
            if (n == 0)
                return 1;

            double half = power(x, n / 2);

            if (n % 2 == 0)
                return half * half;
            else
                return half * half * x;
        }
    };
