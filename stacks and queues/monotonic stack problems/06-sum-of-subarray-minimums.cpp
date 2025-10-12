/*

✅ Problem: Sum of Subarray Minimums
🔗 Link: https://leetcode.com/problems/sum-of-subarray-minimums/

🎯 Given an integer array `arr`, return the sum of the minimum value of every subarray of `arr`.
Since the answer may be large, return it modulo 10^9 + 7.

---

🔸 Example 1:
Input  : arr = [3,1,2,4]
Output : 17
Explanation:
Subarrays are:
[3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
Minimums are:
3, 1, 2, 4, 1, 1, 2, 1, 1, 1 → sum = 17



---

🔒 Constraints:
1 ≤ arr.length ≤ 3 * 10^4
1 ≤ arr[i] ≤ 10^9

*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For every subarray, find the minimum element and add it to the total sum.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            int currMin = arr[i];
            for (int j = i; j < n; j++)
            {
                currMin = min(currMin, arr[j]);
                total = (total + currMin) % MOD;
            }
        }

        return (int)total;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Monotonic Stack (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Each element contributes as the minimum for some subarrays.
// Let `left[i]` = distance to previous smaller element (exclusive)
// and `right[i]` = distance to next smaller element (exclusive).
// Contribution = arr[i] * left[i] * right[i]
// -----------------------------------------------------------------------------

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Find distance to previous smaller element (strictly smaller)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // Clear stack for next computation
        while (!st.empty())
            st.pop();

        // Find distance to next smaller element (smaller OR equal)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
            total = (total + contrib) % MOD;
        }

        return (int)total;
    }
};
