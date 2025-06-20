/*

✅ Problem: Move Zeroes
🔗 Link: https://leetcode.com/problems/move-zeroes/

Problem Statement:
🎯 Given an integer array `nums`, move all 0's to the end while maintaining the relative order of the non-zero elements.

🔸 Example:
Input  : nums = [0,1,0,3,12]
Output : [1,3,12,0,0]

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (Using Extra Array)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Collect non-zero elements, fill the rest with 0s
// -----------------------------------------------------------------------------

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> temp;

        // Collect non-zero elements
        for (int num : nums)
        {
            if (num != 0)
                temp.push_back(num);
        }

        // Fill original array
        for (int i = 0; i < temp.size(); ++i)
        {
            nums[i] = temp[i];
        }
        for (int i = temp.size(); i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};

// -----------------------------------------------------------------------------
// 🟢 Two Pointer Approach (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Move non-zero elements forward and fill remaining with 0
// -----------------------------------------------------------------------------

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int index = 0; // Position to place next non-zero

        // Move all non-zero values to the front
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[index++] = nums[i];
            }
        }

        // Fill remaining positions with 0
        while (index < nums.size())
        {
            nums[index++] = 0;
        }
    }
};

// -----------------------------------------------------------------------------
// 🔵 Swap-based Two Pointer Variation
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Swap 0s with next non-zero elements (preserves relative order)
// -----------------------------------------------------------------------------

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
