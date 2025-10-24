/*
✅ Problem: Maximum Points You Can Obtain from Cards
🔗 Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

🎯 You have several cards arranged in a row, and each card has a point value.
You can pick exactly `k` cards from either the beginning or the end of the row.
Return the maximum score you can obtain.

---

🔸 Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: Pick the first two cards and the last one → 1 + 2 + 6 + 1 = 12.

---

🔒 Constraints:
- 1 ≤ cardPoints.length ≤ 10⁵
- 1 ≤ cardPoints[i] ≤ 10⁴
- 1 ≤ k ≤ cardPoints.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force
// 🕒 Time: O(k²), 🛢️ Space: O(1)
// 📌 Try taking i cards from front and (k-i) from back for all possible i.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxSum = 0;

        for (int i = 0; i <= k; ++i)
        {
            int leftSum = 0, rightSum = 0;

            for (int j = 0; j < i; ++j)
                leftSum += cardPoints[j];

            for (int j = 0; j < k - i; ++j)
                rightSum += cardPoints[n - 1 - j];

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Instead of taking from both ends, think of removing a contiguous subarray
//     of length (n - k). The remaining elements are the chosen ones.
//     → Max Score = Total Sum - Minimum Subarray Sum of length (n - k).
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == n)
            return totalSum;

        int windowSize = n - k;
        int currSum = 0, minWindowSum = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            currSum += cardPoints[i];

            if (i >= windowSize)
                currSum -= cardPoints[i - windowSize];

            if (i >= windowSize - 1)
                minWindowSum = min(minWindowSum, currSum);
        }

        return totalSum - minWindowSum;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Prefix + Suffix Sum Combination
// 🕒 Time: O(k), 🛢️ Space: O(1)
// 📌 Take some cards from the front and the rest from the back,
//     and check all possible splits (0..k).
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int total = 0;

        // Take all from the front first
        for (int i = 0; i < k; ++i)
            total += cardPoints[i];

        int maxPoints = total;

        // Slide one card from front to back each time
        for (int i = 0; i < k; ++i)
        {
            total -= cardPoints[k - 1 - i]; // remove from front side
            total += cardPoints[n - 1 - i]; // add from back side
            maxPoints = max(maxPoints, total);
        }

        return maxPoints;
    }
};
