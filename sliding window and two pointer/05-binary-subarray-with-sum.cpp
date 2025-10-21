/*
✅ Problem: Binary Subarrays With Sum
🔗 Link: https://leetcode.com/problems/binary-subarrays-with-sum/

🎯 Given a binary array `nums` and an integer `goal`,
return the number of non-empty subarrays with a sum equal to `goal`.

---

🔸 Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation:
The 4 subarrays are:
[1,0,1], [0,1,0,1], [1,0,1], and [1,0,1] (overlaps allowed).

---

🔒 Constraints:
- 1 ≤ nums.length ≤ 3 * 10⁴
- nums[i] is either 0 or 1
- 0 ≤ goal ≤ nums.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Check every possible subarray sum and count how many equal the goal.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == goal)
                    count++;
            }
        }

        return count;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Prefix Sum + HashMap (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use prefix sum technique:
//     If prefixSum[j] - prefixSum[i] == goal → subarray(i+1, j) has desired sum.
//     Store frequency of prefix sums in a hashmap.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Base case: prefix sum = 0
        int sum = 0, result = 0;

        for (int num : nums)
        {
            sum += num;

            // Check if there’s a prefix sum (sum - goal)
            if (prefixCount.find(sum - goal) != prefixCount.end())
                result += prefixCount[sum - goal];

            prefixCount[sum]++;
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Sliding Window (Optimized for Binary Array)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 In binary arrays, we can count subarrays with sum ≤ goal
//     and subtract subarrays with sum ≤ goal - 1.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];

            while (sum > goal)
                sum -= nums[left++];

            count += right - left + 1;
        }

        return count;
    }
};
