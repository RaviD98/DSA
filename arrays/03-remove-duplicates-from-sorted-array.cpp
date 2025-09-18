// ✅ Problem: Remove Duplicates from Sorted Array
// 🔗 Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// 🎯 Goal: Modify the sorted array in-place to remove duplicates and return the new length.
// Only the first 'k' elements of the array should hold the unique values.


// -------------------------------------------------------------
// ❗ Approach 1: Brute Force Solution - using hashset
// 🕒 Time: O(n log n) because set insertion takes log n, 🛢️ Space: O(n) for storing unique elements
// -------------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Step 1: Use a set to store unique elements (sorted automatically)
        set<int> unique(nums.begin(), nums.end());

        // Step 2: Copy back into nums
        int i = 0;
        for (int val : unique) {
            nums[i++] = val;
        }

        // Step 3: Return size of unique elements
        return unique.size();
    }
};


// -------------------------------------------------------------
// 🧠 Approach 2: Using HashSet (Extra space, not optimal for sorted array)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// Note: This violates the in-place constraint and is not recommended.
// -------------------------------------------------------------

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_set<int> unique;
        vector<int> temp;

        for (int num : nums)
        {
            if (unique.insert(num).second)
            {
                temp.push_back(num);
            }
        }

        // Copy unique elements back to nums
        for (int i = 0; i < temp.size(); ++i)
        {
            nums[i] = temp[i];
        }

        return temp.size();
    }
};

// -------------------------------------------------------------
// ✅ Approach 3: Two Pointers (In-place, Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -------------------------------------------------------------

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // i tracks the position of the last unique element
        int i = 0;

        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] != nums[i])
            {
                ++i;
                nums[i] = nums[j]; // Move next unique element forward
            }
        }

        return i + 1; // New length = last unique index + 1
    }
};
