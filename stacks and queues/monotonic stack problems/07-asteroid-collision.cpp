/*
✅ Problem: Asteroid Collision
🔗 Link: https://leetcode.com/problems/asteroid-collision/

🎯 We are given an array `asteroids` of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction
(positive = right, negative = left).

Each asteroid moves at the same speed. When two asteroids meet:
- The smaller one explodes.
- If both are the same size, both explode.
- Two asteroids moving in the same direction never meet.

Return the state of the asteroids after all collisions.


🔸 Example 1:
Input  : asteroids = [5, 10, -5]
Output : [5, 10]
Explanation:
The 10 and -5 collide resulting in 10 (since |10| > |−5|). The 5 never collides.


🔒 Constraints:
1 ≤ asteroids.length ≤ 10⁴
-1000 ≤ asteroids[i] ≤ 1000
asteroids[i] ≠ 0

*/

// -----------------------------------------------------------------------------
// 🟠 Approach 1: Brute Force Simulation
// 🕒 Time: O(n²), 🛢️ Space: O(1)
// 📌 Repeatedly traverse the list and simulate collisions until no more can occur.
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        bool changed = true;
        while (changed)
        {
            changed = false;
            vector<int> newAsteroids;
            for (int i = 0; i < asteroids.size(); i++)
            {
                if (!newAsteroids.empty() && newAsteroids.back() > 0 && asteroids[i] < 0)
                {
                    if (abs(newAsteroids.back()) < abs(asteroids[i]))
                    {
                        newAsteroids.pop_back();
                        i--; // recheck current asteroid
                        changed = true;
                    }
                    else if (abs(newAsteroids.back()) == abs(asteroids[i]))
                    {
                        newAsteroids.pop_back();
                        changed = true;
                    }
                    else
                    {
                        changed = true;
                    }
                }
                else
                {
                    newAsteroids.push_back(asteroids[i]);
                }
            }
            asteroids = newAsteroids;
        }
        return asteroids;
    }
};

// -----------------------------------------------------------------------------
// 🟢 Approach 2: Stack Simulation (Optimal)
// 🕒 Time: O(n), 🛢️ Space: O(n)
// 📌 Use a stack to simulate collisions.
//    - Push right-moving asteroids.
//    - When a left-moving asteroid appears, handle possible collisions.
// -----------------------------------------------------------------------------

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int a : asteroids)
        {
            bool destroyed = false;

            // Collision condition: top > 0 (right), current < 0 (left)
            while (!st.empty() && st.top() > 0 && a < 0)
            {
                if (abs(st.top()) < abs(a))
                {
                    st.pop(); // top destroyed
                    continue;
                }
                else if (abs(st.top()) == abs(a))
                {
                    st.pop(); // both destroyed
                }
                destroyed = true; // current destroyed
                break;
            }

            if (!destroyed)
                st.push(a);
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
