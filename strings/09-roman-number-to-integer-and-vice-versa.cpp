/*
✅ Problem: Roman to Integer / Integer to Roman
🔗 Roman to Integer: https://leetcode.com/problems/roman-to-integer/
🔗 Integer to Roman: https://leetcode.com/problems/integer-to-roman/

🎯 Roman to Integer: Given a Roman numeral string `s`, convert it to an integer.
🎯 Integer to Roman: Given an integer `num`, convert it to a Roman numeral string.

---

Roman Numerals Mapping:
I=1, V=5, X=10, L=50, C=100, D=500, M=1000
Subtractive cases: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900

*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Roman to Integer (Scan Left to Right)
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 1 < s.size() && m[s[i]] < m[s[i + 1]])
                res -= m[s[i]]; // subtractive case
            else
                res += m[s[i]];
        }
        return res;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Integer to Roman
// 🕒 Time: O(n), 🛢️ Space: O(1)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> vals = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string res;
        for (auto &[val, sym] : vals)
        {
            while (num >= val)
            {
                num -= val;
                res += sym;
            }
        }
        return res;
    }
};
