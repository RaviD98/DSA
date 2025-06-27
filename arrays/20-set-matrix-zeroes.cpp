/*

✅ Problem: Set Matrix Zeroes
🔗 Link: https://leetcode.com/problems/set-matrix-zeroes/

Problem Statement:
🎯 Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place.

🔸 Example:
Input:
matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output:
[[1,0,1],[0,0,0],[1,0,1]]

🔒 Constraints:
- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -2³¹ <= matrix[i][j] <= 2³¹ - 1

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Mark with temp value)
// 🕒 Time: O(n*m * (n + m)), 🛢️ Space: O(1)
// 📌 For each 0, mark its row & col as temp (-1e9), then replace
// -----------------------------------------------------------------------------

// Skipping due to inefficiency and potential bugs with overlapping updates

// -----------------------------------------------------------------------------
// 🟢 Better Approach: Use Extra Arrays
// 🕒 Time: O(n*m), 🛢️ Space: O(n + m)
// 📌 Store row[] and col[] flags, then update accordingly
// -----------------------------------------------------------------------------

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> row(rows, false);
        vector<bool> col(cols, false);

        // Mark rows and cols that need to be zeroed
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Update the matrix
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal In-Place Approach (Use matrix as marker)
// 🕒 Time: O(n*m), 🛢️ Space: O(1)
// 📌 Use first row & first column to store markers
// -----------------------------------------------------------------------------

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Step 1: Check if first row/col need to be zeroed
        for (int i = 0; i < rows; ++i)
            if (matrix[i][0] == 0)
                firstColZero = true;

        for (int j = 0; j < cols; ++j)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        // Step 2: Use first row and col to mark zeros
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: Set zeroes based on markers
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Step 4: Update first row and column if needed
        if (firstColZero)
        {
            for (int i = 0; i < rows; ++i)
                matrix[i][0] = 0;
        }

        if (firstRowZero)
        {
            for (int j = 0; j < cols; ++j)
                matrix[0][j] = 0;
        }
    }
};
