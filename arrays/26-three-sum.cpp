/*

✅ Problem: 3Sum
🔗 Link: https://leetcode.com/problems/3sum/

Problem Statement:
🎯 Given an integer array `nums`, return all the triplets [nums[i], nums[j], nums[k]]
such that i ≠ j, i ≠ k, and j ≠ k, and nums[i] + nums[j] + nums[k] == 0.

🔸 Example:
Input  : nums = [-1, 0, 1, 2, -1, -4]
Output : [[-1, -1, 2], [-1, 0, 1]]

🔒 Constraints:
- 3 ≤ nums.length ≤ 3000
- -10⁵ ≤ nums[i] ≤ 10⁵

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (TLE for large inputs)
// 🕒 Time: O(n³), 🛢️ Space: O(set) to avoid duplicates
// 📌 Try all triplets and store unique valid ones in a set
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet);
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

// -----------------------------------------------------------------------------
// 🟢 Better Approach: Hash Set
// 🕒 Time: O(n²), 🛢️ Space: O(n)
// 📌 Fix one element and find the other two using a hash set
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> seen;
            for (int j = i + 1; j < n; ++j)
            {
                int complement = -nums[i] - nums[j];
                if (seen.count(complement))
                {
                    vector<int> triplet = {nums[i], nums[j], complement};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal Approach: Two Pointer + Sorting
// 🕒 Time: O(n²), 🛢️ Space: O(1) (excluding result space)
// 📌 Sort the array and use two pointers to find valid triplets
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip duplicates

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++; // skip duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--; // skip duplicates

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};
