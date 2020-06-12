// IS SUBSEQUENCE

/*  PROBLEM:
    Given a string s and a string t, check if s is subsequence of t.

    A subsequence of a string is a new string which is formed from the original string by deleting some 
    (can be none) of the characters without disturbing the relative positions of the remaining characters. 
    (ie, "ace" is a subsequence of "abcde" while "aec" is not).

    Follow up:
    If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check 
    one by one to see if T has its subsequence. In this scenario, how would you change your code?

    Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 10^4
    Both strings consists only of lowercase characters.
*/

/*  EXAMPLES:

    Input: s = "abc", t = "ahbgdc"
    Output: true

    Input: s = "axc", t = "ahbgdc"
    Output: false
*/

/*  APPROACH 1: Two Pointer
    1. Iterate through each string.
    2. Check if the characters from each string are equal.
        a. If the characters are equal, increment the pointer of the first string.
        b. If the characters are not equal, increment the pointer of the second string.
    3. Check if the value of the first pointer is equal to the length of the first string when the loop exits.
        a. If the values are equal, return true.
        b. If the values are unequal, return false.
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        int i = 0, j = 0;
        // Iterate through each string
        while(i < s_len && j < t_len) {
            // Increment i if a charcter is equal
            if(s[i] == t[j]) {
                i++;
            }
            // Increment j if a character is not equal
            j++;
        }
        // Check if the length of string s is equal to i
        return i == s_len ? true : false;
    }
};

/*  APPROACH 2: Top-Down Dynamic Programming

    Helper Function - To find the longest common subsequence
    1. Initialize a two-dimensional array (m x n) to build the DP table.
    2. Build the table by checking the following conditions:
        a. If the cell is in the first row or first column (i = 0 or j = 0),
           then initialize the value of the cell as 0.
        b. If the characters being compared in each string are equal, 
           the value of the cell is obtained by incrementing the value of
           the solution in the top left diagonal cell by 1.
        c. If the characters being compared in each string are unequal,
           the value of the cell is obtained by finding the maximum value
           between the value in the top cell and the left cell.
    3. Return the value of the last cell in the table.

    isSubsequence() Function - To check if the LCS is the same as the smaller substring
    1. Store the length of the smaller string in a variable.
    2. Call the helper function and check if the resulting value is equal to the length of the smaller string.
        a. If the values are equal, return true.
        b. If the values are unequal, return false.

*/

//  SOLUTION 2:
class Solution2 {
public:
    int lcs(string s, string t) {
        int m = s.length() + 1;
        int n = t.length() + 1;
        // Initialize a two-dimensional array of size m x n to build the DP table
        int dp[m][n];
        // Iterate through each row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Initialize the first row and column as 0
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                // If the characters are equal, add one to the solution in the top left diagonal cell
                else if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // If the characters are not equal, find the maximum of the values of the top and left solutions
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // Return the value of the last cell in the table
        return dp[m - 1][n - 1];
    }
    bool isSubsequence(string s, string t) {
        int len = lcs(s, t);
        // Check if the length of the longest common subsequence is equal to the smaller string
        if(len == s.length()) {
            return true;
        }
        return false;
    }
};