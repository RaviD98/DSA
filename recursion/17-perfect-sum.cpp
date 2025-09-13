/*

✅ Problem: Perfect Sum Problem
🔗 GFG Link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

🎯 Given an array `arr[]` of non-negative integers and a sum `target`,
count the number of subsets of `arr` having sum exactly equal to `target`.

Return the count modulo 1e9+7.

🔸 Example 1:
Input  : arr = [5, 2, 3, 10, 6, 8], target = 10
Output : 3
Explanation: Subsets are {5,2,3}, {2,8}, {10}

🔸 Example 2:
Input  : arr = [2, 5, 1, 4, 3], target = 10
Output : 3
Explanation: Subsets are {2,1,4,3}, {5,1,4}, {2,5,3}

🔒 Constraints:
1 ≤ arr.length ≤ 100
0 ≤ arr[i] ≤ 1000
0 ≤ target ≤ 1000

*/

// -----------------------------------------------------------------------------
// 🔁 Plain Recursion
// 🕒 Time: O(2^n) — explore all subsets
// 🛢️ Space: O(n) — recursion stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        const int MOD = 1e9 + 7;
        return countSubsets(0, target, arr, MOD);
    }

private:
    int countSubsets(int index, int target, vector<int> &arr, const int MOD)
    {
        if (index == arr.size())
        {
            return target == 0 ? 1 : 0;
        }

        // ✅ Choice 1: exclude current element
        int notTake = countSubsets(index + 1, target, arr, MOD);

        // ✅ Choice 2: include current element if it fits
        int take = 0;
        if (arr[index] <= target)
        {
            take = countSubsets(index + 1, target - arr[index], arr, MOD);
        }

        return (take + notTake) % MOD;
    }
};
