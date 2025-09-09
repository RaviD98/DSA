/*

✅ Problem: Merge Sort (Recursive)
🔗 Related Link: https://www.geeksforgeeks.org/problems/merge-sort/1

Problem Statement:
🎯 Given an array `arr[]`, sort it using the **merge sort algorithm**.

🔸 Example 1:
Input  : arr = [5, 3, 8, 6, 2]
Output : [2, 3, 5, 6, 8]

🔸 Example 2:
Input  : arr = [1, 2, 3]
Output : [1, 2, 3]

🔒 Constraints:
1 ≤ arr.length ≤ 10⁵
-10⁹ ≤ arr[i] ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Merge Sort
// 🕒 Time: O(n log n), 🛢️ Space: O(n)
// 📌 Divide the array into halves, sort them recursively, and merge
// -----------------------------------------------------------------------------

class Solution
{
public:
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        // Sort left half
        mergeSort(arr, low, mid);

        // Sort right half
        mergeSort(arr, mid + 1, high);

        // Merge sorted halves
        merge(arr, low, mid, high);
    }

private:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy back to original array
        for (int i = low; i <= high; ++i)
            arr[i] = temp[i - low];
    }
};
