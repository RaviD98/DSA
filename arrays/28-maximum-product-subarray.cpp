/*

✅ Problem: Maximum Product Subarray
🔗 Link: https://leetcode.com/problems/maximum-product-subarray/

Problem Statement:
🎯 Given an integer array `nums`, find a contiguous non-empty subarray within the array
that has the largest product, and return the product.

🔸 Example:
Input  : nums = [2, 3, -2, 4]
Output : 6
Explanation: Subarray [2, 3] has the maximum product.

🔸 Example:
Input  : nums = [-2, 0, -1]
Output : 0
Explanation: Subarray [-2, 0] or [-1] both have product 0.

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach (Try all subarrays)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Try every possible subarray and calculate the product
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            int prod = 1;
            for (int j = i; j < n; ++j)
            {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal DP-like Traversal (Kadane's variation for product)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Track both max and min product at every step (because of negatives)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxProd = nums[0];
        int currMax = nums[0], currMin = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(currMax, currMin);

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Prefix & Suffix Product Traversal
// 🕒 Time: O(n), 🛢️ Space: O(1)
// 📌 Handle negative signs and zeros by computing prefix and suffix product
// -----------------------------------------------------------------------------

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int maxProd = nums[0];

        for (int i = 0; i < n; ++i)
        {
            prefix = (prefix == 0 ? 1 : prefix) * nums[i];
            suffix = (suffix == 0 ? 1 : suffix) * nums[n - i - 1];
            maxProd = max({maxProd, prefix, suffix});
        }

        return maxProd;
    }
};
