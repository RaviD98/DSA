/*

✅ Problem: Generate All Valid Parentheses Combinations
🔗 Leetcode Link: https://leetcode.com/problems/generate-parentheses/

🎯 Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

🔸 Example 1:
Input  : n = 3
Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]

🔒 Constraints:
1 ≤ n ≤ 8

*/

// -----------------------------------------------------------------------------
// 🔁 Backtracking Approach
// 🕒 Time: O(2^n) — pruning reduces it from brute force 2^(2n)
// 🛢️ Space: O(n) per recursion call stack + output storage
// 📌 Add '(' if open < n, add ')' if close < open
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current = "";
        backtrack(n, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(int n, int open, int close, string &current, vector<string> &result)
    {
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have left to place
        if (open < n)
        {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back(); // backtrack
        }

        // Add ')' if it won't exceed the number of '('
        if (close < open)
        {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};
