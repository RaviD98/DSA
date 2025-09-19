/*
✅ Problem: Check if Two Strings are Anagram of Each Other
🔗 Link: https://leetcode.com/problems/valid-anagram/

🎯 Given two strings s and t, return true if t is an anagram of s, and false otherwise.
   An anagram is formed by rearranging the letters of a string to get another string.

---

🔸 Example 1:
Input  : s = "anagram", t = "nagaram"
Output : true

🔸 Example 2:
Input  : s = "rat", t = "car"
Output : false

Constraints:
1 ≤ s.length, t.length ≤ 5 * 10^4
s and t consist of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Sorting
// 🕒 Time: O(n log n), 🛢️ Space: O(1) (ignoring sort space)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Frequency Count (Hashing)
// 🕒 Time: O(n), 🛢️ Space: O(1) since only 26 lowercase letters
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        for (char c : t)
            freq[c - 'a']--;

        for (int count : freq)
        {
            if (count != 0)
                return false;
        }
        return true;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: HashMap (for general case with all Unicode chars)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        for (char c : t)
        {
            if (--freq[c] < 0)
                return false;
        }
        return true;
    }
};
