/*

✅ Problem: Union of Two Sorted Arrays
🔗 Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

Problem Statement:
🎯 Given two sorted arrays `arr1[]` and `arr2[]` of size N and M respectively,
return the union of the two arrays as a sorted list of **distinct elements**.

🔸 Example:
Input  : arr1[] = {1, 2, 3, 4, 5}, arr2[] = {1, 2, 3}
Output : {1, 2, 3, 4, 5}

Input  : arr1[] = {2, 2, 3, 4, 5}, arr2[] = {1, 1, 2, 3}
Output : {1, 2, 3, 4, 5}

🔒 Constraints:
1 ≤ N, M ≤ 10^5
1 ≤ arr1[i], arr2[i] ≤ 10^6

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force using Set
// 🕒 Time: O((N + M) log(N + M)), 🛢️ Space: O(N + M)
// 📌 Insert all elements into a set to eliminate duplicates and return sorted order
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr1[i]);
        for (int i = 0; i < m; ++i)
            s.insert(arr2[i]);

        return vector<int>(s.begin(), s.end());
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimized Two Pointer Approach (Since arrays are sorted)
// 🕒 Time: O(N + M), 🛢️ Space: O(N + M) (result space)
// 📌 Traverse both arrays simultaneously and skip duplicates
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                if (result.empty() || result.back() != arr1[i])
                    result.push_back(arr1[i]);
                ++i;
            }
            else if (arr2[j] < arr1[i])
            {
                if (result.empty() || result.back() != arr2[j])
                    result.push_back(arr2[j]);
                ++j;
            }
            else
            {
                if (result.empty() || result.back() != arr1[i])
                    result.push_back(arr1[i]);
                ++i;
                ++j;
            }
        }

        while (i < n)
        {
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            ++i;
        }

        while (j < m)
        {
            if (result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);
            ++j;
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Using Unordered Set + Sorting
// 🕒 Time: O(N + M) + O(K log K), 🛢️ Space: O(N + M)
// 📌 Store all in unordered_set (fast insert), then sort the result
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        unordered_set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr1[i]);
        for (int i = 0; i < m; ++i)
            s.insert(arr2[i]);

        vector<int> result(s.begin(), s.end());
        sort(result.begin(), result.end());
        return result;
    }
};
