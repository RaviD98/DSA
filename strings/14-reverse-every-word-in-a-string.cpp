/*
✅ Problem: Reverse Words in a String
🔗 Link: https://leetcode.com/problems/reverse-words-in-a-string/

🎯 Given an input string `s`, reverse the order of the words.
A word is defined as a sequence of non-space characters.
Return a string of the words in reverse order concatenated by a single space.

---

🔸 Example 1:
Input  : s = "the sky is blue"
Output : "blue is sky the"

🔸 Example 2:
Input  : s = "  hello world  "
Output : "world hello"
Explanation: Trim leading/trailing spaces and reduce multiple spaces to single space.

🔸 Example 3:
Input  : s = "a good   example"
Output : "example good a"

---

🔒 Constraints:
1 ≤ s.length ≤ 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

// -----------------------------------------------------------------------------
// ✅ Approach 1: Using StringStream
// - Split words using stringstream
// - Store in vector, then reverse
// - Join with spaces
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word)
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i < words.size() - 1)
                result += " ";
        }
        return result;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 2: Manual Parsing (In-Place Simulation)
// - Trim spaces
// - Extract words manually and store
// - Reverse word order
// - More control (no extra libs like stringstream)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// -----------------------------------------------------------------------------

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++; // skip spaces
            if (i >= n)
                break;
            int j = i;
            while (j < n && s[j] != ' ')
                j++; // find end of word
            words.push_back(s.substr(i, j - i));
            i = j + 1;
        }

        reverse(words.begin(), words.end());

        string result;
        for (int k = 0; k < words.size(); k++)
        {
            result += words[k];
            if (k < words.size() - 1)
                result += " ";
        }
        return result;
    }
};

// -----------------------------------------------------------------------------
// ✅ Approach 3: In-place Reverse (Optimized)
// - Reverse entire string
// - Reverse each word individually
// - Remove extra spaces
// 🕒 Time: O(n), 🛢️ Space: O(1) (ignoring result string)
// -----------------------------------------------------------------------------

class Solution
{
public:
    void reverseString(string &s, int l, int r)
    {
        while (l < r)
            swap(s[l++], s[r--]);
    }

    string reverseWords(string s)
    {
        int n = s.size();
        // Step 1: Reverse entire string
        reverseString(s, 0, n - 1);

        // Step 2: Reverse each word
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (idx != 0)
                    s[idx++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ')
                    s[idx++] = s[j++];
                reverseString(s, idx - (j - i), idx - 1);
                i = j;
            }
        }

        s.erase(s.begin() + idx, s.end()); // remove extra chars
        return s;
    }
};
