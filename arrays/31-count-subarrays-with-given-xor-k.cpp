/*

✅ Problem: Count the Number of Subarrays with XOR equal to K
🔗 Link: https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

Problem Statement:
🎯 Given an array of integers `arr[]` and an integer `k`, count the number of subarrays whose XOR is equal to `k`.

🔸 Example 1:
Input  : arr = [4, 2, 2, 6, 4], k = 6
Output : 4
Explanation: The subarrays are [4,2], [2,2,6], [6], and [4,2,2,6].

🔸 Example 2:
Input  : arr = [5, 6, 7, 8, 9], k = 5
Output : 2
Explanation: Subarrays [5] and [6,7,8,9] have XOR = 5.

🔒 Constraints:
- 1 ≤ n ≤ 10⁶
- 0 ≤ arr[i], k ≤ 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (Check all subarrays)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every possible subarray and calculate its XOR
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countSubarraysWithXor(vector<int> &arr, int k)
    {
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            int xr = 0;
            for (int j = i; j < n; ++j)
            {
                xr ^= arr[j];
                if (xr == k)
                    count++;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal Approach using Prefix XOR + HashMap
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Let prefixXor = XOR from index 0 to i
//     if prefixXor ^ k = some prefix seen before, we found a valid subarray
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countSubarraysWithXor(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        int count = 0, prefixXor = 0;

        for (int num : arr)
        {
            prefixXor ^= num;

            // Case 1: subarray from beginning
            if (prefixXor == k)
                count++;

            // Case 2: subarray between i and j (prefixXor ^ k = required prefix)
            int required = prefixXor ^ k;
            if (freq.find(required) != freq.end())
            {
                count += freq[required];
            }

            // Update frequency of current prefixXor
            freq[prefixXor]++;
        }

        return count;
    }
};
