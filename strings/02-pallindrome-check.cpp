/*

✅ Problem: Palindrome Check
🔗 Link: https://leetcode.com/problems/valid-palindrome/ (similar)

🎯 Given a string `s`, check if it reads the same forward and backward.

---

🔸 Example 1:
Input  : s = "racecar"
Output : true

🔸 Example 2:
Input  : s = "abba"
Output : true

🔸 Example 3:
Input  : s = "abc"
Output : false

Constraints:
1 ≤ s.length ≤ 2 * 10^5
s consists of printable ASCII characters.

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Two-Pointer
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Reverse and Compare
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution2
{
public:
    bool isPalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: Recursion
// 🕒 Time: O(n), 🛢️ Space: O(n) (recursion stack)
// -----------------------------------------------------------------------------

class Solution3
{
public:
    bool isPalindrome(string s)
    {
        return check(s, 0, s.size() - 1);
    }

private:
    bool check(const string &s, int left, int right)
    {
        if (left >= right)
            return true;
        if (s[left] != s[right])
            return false;
        return check(s, left + 1, right - 1);
    }
};
