/*

Problem: Find the Smallest Divisor Given a Threshold
Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

✅ Approach: Binary Search on Answer
- Divisor is in range [1, max(nums)]
- For each divisor d, compute sum(ceil(nums[i]/d))
- If sum <= threshold, d is valid -> try smaller
- Else, increase d

Time Complexity: O(n · log(max(nums)))
  - O(n) to compute sum for a given divisor
  - O(log(max(nums))) search space

Space Complexity: O(1)
  - Only constant extra variables used

*/

class Solution
{
public:
    // Helper: check if divisor d keeps sum <= threshold
    bool isPossible(vector<int> &nums, int threshold, int d)
    {
        long long sum = 0;
        for (int num : nums)
        {
            sum += (num + d - 1) / d; // ceil(num / d)
            if (sum > threshold)
                return false;
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, threshold, mid))
            {
                ans = mid; // valid, try smaller divisor
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // too small divisor, increase
            }
        }
        return ans;
    }
};
