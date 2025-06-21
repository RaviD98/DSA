/*

✅ Problem: Single Number
🔗 Link: https://leetcode.com/problems/single-number/

Problem Statement:
🎯 Given a non-empty array of integers `nums`, every element appears twice except for one.
Find that single one.

🔸 Example:
Input  : nums = [4,1,2,1,2]
Output : 4

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (Nested Loops)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Compare each element with every other element to check if it appears once
// -----------------------------------------------------------------------------

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            bool foundDuplicate = false;
            for (int j = 0; j < n; ++j)
            {
                if (i != j && nums[i] == nums[j])
                {
                    foundDuplicate = true;
                    break;
                }
            }
            if (!foundDuplicate)
                return nums[i];
        }

        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Hash Map Approach
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use unordered_map to count frequency of each element
// -----------------------------------------------------------------------------

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        for (auto &pair : freq)
        {
            if (pair.second == 1)
                return pair.first;
        }

        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🔵 XOR Approach (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 XOR of two same numbers is 0. So, XOR all elements to cancel duplicates.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        for (int num : nums)
        {
            result ^= num;
        }

        return result;
    }
};
