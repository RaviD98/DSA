/*
Problem: Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/

-------------------------
✅ Approach 1: Linear Search
Time: O(sqrt(x)), Space: O(1)
-------------------------
Check from 1 up to sqrt(x) and return the largest integer i such that i*i <= x.
*/

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        long long i = 1;
        while (i * i <= x)
            i++;

        return i - 1;
    }
};

// -------------------------
// ✅ Approach 2: Binary Search
// Time: O(log x), Space: O(1)
// -------------------------
// Search between [1, x/2] for the integer sqrt.
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        int left = 1, right = x / 2, ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                ans = mid;      // possible answer
                left = mid + 1; // search right
            }
            else
            {
                right = mid - 1; // search left
            }
        }
        return ans;
    }
};

// -------------------------
// ✅ Approach 3: Newton’s Method
// Time: O(log x), Space: O(1)
// -------------------------
// Newton’s iterative formula: guess = (guess + x/guess) / 2
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        long long guess = x / 2;
        while (guess * guess > x)
        {
            guess = (guess + x / guess) / 2;
        }
        return guess;
    }
};
