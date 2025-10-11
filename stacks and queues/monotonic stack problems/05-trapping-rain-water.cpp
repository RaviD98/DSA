/*

✅ Problem: Trapping Rain Water
🔗 Link: https://leetcode.com/problems/trapping-rain-water/

🎯 Given n non-negative integers representing the elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

---

🔸 Example 1:
Input  : height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output : 6
Explanation: Water trapped between bars = 6 units.


---

🔒 Constraints:
1 ≤ height.length ≤ 2 * 10^5
0 ≤ height[i] ≤ 10^4

*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each element, find the maximum bar to its left and right.
// Water trapped = min(leftMax, rightMax) - height[i]
// -----------------------------------------------------------------------------

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int totalWater = 0;

        for (int i = 0; i < n; i++)
        {
            int leftMax = 0, rightMax = 0;

            // find left maximum
            for (int l = 0; l <= i; l++)
                leftMax = max(leftMax, height[l]);

            // find right maximum
            for (int r = i; r < n; r++)
                rightMax = max(rightMax, height[r]);

            totalWater += min(leftMax, rightMax) - height[i];
        }

        return totalWater;
    }
};

// -----------------------------------------------------------------------------
// 🟡 Approach 2: Prefix–Suffix Optimization
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Precompute leftMax and rightMax arrays to avoid nested loops.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> leftMax(n), rightMax(n);
        int totalWater = 0;

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        for (int i = 0; i < n; i++)
            totalWater += min(leftMax[i], rightMax[i]) - height[i];

        return totalWater;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 3: Two Pointer Optimal
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Move two pointers inward, updating leftMax and rightMax dynamically.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    totalWater += leftMax - height[left];
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }
};
