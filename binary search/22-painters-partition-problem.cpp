/*

Problem: Painter's Partition Problem
Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

✅ Problem Statement:
You are given `n` boards of different lengths, and `k` painters.
Each painter paints continuous boards only, and each unit of board takes 1 unit time.
Find the minimum time required to paint all boards if all painters work simultaneously.

✅ Key Insight:
This is the same as **Book Allocation Problem** & **Split Array Largest Sum Problem**.
- We want to minimize the maximum workload assigned to any painter.
- A painter can only take contiguous boards.

✅ Approach: Binary Search on Answer
- Low = max(boardLength) → since one painter must at least handle the largest board.
- High = sum(boardLength) → one painter paints everything.
- Use binary search to find the smallest maximum board sum possible such that
  painters ≤ k can paint all boards.

✅ Helper Function:
`isPossible(boards, k, mid)` → checks if we can assign boards to ≤ k painters such that
no painter paints more than `mid` length.

Time Complexity: O(n log(sum(boards)))
Space Complexity: O(1)

*/

class Solution
{
public:
    // Helper: check if possible within `mid` time
    bool isPossible(vector<int> &boards, int k, long long mid)
    {
        int painters = 1;
        long long total = 0;

        for (int len : boards)
        {
            if (len > mid)
                return false; // a single board too large

            if (total + len > mid)
            {
                painters++; // allocate new painter
                total = len;

                if (painters > k)
                    return false; // too many painters
            }
            else
            {
                total += len;
            }
        }
        return true;
    }

    // Main function
    long long minTime(vector<int> &boards, int k)
    {
        long long low = *max_element(boards.begin(), boards.end());
        long long high = accumulate(boards.begin(), boards.end(), 0LL);
        long long result = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(boards, k, mid))
            {
                result = mid; // valid, try smaller max
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // not valid, increase limit
            }
        }
        return result;
    }
};
