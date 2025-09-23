/*
✅ Problem: Sum of Beauty of All Substrings
🔗 Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

🎯 The beauty of a string is defined as the difference between the highest frequency
and the lowest frequency characters (ignoring zero frequencies).
Given a string `s`, return the sum of beauty for all substrings of `s`.

---

🔸 Example 1:
Input  : s = "aabcb"
Output : 5
Explanation:
Substrings with non-zero beauty are:
"aa" → beauty = 1
"abcb" → beauty = 2
"bcb" → beauty = 1
"bc" → beauty = 1
"cb" → beauty = 1
Total = 5

🔸 Example 2:
Input  : s = "aabcbaa"
Output : 17

---

🔒 Constraints:
1 ≤ s.length ≤ 500
s consists of lowercase English letters only.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Brute Force with Frequency Counting
// For each substring, compute frequencies and beauty.
// 🕒 Time: O(n^2 * 26) = O(n^2), 🛢️ Space: O(26)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq)
                {
                    if (f > 0)
                    {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Optimized (Re-use Frequency Array)
// Still O(n^2), but avoids re-creating freq array from scratch each time.
// 🕒 Time: O(n^2 * 26), 🛢️ Space: O(26)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxFreq = *max_element(freq.begin(), freq.end());
                int minFreq = INT_MAX;
                for (int f : freq)
                {
                    if (f > 0)
                        minFreq = min(minFreq, f);
                }
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};
