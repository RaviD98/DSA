/*

✅ Problem: Number of Next Greater Elements to the Right
🔗 Link: https://takeuforward.org/data-structure/number-of-nges-to-the-right
📘 Similar: https://leetcode.com/problems/next-greater-element-i/

🎯 Given an array `arr` of size `n`, find the Next Greater Element (NGE) for each element.
The NGE of an element is the nearest element on its right that is greater than it.
If no such element exists, store `-1`.

---

🔸 Example 1:
Input  : arr = [1, 3, 2, 4]
Output : [3, 4, 4, -1]
Explanation:
- Next greater of 1 → 3
- Next greater of 3 → 4
- Next greater of 2 → 4
- Next greater of 4 → -1


---

🔒 Constraints:
1 ≤ n ≤ 10^5
0 ≤ arr[i] ≤ 10^9

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each element, scan the right side to find the first greater element
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] > arr[i])
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
// 📌 Traverse from right to left and maintain a stack of potential NGEs.
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores potential NGEs

        for (int i = n - 1; i >= 0; --i)
        {
            // Pop smaller or equal elements
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            // If stack not empty, top is the next greater
            if (!st.empty())
                ans[i] = st.top();

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};
