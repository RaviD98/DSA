/*
✅ Problem: Fruit Into Baskets
🔗 Link: https://leetcode.com/problems/fruit-into-baskets/

🎯 You are given an integer array `fruits` where each element represents a type of fruit.
You have two baskets and each basket can only hold one type of fruit.

You can pick fruits starting from any tree and moving to the right, collecting one fruit per tree.
You must stop once you encounter a third fruit type.

Return the **maximum number of fruits** you can pick.

---

🔸 Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: You can take all fruits since only two types (1 and 2) are present.


---

🔒 Constraints:
- 1 ≤ fruits.length ≤ 10⁵
- 0 ≤ fruits[i] < fruits.length
*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force (Expand Window for Each Start)
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each index, expand right until you encounter more than 2 distinct fruits.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxFruits = 0;

        for (int left = 0; left < n; left++)
        {
            unordered_map<int, int> basket;
            for (int right = left; right < n; right++)
            {
                basket[fruits[right]]++;

                if (basket.size() > 2)
                    break;

                maxFruits = max(maxFruits, right - left + 1);
            }
        }

        return maxFruits;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Sliding Window + HashMap
// 🕒 Time: O(n), 🛢️ Space: O(1) (since only 2 fruit types stored)
// 📌 Maintain a window with at most 2 fruit types.
//     If more than 2 types, shrink from left until valid again.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> basket;
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]++;

            while (basket.size() > 2)
            {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Approach 3: Optimized Sliding Window (Compact Logic)
// 🕒 Time: O(n), 🛢️ Space: O(2)
// 📌 Same as Approach 2 but with tighter logic and minimal branching.
// -----------------------------------------------------------------------------

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> count;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++)
        {
            count[fruits[right]]++;

            while (count.size() > 2)
            {
                if (--count[fruits[left]] == 0)
                    count.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
