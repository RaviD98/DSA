/*

✅ Problem: Merge Sorted Array
🔗 Link: https://leetcode.com/problems/merge-sorted-array/

Problem Statement:
🎯 You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n representing the number of elements in nums1 and nums2 respectively.

🔸 You must merge nums2 into nums1 as one sorted array **in-place**.

nums1 has a size of m + n, with the last n elements set to 0, to accommodate nums2.

🔸 Example:
Input  : nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output : [1,2,2,3,5,6]

🔸 Constraints:
- 1 <= m, n <= 200
- -10⁹ <= nums1[i], nums2[i] <= 10⁹
- Arrays are sorted
- Merge must be in-place in nums1

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O((m+n) log(m+n)), 🛢️ Space: O(1)
// 📌 Copy nums2 to nums1, then sort
// -----------------------------------------------------------------------------

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// -----------------------------------------------------------------------------
// 🟢 Better Approach (Extra space, then copy back)
// 🕒 Time: O(m + n), 🛢️ Space: O(m + n)
// 📌 Use extra array to store merged result
// -----------------------------------------------------------------------------

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < m)
            merged.push_back(nums1[i++]);
        while (j < n)
            merged.push_back(nums2[j++]);

        for (int k = 0; k < m + n; ++k)
            nums1[k] = merged[k];
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal In-Place Approach (From End)
// 🕒 Time: O(m + n), 🛢️ Space: O(1)
// 📌 Start filling from the end of nums1 to avoid overwriting
// -----------------------------------------------------------------------------

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;     // Pointer to last element in nums1
        int j = n - 1;     // Pointer to last element in nums2
        int k = m + n - 1; // Pointer to last position in nums1

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2, if any
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
