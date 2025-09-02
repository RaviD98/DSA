/*

Problem: K-th Element of Two Sorted Arrays
Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0

✅ Problem Statement:
Given two sorted arrays arr1 and arr2 of sizes n and m respectively, and an integer k,
find the k-th element in the combined sorted array (1-based index).

✅ Key Insight:
This problem is similar to "Median of Two Sorted Arrays" but generalized.
We don’t need the full merged array — only the k-th element.

✅ Approach (Binary Search on Partition):
1. Always binary search on the smaller array to minimize search space.
2. Partition arr1 at index i → arr2 partition will be j = k - i.
3. Ensure correct partitioning condition:
     maxLeft1 <= minRight2 && maxLeft2 <= minRight1
4. Answer = max(maxLeft1, maxLeft2).

✅ Edge Cases:
- If partition is at start or end of an array → use INT_MIN / INT_MAX for boundaries.

✅ Time Complexity: O(log(min(n, m)))
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
    {
        // Ensure arr1 is smaller
        if (n > m)
            return kthElement(arr2, arr1, m, n, k);

        int left = max(0, k - m), right = min(k, n);

        while (left <= right)
        {
            int cut1 = (left + right) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if (left1 > right2)
            {
                right = cut1 - 1; // move left
            }
            else
            {
                left = cut1 + 1; // move right
            }
        }
        return -1; // should not reach
    }
};
