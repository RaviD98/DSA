/*

✅ Problem: Remove Outermost Parentheses
🔗 Link: https://leetcode.com/problems/remove-outermost-parentheses/

🎯 A valid parentheses string is either empty "", "(" + A + ")",
or A + B where A and B are valid parentheses strings.

👉 Given a valid parentheses string `s`, remove the outermost parentheses
of every primitive string inside `s`.

---

🔸 Example 1:
Input  : s = "(()())(())"
Output : "()()()"
Explanation:
- Primitive decomposition: "(()())" + "(())"
- After removing outermost: "()" + "()" = "()()()"

🔸 Example 2:
Input  : s = "(()())(())(()(()))"
Output : "()()()()(())"

🔸 Example 3:
Input  : s = "()()"
Output : ""

---

Constraints:
1 ≤ s.length ≤ 10^5
s[i] is either '(' or ')'
s is a valid parentheses string.

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Count Balance
// 🕒 Time: O(n), 🛢️ Space: O(1) (excluding result string)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";
        int balance = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                if (balance > 0)
                    result += c; // not outermost
                balance++;
            }
            else
            {
                balance--;
                if (balance > 0)
                    result += c; // not outermost
            }
        }
        return result;
    }
};
