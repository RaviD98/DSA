/*

✅ Problem: Longest Consecutive Sequence
🔗 Link: https://leetcode.com/problems/longest-consecutive-sequence/

Problem Statement:
🎯 Given an unsorted array of integers `nums`, return the length of the longest sequence of consecutive elements.

🔸 Example:
Input  : nums = [100, 4, 200, 1, 3, 2]
Output : 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].

🔒 Constraints:
- 0 <= nums.length <= 10⁵
- -10⁹ <= nums[i] <= 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Sort and check sequence)
// 🕒 Time: O(n log n), 🛢️ Space: O(1)
// 📌 Sort and count length of streaks
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1, currLen = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                continue; // skip duplicates

            if (nums[i] == nums[i - 1] + 1)
            {
                currLen++;
            }
            else
            {
                longest = max(longest, currLen);
                currLen = 1;
            }
        }

        return max(longest, currLen);
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal HashSet Approach
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use unordered_set to check start of sequences efficiently
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s)
        {
            if (!s.count(num - 1))
            { // start of sequence
                int currentNum = num;
                int currentStreak = 1;

                while (s.count(currentNum + 1))
                {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
