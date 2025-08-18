// Problem: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// -------------------------
// ✅ Binary Search
// Time: O(log n), Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // Minimum lies in the unsorted part
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return nums[low];
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << findMin(arr) << "\n"; // 0
}
