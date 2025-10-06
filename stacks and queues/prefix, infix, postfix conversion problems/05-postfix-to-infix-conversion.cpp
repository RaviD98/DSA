/*
✅ Problem: Postfix to Infix Conversion
🔗 Link: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

🎯 Given a postfix expression, convert it into its equivalent infix expression.
Postfix: Operator comes after operands (e.g., AB+)
Infix  : Operator comes between operands (e.g., A+B)

---

🔸 Example 1:
Input  : "ab+c+"
Output : "((a+b)+c)"

🔸 Example 2:
Input  : "AB+CD-*"
Output : "((A+B)*(C-D))"

---

Constraints:
1 ≤ |expression| ≤ 10^5
Expression consists of single-letter operands (A–Z, a–z) and operators (+, -, *, /, ^)
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Stack-based Conversion
// 🔹 Traverse postfix expression from left to right.
// 🔹 If operand → push to stack.
// 🔹 If operator → pop two operands (op2, op1), form new string = "(" + op1 + operator + op2 + ")"
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

    string postfixToInfix(string exp)
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
                string newExp = "(" + op1 + c + op2 + ")";
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
