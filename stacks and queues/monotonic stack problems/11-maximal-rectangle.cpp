/*
✅ Problem: Maximal Rectangle
🔗 Link: https://leetcode.com/problems/maximal-rectangle/

🎯 Given a binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

This problem extends the **Largest Rectangle in Histogram** concept
(row-by-row accumulation of heights).

---

🔸 Example 1:
Input:
matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
Explanation:
The maximal rectangle is 3 rows by 2 columns (area = 6).

---

🔒 Constraints:
- 1 ≤ matrix.length ≤ 200
- 1 ≤ matrix[0].length ≤ 200
- matrix[i][j] is '0' or '1'
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Histogram Extension (Brute Force for Each Row)
// 🕒 Time: O(n * m²), 🛢️ Space: O(m)
// 📌 For each row, build histogram heights and compute max rectangle
//     using brute force min height expansion.
// -----------------------------------------------------------------------------

class Solution_BruteForce
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            // Update histogram heights
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Compute max area for this row (brute force)
            for (int j = 0; j < m; j++)
            {
                int minHeight = height[j];
                for (int k = j; k < m; k++)
                {
                    minHeight = min(minHeight, height[k]);
                    maxArea = max(maxArea, minHeight * (k - j + 1));
                }
            }
        }

        return maxArea;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Using Monotonic Stack + Histogram Logic
// 🕒 Time: O(n * m), 🛢️ Space: O(m)
// 📌 For each row, treat it as a histogram and apply
//     the Largest Rectangle in Histogram algorithm.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int largestRectangleHistogram(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        long long maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            int h = (i == n ? 0 : heights[i]);
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }

            maxArea = max(maxArea, largestRectangleHistogram(height));
        }

        return maxArea;
    }
};
