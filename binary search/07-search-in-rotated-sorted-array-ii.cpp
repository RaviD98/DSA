// Problem: Search in Rotated Sorted Array II (with Duplicates)
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// -------------------------
// ✅ Modified Binary Search
// Time: O(log n) average, O(n) worst (due to duplicates)
// Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // If we can't decide which half is sorted due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Right half is sorted
            else
            {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    cout << (sol.search(nums, target) ? "Found" : "Not Found") << "\n"; // Found
}
