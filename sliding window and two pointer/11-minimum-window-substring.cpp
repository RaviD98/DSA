/*
✅ Problem: Minimum Window Substring
🔗 Link: https://leetcode.com/problems/minimum-window-substring/

🎯 Given two strings `s` and `t`, return the **minimum window substring** of `s`
that contains all the characters of `t`.
If there is no such substring, return an empty string.

---

🔸 Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring containing "ABC" is "BANC".

---

🔒 Constraints:
- 1 ≤ s.length, t.length ≤ 10⁵
- s and t consist of uppercase and lowercase English letters
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n² * m), 🛢️ Space: O(1)
// 📌 Check all substrings of s and verify if each contains t (using frequency count).
// ❌ Not feasible for large inputs.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            unordered_map<char, int> need;
            for (char c : t)
                need[c]++;

            for (int j = i; j < n; ++j)
            {
                if (need.find(s[j]) != need.end())
                {
                    need[s[j]]--;
                    if (need[s[j]] == 0)
                        need.erase(s[j]);
                }

                if (need.empty())
                {
                    if (j - i + 1 < minLen)
                    {
                        minLen = j - i + 1;
                        ans = s.substr(i, minLen);
                    }
                    break; // smallest from i found
                }
            }
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Expand window until all chars in t are covered, then shrink from left.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> need;
        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        unordered_map<char, int> window;
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size())
        {
            char c = s[r];
            window[c]++;

            if (need.find(c) != need.end() && window[c] == need[c])
                formed++;

            // Try to shrink the window when all chars are matched
            while (l <= r && formed == required)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.find(leftChar) != need.end() && window[leftChar] < need[leftChar])
                    formed--;

                l++;
            }

            r++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Optimized with Frequency Array (Instead of Map)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Using ASCII array improves constant factors over unordered_map.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> need(128, 0);
        for (char c : t)
            need[c]++;

        int required = t.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            if (need[s[right]] > 0)
                required--;
            need[s[right]]--;

            while (required == 0)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
