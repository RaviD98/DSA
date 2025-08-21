// Problem: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// -------------------------
// ✅ Binary Search Approach
// Time: O(log n)
// Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If mid element > rightmost element,
            // min must be in the right half
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            // Otherwise, min is in left half (including mid)
            else
            {
                high = mid;
            }
        }
        return nums[low]; // or nums[high]
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums) << "\n"; // Output: 0
}
