/*
✅ Problem: Largest Rectangle in Histogram
🔗 Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

🎯 Given an array of integers `heights` representing the histogram's bar heights
where the width of each bar is 1, return the area of the largest rectangle in the histogram.

---

🔸 Example 1:
Input  : heights = [2,1,5,6,2,3]
Output : 10
Explanation: The rectangle [5,6] has area = 5×2 = 10 (max possible).


---

🔒 Constraints:
- 1 ≤ heights.length ≤ 10⁵
- 0 ≤ heights[i] ≤ 10⁴
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force (Check all rectangles)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For every bar, expand left and right to find width of rectangle possible.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int minHeight = heights[i];
            for (int j = i; j < n; j++)
            {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        return maxArea;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Monotonic Stack (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 For each bar, find:
//    - Previous Smaller Element (PSE)
//    - Next Smaller Element (NSE)
// Rectangle width = NSE[i] - PSE[i] - 1
// Area = height[i] * width
// -----------------------------------------------------------------------------

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for NSE
        while (!st.empty())
            st.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Compute max area
        long long maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            long long width = right[i] - left[i] - 1;
            long long area = 1LL * heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return (int)maxArea;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Single Stack One-Pass Solution (Space Efficient)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Push indices in increasing order of heights.
// When a smaller height is found, compute area for bars popped from stack.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            int h = (i == n ? 0 : heights[i]); // sentinel height
            while (!st.empty() && h < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, 1LL * height * width);
            }
            st.push(i);
        }
        return (int)maxArea;
    }
};
