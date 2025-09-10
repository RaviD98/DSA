/*

✅ Problem: Subset Sum using Recursion
🔗 Related GFG Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1

🎯 Given an array of integers, generate all possible subset sums using recursion
(i.e., sum of every subsequence). Return them in **non-decreasing order**.

🔸 Example 1:
Input  : arr = [2, 3], n = 2
Output : [0, 2, 3, 5]

🔸 Example 2:
Input  : arr = [5, 2, 1], n = 3
Output : [0, 1, 2, 3, 5, 6, 7, 8]

🔒 Constraints:
1 ≤ n ≤ 15
0 ≤ arr[i] ≤ 10⁴

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Subset Sum (Backtracking)
// 🕒 Time: O(2^n), 🛢️ Space: O(2^n) for storing all sums + O(n) recursion stack
// 📌 At each step, either include or exclude the current element in sum
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> subsetSums(vector<int> &arr, int n)
    {
        vector<int> result;
        generateSums(0, 0, arr, n, result);
        sort(result.begin(), result.end()); // required by problem
        return result;
    }

private:
    void generateSums(int index, int currentSum, vector<int> &arr, int n, vector<int> &result)
    {
        if (index == n)
        {
            result.push_back(currentSum);
            return;
        }

        // Include current element
        generateSums(index + 1, currentSum + arr[index], arr, n, result);

        // Exclude current element
        generateSums(index + 1, currentSum, arr, n, result);
    }
};
