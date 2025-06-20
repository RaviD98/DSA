/*

✅ Problem: Max Consecutive Ones
🔗 Link: https://leetcode.com/problems/max-consecutive-ones/

Problem Statement:
🎯 Given a binary array `nums`, return the maximum number of consecutive 1's in the array.

🔸 Example:
Input  : nums = [1,1,0,1,1,1]
Output : 3

*/

// -----------------------------------------------------------------------------
// 🟢 Single Pass Linear Scan
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Count consecutive 1’s and update max count when interrupted by 0
// -----------------------------------------------------------------------------

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0;
        int count = 0;

        for (int num : nums)
        {
            if (num == 1)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                count = 0; // reset on 0
            }
        }

        return maxCount;
    }
};
