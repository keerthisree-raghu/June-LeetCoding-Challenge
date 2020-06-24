// DUNGEON GAME

/*  PROBLEM:
    The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
    The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially 
    positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
    
    The knight has an initial health point represented by a positive integer. If at any point his health 
    point drops to 0 or below, he dies immediately.
    
    Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
    other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

    In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
    Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

    Note:
    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

/*  I/O FORMAT:

    Input Format: Two-dimensional vector representing the dungeon.
    Output Format: Integer representing the knight's minimum initial health.
*/

/*  APPROACH: Bottom-Up Dynamic Programming
    1. Create a two-dimensional vector to store the value of health points, such that health[i][j] represents the health points required to enter the cell at position ( i, j).
    2. Traverse through the grid in a bottom-up manner
        a. Calculate the minimum number of health points required to travel to the next cell.
        b. If the health value drops below 0, reset the value to 1. Otherwise, calculate the maximum value required.
    3. Return the resulting value generated in the origin cell as the initial health points possessed by the knight.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> health(rows + 1, vector<int>(cols + 1, INT_MAX));
        
        // health[i][j] = minimum health needed to enter position (i, j)
        // Create an auxillary row and column on the right and bottom of the table
        health[rows][cols - 1] = 1;
        health[rows - 1][cols] = 1;
        
        for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {
                // Calculate the number of health points required to move to either possible cell.
                // Find the optimal path by choosing the minimum health value and deducting the value in the dungeon cell.
                int points = min(health[i + 1][j], health[i][j + 1]) - dungeon[i][j];
                // The knight would need at least 1 health point to begin with.
                // Choose the maximum value between the calculated points and the minimum possible points.
                health[i][j] = max(1, points);
            }
        }
        return health[0][0];
    }
};