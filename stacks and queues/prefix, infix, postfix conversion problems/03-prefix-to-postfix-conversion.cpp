/*
✅ Problem: Prefix to Postfix Conversion
🔗 Link: https://www.geeksforgeeks.org/prefix-postfix-conversion/

🎯 Given a prefix expression, convert it into an equivalent postfix expression.
Prefix expression: Operator comes before operands (e.g., +AB)
Postfix expression: Operator comes after operands (e.g., AB+)

---

🔸 Example 1:
Input  : "*-A/BC-/AKL"
Output : "ABC/-AK/L-*"

🔸 Example 2:
Input  : "+AB"
Output : "AB+"

---

Constraints:
1 ≤ |expression| ≤ 10^5
Expression consists of single-letter operands (A–Z, a–z) and operators (+, -, *, /, ^)
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Stack-based Conversion
// 🔹 Traverse prefix expression from right to left.
// 🔹 If operand → push it to stack.
// 🔹 If operator → pop two operands (op1, op2), form new string = op1 + op2 + operator
// 🔹 Push the new expression back to stack.
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

    string prefixToPostfix(string exp)
    {
        stack<string> st;
        int n = exp.size();

        // Traverse right to left
        for (int i = n - 1; i >= 0; i--)
        {
            char c = exp[i];

            if (isOperator(c))
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string newExp = op1 + op2 + c; // postfix order
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
