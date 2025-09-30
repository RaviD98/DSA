/*
✅ Problem: Valid Parentheses
🔗 Link: https://leetcode.com/problems/valid-parentheses/

🎯 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

👉 A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.


🔸 Example 1:
Input  : s = "()"
Output : true

🔸 Example 2:
Input  : s = "()[]{}"
Output : true

🔸 Example 3:
Input  : s = "(]"
Output : false



Constraints:
1 ≤ s.length ≤ 10^4
s consists of parentheses only '()[]{}'.
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Stack
// - Use a stack to track opening brackets.
// - For every closing bracket, check top of stack for correct pair.
// - If mismatch or stack empty at wrong time → invalid.
// - At the end, stack must be empty.
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
