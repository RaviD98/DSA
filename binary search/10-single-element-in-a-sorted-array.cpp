// Problem: Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// -------------------------
// Time: O(log n)
// Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // Ensure mid is even for pairing
            if (mid % 2 == 1)
                mid--;

            // If pair is valid, single element lies in right half
            if (nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                // Otherwise, single element lies in left half (including mid)
                high = mid;
            }
        }

        return nums[low];
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(nums1) << "\n"; // Output: 2

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << sol.singleNonDuplicate(nums2) << "\n"; // Output: 10
}
