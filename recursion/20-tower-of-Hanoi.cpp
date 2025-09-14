/*

✅ Problem: Tower of Hanoi
🔗 Link: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

🎯 Given `n` disks and 3 pegs (source, auxiliary, destination),
move all disks from source to destination following the rules:
1. Only one disk can be moved at a time.
2. A larger disk cannot be placed on top of a smaller disk.

🔸 Example:
Input: n = 3
Output: Sequence of moves:
Move disk 1 from source A to destination C
Move disk 2 from source A to destination B
Move disk 1 from source C to destination B
Move disk 3 from source A to destination C
Move disk 1 from source B to destination A
Move disk 2 from source B to destination C
Move disk 1 from source A to destination C

🔒 Constraints:
1 ≤ n ≤ 20 (practical recursion limit)

*/

// -----------------------------------------------------------------------------
// 🔁 Recursive Approach
// 🕒 Time: O(2^n - 1), 🛢️ Space: O(n) — recursion stack
// -----------------------------------------------------------------------------

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 0)
        return; // base case: no disk to move

    // Step 1: move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: move nth disk from source to destination
    cout << "Move disk " << n << " from source " << source
         << " to destination " << destination << endl;

    // Step 3: move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n = 3;                      // number of disks
    towerOfHanoi(n, 'A', 'B', 'C'); // A: source, B: auxiliary, C: destination
    return 0;
}
