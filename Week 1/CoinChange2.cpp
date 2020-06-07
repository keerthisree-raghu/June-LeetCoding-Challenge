// COIN CHANGE 2

/*  PROBLEM:
    You are given coins of different denominations and a total amount of money. 
    Write a function to compute the number of combinations that make up that amount. 
    You may assume that you have infinite number of each kind of coin.
*/

/*  EXAMPLES:

    Input: amount = 5, coins = [1, 2, 5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1

    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.

    Input: amount = 10, coins = [10] 
    Output: 1
*/

/*  APPROACH: Top-Down Dynamic Programming O(n^2)
    1. Initialize a one-dimensional vector to build the dynamic programming table.
    2. Iterate through every coin value.
    3. Build the table by adding the current value with the value at position (i - coin).
    4. Return the value at the end of the array.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Initialize a vector with size (amount + 1) to account for the case of 0 coins
        vector<int> dp(amount + 1, 0);
        // Initialize the first element of the vector as 1
        dp[0] = 1;
        // Iterate through every coin value
        for(int coin : coins) {
            for(int j = coin; j <= amount; j++) {
                // Add the current value with the value obtained by moving to the position of (i - coin)
                dp[j] += dp[j - coin];
            }
        }
        // Return the last value in the array
        return dp[amount];
    }
};