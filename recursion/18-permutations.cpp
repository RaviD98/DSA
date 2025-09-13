/*

✅ Problem: Permutations
🔗 Leetcode Link: https://leetcode.com/problems/permutations/

🎯 Given an array `nums` of distinct integers, return all possible permutations of `nums`.
You can return the answer in any order.

🔸 Example 1:
Input  : nums = [1,2,3]
Output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

🔸 Example 2:
Input  : nums = [0,1]
Output : [[0,1],[1,0]]

🔒 Constraints:
1 ≤ nums.length ≤ 6
-10 ≤ nums[i] ≤ 10
All integers of nums are **distinct**.

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Backtracking
// 🕒 Time: O(n! * n) — n! permutations and O(n) to copy into result
// 🛢️ Space: O(n) — recursion stack and temporary path storage
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, path, used, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, vector<int> &path, vector<bool> &used, vector<vector<int>> &result)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
                continue;

            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, path, used, result);

            // backtrack
            path.pop_back();
            used[i] = false;
        }
    }
};

// 🔁 Recursive Swapping
// 🕒 Time: O(n! * n) — n! permutations and O(n) to copy into result
// 🛢️ Space: O(n) — recursion stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
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

        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[index], nums[i]); // swap current element with index
            generate(index + 1, nums, result);
            swap(nums[index], nums[i]); // backtrack
        }
    }
};