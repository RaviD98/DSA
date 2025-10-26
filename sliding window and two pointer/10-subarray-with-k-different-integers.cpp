/*
✅ Problem: Subarrays with K Different Integers
🔗 Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

🎯 Given an integer array `nums` and an integer `k`,
return the number of **good subarrays** of `nums`.

A subarray is called good if the number of distinct integers in that subarray is exactly `k`.

---

🔸 Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: The 7 subarrays are:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], and [1,2,1,2].

---

🔒 Constraints:
- 1 ≤ nums.length ≤ 2 * 10⁴
- 1 ≤ nums[i], k ≤ nums.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(n)
// 📌 Generate all subarrays and count distinct numbers in each.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> distinct;
            for (int j = i; j < n; ++j)
            {
                distinct.insert(nums[j]);
                if (distinct.size() == k)
                    result++;
                else if (distinct.size() > k)
                    break;
            }
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Count subarrays with exactly K distinct elements as:
//     f(K) - f(K - 1)
//     where f(X) = number of subarrays with at most X distinct elements.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int> &nums, int k)
    {
        int left = 0, result = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); ++right)
        {
            freq[nums[right]]++;

            while (freq.size() > k)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            result += right - left + 1; // all subarrays ending at right
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Two Sliding Windows (Alternative Efficient Approach)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Maintain two windows: one for ≤ K distinct, another for ≤ (K - 1).
// -----------------------------------------------------------------------------

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }

private:
    int helper(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        int left = 0, total = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            count[nums[right]]++;

            while (count.size() > k)
            {
                count[nums[left]]--;
                if (count[nums[left]] == 0)
                    count.erase(nums[left]);
                left++;
            }

            total += right - left + 1;
        }

        return total;
    }
};
