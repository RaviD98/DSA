/*

✅ Problem: Rotate Array
🔗 Link: https://leetcode.com/problems/rotate-array/

Problem Statement:
🎯 Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

🔸 Example:
Input  : nums = [1,2,3,4,5,6,7], k = 3
Output : [5,6,7,1,2,3,4]

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (TLE)
// 🕒 Time: O(k * n), 🛢️ Space: O(1)
// 📌 Rotate one step at a time, total k times
// -----------------------------------------------------------------------------

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        while (k--)
        {
            int last = nums[n - 1];
            for (int i = n - 1; i > 0; --i)
            {
                nums[i] = nums[i - 1];
            }
            nums[0] = last;
        }
    }
};

// -----------------------------------------------------------------------------
// 🟢 Using Extra Array (Hashing)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Place elements in their rotated positions using a temporary array
// -----------------------------------------------------------------------------

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> temp(n);

        for (int i = 0; i < n; ++i)
        {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Reversal Algorithm (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Reverse the array in 3 parts: full, first k, and last n-k
// -----------------------------------------------------------------------------

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());       // Reverse entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse first k elements
        reverse(nums.begin() + k, nums.end());   // Reverse the rest
    }
};
