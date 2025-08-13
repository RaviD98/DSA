// Problem: Floor and Ceil in a Sorted Array
// Link: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

// -------------------------
// ✅ Floor: Greatest element <= target
// ✅ Ceil: Smallest element >= target
// Time: O(log n), Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int floorVal = -1; // or INT_MIN if needed
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (arr[mid] < target)
        {
            floorVal = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return floorVal;
}

int findCeil(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ceilVal = -1; // or INT_MAX if needed
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (arr[mid] > target)
        {
            ceilVal = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ceilVal;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 10, 12, 14};
    int target = 5;

    cout << "Floor: " << findFloor(arr, target) << "\n"; // 4
    cout << "Ceil: " << findCeil(arr, target) << "\n";   // 6
}
