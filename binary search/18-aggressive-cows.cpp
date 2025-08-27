/*

Problem: Aggressive Cows
Link: https://www.spoj.com/problems/AGGRCOW/
✅ Approach: Binary Search on Answer
- We need to place "cows" in stalls such that the minimum distance
  between any two cows is maximized.
- Sort the stall positions first.
- Search space: [1, max(stall) - min(stall)]
- Use binary search on distance "mid":
    Check if we can place all cows such that each cow is at least "mid" apart.

Time Complexity: O(n log(max(stalls)))
  - O(n) to check feasibility for a given distance
  - O(log(max(stalls))) binary search steps

Space Complexity: O(1)
  - Only constant extra variables used
  
*/

class Solution
{
public:
    // Helper: Check if we can place cows with at least "dist" apart
    bool canPlace(vector<int> &stalls, int cows, int dist)
    {
        int count = 1; // place first cow at stalls[0]
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPos >= dist)
            {
                count++;
                lastPos = stalls[i];
                if (count >= cows)
                    return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int cows)
    {
        sort(stalls.begin(), stalls.end());        // sort stalls first
        int low = 1;                               // minimum distance
        int high = stalls.back() - stalls.front(); // maximum possible distance
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlace(stalls, cows, mid))
            {
                ans = mid;
                low = mid + 1; // try larger distance
            }
            else
            {
                high = mid - 1; // try smaller distance
            }
        }
        return ans;
    }
};
