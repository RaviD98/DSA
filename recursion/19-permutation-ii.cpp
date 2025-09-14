/*

✅ Problem: Permutations II (handling duplicates)
🔗 Leetcode Link: https://leetcode.com/problems/permutations-ii/

🎯 Given an array `nums` that may contain duplicates, return all **unique permutations**.

🔸 Example 1:
Input  : nums = [1,1,2]
Output : [[1,1,2],[1,2,1],[2,1,1]]

🔸 Example 2:
Input  : nums = [1,2,3]
Output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

🔒 Constraints:
1 ≤ nums.length ≤ 8
-10 ≤ nums[i] ≤ 10

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Swapping with Set to Avoid Duplicates
// 🕒 Time: O(n! * n) in worst case
// 🛢️ Space: O(n + n!) — recursion stack + result
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        generate(0, nums, result);
        return result;
    }

private:
    void generate(int index, vector<int> &nums, vector<vector<int>> &result)
    {
        if (index == nums.size())
        {
            result.push_back(nums); // store current permutation
            return;
        }

        unordered_set<int> used; // track numbers used at this index
        for (int i = index; i < nums.size(); ++i)
        {
            if (used.count(nums[i]))
                continue; // skip duplicates at this level
            used.insert(nums[i]);

            swap(nums[index], nums[i]);
            generate(index + 1, nums, result);
            swap(nums[index], nums[i]); // backtrack
        }
    }
};
