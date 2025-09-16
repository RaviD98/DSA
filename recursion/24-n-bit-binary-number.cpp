/*

✅ Problem: N-bit Binary Numbers
🔗 Link: https://www.geeksforgeeks.org/problems/n-bit-binary-numbers-where-sum-of-every-prefix-is-more-than-zero/1

🎯 Given a positive integer `n`, generate all `n`-bit binary numbers
such that in every prefix of the number, the count of 1s is greater than or equal to the count of 0s.

Return the numbers in **lexicographically decreasing order**.

---

🔸 Example 1:
Input : n = 2
Output: ["11", "10"]

🔸 Example 2:
Input : n = 3
Output: ["111", "110", "101"]

---

Constraints:
1 ≤ n ≤ 20

*/

// -----------------------------------------------------------------------------
// 🔁 Recursion + Backtracking
// 🕒 Time: O(2^n) (in worst case generate all binary strings)
// 🛢️ Space: O(n) recursion stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<string> NBitBinary(int n)
    {
        vector<string> result;
        string current = "";
        generate(n, 0, 0, current, result);
        return result;
    }

private:
    void generate(int n, int ones, int zeros, string &current, vector<string> &result)
    {
        if (current.size() == n)
        {
            result.push_back(current);
            return;
        }

        // Always can place '1'
        current.push_back('1');
        generate(n, ones + 1, zeros, current, result);
        current.pop_back();

        // Place '0' only if ones > zeros
        if (ones > zeros)
        {
            current.push_back('0');
            generate(n, ones, zeros + 1, current, result);
            current.pop_back();
        }
    }
};
