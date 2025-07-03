/*

✅ Problem: Merge Intervals
🔗 Link: https://leetcode.com/problems/merge-intervals/

Problem Statement:
🎯 Given an array of intervals where intervals[i] = [start_i, end_i],
merge all overlapping intervals and return an array of the non-overlapping intervals
that cover all the intervals in the input.

🔸 Example:
Input  : intervals = [[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]

🔸 Example:
Input  : intervals = [[1,4],[4,5]]
Output : [[1,5]]

🔒 Constraints:
- 1 <= intervals.length <= 10⁴
- intervals[i].length == 2
- 0 <= start_i <= end_i <= 10⁴

*/

// -----------------------------------------------------------------------------
// 🟠 Brute Force (Inefficient) – Not commonly used
// 🕒 Time: O(n²), 🛢️ Space: O(n)
// 📌 Compare every interval with every other one, merge if overlapping
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        vector<vector<int>> merged;
        vector<bool> used(intervals.size(), false);

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (used[i])
                continue;
            int start = intervals[i][0];
            int end = intervals[i][1];

            for (int j = i + 1; j < intervals.size(); ++j)
            {
                if (used[j])
                    continue;
                int s = intervals[j][0];
                int e = intervals[j][1];

                // Check overlap
                if (!(end < s || e < start))
                {
                    start = min(start, s);
                    end = max(end, e);
                    used[j] = true;
                }
            }

            used[i] = true;
            merged.push_back({start, end});
        }

        sort(merged.begin(), merged.end());
        return merged;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Optimal Greedy Approach
// 🕒 Time: O(n log n), 🛢️ Space: O(n)
// 📌 Sort intervals by start time and merge in one pass
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.empty())
            return merged;

        sort(intervals.begin(), intervals.end());

        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= current[1])
            {
                // Overlapping → merge
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                // No overlap → store previous
                merged.push_back(current);
                current = intervals[i];
            }
        }

        merged.push_back(current);
        return merged;
    }
};
