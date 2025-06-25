/*

✅ Problem: Rearrange Array Elements by Sign
🔗 Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

Problem Statement:
🎯 You are given a 0-indexed integer array `nums` of even length consisting of an equal number of positive and negative integers.
You must rearrange the elements of `nums` such that the modified array follows the alternating pattern:
positive, negative, positive, negative...

🔸 Example:
Input  : nums = [3,1,-2,-5,2,-4]
Output : [3,-2,1,-5,2,-4]

🔒 Constraints:
- 2 <= nums.length <= 2 * 10⁵
- nums.length is even
- nums consists of equal numbers of positive and negative integers
- -10⁴ <= nums[i] <= 10⁴
- nums contains no zeros

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each index, find the correct sign and place by shifting
// -----------------------------------------------------------------------------

// Skipping due to inefficient shifting and not useful in large input scenarios

// -----------------------------------------------------------------------------
// 🟢 Extra Space (Two Arrays + Merge Alternately)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Store positive and negative separately, then merge alternately
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;

        for (int num : nums)
        {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        vector<int> result;
        for (int i = 0; i < pos.size(); ++i)
        {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal In-Place Two Pointers
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Place positive at even, negative at odd indices
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int posIdx = 0, negIdx = 1;

        for (int num : nums)
        {
            if (num > 0)
            {
                res[posIdx] = num;
                posIdx += 2;
            }
            else
            {
                res[negIdx] = num;
                negIdx += 2;
            }
        }

        return res;
    }
};
