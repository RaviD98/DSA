// Problem: Find Rotation Count in Rotated Sorted Array
// Link: https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

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
    int findRotationCount(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If mid element > last element → min lies in right half
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                // Min lies in left half (including mid)
                high = mid;
            }
        }
        // At the end, low points to the minimum element
        return low; // Rotation count
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {15, 18, 2, 3, 6, 12};
    cout << sol.findRotationCount(nums1) << "\n"; // Output: 2

    vector<int> nums2 = {7, 9, 11, 12, 5};
    cout << sol.findRotationCount(nums2) << "\n"; // Output: 4

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << sol.findRotationCount(nums3) << "\n"; // Output: 0 (not rotated)
}
