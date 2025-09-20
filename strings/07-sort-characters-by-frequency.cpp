/*
    ✅ Problem: Sort Characters By Frequency
    🔗 Link: https://leetcode.com/problems/sort-characters-by-frequency/

    🎯 Given a string s, sort it in decreasing order based on the frequency of characters.
        If multiple characters have the same frequency, they can appear in any order.


    🔸 Example 1:
    Input  : s = "tree"
    Output : "eert"   (or "eetr")

    🔸 Example 2:
    Input  : s = "cccaaa"
    Output : "cccaaa" (or "aaaccc")

    🔸 Example 3:
    Input  : s = "Aabb"
    Output : "bbAa"   (or "bbaA")

    Constraints:
    1 ≤ s.length ≤ 5 * 10^5
    s consists of uppercase and lowercase English letters and digits.
    */

    // -----------------------------------------------------------------------------
    // ✅ Approach 1: HashMap + Max Heap (Priority Queue)
    // 🕒 Time: O(n log k), 🛢️ Space: O(n)
    // -----------------------------------------------------------------------------

    class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto &p : freq)
            pq.push({p.second, p.first});

        string result;
        while (!pq.empty())
        {
            auto [count, ch] = pq.top();
            pq.pop();
            result.append(count, ch);
        }
        return result;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: HashMap + Sorting
// 🕒 Time: O(n log k), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        string result;
        for (auto &p : vec)
            result.append(p.second, p.first);

        return result;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: Bucket Sort
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        int n = s.size();
        vector<vector<char>> bucket(n + 1);

        for (auto &p : freq)
            bucket[p.second].push_back(p.first);

        string result;
        for (int i = n; i >= 1; i--)
        {
            for (char c : bucket[i])
                result.append(i, c);
        }

        return result;
    }
};
