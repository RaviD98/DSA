// Problem: Count Occurrences in a Sorted Array
// Link: https://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/

// -------------------------
// ✅ Binary Search (Find First & Last Occurrence)
// Time: O(log n), Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1; // search left
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOccurrence(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1; // search right
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int countOccurrences(vector<int> &arr, int x)
{
    int first = firstOccurrence(arr, x);
    if (first == -1)
        return 0; // not found
    int last = lastOccurrence(arr, x);
    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;
    cout << "Count of " << x << ": " << countOccurrences(arr, x) << "\n"; // 3
}
