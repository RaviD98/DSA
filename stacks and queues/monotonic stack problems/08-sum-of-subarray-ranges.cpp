/*
✅ Problem: Sum of Subarray Ranges
🔗 Link: https://leetcode.com/problems/sum-of-subarray-ranges/

🎯 Given an integer array `nums`, return the sum of the ranges of all subarrays.
The range of a subarray is the difference between the maximum and minimum elements.


🔸 Example 1:
Input  : nums = [1,2,3]
Output : 4
Explanation:
Subarrays and their ranges:
[1] → 0, [2] → 0, [3] → 0, [1,2] → 1, [2,3] → 1, [1,2,3] → 2
Sum = 0+0+0+1+1+2 = 4


🔒 Constraints:
1 ≤ nums.length ≤ 1000
-10^9 ≤ nums[i] ≤ 10^9

*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n^3), 🛢️ Space: O(1)
// 📌 Iterate over all subarrays, compute min and max for each, sum the differences.
// -----------------------------------------------------------------------------

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long total = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int mn = nums[i], mx = nums[i];
                for (int k = i; k <= j; k++)
                {
                    mn = min(mn, nums[k]);
                    mx = max(mx, nums[k]);
                }
                total += (mx - mn);
            }
        }
        return total;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Using Stack / Contribution Technique (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Each element contributes as max in some subarrays and as min in some subarrays.
// Contribution = (number of subarrays where it is max) - (number of subarrays where it is min) * value
// -----------------------------------------------------------------------------

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nextGreater(n), prevGreater(n);
        vector<int> nextSmaller(n), prevSmaller(n);

        stack<int> st;

        // Next Greater
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            nextGreater[st.top()] = n;
            st.pop();
        }

        // Previous Greater
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            prevGreater[st.top()] = -1;
            st.pop();
        }

        // Next Smaller
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            nextSmaller[st.top()] = n;
            st.pop();
        }

        // Previous Smaller
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            prevSmaller[st.top()] = -1;
            st.pop();
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long maxCount = (long long)(i - prevGreater[i]) * (nextGreater[i] - i);
            long long minCount = (long long)(i - prevSmaller[i]) * (nextSmaller[i] - i);
            res += (maxCount - minCount) * (long long)nums[i];
        }
        return res;
    }
};
