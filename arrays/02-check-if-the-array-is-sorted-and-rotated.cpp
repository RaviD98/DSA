// ✅ Problem: Check if Array is Sorted and Rotated
// 🔗 Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


// ✅ Approach:
// Count the number of places where nums[i] > nums[i+1] (with circular check using %n)
// - If count == 0 ➜ sorted, not rotated
// - If count == 1 ➜ sorted and rotated
// - If count > 1 ➜ not sorted and rotated

// 🕒 Time Complexity: O(n)
// 🛢️ Space Complexity: O(1)

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        // Traverse the array and count how many times the next element is smaller
        for (int i = 0; i < n; ++i)
        {
            // Use modulo to check circular condition (nums[n-1] > nums[0])
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }

        // If the count of such drops is more than 1, array is not sorted and rotated
        return count <= 1;
    }
};
