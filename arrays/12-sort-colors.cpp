/*

✅ Problem: Sort Colors
🔗 Link: https://leetcode.com/problems/sort-colors/

Problem Statement:
🎯 Given an array `nums` with n objects colored red (0), white (1), or blue (2),
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

🔸 You must solve this problem without using the library's sort function.

🔸 Example:
Input  : nums = [2,0,2,1,1,0]
Output : [0,0,1,1,2,2]

🔒 Constraints:
- n == nums.length
- 1 <= n <= 300
- nums[i] ∈ {0, 1, 2}

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Sort directly)
// 🕒 Time: O(n log n), 🛢️ Space: O(1)
// 📌 Not allowed as per problem constraint (no library sort)
// -----------------------------------------------------------------------------

// Not used — since we can't use built-in sort.

// -----------------------------------------------------------------------------
// 🟢 Counting Sort (Two-pass)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Count occurrences of 0s, 1s, and 2s, then overwrite
// -----------------------------------------------------------------------------

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, one = 0, two = 0;

        for (int num : nums)
        {
            if (num == 0)
                zero++;
            else if (num == 1)
                one++;
            else
                two++;
        }

        int i = 0;
        while (zero--)
            nums[i++] = 0;
        while (one--)
            nums[i++] = 1;
        while (two--)
            nums[i++] = 2;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal One-pass: Dutch National Flag Algorithm
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Use 3 pointers (low, mid, high) to sort in a single pass
// -----------------------------------------------------------------------------

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
