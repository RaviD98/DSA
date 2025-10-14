/*
✅ Problem: Remove K Digits
🔗 Link: https://leetcode.com/problems/remove-k-digits/

🎯 Given a string `num` representing a non-negative integer, remove exactly `k` digits
so that the resulting number is the smallest possible.

Return the result as a string, removing any leading zeros.
If the result is an empty string, return "0".

---

🔸 Example 1:
Input  : num = "1432219", k = 3
Output : "1219"
Explanation: Remove digits 4, 3, and 2 to get the smallest number.

---

🔒 Constraints:
- 1 ≤ num.length ≤ 10⁵
- 0 ≤ k ≤ num.length
- `num` consists of digits only.
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force (Generate all possibilities)
// 🕒 Time: O(n^2 * k), 🛢️ Space: O(1)
// 📌 Try removing one digit at a time and track the minimum possible number.
// ❌ Not feasible for large inputs (TLE for n > 100).
// -----------------------------------------------------------------------------

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        for (int t = 0; t < k; t++)
        {
            int n = num.size();
            int i = 0;

            // Find the first peak (digit greater than the next one)
            while (i + 1 < n && num[i] <= num[i + 1])
                i++;

            // Remove that digit
            num.erase(num.begin() + i);

            // Remove leading zeros
            int pos = 0;
            while (pos < num.size() && num[pos] == '0')
                pos++;
            num = num.substr(pos);

            // If all digits are removed
            if (num.empty())
                return "0";
        }
        return num;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Monotonic Stack (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Maintain a monotonic increasing stack — if a current digit is smaller than
// the top of stack and we still can remove digits, pop it.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string st; // acts as a stack

        for (char digit : num)
        {
            // Remove previous larger digits (to make number smaller)
            while (!st.empty() && k > 0 && st.back() > digit)
            {
                st.pop_back();
                k--;
            }

            // Push current digit if it's not a leading zero
            if (!st.empty() || digit != '0')
                st.push_back(digit);
        }

        // If still k > 0, remove from the end
        while (!st.empty() && k > 0)
        {
            st.pop_back();
            k--;
        }

        // If result is empty
        return st.empty() ? "0" : st;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Using std::vector as stack (cleaner syntax)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Same as stack logic, but with numeric vector for clarity.
// -----------------------------------------------------------------------------

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> st;

        for (char c : num)
        {
            while (!st.empty() && k > 0 && st.back() > c)
            {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If still digits left to remove
        while (k-- > 0 && !st.empty())
            st.pop_back();

        // Construct final result and remove leading zeros
        string res(st.begin(), st.end());
        int pos = 0;
        while (pos < res.size() && res[pos] == '0')
            pos++;
        res = res.substr(pos);

        return res.empty() ? "0" : res;
    }
};
