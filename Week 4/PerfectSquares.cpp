// PERFECT SQUARES

/*  PROBLEM:
    Given a positive integer n, find the least number of perfect square numbers 
    (for example, 1, 4, 9, 16, ...) which sum to n.
*/

/*  EXAMPLES:

    Input: n = 12
    Output: 3 
    Explanation: 12 = 4 + 4 + 4

    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9
*/

/*  APPROACH: Math (Lagrange's Four-Square Theorem)
    According to Lagrange's Four-Square Theorem, any number can be represented as the sum of four square numbers.
    1. Check if the number itself is a perfect square and return 1 if so.
    2. Check if the number can be formed using two perfect square addends.
        a. Find the square root of the given number.
        b. Iteratively check if the given number subtracted with a perfect square gives another perfect square i.e. the sum of two perfect squares.
        c. If the conditions are satisfied, return 2. 
    3. Check if the number can be formed using four perfect square addends using Legendre's Three-Square Sum Theorem.
        a. Check if the number is a power of 4.
        b. Check if the remainder is 7 when divided by 8.
        c. If the conditions are satisfied, return 4.
    4. If the prior conditions are not satisfied, then the number can be formed using three perfect square addends. Return 3.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
private:
    // Helper function to check if a number is a perfect square
    int isPerfectSquare(int n) {
        int sqrt_n = (int)(sqrt(n));
        return (sqrt_n * sqrt_n == n);
    }
public:
    int numSquares(int n) {
        // ONE ADDEND -> n = n
        // The input number itself is a perfect square
        if(isPerfectSquare(n)) {
            return 1;
        }

        // TWO ADDENDS -> n = a + b
        int sqrt_n = (int)(sqrt(n));
        for(int i = 1; i <= sqrt_n; i++) {
            if(isPerfectSquare(n - (i * i))) {
                return 2;
            }
        }
        
        // FOUR ADDENDS -> n = a + b + c + d
        // (4 ^ k) * ((8 * m) + 7) -> Legendre's Three-Square Theorem
        // Check if the number is a power of 4
        while((n & 3) == 0) { // (n % 4) == 0
            n >>= 2; // n /= 4; 
        }
        // Check if the remainder is 7 when divided by 8
        if((n & 7) == 7) { // (n % 8) == 7
            return 4;
        }
        
        // THREE ADDENDS -> n = a + b + c
        return 3;
    }
};