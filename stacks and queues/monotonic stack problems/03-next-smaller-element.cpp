/*

✅ Problem: Next Smaller Element
🔗 Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

Problem Statement:
🎯 Given an array `arr` of integers, find the Next Smaller Element (NSE) for every element in the array.
The Next Smaller Element for an element `x` is the first element to the right of `x` which is smaller than `x`.
If no such element exists, output `-1` for that position.

🔸 Example 1:
Input  : arr = [4, 8, 5, 2, 25]
Output : [2, 5, 2, -1, -1]
Explanation:
- Next smaller for 4 → 2
- Next smaller for 8 → 5
- Next smaller for 5 → 2
- Next smaller for 2 → -1
- Next smaller for 25 → -1

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each element, scan to the right to find the first smaller element
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextSmallerElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] < arr[i])
                {
                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal Approach (Using Monotonic Stack)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Traverse from right to left, maintain increasing stack
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextSmallerElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // will store elements, not indices

        for (int i = n - 1; i >= 0; --i)
        {
            // Pop elements greater or equal to arr[i]
            while (!st.empty() && st.top() >= arr[i])
                st.pop();

            // If stack not empty, top is the next smaller
            if (!st.empty())
                ans[i] = st.top();

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};
