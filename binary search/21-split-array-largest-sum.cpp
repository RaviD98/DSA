/*

Problem: Split Array Largest Sum
Link: https://leetcode.com/problems/split-array-largest-sum/

✅ Problem Statement:
You are given an array `nums` and an integer `k`. Split the array into `k` non-empty
continuous subarrays such that the largest sum among these subarrays is minimized.
Return the minimized largest sum.

✅ Approach: Binary Search on Answer
- Low = max(nums) → minimum possible largest subarray sum (since one subarray must contain the largest element).
- High = sum(nums) → maximum possible largest subarray sum (if only one subarray is allowed).
- Use binary search to find the smallest possible "largest subarray sum" such that
  we can split the array into at most k subarrays.

✅ Helper Function:
`isPossible(nums, k, mid)` → checks if we can split into <= k subarrays with each sum ≤ mid.

Time Complexity: O(n log(sum(nums)))
Space Complexity: O(1)

*/

class Solution
{
public:
    // Helper function to check feasibility
    bool isPossible(vector<int> &nums, int k, int mid)
    {
        int subarrays = 1; // start with one subarray
        long long sum = 0;

        for (int num : nums)
        {
            if (num > mid)
                return false; // cannot split if element > mid

            if (sum + num > mid)
            {
                subarrays++;
                sum = num;
                if (subarrays > k)
                    return false;
            }
            else
            {
                sum += num;
            }
        }
        return true;
    }

    // Main function: Binary Search on Answer
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int result = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid))
            {
                result = mid; // try smaller max sum
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // need bigger max sum
            }
        }
        return result;
    }
};
