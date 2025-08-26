/*

Problem: Capacity To Ship Packages Within D Days
Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
✅ Approach: Binary Search on Answer
- We want the minimum ship capacity such that all packages can be shipped in D days.
- Lower bound (low): max(weights) → at least the heaviest package must fit
- Upper bound (high): sum(weights) → at most ship all packages in one day
- Use binary search on capacity. For each mid (candidate capacity),
  check if we can ship all packages within D days.

Time Complexity: O(n · log(sum(weights) - max(weights)))
  - O(n) to simulate shipping for a given capacity
  - O(log(sum(weights) - max(weights))) binary search steps

Space Complexity: O(1)
  - Only constant extra variables used

  */

class Solution
{
public:
    // Helper: Check if we can ship within given days using "capacity"
    bool canShip(vector<int> &weights, int days, int capacity)
    {
        int neededDays = 1, currentLoad = 0;
        for (int w : weights)
        {
            if (currentLoad + w > capacity)
            {
                neededDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return neededDays <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());   // min capacity needed
        int high = accumulate(weights.begin(), weights.end(), 0); // max capacity (all in one day)
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid))
            {
                ans = mid;
                high = mid - 1; // try smaller capacity
            }
            else
            {
                low = mid + 1; // need bigger capacity
            }
        }
        return ans;
    }
};
