/*
✅ Problem: Infix to Prefix Conversion
🔗 Link: https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1

🎯 Given an infix expression, convert it to its equivalent prefix expression.
Prefix (Polish Notation): Operator appears before operands (e.g., +AB).
Infix (Normal): Operator appears between operands (e.g., A+B).

---

🔸 Example 1:
Input  : (A-B/C)*(A/K-L)
Output : *-A/BC-/AKL

🔸 Example 2:
Input  : A+(B*C)
Output : +A*BC

---

Constraints:
1 ≤ |expression| ≤ 10^5
Expression consists of uppercase English letters and operators (+, -, *, /, ^)
*/

// -----------------------------------------------------------------------------
// ✅ Approach: Reverse + Infix to Postfix Trick
// 🔹 Step 1: Reverse the infix expression.
// 🔹 Step 2: Replace '(' with ')' and vice versa.
// 🔹 Step 3: Convert the modified expression to postfix using stack rules.
// 🔹 Step 4: Reverse the postfix result to get prefix.
//
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    // Get precedence of operators
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

    string infixToPrefix(string exp)
    {
        // Step 1: Reverse expression
        reverse(exp.begin(), exp.end());

        // Step 2: Swap '(' and ')'
        for (char &c : exp)
        {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        stack<char> st;
        string result = "";

        // Step 3: Infix to Postfix logic (on reversed string)
        for (char c : exp)
        {
            // Operand → directly add
            if (isalnum(c))
                result += c;

            // Opening bracket → push
            else if (c == '(')
                st.push(c);

            // Closing bracket → pop till '('
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // remove '('
            }

            // Operator
            else
            {
                while (!st.empty() && precedence(c) < precedence(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                // For '^' operator (right associative)
                while (!st.empty() && precedence(c) == precedence(st.top()) && c != '^')
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix → prefix
        reverse(result.begin(), result.end());
        return result;
    }
};
