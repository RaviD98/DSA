/*
✅ Problem: Find the Index of the First Occurrence in a String
🔗 Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

🎯 Given two strings `haystack` and `needle`, return the index of the first occurrence
of `needle` in `haystack`, or -1 if `needle` is not part of `haystack`.

---

🔸 Example 1:
Input  : haystack = "sadbutsad", needle = "sad"
Output : 0

🔸 Example 2:
Input  : haystack = "leetcode", needle = "leeto"
Output : -1

---

Constraints:
1 ≤ haystack.length, needle.length ≤ 10^4
Both consist of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Z-Function (Concatenate + Z Array)
// - Build string `P = needle + '#' + haystack`
// - Compute Z-array on P
// - If any Z[i] == needle.length(), return i - (needle.length() + 1)
// 🕒 Time: O(n + m), 🛢️ Space: O(n + m)
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> computeZ(const string &s)
    {
        int n = s.size();
        vector<int> Z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i <= r)
            {
                Z[i] = min(r - i + 1, Z[i - l]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            {
                Z[i]++;
            }
            if (i + Z[i] - 1 > r)
            {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        return Z;
    }

    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        string concat = needle + "#" + haystack;
        vector<int> Z = computeZ(concat);
        int m = needle.size();
        for (int i = 0; i < Z.size(); i++)
        {
            if (Z[i] == m)
            {
                // match found at this position in haystack
                return i - (m + 1);
            }
        }
        return -1;
    }
};
