/*

✅ Problem: Find the Missing Number
🔗 Link: https://leetcode.com/problems/missing-number/

Problem Statement:
🎯 You are given an array `nums` containing n distinct numbers from 0 to n.
Return the only number in the range [0, n] that is missing from the array.

🔸 Example:
Input  : nums = [3, 0, 1]
Output : 2

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Check for every number from 0 to n whether it exists in the array
// -----------------------------------------------------------------------------

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= n; ++i)
        {
            bool found = false;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == i)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return i;
        }
        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Hashing Approach
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use a boolean array to mark presence of each number in the range [0, n]
// -----------------------------------------------------------------------------

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> seen(n + 1, false);

        for (int num : nums)
        {
            seen[num] = true;
        }

        for (int i = 0; i <= n; ++i)
        {
            if (!seen[i])
                return i;
        }

        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Math Formula Approach
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Sum of 0 to n is n*(n+1)/2. Subtract actual sum from expected sum.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums)
        {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

// -----------------------------------------------------------------------------
// 🟣 XOR Approach
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 XOR all elements in array and all numbers from 0 to n. Remaining = missing.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xorAll = 0;
        int xorNums = 0;

        for (int i = 0; i <= n; ++i)
        {
            xorAll ^= i;
        }

        for (int num : nums)
        {
            xorNums ^= num;
        }

        return xorAll ^ xorNums;
    }
};
