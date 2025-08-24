// Problem: Find Nth Root of a Number
// Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m/1

// -------------------------
// ✅ Approach : Binary Search
// Time: O(nlog x), Space: O(1)
// -------------------------

class Solution
{
public:
    // Helper function: checks mid^n compared to x
    long long power(long long mid, int n, int x)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= mid;
            if (ans > x)
                return 2; // mid^n > x
        }
        if (ans == x)
            return 1; // mid^n == x
        return 0;     // mid^n < x
    }

    int NthRoot(int n, int x)
    {
        int low = 1, high = x;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int res = power(mid, n, x);

            if (res == 1)
                return mid; // exact root found
            else if (res == 0)
                low = mid + 1; // move right
            else
                high = mid - 1; // move left
        }
        return -1; // not a perfect nth root
    }
};
