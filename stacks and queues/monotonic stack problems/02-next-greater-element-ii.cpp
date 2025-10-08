/*

✅ Problem: Next Greater Element II
🔗 Link: https://leetcode.com/problems/next-greater-element-ii/

Problem Statement:
🎯 Given a circular integer array `nums`, find the next greater number for every element.
The next greater number is the first greater number you encounter when traversing the array **circularly** (after the last element, continue from the start).

If no such number exists, return -1 for that element.

🔸 Example:
Input  : nums = [1,2,1]
Output : [2,-1,2]
Explanation:
- For 1 → next greater is 2
- For 2 → none → -1
- For 1 (last) → next greater is 2 (circularly)

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each element, look forward circularly to find the next greater
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                int next = nums[(i + j) % n]; // circular index
                if (next > nums[i])
                {
                    ans[i] = next;
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
// 📌 Traverse twice (simulate circular array), use stack to store indices
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        // Traverse array twice for circular effect
        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int num = nums[i % n];

            // Maintain decreasing stack
            while (!st.empty() && st.top() <= num)
                st.pop();

            // If within first pass, fill answer
            if (i < n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(num);
        }

        return ans;
    }
};
