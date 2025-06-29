/*

✅ Problem: Rotate Image
🔗 Link: https://leetcode.com/problems/rotate-image/

Problem Statement:
🎯 You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise) in-place.

🔸 Example:
Input:
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

Output:
matrix = [[7,4,1],
          [8,5,2],
          [9,6,3]]

🔒 Constraints:
- matrix.length == n
- matrix[i].length == n
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

*/

// -----------------------------------------------------------------------------
// 🔵 Optimal In-Place Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Step 1: Transpose the matrix
// 📌 Step 2: Reverse each row
// -----------------------------------------------------------------------------

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose the matrix (swap rows and columns)
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// 4-way swap method
// 🕒 Time: O(n²), 🛢️ Space: O(1)
class Solution
{
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Process layer by layer (from outer to inner)
        for (int layer = 0; layer < n / 2; ++layer)
        {
            int first = layer;        // Starting index of current layer
            int last = n - 1 - layer; // Ending index of current layer

            for (int i = first; i < last; ++i)
            {
                int offset = i - first;

                // 🔁 Save the top value
                int top = matrix[first][i];

                // 🔄 Perform 4-way swap
                matrix[first][i] = matrix[last - offset][first];            // left → top
                matrix[last - offset][first] = matrix[last][last - offset]; // bottom → left
                matrix[last][last - offset] = matrix[i][last];              // right → bottom
                matrix[i][last] = top;                                      // top → right
            }
        }
    }
}