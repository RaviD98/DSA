/*

✅ Problem: Best Time to Buy and Sell Stock II
🔗 Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Problem Statement:
🎯 You are given an integer array `prices` where prices[i] is the price of a stock on the i-th day.
On each day, you may decide to buy and/or sell the stock.
You can only hold at most one share of the stock at any time.
Return the maximum profit you can achieve.

📌 You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

🔸 Example:
Input  : prices = [7,1,5,3,6,4]
Output : 7
Explanation: Buy on day 2 (price=1), sell on day 3 (price=5),
then buy on day 4 (price=3), and sell on day 5 (price=6) → Total profit = 4 + 3 = 7.

🔒 Constraints:
- 1 <= prices.length <= 3 * 10⁴
- 0 <= prices[i] <= 10⁴

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Try all combinations) [Not feasible]
// 🕒 Time: O(2ⁿ), 🛢️ Space: O(n)
// 📌 Recursive all buy-sell possibilities — exponential time
// -----------------------------------------------------------------------------

// Skipping actual code due to inefficiency and irrelevance for large inputs

// -----------------------------------------------------------------------------
// 🟢 Peak-Valley Approach (Greedy)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Buy at every valley, sell at every peak
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, n = prices.size();
        int profit = 0;

        while (i < n - 1)
        {
            // Find valley
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            int buy = prices[i];

            // Find peak
            while (i < n - 1 && prices[i] <= prices[i + 1])
                i++;
            int sell = prices[i];

            profit += sell - buy;
        }

        return profit;
    }
};

// -----------------------------------------------------------------------------
// 🔵 One-Pass Greedy (Simplest)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Add profit whenever prices[i] > prices[i - 1]
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
