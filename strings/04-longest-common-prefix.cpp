/*

✅ Problem: Longest Common Prefix
🔗 Link: https://leetcode.com/problems/longest-common-prefix/

🎯 Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return "".

---

🔸 Example 1:
Input  : strs = ["flower","flow","flight"]
Output : "fl"

🔸 Example 2:
Input  : strs = ["dog","racecar","car"]
Output : ""

---

Constraints:
1 ≤ strs.length ≤ 200
0 ≤ strs[i].length ≤ 200
strs[i] consists of only lowercase English letters.

*/

// -------------------------
// ✅ Approach 1: Horizontal Scanning
// 🕒 Time: O(S), 🛢️ Space: O(1)
// where S = sum of all characters in strs
// -------------------------
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {                      // check prefix in each string
                prefix.pop_back(); // shrink until it matches
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};

// -------------------------
// ✅ Approach 2: Vertical Scanning
// 🕒 Time: O(S), 🛢️ Space: O(1)
// -------------------------
class Solution2
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
