/*
✅ Problem: Infix to Postfix Conversion
🔗 Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/

🎯 Given an infix expression as input, convert it into a postfix expression.
Infix expression: Operators are between operands (e.g., A + B).
Postfix expression: Operators come after operands (e.g., AB+).

👉 Handle precedence and associativity of operators correctly.

---

🔸 Example 1:
Input  : "a+b*(c^d-e)^(f+g*h)-i"
Output : "abcd^e-fgh*+^*+i-"

🔸 Example 2:
Input  : "A*(B+C)/D"
Output : "ABC+*D/"

---

Constraints:
1 ≤ |expression| ≤ 10^5
The expression contains only single-letter operands and operators +,-,*,/,^,(,).
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Stack-based Conversion (Shunting Yard Algorithm)
// - Use a stack for operators and a string for output.
// - Rules:
//   1. If operand → append to result.
//   2. If '(' → push to stack.
//   3. If ')' → pop until '('.
//   4. Else (operator):
//        - While stack not empty and precedence(top) >= precedence(current)
//          (except '^' which is right-associative),
//          pop from stack to result.
//        - Push current operator to stack.
// - At the end: pop all operators from stack.
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    string infixToPostfix(string s)
    {
        stack<char> st;
        string result = "";

        for (char c : s)
        {
            if (isalnum(c))
            {
                result += c; // operand
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            else
            { // operator
                while (!st.empty() &&
                       ((precedence(st.top()) > precedence(c)) ||
                        (precedence(st.top()) == precedence(c) && c != '^')) &&
                       st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
