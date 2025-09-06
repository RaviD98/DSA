/*

✅ Problem: Check Palindrome using Recursion
🔗 Related Link: https://leetcode.com/problems/valid-palindrome/

🎯 Given a string `s`, check if it is a palindrome using recursion.
Assume the input contains only lowercase letters and no special symbols/spaces.

🔸 Palindrome: A string that reads the same backward as forward.

🔸 Example 1:
Input  : s = "racecar"
Output : true

🔸 Example 2:
Input  : s = "hello"
Output : false

🔒 Constraints:
- 1 ≤ s.length ≤ 10⁴

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Two-Pointer Approach
// 🕒 Time: O(n), 🛢️ Space: O(n) — recursion stack
// 📌 Compare characters from both ends and recurse inward
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isPalindrome(string s)
    {
        return check(0, s.length() - 1, s);
    }

private:
    bool check(int left, int right, string &s)
    {
        // base case: crossed over or met in the middle
        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return check(left + 1, right - 1, s);
    }
};
