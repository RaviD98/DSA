/*

✅ Problem: Best Time to Buy and Sell Stock
🔗 Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Problem Statement:
🎯 You are given an array `prices` where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and a different day to sell it.
Return the maximum profit you can achieve. If no profit is possible, return 0.

🔸 Example:
Input  : prices = [7,1,5,3,6,4]
Output : 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.

🔒 Constraints:
- 1 <= prices.length <= 10⁵
- 0 <= prices[i] <= 10⁴

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Check every pair)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every i < j and calculate profit
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int n = prices.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (prices[j] > prices[i])
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }

        return maxProfit;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal: Track Minimum Price So Far
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Buy at min price so far, sell today if profit is max
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, maxProfit = 0;

        for (int price : prices)
        {
            if (price < minPrice)
            {
                minPrice = price;
            }
            else
            {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Prefix Min Variation
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use prefix min array to track min till i and get profit
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prefixMin(n);
        prefixMin[0] = prices[0];

        for (int i = 1; i < n; ++i)
        {
            prefixMin[i] = min(prefixMin[i - 1], prices[i]);
        }

        int maxProfit = 0;
        for (int i = 1; i < n; ++i)
        {
            maxProfit = max(maxProfit, prices[i] - prefixMin[i - 1]);
        }

        return maxProfit;
    }
};
