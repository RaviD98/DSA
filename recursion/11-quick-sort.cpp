/*

✅ Problem: Quick Sort (Recursive)
🔗 Related Link: https://www.geeksforgeeks.org/problems/quick-sort/1

Problem Statement:
🎯 Sort the given array using the Quick Sort algorithm.

🔸 Example 1:
Input  : arr = [4, 1, 3, 9, 7]
Output : [1, 3, 4, 7, 9]

🔸 Example 2:
Input  : arr = [10, 5, 2, 0]
Output : [0, 2, 5, 10]

🔒 Constraints:
1 ≤ arr.length ≤ 10⁵
-10⁹ ≤ arr[i] ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Quick Sort (Lomuto Partition Scheme)
// 🕒 Time: Avg O(n log n), Worst O(n²), 🛢️ Space: O(log n) for recursion stack
// 📌 Choose pivot, partition around it, then sort left and right recursively
// -----------------------------------------------------------------------------

class Solution
{
public:
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int pivotIndex = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }

private:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high]; // choosing last element as pivot
        int i = low - 1;       // index of smaller element

        for (int j = low; j < high; ++j)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]); // place pivot at the correct position
        return i + 1;                // return pivot index
    }
};
