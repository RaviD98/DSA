// Problem: Lower Bound & Upper Bound in Sorted Array
// Link: https://www.geeksforgeeks.org/cpp-stl-lower_bound-and-upper_bound/

// -------------------------
// ✅ Lower Bound: First index where element >= target
// ✅ Upper Bound: First index where element > target
// Time: O(log n), Space: O(1)
// -------------------------

#include <bits/stdc++.h>
using namespace std;

// Function to find lower bound
int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // index
}

// Function to find upper bound
int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // index
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 5, 6};
    int target = 4;

    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    cout << "Lower Bound Index: " << lb << "\n"; // 2
    cout << "Upper Bound Index: " << ub << "\n"; // 4
}
