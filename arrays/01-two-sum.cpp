// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// -------------------------
// ✅ Approach 1: Brute Force
// Time: O(n^2), Space: O(1)
// -------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {}; // No valid pair found
    }
};

// -------------------------
// ✅ Approach 2: Hash Map
// Time: O(n), Space: O(n)
// -------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // value -> index
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (map.count(complement))
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

// -------------------------
// ✅ Approach 3: Two Pointers
// Time: O(n log n), Space: O(n)
// -------------------------
// ⚠️ Works only when we return original indices after sorting
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            numWithIndex.push_back({nums[i], i});
        }

        sort(numWithIndex.begin(), numWithIndex.end());

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = numWithIndex[left].first + numWithIndex[right].first;

            if (sum == target)
            {
                return {numWithIndex[left].second, numWithIndex[right].second};
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return {};
    }
};
