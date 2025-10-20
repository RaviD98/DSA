/*
✅ Problem: Longest Repeating Character Replacement
🔗 Link: https://leetcode.com/problems/longest-repeating-character-replacement/

🎯 Given a string `s` consisting of uppercase English letters, and an integer `k`,
you can replace at most `k` characters in `s` to make all characters in a substring
the same.

Return the length of the **longest substring** containing the same letter after at most `k` replacements.

---

🔸 Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace both 'A's with 'B's or both 'B's with 'A's.


---

🔒 Constraints:
- 1 ≤ s.length ≤ 10⁵
- s consists of only uppercase English letters
- 0 ≤ k ≤ s.length
*/

// -----------------------------------------------------------------------------
// 🟢 Approach 1: Sliding Window + Frequency Map
// 🕒 Time: O(n), 🛢️ Space: O(26)
// 📌 Keep track of the max frequency in current window.
//     If window length - maxFreq > k → shrink window from left.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);
        int left = 0, maxCount = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            while (right - left + 1 - maxCount > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟠 Approach 2: Sliding Window (Optimized)
// 🕒 Time: O(n), 🛢️ Space: O(26)
// 📌 Track maxFreq lazily (does not always update when shrinking window).
//     Still guarantees correctness because window only shrinks when invalid.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, res = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            maxFreq = max(maxFreq, ++freq[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k)
                freq[s[left++] - 'A']--;

            res = max(res, right - left + 1);
        }

        return res;
    }
};
