/*
✅ Problem: Maximum Nesting Depth of the Parentheses
🔗 Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

🎯 Given a valid parentheses string `s`, return the maximum nesting depth.


🔸 Example 1:
Input  : s = "(1+(2*3)+((8)/4))+1"
Output : 3
Explanation: The deepest nested parentheses are "((8)/4)".

🔸 Example 2:
Input  : s = "(1)+((2))+(((3)))"
Output : 3

🔸 Example 3:
Input  : s = "1+(2*3)/(2-1)"
Output : 1

Constraints:
1 ≤ s.length ≤ 100
s consists of digits, '+', '-', '*', '/', '(', ')'.
s is a valid expression.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Counter (Track Open Brackets)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0, maxDepth = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (c == ')')
            {
                depth--;
            }
        }
        return maxDepth;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Stack Simulation
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int maxDepth = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            }
            else if (c == ')')
            {
                st.pop();
            }
        }
        return maxDepth;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: Recursion (DFS style parsing)
// 🕒 Time: O(n), 🛢️ Space: O(n) (recursion stack)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxDepth(string s)
    {
        return helper(s, 0, 0, 0);
    }

private:
    int helper(const string &s, int idx, int depth, int maxDepth)
    {
        if (idx == s.size())
            return maxDepth;

        if (s[idx] == '(')
            return helper(s, idx + 1, depth + 1, max(maxDepth, depth + 1));
        else if (s[idx] == ')')
            return helper(s, idx + 1, depth - 1, maxDepth);
        else
            return helper(s, idx + 1, depth, maxDepth);
    }
};
