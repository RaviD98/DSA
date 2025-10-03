/*
✅ Problem: Prefix to Infix Conversion
🔗 Link: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

🎯 Given a prefix expression, convert it into an equivalent infix expression.
Prefix expression: Operator comes before operands (e.g., +AB).
Infix expression: Operands are around operator (e.g., A+B).


🔸 Example 1:
Input  : "*-A/BC-/AKL"
Output : "((A-(B/C))*((A/K)-L))"



// -----------------------------------------------------------------------------
// ✅ Approach: Stack-based Conversion
// - Traverse prefix expression from right to left.
// - If operand → push to stack.
// - If operator → pop two operands from stack, form "(op1 operator op2)", push back.
// - At the end: stack top = result (valid infix).
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

    string prefixToInfix(string exp)
    {
        stack<string> st;
        int n = exp.size();

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            char c = exp[i];

            if (isOperator(c))
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
            else
            {
                st.push(string(1, c)); // operand
            }
        }
        return st.top();
    }
};
