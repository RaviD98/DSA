/*

Problem: Kth Missing Positive Number
Statement: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Link: https://leetcode.com/problems/kth-missing-positive-number/

✅ Approach 1: Brute Force
- Start from 1, check if it's in the array.
- Count missing numbers until we reach k.
Time Complexity: O(n + k)
Space Complexity: O(1)

✅ Approach 2: Binary Search (Efficient)
- Observation: For index i, the number of missing elements before arr[i] is arr[i] - (i + 1).
- We can binary search for the smallest index where missing >= k.
- Answer is arr[left-1] + (k - missingBeforeLast).

Time Complexity: O(log n)
Space Complexity: O(1)

*/

class Solution
{
public:
    // Efficient Binary Search Approach
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1); // how many numbers missing until arr[mid]

            if (missing < k)
            {
                low = mid + 1; // we need more missing numbers
            }
            else
            {
                high = mid - 1; // look left
            }
        }

        // After binary search, 'low' is the position where kth missing lies
        return low + k;
    }
};
