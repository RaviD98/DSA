/*

✅ Problem: Next Greater Element I
🔗 Link: https://leetcode.com/problems/next-greater-element-i/

Problem Statement:
🎯 The next greater element of some element `x` in an array is the first greater element that is to the right of `x` in the same array.

You are given two arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.
For each element in `nums1`, find the **next greater element** in `nums2`.
If it does not exist, return -1 for that element.

🔸 Example:
Input  : nums1 = [4,1,2], nums2 = [1,3,4,2]
Output : [-1,3,-1]
Explanation:
- Next greater of 4 → none → -1
- Next greater of 1 → 3
- Next greater of 2 → none → -1

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n1 * n2), 🛢️ Space: O(1)
// 📌 For each element in nums1, search its next greater in nums2
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); ++i)
        {
            int num = nums1[i];
            bool found = false;
            int greater = -1;

            // Search for num in nums2
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (nums2[j] == num)
                {
                    found = true;
                }
                else if (found && nums2[j] > num)
                {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal Approach (Using Stack + HashMap)
// 🕒 Time: O(n2 + n1), 🛢️ Space: O(n2)
// 📌 Use a stack to precompute the next greater for each element in nums2
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            int num = nums2[i];

            // Maintain decreasing stack
            while (!st.empty() && st.top() <= num)
                st.pop();

            // If stack empty → no greater element
            nextGreater[num] = st.empty() ? -1 : st.top();

            st.push(num);
        }

        // Build result for nums1
        vector<int> ans;
        for (int num : nums1)
        {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
