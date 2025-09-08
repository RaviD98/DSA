/*

✅ Problem: Convert Lowercase to Uppercase (Recursively)
🔗 Custom Recursion Problem (No direct Leetcode/GFG link)

Problem Statement:
🎯 Given a string `s`, convert all lowercase characters to uppercase using recursion.

🔸 Example 1:
Input  : s = "helloWorld"
Output : "HELLOWORLD"

🔸 Example 2:
Input  : s = "RecursionIsFun"
Output : "RECURSIONISFUN"

🔒 Constraints:
1 ≤ s.length ≤ 10⁴
Only alphabetic characters

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach
// 🕒 Time: O(n), 🛢️ Space: O(n) — due to recursion stack
// 📌 Convert character by character from start to end
// -----------------------------------------------------------------------------

class Solution
{
public:
    void toUppercase(string &s)
    {
        helper(s, 0);
    }

private:
    void helper(string &s, int index)
    {
        if (index == s.length())
            return;

        if (s[index] >= 'a' && s[index] <= 'z')
            s[index] = s[index] - ('a' - 'A');

        helper(s, index + 1);
    }
};
