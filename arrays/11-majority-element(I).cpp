/*

✅ Problem: Majority Element
🔗 Link: https://leetcode.com/problems/majority-element/

Problem Statement:
🎯 Given an array `nums` of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

🔸 Example:
Input  : nums = [2,2,1,1,1,2,2]
Output : 2

🔸 Constraints:
- n == nums.length
- 1 <= n <= 5 * 10⁴
- -10⁹ <= nums[i] <= 10⁹
- The majority element always exists in the array.

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Count frequency of each element one-by-one
// -----------------------------------------------------------------------------

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == nums[i])
                    count++;
            }

            if (count > n / 2)
                return nums[i];
        }

        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Hash Map Approach
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Store frequencies using unordered_map
// -----------------------------------------------------------------------------

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] > n / 2)
                return num;
        }

        return -1;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Sorting Approach
// 🕒 Time: O(n log n), 🛢️ Space: O(1)
// 📌 After sorting, the middle element is guaranteed to be the majority element
// -----------------------------------------------------------------------------

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// -----------------------------------------------------------------------------
// 🟣 Boyer-Moore Voting Algorithm (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Keep a count and candidate. Cancel out majority with minority.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
