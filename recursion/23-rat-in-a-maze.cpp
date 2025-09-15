/*

✅ Problem: Rat in a Maze
🔗 Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

🎯 You are given a `n x n` maze represented by a binary matrix `m[][]`.
- 1 → open cell (rat can move).
- 0 → blocked cell (rat cannot move).

The rat starts at `(0,0)` and must reach `(n-1,n-1)` by moving **Down (D), Left (L), Right (R), Up (U)**.
Return all possible paths in **lexicographic order**. If no path exists, return an empty list.

---

🔸 Example 1:
Input : n = 4
m[][] =
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Output : ["DDRDRR", "DRDDRR"]

🔸 Example 2:
Input : n = 2
m[][] =
1 0
1 0

Output : []

---

*/

// -----------------------------------------------------------------------------
// 🔁 Recursion + Backtracking
// 🕒 Time: O(4^(n^2)) worst case (every cell with 4 directions)
// 🛢️ Space: O(n^2) recursion stack + visited matrix
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> result;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if (m[0][0] == 0)
            return result; // start blocked

        string path = "";
        dfs(0, 0, m, visited, path, result, n);

        sort(result.begin(), result.end()); // lexicographic order
        return result;
    }

private:
    void dfs(int i, int j, vector<vector<int>> &m, vector<vector<bool>> &visited,
             string &path, vector<string> &result, int n)
    {

        // Base case: reached destination
        if (i == n - 1 && j == n - 1)
        {
            result.push_back(path);
            return;
        }

        // Mark visited
        visited[i][j] = true;

        // Directions: D, L, R, U (in lexicographic order)
        static int di[] = {1, 0, 0, -1};
        static int dj[] = {0, -1, 1, 0};
        static char dir[] = {'D', 'L', 'R', 'U'};

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (isSafe(ni, nj, m, visited, n))
            {
                path.push_back(dir[k]);
                dfs(ni, nj, m, visited, path, result, n);
                path.pop_back(); // backtrack
            }
        }

        // Unmark visited (backtrack)
        visited[i][j] = false;
    }

    bool isSafe(int i, int j, vector<vector<int>> &m, vector<vector<bool>> &visited, int n)
    {
        return (i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1 && !visited[i][j]);
    }
};
