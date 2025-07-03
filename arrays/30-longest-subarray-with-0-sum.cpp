/*

✅ Problem: Longest Subarray with 0 Sum
🔗 Link: https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

Problem Statement:
🎯 Given an array of integers, find the length of the longest subarray whose sum is 0.

🔸 Example:
Input  : arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output : 5
Explanation: The subarray [-2, 2, -8, 1, 7] sums to 0.

Input  : arr = [1, 2, 3]
Output : 0

Input  : arr = [1, -1, 3, 2, -2, -3]
Output : 6

🔒 Constraints:
1 ≤ n ≤ 10⁶
-10⁹ ≤ arr[i] ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (Nested loops)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every subarray and check sum
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int maxLen = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += arr[j];
                if (sum == 0)
                    maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal Approach using Prefix Sum + HashMap
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Track first occurrence of prefix sum. If same sum seen again,
// it means elements between those indices sum to 0.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> prefixIndex;
        int maxLen = 0, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];

            if (sum == 0)
                maxLen = i + 1;

            if (prefixIndex.find(sum) != prefixIndex.end())
            {
                maxLen = max(maxLen, i - prefixIndex[sum]);
            }
            else
            {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Variation: Return actual subarray too (optional)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    pair<int, int> maxLenSubarrayIndices(vector<int> &arr)
    {
        unordered_map<int, int> prefixIndex;
        int maxLen = 0, sum = 0;
        int start = -1, end = -1;

        for (int i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];

            if (sum == 0)
            {
                if (i + 1 > maxLen)
                {
                    maxLen = i + 1;
                    start = 0;
                    end = i;
                }
            }

            if (prefixIndex.find(sum) != prefixIndex.end())
            {
                if (i - prefixIndex[sum] > maxLen)
                {
                    maxLen = i - prefixIndex[sum];
                    start = prefixIndex[sum] + 1;
                    end = i;
                }
            }
            else
            {
                prefixIndex[sum] = i;
            }
        }

        return {start, end}; // or return maxLen if only length is needed
    }
};



// Follow up:
// Instead of returning just the length, return the actual subarray.

vector<int> largestZeroSumSubarray(vector<int> &nums)
{
    unordered_map<int, int> sumIndex;
    int sum = 0, maxLength = 0;
    int startIndex = -1;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];

        if (sum == 0)
        {
            maxLength = i + 1;
            startIndex = 0;
        }

        if (sumIndex.find(sum) != sumIndex.end())
        {
            int length = i - sumIndex[sum];
            if (length > maxLength)
            {
                maxLength = length;
                startIndex = sumIndex[sum] + 1;
            }
        }
        else
        {
            sumIndex[sum] = i;
        }
    }

    // Return subarray
    if (maxLength == 0)
        return {}; // No zero-sum subarray

    return vector<int>(nums.begin() + startIndex, nums.begin() + startIndex + maxLength);
}
