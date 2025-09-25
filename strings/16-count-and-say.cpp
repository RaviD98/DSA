/*
✅ Problem: Count and Say
🔗 Link: https://leetcode.com/problems/count-and-say/

🎯 The "count-and-say" sequence is the sequence of integers with the first five terms as:
1.     1
2.     11
3.     21
4.     1211
5.     111221

To generate the nth term, start with "1" and count the number of digits in groups of the same digit.

---

🔸 Example 1:
Input  : n = 1
Output : "1"

🔸 Example 2:
Input  : n = 4
Output : "1211"
Explanation:
- term 1 = "1"
- term 2 = "11" (one 1)
- term 3 = "21" (two 1s)
- term 4 = "1211" (one 2, then one 1)

---

🔒 Constraints:
1 ≤ n ≤ 30
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Iterative String Construction
// Generate sequence term by term using grouping and counting.
// 🕒 Time: O(n * L) where L = length of sequence term
// 🛢️ Space: O(L)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";

        for (int i = 2; i <= n; i++)
        {
            string next = "";
            int count = 1;
            for (int j = 1; j < result.size(); j++)
            {
                if (result[j] == result[j - 1])
                {
                    count++;
                }
                else
                {
                    next += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            // append last group
            next += to_string(count) + result.back();
            result = next;
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Recursion
// Define a recursive function f(n) that generates the nth string.
// 🕒 Time: O(n * L), 🛢️ Space: O(L + recursion stack)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string prev = countAndSay(n - 1);
        string result = "";

        int count = 1;
        for (int i = 1; i < prev.size(); i++)
        {
            if (prev[i] == prev[i - 1])
            {
                count++;
            }
            else
            {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        result += to_string(count) + prev.back();

        return result;
    }
};
