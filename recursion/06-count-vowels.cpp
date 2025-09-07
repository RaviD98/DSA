/*

✅ Problem: Count Vowels in a String
🔗 Link: https://www.geeksforgeeks.org/problems/count-vowels-in-a-string-1587115621/1

🎯 Given a string `s`, return the total number of vowels (a, e, i, o, u)
present in it using recursion.

🔸 Example 1:
Input  : s = "geeksforgeeks"
Output : 5

🔸 Example 2:
Input  : s = "abcde"
Output : 2

🔒 Constraints:
1 ≤ s.length ≤ 10⁴
String may contain lowercase and uppercase characters

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach
// 🕒 Time: O(n), 🛢️ Space: O(n) — recursion stack
// 📌 Recursively check if the current character is a vowel
// -----------------------------------------------------------------------------

class Solution
{
public:
    int countVowels(string &s)
    {
        return helper(s, 0);
    }

private:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int helper(string &s, int i)
    {
        if (i == s.length())
            return 0;

        int count = isVowel(s[i]) ? 1 : 0;
        return count + helper(s, i + 1);
    }
};
