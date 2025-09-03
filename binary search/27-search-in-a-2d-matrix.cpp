/*

Problem: Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/

✅ Problem Statement:
You are given an m x n integer matrix `matrix` where each row is sorted in ascending order
from left to right, and the first integer of each row is greater than the last integer of
the previous row.

Given an integer `target`, return true if target is in matrix, otherwise return false.

✅ Key Insight:
- The matrix can be "flattened" into a **sorted 1D array**.
- Thus, we can apply **Binary Search** in two ways:
  1. Binary search treating the matrix as a flattened array.
  2. Smarter row + column search from top-right.

✅ Approaches:

1️⃣ **Binary Search (Flattened Indexing)**
- Treat `matrix` as 1D of size `m*n`.
- mid → map to (row = mid / n, col = mid % n).
- Compare and adjust bounds.

   ⏱ Time: O(log(m*n))
   💾 Space: O(1)

2️⃣ **Row + Column Search**
- Start from top-right (matrix[0][n-1]).
- If target < current → move left.
- If target > current → move down.
- If equal → found.

   ⏱ Time: O(m + n)
   💾 Space: O(1)

✅ Best Choice: Approach 1 (Binary Search), as it’s cleaner and optimal.

*/

class Solution
{
public:
    // ✅ Approach 1: Binary Search (Flattened Indexing)
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / n, col = mid % n;
            int value = matrix[row][col];

            if (value == target)
                return true;
            else if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    // ✅ Approach 2: Row + Column Search
    bool searchMatrix2(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;

        while (row < m && col >= 0)
        {
            int value = matrix[row][col];
            if (value == target)
                return true;
            else if (value > target)
                col--; // move left
            else
                row++; // move down
        }
        return false;
    }
};
