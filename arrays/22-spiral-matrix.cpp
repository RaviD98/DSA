/*

✅ Problem: Spiral Matrix
🔗 Link: https://leetcode.com/problems/spiral-matrix/

Problem Statement:
🎯 Given an m x n matrix, return all elements of the matrix in spiral order.

🔸 Example:
Input  : matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output : [1,2,3,6,9,8,7,4,5]

🔒 Constraints:
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100

*/

// -----------------------------------------------------------------------------
// 🔵 Boundary Traversal Approach
// 🕒 Time: O(m*n), 🛢️ Space: O(1) (excluding output vector)
// 📌 Move in 4 directions: left to right, top to bottom, right to left, bottom to top
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse from left to right
            for (int col = left; col <= right; ++col)
                result.push_back(matrix[top][col]);
            top++;

            // Traverse from top to bottom
            for (int row = top; row <= bottom; ++row)
                result.push_back(matrix[row][right]);
            right--;

            // Traverse from right to left, if there's a remaining row
            if (top <= bottom)
            {
                for (int col = right; col >= left; --col)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }

            // Traverse from bottom to top, if there's a remaining column
            if (left <= right)
            {
                for (int row = bottom; row >= top; --row)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }

        return result;
    }
};
