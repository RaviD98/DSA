/*

Problem: Minimum Number of Days to Make m Bouquets
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

✅ Approach: Binary Search on Answer
- We need to find the minimum day such that at least m bouquets can be made.
- Each bouquet requires k consecutive flowers blooming on or before that day.
- Search space: [min(bloomDay), max(bloomDay)]
- For each mid (candidate day), check if we can make ≥ m bouquets.

Time Complexity: O(n · log(max(bloomDay)))
  - O(n) to check feasibility for a given day
  - O(log(max(bloomDay))) binary search steps

Space Complexity: O(1)
  - Only constant extra variables used

*/
class Solution
{
public:
    // Helper: Check if we can make at least m bouquets by "day"
    bool canMake(vector<int> &bloomDay, int m, int k, int day)
    {
        int bouquets = 0, consecutive = 0;
        for (int bloom : bloomDay)
        {
            if (bloom <= day)
            {
                consecutive++;
                if (consecutive == k)
                {
                    bouquets++;
                    consecutive = 0; // reset after making one bouquet
                }
            }
            else
            {
                consecutive = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long total = 1LL * m * k;
        if (total > bloomDay.size())
            return -1; // impossible case

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid))
            {
                ans = mid;
                high = mid - 1; // try smaller days
            }
            else
            {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};
