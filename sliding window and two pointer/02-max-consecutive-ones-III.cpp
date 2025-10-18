/*
✅ Problem: Max Consecutive Ones III
🔗 Link: https://leetcode.com/problems/max-consecutive-ones-iii/

🎯 You are given a binary array `nums` and an integer `k`.
Return the maximum number of consecutive 1's in the array if you can flip at most `k` 0's.

---

🔸 Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: Flip 2 zeros at indices 5 and 10 → longest sequence of 1's = 6.


---

🔒 Constraints:
- 1 ≤ nums.length ≤ 10⁵
- nums[i] is either 0 or 1.
- 0 ≤ k ≤ nums.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For every starting point, expand until the number of zeros > k.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int left = 0; left < n; left++)
        {
            int zeroCount = 0;
            for (int right = left; right < n; right++)
            {
                if (nums[right] == 0)
                    zeroCount++;

                if (zeroCount > k)
                    break;

                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window (Two Pointers)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Maintain a window [left, right] with at most `k` zeros.
//     Expand right pointer, and shrink left when zeroCount > k.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, zeroCount = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                zeroCount++;

            // shrink window until valid
            while (zeroCount > k)
            {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Sliding Window (Optimized with Constant Update)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Similar to Approach 2 but avoids nested while loop logic by ensuring
//     window validity check inside loop — minimal pointer movement.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                k--;

            while (k < 0)
            {
                if (nums[left] == 0)
                    k++;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
