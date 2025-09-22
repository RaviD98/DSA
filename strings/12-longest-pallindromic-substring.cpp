/*
✅ Problem: Longest Palindromic Substring
🔗 Link: https://leetcode.com/problems/longest-palindromic-substring/

🎯 Given a string `s`, return the longest substring of `s` that is a palindrome.


🔸 Example 1:
Input  : s = "babad"
Output : "bab"
Explanation: "aba" is also a valid answer.

🔸 Example 2:
Input  : s = "cbbd"
Output : "bb"


🔒 Constraints:
1 ≤ s.length ≤ 1000
s consists of only digits and English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Expand Around Center
// 🕒 Time: O(n^2), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int start = 0, maxLen = 1;

        for (int center = 0; center < n; center++)
        {
            // Odd length palindrome
            expandAroundCenter(s, center, center, start, maxLen);
            // Even length palindrome
            expandAroundCenter(s, center, center + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Dynamic Programming
// dp[i][j] = true if substring s[i..j] is palindrome
// 🕒 Time: O(n^2), 🛢️ Space: O(n^2)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // every single char is a palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if (len == 2 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        if (len > maxLen)
                        {
                            maxLen = len;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
