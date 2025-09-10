/*

✅ Problem: Print All Subsequences of a String using Recursion
🔗 No direct Leetcode/GFG link — but very important for recursion & backtracking

Problem Statement:
🎯 Given a string `s`, print **all possible subsequences** of the string.
A subsequence is a sequence that can be derived by deleting some or no characters
without changing the order of the remaining characters.

🔸 Example:
Input  : s = "abc"
Output : "", "a", "b", "c", "ab", "ac", "bc", "abc"

🔒 Constraints:
1 ≤ s.length ≤ 15

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Backtracking Approach
// 🕒 Time: O(2^n), 🛢️ Space: O(n) — recursion stack (depth = n)
// 📌 At each step, include the current character or exclude it
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<string> subsequences(string &s)
    {
        vector<string> result;
        string current = "";
        generate(0, s, current, result);
        return result;
    }

private:
    void generate(int index, string &s, string &current, vector<string> &result)
    {
        if (index == s.length())
        {
            result.push_back(current); // reached end, save current subsequence
            return;
        }

        // Include current character
        current.push_back(s[index]);
        generate(index + 1, s, current, result);

        // Backtrack and exclude current character
        current.pop_back();
        generate(index + 1, s, current, result);
    }
};
