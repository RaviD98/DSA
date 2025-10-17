/*
✅ Problem: Longest Substring Without Repeating Characters
🔗 Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

🎯 Given a string `s`, find the length of the longest substring
without repeating characters.

---

🔸 Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.


---

🔒 Constraints:
- 0 ≤ s.length ≤ 5 * 10⁴
- s consists of English letters, digits, symbols, and spaces.
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force (Generate All Substrings)
// 🕒 Time: O(n³), 🛢️ Space: O(n)
// 📌 Check every substring and validate uniqueness using a set.
// -----------------------------------------------------------------------------

class Solution_BruteForce
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_set<char> st;
                bool unique = true;

                for (int k = i; k <= j; k++)
                {
                    if (st.count(s[k]))
                    {
                        unique = false;
                        break;
                    }
                    st.insert(s[k]);
                }

                if (unique)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window + Hash Set
// 🕒 Time: O(2n) ≈ O(n), 🛢️ Space: O(n)
// 📌 Maintain a sliding window [left, right] with unique characters.
//     Expand right, and shrink left when duplicates appear.
// -----------------------------------------------------------------------------

class Solution_SlidingWindow
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.size())
        {
            if (!st.count(s[right]))
            {
                st.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            else
            {
                st.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Optimized Sliding Window + Hash Map (Most Efficient)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Store the last seen index of each character to jump the `left` pointer
//     directly to avoid re-checking intermediate characters.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> lastSeen(256, -1); // store last index of each char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++)
        {
            if (lastSeen[s[right]] != -1)
                left = max(left, lastSeen[s[right]] + 1);

            lastSeen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
