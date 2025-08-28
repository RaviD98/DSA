/*

Problem: Allocate Minimum Number of Pages (Book Allocation Problem)
Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

✅ Problem Statement:
We are given `n` books and `m` students. Each book has some number of pages.
The task is to allocate books to students such that:
  - Each student gets at least one book
  - Books are allocated in a contiguous manner
  - The maximum number of pages assigned to a student is minimized

✅ Approach: Binary Search on Answer
- Low = max(pages) (minimum possible allocation, since at least one student must take the largest book).
- High = sum(pages) (maximum allocation if only one student takes all books).
- We binary search for the smallest maxPages such that allocation is possible.

✅ Helper Function:
`isPossible(pages, n, m, mid)` → checks if we can allocate books with max pages = mid.

Time Complexity: O(n log(sum(pages)))
Space Complexity: O(1)

*/

class Solution
{
public:
    // Helper function: Check if allocation possible with maxPages = mid
    bool isPossible(vector<int> &arr, int n, int m, int mid)
    {
        int studentCount = 1; // start with 1 student
        int pagesSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                return false; // single book exceeds mid

            if (pagesSum + arr[i] > mid)
            {
                studentCount++;
                pagesSum = arr[i];

                if (studentCount > m)
                    return false;
            }
            else
            {
                pagesSum += arr[i];
            }
        }
        return true;
    }

    // Main function: Allocate pages
    int findPages(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (m > n)
            return -1; // not enough books

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, n, m, mid))
            {
                result = mid;
                high = mid - 1; // try for smaller maximum
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
