/*
Problem: Find Peak Element II (2D Matrix)
Link: https://leetcode.com/problems/find-a-peak-element-ii/

✅ Problem Statement:
You are given a 2D matrix `mat` where:
- `mat[i][j]` is an integer.
- A **peak element** is one that is strictly greater than its neighbors (up, down, left, right).
- The task is to find **any peak element’s position (i, j)**.

It is guaranteed that at least one peak exists.

✅ Key Insight:
- Instead of searching the whole 2D matrix, we can use **Binary Search on columns**.
- In each column:
  1. Find the row with the maximum element in that column.
  2. Compare it with its left & right neighbors.
  3. If it’s greater, that’s our peak.
  4. Otherwise, move search to the side with the larger neighbor.

✅ Approach:
1. Start with `low = 0`, `high = m-1` (columns).
2. While searching:
   - Find middle column `mid`.
   - Get the row `maxRow` with max element in `mid` column.
   - Check neighbors:
     - If it’s greater than both sides → return {maxRow, mid}.
     - Else move left or right accordingly.
3. Return the found coordinates.

✅ Time Complexity: O(n log m)
   (Finding max in a column → O(n), repeated log m times)
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // find max element row in current column
            int maxRow = 0;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            bool left = (mid - 1 >= 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool right = (mid + 1 < m && mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!left && !right)
            {
                return {maxRow, mid}; // found peak
            }
            else if (right)
            {
                low = mid + 1; // move right
            }
            else
            {
                high = mid - 1; // move left
            }
        }
        return {-1, -1}; // should never reach here
    }
};
