/*

✅ Problem: Longest Subarray with Sum K
🔗 Link: https://www.geeksforgeeks.org/longest-sub-array-sum-k/

Problem Statement:
🎯 Given an array arr[] containing integers and an integer k,
your task is to find the length of the longest subarray
where the sum of its elements is equal to the given value k.

🔸 Examples:

Input  : arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output : 6

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try all subarrays and calculate their sum
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestSubarrayWithSumK(vector<int> &nums, int k)
    {
        int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                if (sum == k)
                    maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Prefix Sum + HashMap Approach
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Store the first occurrence of each prefix sum
// ✅ Works with positive, negative and zero elements
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestSubarrayWithSumK(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (sum == k)
            {
                maxLen = i + 1;
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end())
            {
                maxLen = max(maxLen, i - prefixSumIndex[sum - k]);
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end())
            {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Sliding Window Approach (Only for non-negative numbers)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Expand right pointer to grow window, shrink left if sum > k
// ⚠️ Only works when all elements are non-negative
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestSubarrayWithSumK(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int sum = 0, maxLen = 0;
        int n = nums.size();

        while (right < n)
        {
            sum += nums[right];

            while (left <= right && sum > k)
            {
                sum -= nums[left++];
            }

            if (sum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            ++right;
        }

        return maxLen;
    }
};
