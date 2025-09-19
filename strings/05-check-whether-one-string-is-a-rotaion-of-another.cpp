/*
✅ Problem: Check if one string is a rotation of another
🔗 Link: https://www.geeksforgeeks.org/check-if-a-string-is-rotation-of-another/

🎯 Given two strings s1 and s2, check if s2 is a rotation of s1.
   A string s2 is a rotation of s1 if we can obtain s2 by rotating s1
   some number of times.

---

🔸 Example 1:
Input  : s1 = "abcd", s2 = "cdab"
Output : true

🔸 Example 2:
Input  : s1 = "abcd", s2 = "acbd"
Output : false

🔸 Example 3:
Input  : s1 = "aab", s2 = "aba"
Output : true

Constraints:
1 ≤ s1.length, s2.length ≤ 10^5
s1 and s2 consist of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Concatenation Trick
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isRotation(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        // Concatenate s1 with itself and check if s2 is a substring
        string doubled = s1 + s1;
        return doubled.find(s2) != string::npos;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Brute Force (Try all rotations)
// 🕒 Time: O(n^2), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isRotation(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            // rotate by i: s1[i..n-1] + s1[0..i-1]
            string rotated = s1.substr(i) + s1.substr(0, i);
            if (rotated == s2)
                return true;
        }
        return false;
    }
};
