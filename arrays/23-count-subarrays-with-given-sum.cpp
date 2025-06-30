/*

✅ Problem: Count the number of subarrays with sum K
🔗 Link: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

Problem Statement:
🎯 Given an array of integers and a target sum K, return the number of subarrays that sum exactly to K.

🔸 Example:
Input  : arr = [10, 2, -2, -20, 10], k = -10
Output : 3
Explanation: Subarrays are [10, 2, -2, -20], [2, -2, -20, 10], [-20, 10]

🔒 Constraints:
- 1 ≤ N ≤ 10⁶
- -10⁹ ≤ arr[i], K ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every subarray, check if sum equals k
// -----------------------------------------------------------------------------

class Solution
{
public:
    int findSubArraySum(vector<int> &arr, int K)
    {
        int count = 0;
        int n = arr.size();

        for (int start = 0; start < n; ++start)
        {
            int sum = 0;
            for (int end = start; end < n; ++end)
            {
                sum += arr[end];
                if (sum == K)
                    count++;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Better Approach: Prefix Sum Array (Not very helpful in this case)
// 🕒 Time: O(n²), 🛢️ Space: O(n)
// 📌 Prefix sums can be precomputed to reduce sum() time but still not optimal.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int findSubArraySum(vector<int> &arr, int K)
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (prefix[j] - prefix[i] == K)
                    count++;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal Approach: HashMap to store Prefix Sums
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 If sum - k exists in the map, then there's a subarray ending at current index with sum k
// -----------------------------------------------------------------------------

class Solution
{
public:
    int findSubArraySum(vector<int> &arr, int K)
    {
        unordered_map<int, int> prefixCount;
        int sum = 0, count = 0;

        prefixCount[0] = 1; // base case

        for (int num : arr)
        {
            sum += num;

            if (prefixCount.count(sum - K))
                count += prefixCount[sum - K];

            prefixCount[sum]++;
        }

        return count;
    }
};
