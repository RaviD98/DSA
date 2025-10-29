/*
✅ Problem: Repeated String Match
🔗 Link: https://leetcode.com/problems/repeated-string-match/

🎯 Given two strings `a` and `b`, return the minimum number of times string `a`
needs to be repeated such that `b` is a substring of the repeated string.
If no such solution exists, return -1.

---

🔸 Example 1:
Input  : a = "abcd", b = "cdabcdab"
Output : 3
Explanation:
Repeating a → "abcdabcdabcd" contains "cdabcdab".

🔸 Example 2:
Input  : a = "a", b = "aa"
Output : 2

---

🔒 Constraints:
1 ≤ a.length, b.length ≤ 10^4
a and b consist of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Rabin-Karp String Matching
// 1. Repeat string `a` until its length ≥ b.size().
// 2. Compute hash of `b`.
// 3. Compute rolling hash of repeated string and check substring existence.
// 4. If not found, repeat `a` one more time and check again.
// 🕒 Time: O((n+m)) average, 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
    const long long MOD = 1e9 + 7;
    const long long BASE = 31;

    long long computeHash(const string &s)
    {
        long long hash = 0;
        for (char c : s)
        {
            hash = (hash * BASE + (c - 'a' + 1)) % MOD;
        }
        return hash;
    }

    bool rabinKarp(const string &text, const string &pattern)
    {
        int n = text.size(), m = pattern.size();
        if (m > n)
            return false;

        long long patternHash = computeHash(pattern);
        long long power = 1;
        for (int i = 0; i < m - 1; i++)
            power = (power * BASE) % MOD;

        long long hash = 0;
        for (int i = 0; i < m; i++)
        {
            hash = (hash * BASE + (text[i] - 'a' + 1)) % MOD;
        }

        if (hash == patternHash)
            return true;

        for (int i = m; i < n; i++)
        {
            hash = (hash - (text[i - m] - 'a' + 1) * power % MOD + MOD) % MOD;
            hash = (hash * BASE + (text[i] - 'a' + 1)) % MOD;

            if (hash == patternHash)
                return true;
        }

        return false;
    }

public:
    int repeatedStringMatch(string a, string b)
    {
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size())
        {
            repeated += a;
            count++;
        }

        if (rabinKarp(repeated, b))
            return count;
        repeated += a;
        if (rabinKarp(repeated, b))
            return count + 1;

        return -1;
    }
};
