/*

Problem: Row with max 1s
Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

✅ Problem Statement:
Given a boolean 2D array mat[][] of size n x m where each row is sorted,
find the index of the row that has the maximum number of 1s.
If there are multiple rows with the same maximum, return the smallest index.
If no 1 is present, return -1.

✅ Key Insight:
Since each row is sorted (0s first, then 1s), we can efficiently count 1s using binary search.

✅ Approaches:
1. Brute Force (O(n*m)):
   Count 1s in each row and track the maximum.
2. Optimized Binary Search (O(n*log m)):
   For each row, use binary search to find the first 1 → number of 1s = m - index.
3. Most Optimal (O(n+m)):
   Start from top-right corner and move left/down like a staircase:
     - If mat[i][j] == 1 → move left (possible better row).
     - If mat[i][j] == 0 → move down.
   This ensures only n+m steps.

✅ Time Complexity: O(n+m) (Best Approach)
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();    // total rows
        int m = mat[0].size(); // total cols

        int maxRowIndex = -1;
        int j = m - 1; // start from top-right corner

        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && mat[i][j] == 1)
            {
                j--;             // move left
                maxRowIndex = i; // update row index
            }
        }
        return maxRowIndex;
    }
};
