/*

✅ Problem: Next Permutation
🔗 Link: https://leetcode.com/problems/next-permutation/

Problem Statement:
🎯 Implement the next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

🔸 Example:
Input  : nums = [1,2,3]
Output : [1,3,2]

Input  : nums = [3,2,1]
Output : [1,2,3]

🔒 Constraints:
- 1 <= nums.length <= 100
- 0 <= nums[i] <= 100

*/

// -----------------------------------------------------------------------------
// 🔵 Optimal In-Place Approach
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Steps:
//   1. Find the first decreasing element from the end (i)
//   2. Find just larger element than nums[i-1] from the end (j) and swap
//   3. Reverse the suffix starting at i
// -----------------------------------------------------------------------------

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find first decreasing index from end
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        // Step 2: If such index found, find just greater element and swap
        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements from i+1 to end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
