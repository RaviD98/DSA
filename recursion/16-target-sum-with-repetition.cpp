/*

✅ Problem: Combination Sum (with repetition allowed)
🔗 Leetcode Link: https://leetcode.com/problems/combination-sum/

🎯 Given an array of distinct integers candidates and a target integer target,
return all unique combinations of candidates where the chosen numbers sum to target.
The same number may be chosen from candidates an unlimited number of times.

Two combinations are unique if the frequency of at least one of the chosen numbers is different.

🔸 Example 1:
Input  : candidates = [2,3,6,7], target = 7
Output : [[2,2,3],[7]]
Explanation:
2 and 3 can form (2+2+3 = 7).
Also, 7 itself is a valid combination.

🔸 Example 2:
Input  : candidates = [2,3,5], target = 8
Output : [[2,2,2,2],[2,3,3],[3,5]]

🔸 Example 3:
Input  : candidates = [2], target = 1
Output : []

🔒 Constraints:
1 ≤ candidates.length ≤ 30
2 ≤ candidates[i] ≤ 40
All elements of candidates are distinct.
1 ≤ target ≤ 40

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Backtracking
// 🕒 Time: O(2^t) where t = target (try or skip each candidate recursively)
// 🛢️ Space: O(t) recursion stack depth
// 📌 At each step: either pick the current number (can reuse it) or skip to next
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        dfs(0, target, candidates, current, result);
        return result;
    }

private:
    void dfs(int index, int target, vector<int> &candidates,
             vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current); // found a valid combination
            return;
        }
        if (index >= candidates.size() || target < 0)
            return;

        // ✅ Choice 1: Pick current candidate (can reuse)
        current.push_back(candidates[index]);
        dfs(index, target - candidates[index], candidates, current, result);
        current.pop_back(); // backtrack

        // ✅ Choice 2: Skip current candidate
        dfs(index + 1, target, candidates, current, result);
    }
};
