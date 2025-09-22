/*
✅ Problem: Count Number of Substrings with Exactly K Distinct Characters
🔗 Link: https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/

🎯 Given a string `s` and an integer `k`, count the number of substrings that contain exactly `k` distinct characters.


🔸 Example 1:
Input  : s = "pqpqs", k = 2
Output : 7
Explanation:
Substrings with exactly 2 distinct characters are:
"pq", "pqp", "qp", "qpq", "pq", "pqs", "qs"

🔸 Example 2:
Input  : s = "aabab", k = 3
Output : 0


🔒 Constraints:
1 ≤ |s| ≤ 10^5
1 ≤ k ≤ 26
s consists of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Sliding Window + AtMost K
// Idea: Count substrings with at most K distinct - at most (K-1) distinct
// 🕒 Time: O(n), 🛢️ Space: O(26) ~ O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int substrCount(string s, int k)
    {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    int atMostK(const string &s, int k)
    {
        if (k == 0)
            return 0;

        vector<int> freq(26, 0);
        int left = 0, distinct = 0;
        long long count = 0;

        for (int right = 0; right < s.size(); right++)
        {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k)
            {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            count += (right - left + 1); // all substrings ending at right
        }
        return count;
    }
};
