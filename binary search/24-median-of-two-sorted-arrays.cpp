/*

Problem: Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

✅ Problem Statement:
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log(min(m, n))).

✅ Key Insight:
- This is a **Binary Search on Partitions** problem.
- We want to partition both arrays such that:
  - Left half contains the smaller half of total elements
  - Right half contains the larger half of total elements
- Median lies between `max(left parts)` and `min(right parts)`.

✅ Approach (Binary Search):
1. Ensure nums1 is the smaller array (to minimize binary search space).
2. Binary search on nums1's partition index i, derive nums2's partition index j.
3. Check conditions:
   - If left1 <= right2 && left2 <= right1 → correct partition
   - Else adjust binary search range.
4. Median:
   - If total length is odd → max(left1, left2)
   - If even → (max(left1, left2) + min(right1, right2)) / 2.0

✅ Time Complexity: O(log(min(m, n)))
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Ensure nums1 is smaller
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int left = 0, right = m;

        while (left <= right)
        {
            int i = (left + right) / 2; // partition nums1
            int j = half - i;           // partition nums2

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1)
            {
                if (total % 2 == 0)
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else
                {
                    return max(left1, left2);
                }
            }
            else if (left1 > right2)
            {
                right = i - 1; // move left
            }
            else
            {
                left = i + 1; // move right
            }
        }
        return 0.0; // should never reach here
    }
};
