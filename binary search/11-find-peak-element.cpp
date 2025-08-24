/*
Problem: Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/

-------------------------
✅ Approach 1: Linear Scan
Time: O(n), Space: O(1)
-------------------------
A peak element is an element strictly greater than its neighbors.
Scan the array and return the index of first peak.
*/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1]) // descent found
                return i;
        }
        return n - 1; // last element is peak if no descent
    }
};

/*
-------------------------
✅ Approach 2: Binary Search
Time: O(log n), Space: O(1)
-------------------------
Idea: A peak always exists. If nums[mid] > nums[mid+1],
then the peak lies in left half (including mid).
Otherwise, it lies in right half.
*/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                // Peak is on the left (including mid)
                right = mid;
            }
            else
            {
                // Peak is on the right
                left = mid + 1;
            }
        }
        return left; // or right (both same here)
    }
};
