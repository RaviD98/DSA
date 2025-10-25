/*
✅ Problem: Longest Substring with At Most K Distinct Characters
🔗 Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

🎯 Given a string `s` and an integer `k`, return the length of the longest substring
that contains at most `k` distinct characters.

---

🔸 Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

---

🔒 Constraints:
- 1 ≤ s.length ≤ 5 * 10⁴
- 0 ≤ k ≤ 50
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(n)
// 📌 Try all substrings and check how many distinct characters they contain.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_map<char, int> freq;
            for (int j = i; j < n; ++j)
            {
                freq[s[j]]++;

                if (freq.size() <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break; // more than k distinct chars
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window + HashMap (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(k)
// 📌 Expand right pointer to include characters until >k distinct chars.
//     Then shrink from left until valid again.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if (k == 0)
            return 0;

        int left = 0, maxLen = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); ++right)
        {
            freq[s[right]]++;

            // Shrink window if distinct chars exceed k
            while (freq.size() > k)
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Ordered Map Optimization (Track Last Indices)
// 🕒 Time: O(n log k), 🛢️ Space: O(k)
// 📌 Use an ordered map to track last seen indices and remove the oldest
//     when we exceed `k` distinct characters.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if (k == 0)
            return 0;

        int maxLen = 0;
        map<char, int> lastIndex; // keeps characters sorted by their index
        int left = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            lastIndex[s[right]] = right;

            if (lastIndex.size() > k)
            {
                // remove the leftmost character (earliest index)
                auto it = min_element(lastIndex.begin(), lastIndex.end(),
                                      [](auto &a, auto &b)
                                      { return a.second < b.second; });

                left = it->second + 1;
                lastIndex.erase(it);
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
