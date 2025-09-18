/*

✅ Problem: Largest Odd Number in String
🔗 Link: https://leetcode.com/problems/largest-odd-number-in-string/

🎯 You are given a numeric string `num`, representing a large integer.
Return the **largest-valued odd integer** (as a string) that is a non-empty substring of `num`,
or an empty string "" if no odd number exists.

---

🔸 Example 1:
Input  : num = "52"
Output : "5"

🔸 Example 2:
Input  : num = "4206"
Output : ""

🔸 Example 3:
Input  : num = "35427"
Output : "35427"

Constraints:
1 ≤ num.length ≤ 10^5
num only consists of digits and does not contain leading zeros.

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Traverse from Right
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Idea: The largest odd number must end at the rightmost odd digit.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
