/*
✅ Problem: Minimum Window Subsequence
🔗 Link: https://leetcode.com/problems/minimum-window-subsequence/

🎯 Given two strings `s1` and `s2`, return the minimum window in s1 which will contain `s2` as a subsequence.
If there is no such window in `s1` that covers all characters in `s2` in order, return "".

A *subsequence* means the characters of `s2` appear in `s1` in the same order, but not necessarily consecutively.

---

🔸 Example 1:
Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation: "bcde" is the shortest substring of s1 where s2 appears as a subsequence.

---

🔒 Constraints:
- 1 ≤ s1.length, s2.length ≤ 2000
- s1 and s2 consist only of lowercase English letters
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n² * m), 🛢️ Space: O(1)
// 📌 For each starting point in s1, find the smallest substring that forms s2 as subsequence.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string minWindow(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < n; ++i)
        {
            if (s1[i] == s2[0])
            {
                int j = i, k = 0;
                while (j < n && k < m)
                {
                    if (s1[j] == s2[k])
                        k++;
                    j++;
                }

                if (k == m)
                {
                    // s2 matched — now shrink from left
                    int end = j;
                    k = m - 1;
                    j--;
                    while (j >= i)
                    {
                        if (s1[j] == s2[k])
                            k--;
                        if (k < 0)
                            break;
                        j--;
                    }
                    if (end - j < minLen)
                    {
                        minLen = end - j - 1;
                        start = j + 1;
                    }
                }
            }
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Two Pointers (Optimized)
// 🕒 Time: O(n * m), 🛢️ Space: O(1)
// 📌 Move forward to find subsequence, then move backward to minimize the window.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string minWindow(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < n; ++i)
        {
            if (s1[i] != s2[0])
                continue;

            int j = i, k = 0;
            while (j < n && k < m)
            {
                if (s1[j] == s2[k])
                    k++;
                j++;
            }

            if (k == m)
            {
                // Now move backward to minimize window
                int end = j;
                k = m - 1;
                j--;
                while (j >= i)
                {
                    if (s1[j] == s2[k])
                        k--;
                    if (k < 0)
                        break;
                    j--;
                }

                if (end - j - 1 < minLen)
                {
                    minLen = end - j - 1;
                    start = j + 1;
                }
            }
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};
