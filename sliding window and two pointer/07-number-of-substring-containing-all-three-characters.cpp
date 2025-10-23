/*
✅ Problem: Number of Substrings Containing All Three Characters
🔗 Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

🎯 Given a string `s` consisting only of characters 'a', 'b', and 'c',
return the number of substrings that contain at least one occurrence
of each of these characters.

---

🔸 Example 1:
Input: s = "abcabc"
Output: 10
Explanation:
The substrings containing at least one 'a', 'b', and 'c' are:
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", "abc".


---

🔒 Constraints:
- 3 ≤ s.length ≤ 5 * 10⁴
- s consists only of letters 'a', 'b', and 'c'.
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Check all substrings and count those that have 'a', 'b', and 'c'.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            bool hasA = false, hasB = false, hasC = false;
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'a')
                    hasA = true;
                else if (s[j] == 'b')
                    hasB = true;
                else
                    hasC = true;

                if (hasA && hasB && hasC)
                    count++;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Use two pointers and maintain counts of 'a', 'b', and 'c'.
//     When all characters exist in window → all substrings ending at right
//     and starting from any index ≤ left are valid.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int count[3] = {0, 0, 0}; // For 'a', 'b', 'c'
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right)
        {
            count[s[right] - 'a']++;

            // Shrink window when we have all 3 characters
            while (count[0] && count[1] && count[2])
            {
                result += n - right; // all substrings ending at right are valid
                count[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Prefix Index Tracking
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Track the latest index of each 'a', 'b', 'c'.
//     For each position, smallest index among them determines how many substrings
//     ending here are valid.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> last(3, -1); // last indices of 'a', 'b', 'c'
        int res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;

            // Check if all characters have appeared at least once
            if (last[0] != -1 && last[1] != -1 && last[2] != -1)
                res += 1 + min({last[0], last[1], last[2]});
        }

        return res;
    }
};
