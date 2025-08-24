/*
Problem: Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/


✅ Approach: Binary Search on Answer
- Speed (k) is between [1, max(piles)]
- Check feasibility with a helper function canEat()
- If feasible, try smaller k (move left); else, move right

Time Complexity: O(n · log(max(piles)))
  - O(n) to compute hours for a given speed
  - O(log(max(piles))) binary search range

Space Complexity: O(1)
*/


class Solution
{
public:
    // Helper: can Koko finish all bananas with speed 'k' in <= h hours?
    bool canEat(vector<int> &piles, int h, int k)
    {
        long long hours = 0;
        for (int bananas : piles)
        {
            hours += (bananas + k - 1) / k; // ceil(bananas / k)
            if (hours > h)
                return false; // too slow
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid))
            {
                ans = mid; // valid, try smaller
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // too slow, increase speed
            }
        }
        return ans;
    }
};
