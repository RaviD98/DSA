/*

✅ Problem: Pascal's Triangle
🔗 Link: https://leetcode.com/problems/pascals-triangle/

Problem Statement:
🎯 Given an integer numRows, return the first numRows of Pascal's Triangle.

In Pascal's Triangle, each number is the sum of the two numbers directly above it.

🔸 Example:
Input  : numRows = 5
Output : [
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
]

🔒 Constraints:
- 1 <= numRows <= 30

*/

// -----------------------------------------------------------------------------
// 🔵 Iterative Build Row-by-Row
// 🕒 Time: O(n²), 🛢️ Space: O(n²)
// 📌 Use previous row to compute current row
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; ++row)
        {
            vector<int> current(row + 1, 1); // first and last elements are always 1

            // Fill middle values
            for (int j = 1; j < row; ++j)   
            {
                current[j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};
