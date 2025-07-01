/*

✅ Problem: Majority Element II
🔗 Link: https://leetcode.com/problems/majority-element-ii/

Problem Statement:
🎯 Given an integer array of size `n`, find all elements that appear more than ⌊ n/3 ⌋ times.

🔸 Example:
Input  : nums = [3,2,3]
Output : [3]

Input  : nums = [1,1,1,3,3,2,2,2]
Output : [1,2]

🔒 Constraints:
- 1 <= nums.length <= 5 * 10⁴
- -10⁹ <= nums[i] <= 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Count frequency for each element manually (skip duplicates)
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; ++i)
        {
            // Skip duplicates already added
            if (find(result.begin(), result.end(), nums[i]) != result.end())
                continue;

            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == nums[i])
                    count++;
            }

            if (count > n / 3)
                result.push_back(nums[i]);
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Better Approach: Hash Map
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Store frequency in a hashmap and filter elements > n/3
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        vector<int> result;
        int n = nums.size();

        for (int num : nums)
            freq[num]++;

        for (auto [num, count] : freq)
        {
            if (count > n / 3)
                result.push_back(num);
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal Approach: Extended Boyer-Moore Voting Algorithm
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 At most 2 elements can appear > n/3 times → use 2 counters & 2 candidates
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1; // any 2 different values

        for (int num : nums)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        // Verify the candidates
        count1 = count2 = 0;
        for (int num : nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3)
            result.push_back(candidate1);
        if (count2 > n / 3)
            result.push_back(candidate2);

        return result;
    }
};
