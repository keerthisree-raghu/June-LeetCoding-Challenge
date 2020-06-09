// POWER OF TWO

/*  PROBLEM:
    Given an integer, write a function to determine if it is a power of two.
*/

/*  EXAMPLES:

    Input: 1
    Output: true 
    Explanation: 2^0 = 1

    Input: 16
    Output: true
    Explanation: 2^4 = 16

    Input: 218
    Output: false
*/

/*  APPROACH: Iterative - O(logn)
    1. If the number is 0, it cannot be a power of 2.
    2. If the number is 1, since 2 ^ 0 = 1, it is a power of 2.
    3. Iteratively reduce the power of the number by dividing by 2.
        a. If the number % 2 yields a remainder and is not 1, then it is not a power of 2.
        b. If the number evenly divides 2 and yields no remainder, it is a power of 2.
    
    Example:
    
    If n = 16,
    16 / 2 = 8
    8 / 2 = 4
    4 / 2 = 2
    2 / 2 = 1 and 2 % 2 = 0 -> return true

    If n = 17,
    17 / 2 = 8
    17 % 2 = 1 and n != 1 -> return false
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // If the number is 0, it cannot be a power of 2
        if(n == 0) {
            return false;
        }
        // If a number does not divide 2 evenly and is not 1 (since, 2 / 2 = 1), then return false
        while(n != 1) {
            if(n % 2 != 0) {
                return false;
            }
            // Iteratively divide the number by 2 to reduce the power
            n /= 2;
        }
        return true;
    }
};