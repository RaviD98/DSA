/*

✅ Problem: Recursive Binary Search
🔗 Related Link: https://www.geeksforgeeks.org/problems/binary-search-1587115620/1

Problem Statement:
🎯 Given a **sorted array** and a target value, return the index of the target
using recursive binary search. If not found, return -1.

🔸 Example 1:
Input  : arr = [1, 3, 5, 7, 9], target = 5
Output : 2

🔸 Example 2:
Input  : arr = [1, 3, 5, 7, 9], target = 4
Output : -1

🔒 Constraints:
- Array is sorted in ascending order
- 1 ≤ arr.size() ≤ 10⁵

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Binary Search
// 🕒 Time: O(log n), 🛢️ Space: O(log n) — recursion stack
// 📌 Divide the array into halves and recursively search
// -----------------------------------------------------------------------------

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        return binarySearch(arr, 0, arr.size() - 1, target);
    }

private:
    int binarySearch(vector<int> &arr, int low, int high, int target)
    {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            return binarySearch(arr, low, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, high, target);
    }
};
