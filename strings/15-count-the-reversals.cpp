/*
✅ Problem: Minimum Number of Bracket Reversals
🔗 Link: https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

🎯 Given a string `expr` consisting only of '{' and '}',
the task is to find the minimum number of reversals required to make the expression balanced.

---

🔸 Example 1:
Input  : expr = "}{{}}{{{"
Output : 3
Explanation:
To make the expression balanced, we can:
- Reverse the first bracket: "}{... → {..."
- Reverse the last two: "{{{ → }}}"
Total 3 reversals.

🔸 Example 2:
Input  : expr = "{{}{{{}{{}}{{"
Output : -1
Explanation:
Odd length string → cannot be balanced.

---

🔒 Constraints:
1 ≤ |expr| ≤ 10^5
expr contains only '{' and '}'.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Stack-Based Counting
// - Push/pop brackets using stack
// - After scanning, count unbalanced '{' and '}'
// - Formula: (open+1)/2 + (close+1)/2
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countRev(string expr)
    {
        int n = expr.length();
        if (n % 2 != 0)
            return -1; // odd length → impossible

        stack<char> st;
        for (char c : expr)
        {
            if (c == '{')
            {
                st.push(c);
            }
            else
            {
                if (!st.empty() && st.top() == '{')
                    st.pop(); // balanced pair
                else
                    st.push(c);
            }
        }

        int open = 0, close = 0;
        while (!st.empty())
        {
            if (st.top() == '{')
                open++;
            else
                close++;
            st.pop();
        }

        return (open + 1) / 2 + (close + 1) / 2;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Without Stack (Optimized Counting)
// - Track imbalance of open/close brackets
// - If closing bracket comes with no matching open, count it separately
// - Finally compute reversals
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countRev(string expr)
    {
        int n = expr.length();
        if (n % 2 != 0)
            return -1;

        int open = 0, close = 0;

        for (char c : expr)
        {
            if (c == '{')
            {
                open++;
            }
            else
            {
                if (open > 0)
                    open--; // matched
                else
                    close++; // unbalanced close
            }
        }

        // open = unmatched '{'
        // close = unmatched '}'
        return (open + 1) / 2 + (close + 1) / 2;
    }
};
