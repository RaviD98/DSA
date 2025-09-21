/*
✅ Problem: Implement atoi (String to Integer)
🔗 Link: https://leetcode.com/problems/string-to-integer-atoi/

🎯 Convert a string `s` to a 32-bit signed integer (similar to C/C++ `atoi`).
- Discard leading whitespaces.
- Optional '+' or '-' sign.
- Read digits until non-digit or end of string.
- Clamp result within [-2^31, 2^31-1] if overflow occurs.

*/

// -----------------------------------------------------------------------------
// ✅ Approach: Iterative Parsing
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++; // skip whitespaces

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long res = 0; // use long long to detect overflow
        while (i < n && isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');

            // Clamp to INT_MAX / INT_MIN
            if (sign * res > INT_MAX)
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;

            i++;
        }
        return sign * res;
    }
};
