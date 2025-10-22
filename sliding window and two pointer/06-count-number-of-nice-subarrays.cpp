/*
✅ Problem: Count Number of Nice Subarrays
🔗 Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

🎯 Given an integer array `nums` and an integer `k`, return the number of contiguous subarrays that contain exactly `k` odd numbers.

---

🔸 Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation:
The subarrays with exactly 3 odd numbers are [1,1,2,1] and [1,2,1,1].

---

🔒 Constraints:
- 1 ≤ nums.length ≤ 10⁵
- 1 ≤ nums[i] ≤ 10⁵
- 1 ≤ k ≤ nums.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Check every subarray and count if it has exactly k odd numbers.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            int oddCount = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 != 0)
                    oddCount++;

                if (oddCount == k)
                    count++;
                else if (oddCount > k)
                    break;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Prefix Sum + HashMap (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Treat odd numbers as 1 and even as 0.
//     We find the number of subarrays whose prefix sum difference == k.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int sum = 0, result = 0;

        for (int num : nums)
        {
            sum += (num % 2);

            if (prefixCount.find(sum - k) != prefixCount.end())
                result += prefixCount[sum - k];

            prefixCount[sum]++;
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Sliding Window (Optimized for Binary-like Conversion)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Convert odds to 1s and evens to 0s.
//     Count subarrays with ≤ k odds - count subarrays with ≤ k - 1 odds.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int left = 0, count = 0, odd = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] % 2 != 0)
                odd++;

            while (odd > k)
            {
                if (nums[left++] % 2 != 0)
                    odd--;
            }

            count += right - left + 1;
        }

        return count;
    }
};
