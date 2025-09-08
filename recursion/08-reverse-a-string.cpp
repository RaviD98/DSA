/*

✅ Problem: Reverse a String using Recursion
🔗 Leetcode Related: https://leetcode.com/problems/reverse-string/ (Leetcode 344)

Problem Statement:
🎯 Given a string `s`, reverse the string using recursion.

🔸 Example 1:
Input  : s = "hello"
Output : "olleh"

🔸 Example 2:
Input  : s = "recursion"
Output : "noisrucer"

🔒 Constraints:
1 ≤ s.length ≤ 10⁴

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Two-Pointer Swap Approach
// 🕒 Time: O(n), 🛢️ Space: O(n) — recursion stack
// 📌 Swap characters from ends and move inward
// -----------------------------------------------------------------------------

class Solution
{
public:
    void reverseString(string &s)
    {
        reverseHelper(s, 0, s.length() - 1);
    }

private:
    void reverseHelper(string &s, int left, int right)
    {
        if (left >= right)
            return;

        // swap characters
        swap(s[left], s[right]);

        // recursive call
        reverseHelper(s, left + 1, right - 1);
    }
};
