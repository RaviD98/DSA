// Problem: Find First or Last Occurrence of a Given Number in a Sorted Array
// Link: https://www.geeksforgeeks.org/first-and-last-occurrences-of-x-in-sorted-array/

// -------------------------
// ✅ Binary Search
// Time: O(log n), Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

// Find first occurrence of x
int firstOccurrence(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1; // keep searching left
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

// Find last occurrence of x
int lastOccurrence(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1; // keep searching right
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

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    int first = firstOccurrence(arr, x);
    int last = lastOccurrence(arr, x);

    cout << "First occurrence of " << x << " is at index: " << first << "\n"; // 1
    cout << "Last occurrence of " << x << " is at index: " << last << "\n";   // 3
}
