/*

Problem: Matrix Median
Link: https://www.interviewbit.com/problems/matrix-median/

✅ Problem Statement:
You are given a matrix of size `R x C`:
- Each row of the matrix is sorted in non-decreasing order.
- Your task is to find the median of the entire matrix.

⚠️ Constraints:
- R, C are odd → So the total number of elements (R*C) is odd.
- 1 ≤ R, C ≤ 400
- 1 ≤ mat[i][j] ≤ 10^9

✅ Key Insight:
- If we flatten the matrix → it becomes a sorted array → we can find median easily.
- But flattening costs O(R*C log(R*C)) which is too slow for large inputs.

✅ Optimized Approach: Binary Search on Value Range
1. The smallest element is in the first column, and largest is in the last column.
2. Perform binary search on value range:
   - mid = (low + high) / 2
   - Count how many elements in the matrix ≤ mid (using upper_bound in each row).
   - If count ≤ (R*C)/2 → median lies on the right.
   - Else move left.
3. The first number such that count > (R*C)/2 is the median.

✅ Time Complexity: O(R * logC * log(maxVal))
   - log(maxVal) → Binary search on range [min..max]
   - logC → Binary search in each row (upper_bound)
   - R rows processed
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    int matrixMedian(vector<vector<int>> &mat)
    {
        int R = mat.size(), C = mat[0].size();

        // find global min and max
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(low, mat[i][0]);       // smallest in row
            high = max(high, mat[i][C - 1]); // largest in row
        }

        int desired = (R * C + 1) / 2; // position of median

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // count how many elements <= mid
            int count = 0;
            for (int i = 0; i < R; i++)
            {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count < desired)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
