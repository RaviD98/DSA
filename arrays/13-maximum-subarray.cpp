/*

✅ Problem: Maximum Subarray
🔗 Link: https://leetcode.com/problems/maximum-subarray/

Problem Statement:
🎯 Given an integer array `nums`, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

🔸 Example:
Input  : nums = [-2,1,-3,4,-1,2,1,-5,4]
Output : 6
Explanation: [4,-1,2,1] has the largest sum = 6.

🔒 Constraints:
- 1 <= nums.length <= 10⁵
- -10⁴ <= nums[i] <= 10⁴

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (All subarrays)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every possible subarray and track the max sum
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int currSum = 0;
            for (int j = i; j < n; ++j)
            {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Prefix Sum Approach (Better)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Track prefix sums and min prefix so far to get max subarray sum
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i];

        int maxSum = prefix[0], minPrefix = 0;

        for (int i = 0; i < n; ++i)
        {
            maxSum = max(maxSum, prefix[i] - minPrefix);
            minPrefix = min(minPrefix, prefix[i]);
        }

        return maxSum;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Kadane’s Algorithm (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Reset current sum to 0 when it goes below 0
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0], currSum = 0;

        for (int num : nums)
        {
            currSum += num;
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }
};
