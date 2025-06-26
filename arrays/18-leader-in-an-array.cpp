/*

✅ Problem: Leaders in an Array
🔗 Link (GFG): https://www.geeksforgeeks.org/leaders-in-an-array/

Problem Statement:
🎯 A leader in an array is an element that is strictly greater than all the elements to its right.

Return all the leaders in the array. The rightmost element is always a leader.

🔸 Example:
Input  : arr = [16, 17, 4, 3, 5, 2]
Output : [17, 5, 2]

Input  : arr = [1, 2, 3, 4, 0]
Output : [4, 0]

🔒 Constraints:
- 1 <= arr.length <= 10⁵
- -10⁹ <= arr[i] <= 10⁹

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force Approach
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 For each element, check if it is greater than all elements to the right
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> leadersBrute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result;

        for (int i = 0; i < n; ++i)
        {
            bool isLeader = true;
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] > arr[i])
                {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader)
                result.push_back(arr[i]);
        }

        return result;
    }
};

// -----------------------------------------------------------------------------
// 🔵 Optimal Approach (Traverse from right)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Track the max from right and collect leaders in reverse
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result;
        int maxFromRight = arr[n - 1];

        result.push_back(maxFromRight); // Rightmost is always a leader

        for (int i = n - 2; i >= 0; --i)
        {
            if (arr[i] > maxFromRight)
            {
                maxFromRight = arr[i];
                result.push_back(arr[i]);
            }
        }

        reverse(result.begin(), result.end()); // To maintain left-to-right order
        return result;
    }
};
