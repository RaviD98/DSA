/*

Problem: Minimize Max Distance to Gas Station
Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/

✅ Problem Statement:
You are given an array `stations[]` sorted in ascending order, representing positions of gas stations.
You are also given `k` new gas stations to add between these positions.
Place the new stations such that the **maximum distance between adjacent stations is minimized**.
Return this minimized maximum distance.

✅ Key Insight:
- This is a classic **Binary Search on Answer** problem.
- The answer lies between 0 and (max distance between two consecutive stations).
- For a candidate answer `mid`, check if we can insert ≤ k new stations to make
  every gap ≤ mid.

✅ Approach:
1. Low = 0, High = max(stations[i+1] - stations[i]).
2. For each mid, compute how many stations are needed to break all gaps ≤ mid.
3. If needed stations ≤ k → feasible, try smaller distance.
4. Otherwise, increase mid.

✅ Time Complexity: O(n log(1e6)) ≈ O(n logC)
✅ Space Complexity: O(1)

*/

class Solution
{
public:
    // Helper: checks if distance `mid` is possible with ≤ k stations
    bool canPlace(vector<int> &stations, int k, double mid)
    {
        int count = 0;
        for (int i = 1; i < stations.size(); i++)
        {
            double gap = stations[i] - stations[i - 1];
            count += int(gap / mid); // how many extra stations needed
        }
        return count <= k;
    }

    double minmaxGasDist(vector<int> &stations, int k)
    {
        double low = 0, high = stations.back() - stations.front();
        double result = high;

        // Binary search on precision (1e-6 for floating point)
        while (high - low > 1e-6)
        {
            double mid = (low + high) / 2.0;

            if (canPlace(stations, k, mid))
            {
                result = mid; // feasible, try smaller max distance
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return result;
    }
};
