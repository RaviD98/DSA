/*
✅ Problem: Postfix to Prefix Conversion
🔗 Link: https://www.geeksforgeeks.org/postfix-prefix-conversion/

🎯 Given a postfix expression, convert it into an equivalent prefix expression.
Postfix: Operator comes after operands (e.g., AB+)
Prefix : Operator comes before operands (e.g., +AB)

---

🔸 Example 1:
Input  : "ABC/-AK/L-*"
Output : "*-A/BC-/AKL"

🔸 Example 2:
Input  : "AB+CD-*"
Output : "*+AB-CD"

---

Constraints:
1 ≤ |expression| ≤ 10^5
Expression consists of single-letter operands (A–Z, a–z) and operators (+, -, *, /, ^)
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Stack-based Conversion
// 🔹 Traverse postfix expression from left to right.
// 🔹 If operand → push it to stack.
// 🔹 If operator → pop two operands (op2, op1), form new string = operator + op1 + op2
// 🔹 Push this new string back to stack.
// 🔹 Result = stack top.
//
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string postfixToPrefix(string exp)
    {
        stack<string> st;

        for (char c : exp)
        {
            if (isOperator(c))
            {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                string newExp = c + op1 + op2; // prefix form
                st.push(newExp);
            }
            else
            {
                st.push(string(1, c)); // operand
            }
        }

        return st.top();
    }
};
