/*

✅ Problem: Find Target Sum Ways (Add '+' or '-' to reach target)
🔗 Leetcode Link: https://leetcode.com/problems/target-sum/

🎯 Given an integer array `nums` and a target integer `target`,
count the number of ways to assign '+' or '-' signs to each number
such that the final sum is equal to the target.

🔸 Example 1:
Input  : nums = [1,1,1,1,1], target = 3
Output : 5
Explanation: There are 5 ways to reach sum 3 using + and - on elements.

🔸 Example 2:
Input  : nums = [2, 1], target = 1
Output : 1

🔒 Constraints:
1 ≤ nums.length ≤ 20
0 ≤ nums[i] ≤ 1000
0 ≤ target ≤ 1000

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Backtracking
// 🕒 Time: O(2^n), 🛢️ Space: O(n) — recursion stack
// 📌 At each index, try adding and subtracting the current number
// -----------------------------------------------------------------------------

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countWays(0, 0, nums, target);
    }

private:
    int countWays(int index, int currentSum, vector<int> &nums, int target)
    {
        if (index == nums.size())
        {
            return currentSum == target ? 1 : 0;
        }

        // Try adding and subtracting current number
        int add = countWays(index + 1, currentSum + nums[index], nums, target);
        int subtract = countWays(index + 1, currentSum - nums[index], nums, target);

        return add + subtract;
    }
};
